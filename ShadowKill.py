from datetime import datetime
import os
import sys
import ctypes
from PyQt5 import QtWidgets, QtGui
from PyQt5.QtWidgets import QMessageBox, QApplication

import ShadowKill_UI


### 用于读取QSS
class CommonHelper:
    def __init__(self):
        pass

    @staticmethod
    def readQss(style):
        try:
            with open(style, 'r', encoding='utf-8') as f:
                return f.read()
        except FileNotFoundError:
            return False


def get_qss_files(folder_path):
    qss_files = []
    for root, dirs, files in os.walk(folder_path):
        for file in files:
            if file.endswith('.qss'):
                qss_files.append(file[:-4])  # 去掉 .qss 后缀
    return qss_files


### 页面设置
class MyUI(QtWidgets.QWidget):
    def __init__(self):
        self.theme_list = ['default']
        self.theme_list.extend(get_qss_files('./config'))
        print(self.theme_list)
        self.save_photo_path = ''  # 游戏截图保存目录
        self.color_list = []  # 每个人的颜色
        self.player_list = []  # 开始的参与者名单
        self.player_now_state = []  # 当前参与者
        super().__init__()
        self.init_my_ui()
        self.ui.theme_comboBox.addItems(self.theme_list)
        self.init_my_button()

    def init_my_ui(self):
        # 创建一个 test0.shadowkill 的实例
        self.ui = ShadowKill_UI.Ui_shadowkill()
        self.ui.setupUi(self)
        self.setWindowTitle("ShadowKill")

        ctypes.windll.shell32.SetCurrentProcessExplicitAppUserModelID("myappid")

        try:
            icon = QtGui.QIcon()
            icon.addPixmap(QtGui.QPixmap("./icon/Kano.ico"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
            self.setWindowIcon(icon)
        except FileNotFoundError:
            self.add_history_text('图标文件不存在')

    ### 按键初始化
    def init_my_button(self):

        # 绑定按钮
        self.ui.theme_comboBox.currentIndexChanged.connect(self.change_theme)
        self.ui.load_name_pushbutton.clicked.connect(self.load_name_list)
        self.ui.sure_name_pushbutton.clicked.connect(self.sure_name_list)
        self.ui.unlock_pushbutton.clicked.connect(self.unlock_name_list)
        self.ui.load_config_pushbutton.clicked.connect(self.load_config)

    ### 添加历史操作记录
    def add_history_text(self, message):
        self.ui.operation_history_textEdit.append(message)

    ### 修改主题
    def change_theme(self, index):
        if index == 0:
            self.setStyleSheet("")  # 清除样式，恢复默认
            self.add_history_text("主题切换为: default")
            return
        style_fil_path = f'./config/{self.ui.theme_comboBox.currentText()}.qss'
        print(index)
        qssStyle = CommonHelper.readQss(style_fil_path)
        if qssStyle:
            self.setStyleSheet(qssStyle)
            self.add_history_text(f"主题切换为: {self.ui.theme_comboBox.currentText()}")
        else:
            self.add_history_text("主题文件读取失败")
        print(f"Selected item: {self.ui.theme_comboBox.currentText()}")

    def load_config(self):
        try:
            with open('./config/color.txt', 'r') as file:
                # 读取文件的每一行，并存储在一个列表中
                self.color_list = file.readlines()
            self.color_list = [name.strip() for name in self.color_list]
            self.add_history_text('读取配置信息成功')
        except FileNotFoundError:
            self.add_history_text('文件 color.txt 不存在，已创建新文件')
            # 创建新文件
            with open('./config/color.txt', 'w') as file:
                pass
        print(self.color_list)

    def take_screenshot(self, button_text):
        # 获取当前时间
        now = datetime.now()
        # 格式化时间字符串为文件名
        file_name = f"{button_text}_{now.strftime('%Y-%m-%d_%H-%M-%S')}.png"

        # 指定保存路径
        save_path = os.path.join("screenshots", file_name)

        # 截取窗口
        screenshot = QApplication.primaryScreen().grabWindow(self.winId())

        # 保存截图
        try:
            screenshot.save(save_path)
            print(f"截图保存为 {save_path}")
        except Exception as e:
            print(f"保存截图时出错: {e}")

    def create_folder(self):
        # 获取当前时间
        now = datetime.now()
        # 格式化时间字符串为文件夹名
        folder_name = now.strftime("%Y-%m-%d_%H-%M-%S")

        # 指定文件夹路径
        self.save_photo_path = os.path.join("res", folder_name)

        # 创建文件夹
        try:
            os.makedirs(self.save_photo_path, exist_ok=True)
            self.add_history_text(f"\n文件夹 {folder_name} 创建成功！")
        except Exception as e:
            self.add_history_text(f"创建文件夹时出错: {e}")

    ### 确认参与者名单，并将其锁定
    def sure_name_list(self):
        if self.ui.name_textEdit.toPlainText() == '':
            # 弹出一个消息框来提醒用户
            self.add_history_text('游戏玩家为空')
            return
        if not self.color_list:
            self.add_history_text('未读取配置信息')
            return
        self.create_folder()
        self.ui.name_textEdit.setReadOnly(True)
        text = self.ui.name_textEdit.toPlainText()

        self.player_list = text.split('\n')
        self.player_list = [item for item in self.player_list if item]
        print(self.player_list)
        self.player_now_state = []  # 清空
        item_list = list(range(self.ui.game_player_horizontalLayout.count()))
        item_list.reverse()  # 倒序删除，避免影响布局顺序

        for i in item_list:
            item = self.ui.game_player_horizontalLayout.itemAt(i)
            self.ui.game_player_horizontalLayout.removeItem(item)
            if item.widget():
                item.widget().deleteLater()

        for i, player in enumerate(self.player_list):
            # 创建一个按钮
            button = QtWidgets.QPushButton(player)
            # 将颜色设置为按钮的文字颜色
            button.setStyleSheet(f"color: {self.color_list[i]}; font-size: 15pt;font-weight: bold")
            # 将按钮添加到 QHBoxLayout 中
            self.ui.game_player_horizontalLayout.addWidget(button)
            # 将按钮添加到 player_now_state 列表中
            self.player_now_state.append(button)
        for button in self.player_now_state:
            # 将按钮添加到 QHBoxLayout 中
            self.ui.game_player_horizontalLayout.addWidget(button)

        self.ui.load_name_pushbutton.setStyleSheet("color: gray")
        self.ui.load_name_pushbutton.setEnabled(False)  # 禁用加载按钮，防止未知bug
        self.ui.load_config_pushbutton.setStyleSheet("color: gray")
        self.ui.load_config_pushbutton.setEnabled(False)  # 禁用按钮，防止未知bug
        self.ui.sure_name_pushbutton.setStyleSheet("color: gray")
        self.ui.sure_name_pushbutton.setEnabled(False)  # 禁用确认按钮，防止未知bug

    ### 解除参与者名单锁定
    def unlock_name_list(self):
        self.ui.name_textEdit.setReadOnly(False)
        self.ui.sure_name_pushbutton.setStyleSheet("color: black")
        self.ui.sure_name_pushbutton.setEnabled(True)
        self.ui.load_name_pushbutton.setStyleSheet("color: black")
        self.ui.load_name_pushbutton.setEnabled(True)
        self.ui.load_config_pushbutton.setStyleSheet("color: black")
        self.ui.load_config_pushbutton.setEnabled(True)

    ### 读取参与者名单
    def load_name_list(self):
        try:
            with open('./config/name.txt', 'r') as file:
                # 读取文件的每一行，并存储在一个列表中
                namelist = file.readlines()
            namelist = [name.strip() for name in namelist]
            print(namelist)
            # 将列表转换为字符串
            text = '\n'.join(namelist)
            # 将文本设置到 QTextEdit 中
            self.ui.name_textEdit.setText(text)
            self.add_history_text('读取参与者名单成功')
        except FileNotFoundError:
            self.add_history_text('文件 name.txt 不存在，已创建新文件')
            # 创建新文件
            with open('./config/name.txt', 'w') as file:
                pass


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    Form = MyUI()
    Form.show()
    sys.exit(app.exec_())
