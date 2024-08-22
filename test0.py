# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'test0.ui'
#
# Created by: PyQt5 UI code generator 5.15.9
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_Form(object):
    def setupUi(self, Form):
        Form.setObjectName("Form")
        Form.resize(893, 685)
        self.verticalLayoutWidget = QtWidgets.QWidget(Form)
        self.verticalLayoutWidget.setGeometry(QtCore.QRect(10, 20, 221, 571))
        self.verticalLayoutWidget.setObjectName("verticalLayoutWidget")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout.setObjectName("verticalLayout")
        self.lineEdit = QtWidgets.QLineEdit(self.verticalLayoutWidget)
        self.lineEdit.setMouseTracking(False)
        self.lineEdit.setFocusPolicy(QtCore.Qt.NoFocus)
        self.lineEdit.setContextMenuPolicy(QtCore.Qt.NoContextMenu)
        self.lineEdit.setAlignment(QtCore.Qt.AlignCenter)
        self.lineEdit.setObjectName("lineEdit")
        self.verticalLayout.addWidget(self.lineEdit)
        self.name_textEdit = QtWidgets.QTextEdit(self.verticalLayoutWidget)
        self.name_textEdit.setObjectName("name_textEdit")
        self.verticalLayout.addWidget(self.name_textEdit)
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.sure_name_pushbutton = QtWidgets.QPushButton(self.verticalLayoutWidget)
        self.sure_name_pushbutton.setObjectName("sure_name_pushbutton")
        self.horizontalLayout.addWidget(self.sure_name_pushbutton)
        self.load_name_pushbutton = QtWidgets.QPushButton(self.verticalLayoutWidget)
        self.load_name_pushbutton.setObjectName("load_name_pushbutton")
        self.horizontalLayout.addWidget(self.load_name_pushbutton)
        self.verticalLayout.addLayout(self.horizontalLayout)
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.unlock_pushbutton = QtWidgets.QPushButton(self.verticalLayoutWidget)
        self.unlock_pushbutton.setObjectName("unlock_pushbutton")
        self.horizontalLayout_3.addWidget(self.unlock_pushbutton)
        self.load_config_pushbutton = QtWidgets.QPushButton(self.verticalLayoutWidget)
        self.load_config_pushbutton.setObjectName("load_config_pushbutton")
        self.horizontalLayout_3.addWidget(self.load_config_pushbutton)
        self.verticalLayout.addLayout(self.horizontalLayout_3)
        self.horizontalLayoutWidget = QtWidgets.QWidget(Form)
        self.horizontalLayoutWidget.setGeometry(QtCore.QRect(240, 20, 595, 80))
        self.horizontalLayoutWidget.setObjectName("horizontalLayoutWidget")
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout(self.horizontalLayoutWidget)
        self.horizontalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.pushButton_6 = QtWidgets.QPushButton(self.horizontalLayoutWidget)
        self.pushButton_6.setObjectName("pushButton_6")
        self.horizontalLayout_2.addWidget(self.pushButton_6)
        self.pushButton = QtWidgets.QPushButton(self.horizontalLayoutWidget)
        self.pushButton.setObjectName("pushButton")
        self.horizontalLayout_2.addWidget(self.pushButton)
        self.pushButton_2 = QtWidgets.QPushButton(self.horizontalLayoutWidget)
        self.pushButton_2.setObjectName("pushButton_2")
        self.horizontalLayout_2.addWidget(self.pushButton_2)
        self.pushButton_3 = QtWidgets.QPushButton(self.horizontalLayoutWidget)
        self.pushButton_3.setObjectName("pushButton_3")
        self.horizontalLayout_2.addWidget(self.pushButton_3)
        self.pushButton_4 = QtWidgets.QPushButton(self.horizontalLayoutWidget)
        self.pushButton_4.setObjectName("pushButton_4")
        self.horizontalLayout_2.addWidget(self.pushButton_4)
        self.pushButton_5 = QtWidgets.QPushButton(self.horizontalLayoutWidget)
        self.pushButton_5.setObjectName("pushButton_5")
        self.horizontalLayout_2.addWidget(self.pushButton_5)
        self.horizontalLayoutWidget_2 = QtWidgets.QWidget(Form)
        self.horizontalLayoutWidget_2.setGeometry(QtCore.QRect(240, 590, 601, 80))
        self.horizontalLayoutWidget_2.setObjectName("horizontalLayoutWidget_2")
        self.game_player_horizontalLayout = QtWidgets.QHBoxLayout(self.horizontalLayoutWidget_2)
        self.game_player_horizontalLayout.setContentsMargins(0, 0, 0, 0)
        self.game_player_horizontalLayout.setObjectName("game_player_horizontalLayout")

        self.retranslateUi(Form)
        QtCore.QMetaObject.connectSlotsByName(Form)

    def retranslateUi(self, Form):
        _translate = QtCore.QCoreApplication.translate
        Form.setWindowTitle(_translate("Form", "Form"))
        self.lineEdit.setText(_translate("Form", "参与者名单"))
        self.sure_name_pushbutton.setText(_translate("Form", "确定"))
        self.load_name_pushbutton.setText(_translate("Form", "读取名字文件"))
        self.unlock_pushbutton.setText(_translate("Form", "解除锁定"))
        self.load_config_pushbutton.setText(_translate("Form", "读取配置文件"))
        self.pushButton_6.setText(_translate("Form", "保存图片"))
        self.pushButton.setText(_translate("Form", "旋转魔方"))
        self.pushButton_2.setText(_translate("Form", "交换"))
        self.pushButton_3.setText(_translate("Form", "通路"))
        self.pushButton_4.setText(_translate("Form", "改建"))
        self.pushButton_5.setText(_translate("Form", "完成"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    Form = QtWidgets.QWidget()
    ui = Ui_Form()
    ui.setupUi(Form)
    Form.show()
    sys.exit(app.exec_())
