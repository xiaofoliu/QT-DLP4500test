/********************************************************************************
** Form generated from reading UI file 'DLP4500Test.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLP4500TEST_H
#define UI_DLP4500TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DLP4500TestClass
{
public:
    QWidget *centralWidget;
    QPushButton *connectButton;
    QLabel *label;
    QLabel *label_firmwareTagInfo;
    QPushButton *project_Button;
    QRadioButton *radioButton_PatSeqDispRunContinuous;
    QRadioButton *radioButton_PatSeqDispRunOnce;
    QLineEdit *lineEdit_PatSeqPatExpTime;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_PatSeqPatPeriod;
    QPushButton *stopButton;
    QCheckBox *checkBox_SLMode;
    QPushButton *testButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DLP4500TestClass)
    {
        if (DLP4500TestClass->objectName().isEmpty())
            DLP4500TestClass->setObjectName(QStringLiteral("DLP4500TestClass"));
        DLP4500TestClass->resize(823, 438);
        centralWidget = new QWidget(DLP4500TestClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        connectButton = new QPushButton(centralWidget);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setGeometry(QRect(110, 30, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(230, 30, 71, 21));
        label_firmwareTagInfo = new QLabel(centralWidget);
        label_firmwareTagInfo->setObjectName(QStringLiteral("label_firmwareTagInfo"));
        label_firmwareTagInfo->setGeometry(QRect(310, 30, 61, 21));
        project_Button = new QPushButton(centralWidget);
        project_Button->setObjectName(QStringLiteral("project_Button"));
        project_Button->setGeometry(QRect(110, 70, 181, 31));
        radioButton_PatSeqDispRunContinuous = new QRadioButton(centralWidget);
        radioButton_PatSeqDispRunContinuous->setObjectName(QStringLiteral("radioButton_PatSeqDispRunContinuous"));
        radioButton_PatSeqDispRunContinuous->setGeometry(QRect(410, 80, 89, 16));
        radioButton_PatSeqDispRunOnce = new QRadioButton(centralWidget);
        radioButton_PatSeqDispRunOnce->setObjectName(QStringLiteral("radioButton_PatSeqDispRunOnce"));
        radioButton_PatSeqDispRunOnce->setGeometry(QRect(300, 80, 89, 16));
        lineEdit_PatSeqPatExpTime = new QLineEdit(centralWidget);
        lineEdit_PatSeqPatExpTime->setObjectName(QStringLiteral("lineEdit_PatSeqPatExpTime"));
        lineEdit_PatSeqPatExpTime->setGeometry(QRect(610, 70, 113, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(523, 70, 81, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(520, 100, 81, 16));
        lineEdit_PatSeqPatPeriod = new QLineEdit(centralWidget);
        lineEdit_PatSeqPatPeriod->setObjectName(QStringLiteral("lineEdit_PatSeqPatPeriod"));
        lineEdit_PatSeqPatPeriod->setGeometry(QRect(610, 100, 113, 20));
        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setGeometry(QRect(110, 140, 131, 31));
        checkBox_SLMode = new QCheckBox(centralWidget);
        checkBox_SLMode->setObjectName(QStringLiteral("checkBox_SLMode"));
        checkBox_SLMode->setGeometry(QRect(350, 30, 121, 21));
        testButton = new QPushButton(centralWidget);
        testButton->setObjectName(QStringLiteral("testButton"));
        testButton->setGeometry(QRect(390, 130, 75, 23));
        DLP4500TestClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DLP4500TestClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 823, 23));
        DLP4500TestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DLP4500TestClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DLP4500TestClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DLP4500TestClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DLP4500TestClass->setStatusBar(statusBar);

        retranslateUi(DLP4500TestClass);

        QMetaObject::connectSlotsByName(DLP4500TestClass);
    } // setupUi

    void retranslateUi(QMainWindow *DLP4500TestClass)
    {
        DLP4500TestClass->setWindowTitle(QApplication::translate("DLP4500TestClass", "DLP4500Test", Q_NULLPTR));
        connectButton->setText(QApplication::translate("DLP4500TestClass", "\350\277\236\346\216\245\346\212\225\345\275\261\344\273\252", Q_NULLPTR));
        label->setText(QApplication::translate("DLP4500TestClass", "FirmwareTag", Q_NULLPTR));
        label_firmwareTagInfo->setText(QApplication::translate("DLP4500TestClass", "xxx", Q_NULLPTR));
        project_Button->setText(QApplication::translate("DLP4500TestClass", "\345\274\200\345\247\213\346\212\225\345\275\261\346\240\274\351\233\267\347\240\201+\345\233\233\346\255\245\347\233\270\347\247\273\345\233\276\346\241\210", Q_NULLPTR));
        radioButton_PatSeqDispRunContinuous->setText(QApplication::translate("DLP4500TestClass", "repeat", Q_NULLPTR));
        radioButton_PatSeqDispRunOnce->setText(QApplication::translate("DLP4500TestClass", "play once", Q_NULLPTR));
        label_2->setText(QApplication::translate("DLP4500TestClass", "ExposureTime", Q_NULLPTR));
        label_3->setText(QApplication::translate("DLP4500TestClass", "PatternPeriod", Q_NULLPTR));
        stopButton->setText(QApplication::translate("DLP4500TestClass", "\345\201\234\346\255\242\346\212\225\345\275\261", Q_NULLPTR));
        checkBox_SLMode->setText(QApplication::translate("DLP4500TestClass", "PatternSequence", Q_NULLPTR));
        testButton->setText(QApplication::translate("DLP4500TestClass", "test", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DLP4500TestClass: public Ui_DLP4500TestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLP4500TEST_H
