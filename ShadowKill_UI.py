# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'ShadowKill_UI.ui'
#
# Created by: PyQt5 UI code generator 5.15.9
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_shadowkill(object):
    def setupUi(self, shadowkill):
        shadowkill.setObjectName("shadowkill")
        shadowkill.resize(1101, 808)
        self.horizontalLayoutWidget_2 = QtWidgets.QWidget(shadowkill)
        self.horizontalLayoutWidget_2.setGeometry(QtCore.QRect(300, 680, 781, 80))
        self.horizontalLayoutWidget_2.setObjectName("horizontalLayoutWidget_2")
        self.game_player_horizontalLayout = QtWidgets.QHBoxLayout(self.horizontalLayoutWidget_2)
        self.game_player_horizontalLayout.setContentsMargins(0, 0, 0, 0)
        self.game_player_horizontalLayout.setObjectName("game_player_horizontalLayout")
        self.horizontalLayoutWidget = QtWidgets.QWidget(shadowkill)
        self.horizontalLayoutWidget.setGeometry(QtCore.QRect(10, 20, 271, 741))
        self.horizontalLayoutWidget.setObjectName("horizontalLayoutWidget")
        self.horizontalLayout = QtWidgets.QHBoxLayout(self.horizontalLayoutWidget)
        self.horizontalLayout.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.lineEdit_3 = QtWidgets.QLineEdit(self.horizontalLayoutWidget)
        self.lineEdit_3.setMouseTracking(False)
        self.lineEdit_3.setFocusPolicy(QtCore.Qt.NoFocus)
        self.lineEdit_3.setAlignment(QtCore.Qt.AlignCenter)
        self.lineEdit_3.setObjectName("lineEdit_3")
        self.verticalLayout.addWidget(self.lineEdit_3)
        self.unlock_pushbutton = QtWidgets.QPushButton(self.horizontalLayoutWidget)
        self.unlock_pushbutton.setObjectName("unlock_pushbutton")
        self.verticalLayout.addWidget(self.unlock_pushbutton)
        self.sure_name_pushbutton = QtWidgets.QPushButton(self.horizontalLayoutWidget)
        self.sure_name_pushbutton.setObjectName("sure_name_pushbutton")
        self.verticalLayout.addWidget(self.sure_name_pushbutton)
        self.lineEdit = QtWidgets.QLineEdit(self.horizontalLayoutWidget)
        self.lineEdit.setMouseTracking(False)
        self.lineEdit.setFocusPolicy(QtCore.Qt.NoFocus)
        self.lineEdit.setContextMenuPolicy(QtCore.Qt.NoContextMenu)
        self.lineEdit.setAlignment(QtCore.Qt.AlignCenter)
        self.lineEdit.setObjectName("lineEdit")
        self.verticalLayout.addWidget(self.lineEdit)
        self.name_textEdit = QtWidgets.QTextEdit(self.horizontalLayoutWidget)
        self.name_textEdit.setObjectName("name_textEdit")
        self.verticalLayout.addWidget(self.name_textEdit)
        self.horizontalLayout.addLayout(self.verticalLayout)
        self.verticalLayout_2 = QtWidgets.QVBoxLayout()
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.theme_comboBox = QtWidgets.QComboBox(self.horizontalLayoutWidget)
        self.theme_comboBox.setObjectName("theme_comboBox")
        self.verticalLayout_2.addWidget(self.theme_comboBox)
        self.load_config_pushbutton = QtWidgets.QPushButton(self.horizontalLayoutWidget)
        self.load_config_pushbutton.setObjectName("load_config_pushbutton")
        self.verticalLayout_2.addWidget(self.load_config_pushbutton)
        self.load_name_pushbutton = QtWidgets.QPushButton(self.horizontalLayoutWidget)
        self.load_name_pushbutton.setObjectName("load_name_pushbutton")
        self.verticalLayout_2.addWidget(self.load_name_pushbutton)
        self.lineEdit_2 = QtWidgets.QLineEdit(self.horizontalLayoutWidget)
        self.lineEdit_2.setMouseTracking(False)
        self.lineEdit_2.setFocusPolicy(QtCore.Qt.NoFocus)
        self.lineEdit_2.setAlignment(QtCore.Qt.AlignCenter)
        self.lineEdit_2.setObjectName("lineEdit_2")
        self.verticalLayout_2.addWidget(self.lineEdit_2)
        self.operation_history_textEdit = QtWidgets.QTextEdit(self.horizontalLayoutWidget)
        self.operation_history_textEdit.setMouseTracking(False)
        self.operation_history_textEdit.setFocusPolicy(QtCore.Qt.NoFocus)
        self.operation_history_textEdit.setObjectName("operation_history_textEdit")
        self.verticalLayout_2.addWidget(self.operation_history_textEdit)
        self.horizontalLayout.addLayout(self.verticalLayout_2)
        self.gridLayoutWidget = QtWidgets.QWidget(shadowkill)
        self.gridLayoutWidget.setGeometry(QtCore.QRect(330, 40, 151, 141))
        self.gridLayoutWidget.setObjectName("gridLayoutWidget")
        self.gridLayout = QtWidgets.QGridLayout(self.gridLayoutWidget)
        self.gridLayout.setContentsMargins(0, 0, 0, 0)
        self.gridLayout.setObjectName("gridLayout")
        self.textEdit_3 = QtWidgets.QTextEdit(self.gridLayoutWidget)
        self.textEdit_3.setObjectName("textEdit_3")
        self.gridLayout.addWidget(self.textEdit_3, 0, 2, 1, 1)
        self.textEdit_4 = QtWidgets.QTextEdit(self.gridLayoutWidget)
        self.textEdit_4.setObjectName("textEdit_4")
        self.gridLayout.addWidget(self.textEdit_4, 1, 0, 1, 1)
        self.textEdit_2 = QtWidgets.QTextEdit(self.gridLayoutWidget)
        self.textEdit_2.setObjectName("textEdit_2")
        self.gridLayout.addWidget(self.textEdit_2, 0, 1, 1, 1)
        self.textEdit_7 = QtWidgets.QTextEdit(self.gridLayoutWidget)
        self.textEdit_7.setObjectName("textEdit_7")
        self.gridLayout.addWidget(self.textEdit_7, 2, 0, 1, 1)
        self.textEdit_8 = QtWidgets.QTextEdit(self.gridLayoutWidget)
        self.textEdit_8.setObjectName("textEdit_8")
        self.gridLayout.addWidget(self.textEdit_8, 2, 1, 1, 1)
        self.textEdit_5 = QtWidgets.QTextEdit(self.gridLayoutWidget)
        self.textEdit_5.setObjectName("textEdit_5")
        self.gridLayout.addWidget(self.textEdit_5, 1, 1, 1, 1)
        self.textEdit_6 = QtWidgets.QTextEdit(self.gridLayoutWidget)
        self.textEdit_6.setObjectName("textEdit_6")
        self.gridLayout.addWidget(self.textEdit_6, 1, 2, 1, 1)
        self.textEdit = QtWidgets.QTextEdit(self.gridLayoutWidget)
        self.textEdit.setObjectName("textEdit")
        self.gridLayout.addWidget(self.textEdit, 0, 0, 1, 1)
        self.textEdit_9 = QtWidgets.QTextEdit(self.gridLayoutWidget)
        self.textEdit_9.setObjectName("textEdit_9")
        self.gridLayout.addWidget(self.textEdit_9, 2, 2, 1, 1)
        self.gridLayoutWidget_2 = QtWidgets.QWidget(shadowkill)
        self.gridLayoutWidget_2.setGeometry(QtCore.QRect(550, 40, 181, 181))
        self.gridLayoutWidget_2.setObjectName("gridLayoutWidget_2")
        self.gridLayout_2 = QtWidgets.QGridLayout(self.gridLayoutWidget_2)
        self.gridLayout_2.setContentsMargins(0, 0, 0, 0)
        self.gridLayout_2.setObjectName("gridLayout_2")
        self.textEdit_10 = QtWidgets.QTextEdit(self.gridLayoutWidget_2)
        self.textEdit_10.setObjectName("textEdit_10")
        self.gridLayout_2.addWidget(self.textEdit_10, 0, 2, 1, 1)
        self.textEdit_11 = QtWidgets.QTextEdit(self.gridLayoutWidget_2)
        self.textEdit_11.setObjectName("textEdit_11")
        self.gridLayout_2.addWidget(self.textEdit_11, 1, 0, 1, 1)
        self.textEdit_12 = QtWidgets.QTextEdit(self.gridLayoutWidget_2)
        self.textEdit_12.setObjectName("textEdit_12")
        self.gridLayout_2.addWidget(self.textEdit_12, 0, 1, 1, 1)
        self.textEdit_13 = QtWidgets.QTextEdit(self.gridLayoutWidget_2)
        self.textEdit_13.setObjectName("textEdit_13")
        self.gridLayout_2.addWidget(self.textEdit_13, 1, 1, 1, 1)
        self.textEdit_14 = QtWidgets.QTextEdit(self.gridLayoutWidget_2)
        self.textEdit_14.setObjectName("textEdit_14")
        self.gridLayout_2.addWidget(self.textEdit_14, 1, 2, 1, 1)
        self.textEdit_15 = QtWidgets.QTextEdit(self.gridLayoutWidget_2)
        self.textEdit_15.setObjectName("textEdit_15")
        self.gridLayout_2.addWidget(self.textEdit_15, 0, 0, 1, 1)
        self.textEdit_16 = QtWidgets.QTextEdit(self.gridLayoutWidget_2)
        self.textEdit_16.setObjectName("textEdit_16")
        self.gridLayout_2.addWidget(self.textEdit_16, 2, 0, 1, 1)
        self.textEdit_17 = QtWidgets.QTextEdit(self.gridLayoutWidget_2)
        self.textEdit_17.setObjectName("textEdit_17")
        self.gridLayout_2.addWidget(self.textEdit_17, 2, 1, 1, 1)
        self.textEdit_18 = QtWidgets.QTextEdit(self.gridLayoutWidget_2)
        self.textEdit_18.setObjectName("textEdit_18")
        self.gridLayout_2.addWidget(self.textEdit_18, 2, 2, 1, 1)
        self.gridLayoutWidget_3 = QtWidgets.QWidget(shadowkill)
        self.gridLayoutWidget_3.setGeometry(QtCore.QRect(770, 40, 201, 181))
        self.gridLayoutWidget_3.setObjectName("gridLayoutWidget_3")
        self.gridLayout_3 = QtWidgets.QGridLayout(self.gridLayoutWidget_3)
        self.gridLayout_3.setContentsMargins(0, 0, 0, 0)
        self.gridLayout_3.setObjectName("gridLayout_3")
        self.textEdit_19 = QtWidgets.QTextEdit(self.gridLayoutWidget_3)
        self.textEdit_19.setObjectName("textEdit_19")
        self.gridLayout_3.addWidget(self.textEdit_19, 0, 2, 1, 1)
        self.textEdit_20 = QtWidgets.QTextEdit(self.gridLayoutWidget_3)
        self.textEdit_20.setObjectName("textEdit_20")
        self.gridLayout_3.addWidget(self.textEdit_20, 1, 0, 1, 1)
        self.textEdit_21 = QtWidgets.QTextEdit(self.gridLayoutWidget_3)
        self.textEdit_21.setObjectName("textEdit_21")
        self.gridLayout_3.addWidget(self.textEdit_21, 0, 1, 1, 1)
        self.textEdit_22 = QtWidgets.QTextEdit(self.gridLayoutWidget_3)
        self.textEdit_22.setObjectName("textEdit_22")
        self.gridLayout_3.addWidget(self.textEdit_22, 1, 1, 1, 1)
        self.textEdit_23 = QtWidgets.QTextEdit(self.gridLayoutWidget_3)
        self.textEdit_23.setObjectName("textEdit_23")
        self.gridLayout_3.addWidget(self.textEdit_23, 1, 2, 1, 1)
        self.textEdit_24 = QtWidgets.QTextEdit(self.gridLayoutWidget_3)
        self.textEdit_24.setObjectName("textEdit_24")
        self.gridLayout_3.addWidget(self.textEdit_24, 0, 0, 1, 1)
        self.textEdit_25 = QtWidgets.QTextEdit(self.gridLayoutWidget_3)
        self.textEdit_25.setObjectName("textEdit_25")
        self.gridLayout_3.addWidget(self.textEdit_25, 2, 0, 1, 1)
        self.textEdit_26 = QtWidgets.QTextEdit(self.gridLayoutWidget_3)
        self.textEdit_26.setObjectName("textEdit_26")
        self.gridLayout_3.addWidget(self.textEdit_26, 2, 1, 1, 1)
        self.textEdit_27 = QtWidgets.QTextEdit(self.gridLayoutWidget_3)
        self.textEdit_27.setObjectName("textEdit_27")
        self.gridLayout_3.addWidget(self.textEdit_27, 2, 2, 1, 1)
        self.gridLayoutWidget_4 = QtWidgets.QWidget(shadowkill)
        self.gridLayoutWidget_4.setGeometry(QtCore.QRect(310, 350, 181, 171))
        self.gridLayoutWidget_4.setObjectName("gridLayoutWidget_4")
        self.gridLayout_4 = QtWidgets.QGridLayout(self.gridLayoutWidget_4)
        self.gridLayout_4.setContentsMargins(0, 0, 0, 0)
        self.gridLayout_4.setObjectName("gridLayout_4")
        self.textEdit_28 = QtWidgets.QTextEdit(self.gridLayoutWidget_4)
        self.textEdit_28.setObjectName("textEdit_28")
        self.gridLayout_4.addWidget(self.textEdit_28, 0, 2, 1, 1)
        self.textEdit_29 = QtWidgets.QTextEdit(self.gridLayoutWidget_4)
        self.textEdit_29.setObjectName("textEdit_29")
        self.gridLayout_4.addWidget(self.textEdit_29, 1, 0, 1, 1)
        self.textEdit_30 = QtWidgets.QTextEdit(self.gridLayoutWidget_4)
        self.textEdit_30.setObjectName("textEdit_30")
        self.gridLayout_4.addWidget(self.textEdit_30, 0, 1, 1, 1)
        self.textEdit_31 = QtWidgets.QTextEdit(self.gridLayoutWidget_4)
        self.textEdit_31.setObjectName("textEdit_31")
        self.gridLayout_4.addWidget(self.textEdit_31, 1, 1, 1, 1)
        self.textEdit_32 = QtWidgets.QTextEdit(self.gridLayoutWidget_4)
        self.textEdit_32.setObjectName("textEdit_32")
        self.gridLayout_4.addWidget(self.textEdit_32, 1, 2, 1, 1)
        self.textEdit_33 = QtWidgets.QTextEdit(self.gridLayoutWidget_4)
        self.textEdit_33.setObjectName("textEdit_33")
        self.gridLayout_4.addWidget(self.textEdit_33, 0, 0, 1, 1)
        self.textEdit_34 = QtWidgets.QTextEdit(self.gridLayoutWidget_4)
        self.textEdit_34.setObjectName("textEdit_34")
        self.gridLayout_4.addWidget(self.textEdit_34, 2, 0, 1, 1)
        self.textEdit_35 = QtWidgets.QTextEdit(self.gridLayoutWidget_4)
        self.textEdit_35.setObjectName("textEdit_35")
        self.gridLayout_4.addWidget(self.textEdit_35, 2, 1, 1, 1)
        self.textEdit_36 = QtWidgets.QTextEdit(self.gridLayoutWidget_4)
        self.textEdit_36.setObjectName("textEdit_36")
        self.gridLayout_4.addWidget(self.textEdit_36, 2, 2, 1, 1)
        self.gridLayoutWidget_5 = QtWidgets.QWidget(shadowkill)
        self.gridLayoutWidget_5.setGeometry(QtCore.QRect(600, 360, 171, 171))
        self.gridLayoutWidget_5.setObjectName("gridLayoutWidget_5")
        self.gridLayout_5 = QtWidgets.QGridLayout(self.gridLayoutWidget_5)
        self.gridLayout_5.setContentsMargins(0, 0, 0, 0)
        self.gridLayout_5.setObjectName("gridLayout_5")
        self.textEdit_42 = QtWidgets.QTextEdit(self.gridLayoutWidget_5)
        self.textEdit_42.setObjectName("textEdit_42")
        self.gridLayout_5.addWidget(self.textEdit_42, 0, 0, 1, 1)
        self.textEdit_45 = QtWidgets.QTextEdit(self.gridLayoutWidget_5)
        self.textEdit_45.setObjectName("textEdit_45")
        self.gridLayout_5.addWidget(self.textEdit_45, 2, 2, 1, 1)
        self.textEdit_40 = QtWidgets.QTextEdit(self.gridLayoutWidget_5)
        self.textEdit_40.setObjectName("textEdit_40")
        self.gridLayout_5.addWidget(self.textEdit_40, 1, 1, 1, 1)
        self.textEdit_44 = QtWidgets.QTextEdit(self.gridLayoutWidget_5)
        self.textEdit_44.setObjectName("textEdit_44")
        self.gridLayout_5.addWidget(self.textEdit_44, 2, 1, 1, 1)
        self.textEdit_38 = QtWidgets.QTextEdit(self.gridLayoutWidget_5)
        self.textEdit_38.setObjectName("textEdit_38")
        self.gridLayout_5.addWidget(self.textEdit_38, 1, 0, 1, 1)
        self.textEdit_43 = QtWidgets.QTextEdit(self.gridLayoutWidget_5)
        self.textEdit_43.setObjectName("textEdit_43")
        self.gridLayout_5.addWidget(self.textEdit_43, 2, 0, 1, 1)
        self.textEdit_37 = QtWidgets.QTextEdit(self.gridLayoutWidget_5)
        self.textEdit_37.setObjectName("textEdit_37")
        self.gridLayout_5.addWidget(self.textEdit_37, 0, 2, 1, 1)
        self.textEdit_41 = QtWidgets.QTextEdit(self.gridLayoutWidget_5)
        self.textEdit_41.setObjectName("textEdit_41")
        self.gridLayout_5.addWidget(self.textEdit_41, 1, 2, 1, 1)
        self.textEdit_39 = QtWidgets.QTextEdit(self.gridLayoutWidget_5)
        self.textEdit_39.setObjectName("textEdit_39")
        self.gridLayout_5.addWidget(self.textEdit_39, 0, 1, 1, 1)
        self.gridLayoutWidget_6 = QtWidgets.QWidget(shadowkill)
        self.gridLayoutWidget_6.setGeometry(QtCore.QRect(920, 370, 161, 161))
        self.gridLayoutWidget_6.setObjectName("gridLayoutWidget_6")
        self.gridLayout_6 = QtWidgets.QGridLayout(self.gridLayoutWidget_6)
        self.gridLayout_6.setContentsMargins(0, 0, 0, 0)
        self.gridLayout_6.setObjectName("gridLayout_6")
        self.textEdit_46 = QtWidgets.QTextEdit(self.gridLayoutWidget_6)
        self.textEdit_46.setObjectName("textEdit_46")
        self.gridLayout_6.addWidget(self.textEdit_46, 0, 2, 1, 1)
        self.textEdit_47 = QtWidgets.QTextEdit(self.gridLayoutWidget_6)
        self.textEdit_47.setObjectName("textEdit_47")
        self.gridLayout_6.addWidget(self.textEdit_47, 1, 0, 1, 1)
        self.textEdit_48 = QtWidgets.QTextEdit(self.gridLayoutWidget_6)
        self.textEdit_48.setObjectName("textEdit_48")
        self.gridLayout_6.addWidget(self.textEdit_48, 0, 1, 1, 1)
        self.textEdit_49 = QtWidgets.QTextEdit(self.gridLayoutWidget_6)
        self.textEdit_49.setObjectName("textEdit_49")
        self.gridLayout_6.addWidget(self.textEdit_49, 1, 1, 1, 1)
        self.textEdit_50 = QtWidgets.QTextEdit(self.gridLayoutWidget_6)
        self.textEdit_50.setObjectName("textEdit_50")
        self.gridLayout_6.addWidget(self.textEdit_50, 1, 2, 1, 1)
        self.textEdit_51 = QtWidgets.QTextEdit(self.gridLayoutWidget_6)
        self.textEdit_51.setObjectName("textEdit_51")
        self.gridLayout_6.addWidget(self.textEdit_51, 0, 0, 1, 1)
        self.textEdit_52 = QtWidgets.QTextEdit(self.gridLayoutWidget_6)
        self.textEdit_52.setObjectName("textEdit_52")
        self.gridLayout_6.addWidget(self.textEdit_52, 2, 0, 1, 1)
        self.textEdit_53 = QtWidgets.QTextEdit(self.gridLayoutWidget_6)
        self.textEdit_53.setObjectName("textEdit_53")
        self.gridLayout_6.addWidget(self.textEdit_53, 2, 1, 1, 1)
        self.textEdit_54 = QtWidgets.QTextEdit(self.gridLayoutWidget_6)
        self.textEdit_54.setObjectName("textEdit_54")
        self.gridLayout_6.addWidget(self.textEdit_54, 2, 2, 1, 1)

        self.retranslateUi(shadowkill)
        QtCore.QMetaObject.connectSlotsByName(shadowkill)

    def retranslateUi(self, shadowkill):
        _translate = QtCore.QCoreApplication.translate
        shadowkill.setWindowTitle(_translate("shadowkill", "Form"))
        self.lineEdit_3.setText(_translate("shadowkill", "主题选择"))
        self.unlock_pushbutton.setText(_translate("shadowkill", "解除锁定"))
        self.sure_name_pushbutton.setText(_translate("shadowkill", "确定"))
        self.lineEdit.setText(_translate("shadowkill", "参与者名单"))
        self.load_config_pushbutton.setText(_translate("shadowkill", "读取配置文件"))
        self.load_name_pushbutton.setText(_translate("shadowkill", "读取名字文件"))
        self.lineEdit_2.setText(_translate("shadowkill", "操作历史"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    shadowkill = QtWidgets.QWidget()
    ui = Ui_shadowkill()
    ui.setupUi(shadowkill)
    shadowkill.show()
    sys.exit(app.exec_())
