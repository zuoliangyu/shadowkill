from datetime import datetime
import os
import sys

from PyQt5 import QtWidgets
from PyQt5.QtWidgets import QMessageBox, QApplication

import test0


### 用于读取QSS
class CommonHelper:
    def __init__(self):
        pass

    @staticmethod
    def readQss(style):
        with open(style, 'r', encoding='utf-8') as f:
            return f.read()


### 页面设置
class MyUI(QtWidgets.QWidget):
    def __init__(self):
        self.save_photo_path = ''  # 游戏截图保存目录
        self.color_list = []  # 每个人的颜色
        self.player_list = []  # 开始的参与者名单
        self.player_now_state = []  # 当前参与者
        super().__init__()
        # 创建一个 test0.Ui_Form 的实例
        self.ui = test0.Ui_Form()
        self.ui.setupUi(self)

        self.ui.load_name_pushbutton.clicked.connect(self.load_name_list)
        self.ui.sure_name_pushbutton.clicked.connect(self.sure_name_list)
        self.ui.unlock_pushbutton.clicked.connect(self.unlock_name_list)
        self.ui.load_config_pushbutton.clicked.connect(self.load_config)


    def load_config(self):
        try:
            with open('color.txt', 'r') as file:
                # 读取文件的每一行，并存储在一个列表中
                self.color_list = file.readlines()
            self.color_list = [name.strip() for name in self.color_list]
        except FileNotFoundError:
            # 弹出一个消息框来提醒用户
            QtWidgets.QMessageBox.warning(self, '文件不存在', '文件 color.txt 不存在，已创建新文件。')
            # 创建新文件
            with open('color.txt', 'w') as file:
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
            QMessageBox.information(self, "成功", f"文件夹 {folder_name} 创建成功！")
        except Exception as e:
            QMessageBox.critical(self, "错误", f"创建文件夹时出错: {e}")

    ### 确认参与者名单，并将其锁定
    def sure_name_list(self):
        if self.ui.name_textEdit.toPlainText() == '':
            # 弹出一个消息框来提醒用户
            QtWidgets.QMessageBox.warning(self, '警告', '游戏玩家为空')
            return
        if not self.color_list:
            QtWidgets.QMessageBox.warning(self, '警告', '未读取配置信息')
            return
        self.create_folder()
        self.ui.name_textEdit.setReadOnly(True)
        text = self.ui.name_textEdit.toPlainText()
        self.player_list = text.split('\n')
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
            with open('name.txt', 'r') as file:
                # 读取文件的每一行，并存储在一个列表中
                namelist = file.readlines()
            namelist = [name.strip() for name in namelist]
            print(namelist)
            # 将列表转换为字符串
            text = '\n'.join(namelist)
            # 将文本设置到 QTextEdit 中
            self.ui.name_textEdit.setText(text)
        except FileNotFoundError:
            # 弹出一个消息框来提醒用户
            QtWidgets.QMessageBox.warning(self, '文件不存在', '文件 name.txt 不存在，已创建新文件。')
            # 创建新文件
            with open('name.txt', 'w') as file:
                pass


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    styleFile = './style.qss'
    qssStyle = CommonHelper.readQss(styleFile)
    Form = MyUI()
    Form.setStyleSheet(qssStyle)
    Form.show()

    sys.exit(app.exec_())
