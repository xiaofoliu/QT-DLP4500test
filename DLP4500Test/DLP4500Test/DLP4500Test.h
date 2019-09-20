#pragma once

#include <QtWidgets/QMainWindow>
#include <QSettings>
#include <QListWidgetItem>
#include <QFileInfo>
#include <QThread>
#include "ui_DLP4500Test.h"

#include "dlpc350_common.h"
#include "dlpc350_firmware.h"

class SleeperThread : public QThread
{
public:
	static void msleep(unsigned long msecs)
	{
		QThread::msleep(msecs);
	}
};

class DLP4500Test : public QMainWindow
{
	Q_OBJECT

public:
	DLP4500Test(QWidget *parent = Q_NULLPTR);
	~DLP4500Test();

private slots:
    void timerTimeout(void);
	void on_connectButton_clicked();
	void on_checkBox_SLMode_clicked();
	void on_project_Button_clicked();
	void on_stopButton_clicked();
	void on_testButton_clicked();

private:
	Ui::DLP4500TestClass ui;
	QTimer *m_usbPollTimer;
	int numPatterns;
	int numLutEntries = 10;
	int numSplashLutEntries;

	void SetDLPC350InPatternMode();
	void ShowError(const char *str);
	
};
