# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'cfg_gui.ui'
##
## Created by: Qt User Interface Compiler version 6.7.0
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QApplication, QComboBox, QFrame, QGridLayout,
    QGroupBox, QHBoxLayout, QLabel, QLayout,
    QLineEdit, QPushButton, QScrollArea, QSizePolicy,
    QSpinBox, QTabWidget, QTextEdit, QVBoxLayout,
    QWidget)

class Ui_Form(object):
    def setupUi(self, Form):
        if not Form.objectName():
            Form.setObjectName(u"Form")
        Form.resize(658, 655)
        palette = QPalette()
        brush = QBrush(QColor(0, 0, 0, 255))
        brush.setStyle(Qt.SolidPattern)
        palette.setBrush(QPalette.Active, QPalette.WindowText, brush)
        brush1 = QBrush(QColor(255, 255, 255, 255))
        brush1.setStyle(Qt.SolidPattern)
        palette.setBrush(QPalette.Active, QPalette.Button, brush1)
        palette.setBrush(QPalette.Active, QPalette.Light, brush1)
        palette.setBrush(QPalette.Active, QPalette.Midlight, brush1)
        brush2 = QBrush(QColor(127, 127, 127, 255))
        brush2.setStyle(Qt.SolidPattern)
        palette.setBrush(QPalette.Active, QPalette.Dark, brush2)
        brush3 = QBrush(QColor(170, 170, 170, 255))
        brush3.setStyle(Qt.SolidPattern)
        palette.setBrush(QPalette.Active, QPalette.Mid, brush3)
        palette.setBrush(QPalette.Active, QPalette.Text, brush)
        palette.setBrush(QPalette.Active, QPalette.BrightText, brush1)
        palette.setBrush(QPalette.Active, QPalette.ButtonText, brush)
        palette.setBrush(QPalette.Active, QPalette.Base, brush1)
        palette.setBrush(QPalette.Active, QPalette.Window, brush1)
        palette.setBrush(QPalette.Active, QPalette.Shadow, brush)
        palette.setBrush(QPalette.Active, QPalette.AlternateBase, brush1)
        brush4 = QBrush(QColor(255, 255, 220, 255))
        brush4.setStyle(Qt.SolidPattern)
        palette.setBrush(QPalette.Active, QPalette.ToolTipBase, brush4)
        palette.setBrush(QPalette.Active, QPalette.ToolTipText, brush)
        brush5 = QBrush(QColor(0, 0, 0, 127))
        brush5.setStyle(Qt.SolidPattern)
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette.Active, QPalette.PlaceholderText, brush5)
#endif
        palette.setBrush(QPalette.Active, QPalette.Accent, brush1)
        palette.setBrush(QPalette.Inactive, QPalette.WindowText, brush)
        palette.setBrush(QPalette.Inactive, QPalette.Button, brush1)
        palette.setBrush(QPalette.Inactive, QPalette.Light, brush1)
        palette.setBrush(QPalette.Inactive, QPalette.Midlight, brush1)
        palette.setBrush(QPalette.Inactive, QPalette.Dark, brush2)
        palette.setBrush(QPalette.Inactive, QPalette.Mid, brush3)
        palette.setBrush(QPalette.Inactive, QPalette.Text, brush)
        palette.setBrush(QPalette.Inactive, QPalette.BrightText, brush1)
        palette.setBrush(QPalette.Inactive, QPalette.ButtonText, brush)
        palette.setBrush(QPalette.Inactive, QPalette.Base, brush1)
        palette.setBrush(QPalette.Inactive, QPalette.Window, brush1)
        palette.setBrush(QPalette.Inactive, QPalette.Shadow, brush)
        palette.setBrush(QPalette.Inactive, QPalette.AlternateBase, brush1)
        palette.setBrush(QPalette.Inactive, QPalette.ToolTipBase, brush4)
        palette.setBrush(QPalette.Inactive, QPalette.ToolTipText, brush)
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette.Inactive, QPalette.PlaceholderText, brush5)
#endif
        palette.setBrush(QPalette.Inactive, QPalette.Accent, brush1)
        palette.setBrush(QPalette.Disabled, QPalette.WindowText, brush2)
        palette.setBrush(QPalette.Disabled, QPalette.Button, brush1)
        palette.setBrush(QPalette.Disabled, QPalette.Light, brush1)
        palette.setBrush(QPalette.Disabled, QPalette.Midlight, brush1)
        palette.setBrush(QPalette.Disabled, QPalette.Dark, brush2)
        palette.setBrush(QPalette.Disabled, QPalette.Mid, brush3)
        palette.setBrush(QPalette.Disabled, QPalette.Text, brush2)
        palette.setBrush(QPalette.Disabled, QPalette.BrightText, brush1)
        palette.setBrush(QPalette.Disabled, QPalette.ButtonText, brush2)
        palette.setBrush(QPalette.Disabled, QPalette.Base, brush1)
        palette.setBrush(QPalette.Disabled, QPalette.Window, brush1)
        palette.setBrush(QPalette.Disabled, QPalette.Shadow, brush)
        palette.setBrush(QPalette.Disabled, QPalette.AlternateBase, brush1)
        palette.setBrush(QPalette.Disabled, QPalette.ToolTipBase, brush4)
        palette.setBrush(QPalette.Disabled, QPalette.ToolTipText, brush)
        brush6 = QBrush(QColor(127, 127, 127, 127))
        brush6.setStyle(Qt.SolidPattern)
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette.Disabled, QPalette.PlaceholderText, brush6)
#endif
        palette.setBrush(QPalette.Disabled, QPalette.Accent, brush1)
        Form.setPalette(palette)
        self.tabWidget = QTabWidget(Form)
        self.tabWidget.setObjectName(u"tabWidget")
        self.tabWidget.setGeometry(QRect(0, 0, 661, 661))
        self.tabWidget.setTabShape(QTabWidget.TabShape.Rounded)
        self.tab = QWidget()
        self.tab.setObjectName(u"tab")
        self.lineEdit_curConfig = QLineEdit(self.tab)
        self.lineEdit_curConfig.setObjectName(u"lineEdit_curConfig")
        self.lineEdit_curConfig.setGeometry(QRect(130, 20, 421, 26))
        self.lineEdit_curConfig.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.lineEdit_curConfig.setReadOnly(True)
        self.pushButton_browse = QPushButton(self.tab)
        self.pushButton_browse.setObjectName(u"pushButton_browse")
        self.pushButton_browse.setGeometry(QRect(550, 20, 94, 26))
        self.label_curConfig = QLabel(self.tab)
        self.label_curConfig.setObjectName(u"label_curConfig")
        self.label_curConfig.setGeometry(QRect(10, 20, 121, 21))
        self.groupBox_scConfig = QGroupBox(self.tab)
        self.groupBox_scConfig.setObjectName(u"groupBox_scConfig")
        self.groupBox_scConfig.setGeometry(QRect(10, 260, 631, 321))
        self.horizontalLayoutWidget_6 = QWidget(self.groupBox_scConfig)
        self.horizontalLayoutWidget_6.setObjectName(u"horizontalLayoutWidget_6")
        self.horizontalLayoutWidget_6.setGeometry(QRect(0, 20, 631, 301))
        self.horizontalLayout_6 = QHBoxLayout(self.horizontalLayoutWidget_6)
        self.horizontalLayout_6.setObjectName(u"horizontalLayout_6")
        self.horizontalLayout_6.setContentsMargins(0, 0, 0, 0)
        self.scrollArea = QScrollArea(self.horizontalLayoutWidget_6)
        self.scrollArea.setObjectName(u"scrollArea")
        sizePolicy = QSizePolicy(QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.scrollArea.sizePolicy().hasHeightForWidth())
        self.scrollArea.setSizePolicy(sizePolicy)
        self.scrollArea.setAutoFillBackground(True)
        self.scrollArea.setVerticalScrollBarPolicy(Qt.ScrollBarPolicy.ScrollBarAlwaysOn)
        self.scrollArea.setHorizontalScrollBarPolicy(Qt.ScrollBarPolicy.ScrollBarAlwaysOff)
        self.scrollArea.setWidgetResizable(True)
        self.scrollAreaWidgetContents = QWidget()
        self.scrollAreaWidgetContents.setObjectName(u"scrollAreaWidgetContents")
        self.scrollAreaWidgetContents.setGeometry(QRect(0, 0, 613, 68))
        sizePolicy1 = QSizePolicy(QSizePolicy.Policy.Preferred, QSizePolicy.Policy.Preferred)
        sizePolicy1.setHorizontalStretch(0)
        sizePolicy1.setVerticalStretch(0)
        sizePolicy1.setHeightForWidth(self.scrollAreaWidgetContents.sizePolicy().hasHeightForWidth())
        self.scrollAreaWidgetContents.setSizePolicy(sizePolicy1)
        self.verticalLayout_3 = QVBoxLayout(self.scrollAreaWidgetContents)
        self.verticalLayout_3.setObjectName(u"verticalLayout_3")
        self.verticalLayout_3.setSizeConstraint(QLayout.SizeConstraint.SetDefaultConstraint)
        self.scrollArea.setWidget(self.scrollAreaWidgetContents)

        self.horizontalLayout_6.addWidget(self.scrollArea, 0, Qt.AlignmentFlag.AlignTop)

        self.spinBox_configNumber = QSpinBox(self.groupBox_scConfig)
        self.spinBox_configNumber.setObjectName(u"spinBox_configNumber")
        self.spinBox_configNumber.setGeometry(QRect(150, -1, 48, 21))
        self.spinBox_configNumber.setMinimum(1)
        self.groupBox_masterConfig = QGroupBox(self.tab)
        self.groupBox_masterConfig.setObjectName(u"groupBox_masterConfig")
        self.groupBox_masterConfig.setGeometry(QRect(10, 60, 631, 181))
        self.horizontalLayoutWidget_5 = QWidget(self.groupBox_masterConfig)
        self.horizontalLayoutWidget_5.setObjectName(u"horizontalLayoutWidget_5")
        self.horizontalLayoutWidget_5.setGeometry(QRect(0, 20, 631, 161))
        self.horizontalLayout_5 = QHBoxLayout(self.horizontalLayoutWidget_5)
        self.horizontalLayout_5.setObjectName(u"horizontalLayout_5")
        self.horizontalLayout_5.setContentsMargins(0, 0, 0, 0)
        self.textEdit_masterConfig = QTextEdit(self.horizontalLayoutWidget_5)
        self.textEdit_masterConfig.setObjectName(u"textEdit_masterConfig")
        self.textEdit_masterConfig.setReadOnly(False)

        self.horizontalLayout_5.addWidget(self.textEdit_masterConfig)

        self.pushButton_save = QPushButton(self.tab)
        self.pushButton_save.setObjectName(u"pushButton_save")
        self.pushButton_save.setGeometry(QRect(220, 590, 94, 26))
        self.pushButton_saveAs = QPushButton(self.tab)
        self.pushButton_saveAs.setObjectName(u"pushButton_saveAs")
        self.pushButton_saveAs.setGeometry(QRect(330, 590, 94, 26))
        self.label_nos3Logo = QLabel(self.tab)
        self.label_nos3Logo.setObjectName(u"label_nos3Logo")
        self.label_nos3Logo.setGeometry(QRect(30, 585, 161, 41))
        self.label_nos3Logo.setScaledContents(True)
        self.label_jstarLogo = QLabel(self.tab)
        self.label_jstarLogo.setObjectName(u"label_jstarLogo")
        self.label_jstarLogo.setGeometry(QRect(450, 585, 171, 41))
        self.label_jstarLogo.setScaledContents(True)
        self.label_jstarLogo.setAlignment(Qt.AlignmentFlag.AlignLeading|Qt.AlignmentFlag.AlignLeft|Qt.AlignmentFlag.AlignVCenter)
        self.tabWidget.addTab(self.tab, "")
        self.tab_2 = QWidget()
        self.tab_2.setObjectName(u"tab_2")
        self.groupBox_8 = QGroupBox(self.tab_2)
        self.groupBox_8.setObjectName(u"groupBox_8")
        self.groupBox_8.setGeometry(QRect(10, 120, 631, 491))
        self.groupBox_8.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.groupBox_8.setFlat(False)
        self.groupBox_8.setCheckable(False)
        self.textEdit_buildConsole = QTextEdit(self.groupBox_8)
        self.textEdit_buildConsole.setObjectName(u"textEdit_buildConsole")
        self.textEdit_buildConsole.setGeometry(QRect(0, 20, 631, 471))
        palette1 = QPalette()
        palette1.setBrush(QPalette.Active, QPalette.Text, brush1)
        palette1.setBrush(QPalette.Active, QPalette.Base, brush)
        palette1.setBrush(QPalette.Inactive, QPalette.Text, brush1)
        palette1.setBrush(QPalette.Inactive, QPalette.Base, brush)
        self.textEdit_buildConsole.setPalette(palette1)
        self.textEdit_buildConsole.setReadOnly(True)
        self.frame_2 = QFrame(self.tab_2)
        self.frame_2.setObjectName(u"frame_2")
        self.frame_2.setGeometry(QRect(10, 20, 641, 81))
        self.frame_2.setFrameShape(QFrame.Shape.StyledPanel)
        self.frame_2.setFrameShadow(QFrame.Shadow.Raised)
        self.frame = QFrame(self.frame_2)
        self.frame.setObjectName(u"frame")
        self.frame.setGeometry(QRect(79, 0, 561, 80))
        self.frame.setFrameShape(QFrame.Shape.StyledPanel)
        self.frame.setFrameShadow(QFrame.Shadow.Raised)
        self.gridLayoutWidget_2 = QWidget(self.frame)
        self.gridLayoutWidget_2.setObjectName(u"gridLayoutWidget_2")
        self.gridLayoutWidget_2.setGeometry(QRect(0, 0, 561, 80))
        self.gridLayout_buildCleanButtons = QGridLayout(self.gridLayoutWidget_2)
        self.gridLayout_buildCleanButtons.setObjectName(u"gridLayout_buildCleanButtons")
        self.gridLayout_buildCleanButtons.setContentsMargins(0, 0, 0, 0)
        self.pushButton_cleanAll = QPushButton(self.gridLayoutWidget_2)
        self.pushButton_cleanAll.setObjectName(u"pushButton_cleanAll")

        self.gridLayout_buildCleanButtons.addWidget(self.pushButton_cleanAll, 1, 0, 1, 1)

        self.pushButton_buildAll = QPushButton(self.gridLayoutWidget_2)
        self.pushButton_buildAll.setObjectName(u"pushButton_buildAll")

        self.gridLayout_buildCleanButtons.addWidget(self.pushButton_buildAll, 0, 0, 1, 1)

        self.pushButton_fswBuild = QPushButton(self.gridLayoutWidget_2)
        self.pushButton_fswBuild.setObjectName(u"pushButton_fswBuild")

        self.gridLayout_buildCleanButtons.addWidget(self.pushButton_fswBuild, 0, 2, 1, 1)

        self.pushButton_cfgBuild = QPushButton(self.gridLayoutWidget_2)
        self.pushButton_cfgBuild.setObjectName(u"pushButton_cfgBuild")

        self.gridLayout_buildCleanButtons.addWidget(self.pushButton_cfgBuild, 0, 1, 1, 1)

        self.pushButton_simClean = QPushButton(self.gridLayoutWidget_2)
        self.pushButton_simClean.setObjectName(u"pushButton_simClean")

        self.gridLayout_buildCleanButtons.addWidget(self.pushButton_simClean, 1, 4, 1, 1)

        self.pushButton_simBuild = QPushButton(self.gridLayoutWidget_2)
        self.pushButton_simBuild.setObjectName(u"pushButton_simBuild")

        self.gridLayout_buildCleanButtons.addWidget(self.pushButton_simBuild, 0, 4, 1, 1)

        self.pushButton_gswBuild = QPushButton(self.gridLayoutWidget_2)
        self.pushButton_gswBuild.setObjectName(u"pushButton_gswBuild")

        self.gridLayout_buildCleanButtons.addWidget(self.pushButton_gswBuild, 0, 3, 1, 1)

        self.pushButton_fswClean = QPushButton(self.gridLayoutWidget_2)
        self.pushButton_fswClean.setObjectName(u"pushButton_fswClean")

        self.gridLayout_buildCleanButtons.addWidget(self.pushButton_fswClean, 1, 2, 1, 1)

        self.pushButton_gswClean = QPushButton(self.gridLayoutWidget_2)
        self.pushButton_gswClean.setObjectName(u"pushButton_gswClean")

        self.gridLayout_buildCleanButtons.addWidget(self.pushButton_gswClean, 1, 3, 1, 1)

        self.frame_3 = QFrame(self.frame_2)
        self.frame_3.setObjectName(u"frame_3")
        self.frame_3.setGeometry(QRect(0, 0, 81, 41))
        self.frame_3.setFrameShape(QFrame.Shape.StyledPanel)
        self.frame_3.setFrameShadow(QFrame.Shadow.Raised)
        self.verticalLayoutWidget = QWidget(self.frame_3)
        self.verticalLayoutWidget.setObjectName(u"verticalLayoutWidget")
        self.verticalLayoutWidget.setGeometry(QRect(0, 0, 81, 41))
        self.verticalLayout = QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)
        self.label_4 = QLabel(self.verticalLayoutWidget)
        self.label_4.setObjectName(u"label_4")
        self.label_4.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.verticalLayout.addWidget(self.label_4)

        self.frame_4 = QFrame(self.frame_2)
        self.frame_4.setObjectName(u"frame_4")
        self.frame_4.setGeometry(QRect(0, 40, 81, 41))
        self.frame_4.setFrameShape(QFrame.Shape.StyledPanel)
        self.frame_4.setFrameShadow(QFrame.Shadow.Raised)
        self.verticalLayoutWidget_2 = QWidget(self.frame_4)
        self.verticalLayoutWidget_2.setObjectName(u"verticalLayoutWidget_2")
        self.verticalLayoutWidget_2.setGeometry(QRect(0, 0, 81, 41))
        self.verticalLayout_2 = QVBoxLayout(self.verticalLayoutWidget_2)
        self.verticalLayout_2.setObjectName(u"verticalLayout_2")
        self.verticalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.label_5 = QLabel(self.verticalLayoutWidget_2)
        self.label_5.setObjectName(u"label_5")
        self.label_5.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.verticalLayout_2.addWidget(self.label_5)

        self.tabWidget.addTab(self.tab_2, "")
        self.tab_3 = QWidget()
        self.tab_3.setObjectName(u"tab_3")
        self.groupBox_control = QGroupBox(self.tab_3)
        self.groupBox_control.setObjectName(u"groupBox_control")
        self.groupBox_control.setGeometry(QRect(10, 10, 631, 611))
        self.horizontalLayoutWidget = QWidget(self.groupBox_control)
        self.horizontalLayoutWidget.setObjectName(u"horizontalLayoutWidget")
        self.horizontalLayoutWidget.setGeometry(QRect(10, 570, 611, 31))
        self.horizontalLayout = QHBoxLayout(self.horizontalLayoutWidget)
        self.horizontalLayout.setSpacing(45)
        self.horizontalLayout.setObjectName(u"horizontalLayout")
        self.horizontalLayout.setContentsMargins(0, 0, 0, 0)
        self.pushButton_play = QPushButton(self.horizontalLayoutWidget)
        self.pushButton_play.setObjectName(u"pushButton_play")
        icon = QIcon()
        icon.addFile(u"../../../../../../../../usr/share/icons/Humanity/actions/24/gtk-media-play-ltr.svg", QSize(), QIcon.Normal, QIcon.Off)
        self.pushButton_play.setIcon(icon)

        self.horizontalLayout.addWidget(self.pushButton_play)

        self.pushButton_pause = QPushButton(self.horizontalLayoutWidget)
        self.pushButton_pause.setObjectName(u"pushButton_pause")
        icon1 = QIcon()
        icon1.addFile(u"../../../../../../../../usr/share/icons/Humanity/actions/24/media-playback-pause.svg", QSize(), QIcon.Normal, QIcon.Off)
        self.pushButton_pause.setIcon(icon1)

        self.horizontalLayout.addWidget(self.pushButton_pause)

        self.horizontalLayoutWidget_2 = QWidget(self.groupBox_control)
        self.horizontalLayoutWidget_2.setObjectName(u"horizontalLayoutWidget_2")
        self.horizontalLayoutWidget_2.setGeometry(QRect(10, 10, 611, 41))
        self.horizontalLayout_2 = QHBoxLayout(self.horizontalLayoutWidget_2)
        self.horizontalLayout_2.setObjectName(u"horizontalLayout_2")
        self.horizontalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.pushButton_launch = QPushButton(self.horizontalLayoutWidget_2)
        self.pushButton_launch.setObjectName(u"pushButton_launch")

        self.horizontalLayout_2.addWidget(self.pushButton_launch)

        self.pushButton_stop = QPushButton(self.horizontalLayoutWidget_2)
        self.pushButton_stop.setObjectName(u"pushButton_stop")

        self.horizontalLayout_2.addWidget(self.pushButton_stop)

        self.groupBox_9 = QGroupBox(self.groupBox_control)
        self.groupBox_9.setObjectName(u"groupBox_9")
        self.groupBox_9.setGeometry(QRect(10, 60, 611, 451))
        self.groupBox_9.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.groupBox_9.setFlat(False)
        self.groupBox_9.setCheckable(False)
        self.textEdit_launchConsole = QTextEdit(self.groupBox_9)
        self.textEdit_launchConsole.setObjectName(u"textEdit_launchConsole")
        self.textEdit_launchConsole.setGeometry(QRect(0, 20, 611, 431))
        palette2 = QPalette()
        palette2.setBrush(QPalette.Active, QPalette.Text, brush1)
        palette2.setBrush(QPalette.Active, QPalette.Base, brush)
        palette2.setBrush(QPalette.Inactive, QPalette.Text, brush1)
        palette2.setBrush(QPalette.Inactive, QPalette.Base, brush)
        self.textEdit_launchConsole.setPalette(palette2)
        self.textEdit_launchConsole.setReadOnly(True)
        self.horizontalLayoutWidget_3 = QWidget(self.groupBox_control)
        self.horizontalLayoutWidget_3.setObjectName(u"horizontalLayoutWidget_3")
        self.horizontalLayoutWidget_3.setGeometry(QRect(190, 520, 261, 41))
        self.horizontalLayout_runForUntil = QHBoxLayout(self.horizontalLayoutWidget_3)
        self.horizontalLayout_runForUntil.setObjectName(u"horizontalLayout_runForUntil")
        self.horizontalLayout_runForUntil.setContentsMargins(0, 0, 0, 0)
        self.comboBox_run = QComboBox(self.horizontalLayoutWidget_3)
        self.comboBox_run.addItem("")
        self.comboBox_run.addItem("")
        self.comboBox_run.addItem("")
        self.comboBox_run.setObjectName(u"comboBox_run")

        self.horizontalLayout_runForUntil.addWidget(self.comboBox_run)

        self.lineEdit_secondsEntry = QLineEdit(self.horizontalLayoutWidget_3)
        self.lineEdit_secondsEntry.setObjectName(u"lineEdit_secondsEntry")
        self.lineEdit_secondsEntry.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.horizontalLayout_runForUntil.addWidget(self.lineEdit_secondsEntry)

        self.tabWidget.addTab(self.tab_3, "")

        self.retranslateUi(Form)

        self.tabWidget.setCurrentIndex(0)


        QMetaObject.connectSlotsByName(Form)
    # setupUi

    def retranslateUi(self, Form):
        Form.setWindowTitle(QCoreApplication.translate("Form", u"Form", None))
        self.lineEdit_curConfig.setPlaceholderText(QCoreApplication.translate("Form", u"None", None))
        self.pushButton_browse.setText(QCoreApplication.translate("Form", u"Browse...", None))
        self.label_curConfig.setText(QCoreApplication.translate("Form", u"Current Config:", None))
        self.groupBox_scConfig.setTitle(QCoreApplication.translate("Form", u"Spacecraft Config", None))
        self.groupBox_masterConfig.setTitle(QCoreApplication.translate("Form", u"Master Config", None))
        self.pushButton_save.setText(QCoreApplication.translate("Form", u"Save", None))
        self.pushButton_saveAs.setText(QCoreApplication.translate("Form", u"Save As...", None))
        self.label_nos3Logo.setText("")
        self.label_jstarLogo.setText("")
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab), QCoreApplication.translate("Form", u"Config", None))
        self.groupBox_8.setTitle(QCoreApplication.translate("Form", u"Console Output", None))
        self.pushButton_cleanAll.setText(QCoreApplication.translate("Form", u"All", None))
        self.pushButton_buildAll.setText(QCoreApplication.translate("Form", u"All", None))
        self.pushButton_fswBuild.setText(QCoreApplication.translate("Form", u"FSW", None))
        self.pushButton_cfgBuild.setText(QCoreApplication.translate("Form", u"CFG", None))
        self.pushButton_simClean.setText(QCoreApplication.translate("Form", u"SIM", None))
        self.pushButton_simBuild.setText(QCoreApplication.translate("Form", u"SIM", None))
        self.pushButton_gswBuild.setText(QCoreApplication.translate("Form", u"GSW", None))
        self.pushButton_fswClean.setText(QCoreApplication.translate("Form", u"FSW", None))
        self.pushButton_gswClean.setText(QCoreApplication.translate("Form", u"GSW", None))
        self.label_4.setText(QCoreApplication.translate("Form", u"Build", None))
        self.label_5.setText(QCoreApplication.translate("Form", u"Clean", None))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_2), QCoreApplication.translate("Form", u"Build", None))
        self.groupBox_control.setTitle("")
        self.pushButton_play.setText(QCoreApplication.translate("Form", u"Play", None))
        self.pushButton_pause.setText(QCoreApplication.translate("Form", u"Pause", None))
        self.pushButton_launch.setText(QCoreApplication.translate("Form", u"Launch", None))
        self.pushButton_stop.setText(QCoreApplication.translate("Form", u"Stop", None))
        self.groupBox_9.setTitle(QCoreApplication.translate("Form", u"NOS3 Time Driver", None))
        self.comboBox_run.setItemText(0, "")
        self.comboBox_run.setItemText(1, QCoreApplication.translate("Form", u"Run For", None))
        self.comboBox_run.setItemText(2, QCoreApplication.translate("Form", u"Run Until", None))

        self.lineEdit_secondsEntry.setText("")
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_3), QCoreApplication.translate("Form", u"Launch", None))
    # retranslateUi

