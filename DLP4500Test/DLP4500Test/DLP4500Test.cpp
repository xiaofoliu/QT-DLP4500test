#include "DLP4500Test.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hidapi.h"

#include "dlpc350_common.h"
#include "dlpc350_error.h"
#include "dlpc350_usb.h"
#include "dlpc350_api.h"
#include "dlpc350_flashDevice.h"
#include "dlpc350_BMPParser.h"
#include "dlpc350_firmware.h"
#include "dlpc350_version.h"

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QtGlobal>
#include <QThread>
#include <QTextStream>
#include <QListWidgetItem>
#include <QItemSelectionModel>
#include <QMenu>
#include <QPainter>
#include <QTimer>
#include <QTime>
#include <QDebug>
#include "Helper.h"

#define MAX_NUM_RETRIES 5

DLP4500Test::DLP4500Test(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// Display GUI Version #
	char versionStr[255];
	sprintf(versionStr, "DLP LightCrafter 4500 Control Software v%d.%d.%d [%s %s]", \
		GUI_VERSION_MAJOR, GUI_VERSION_MINOR, GUI_VERSION_BUILD, __DATE__, __TIME__);
	setWindowTitle(versionStr);

	
	DLPC350_USB_Init();
	ui.connectButton->setEnabled(DLPC350_USB_IsConnected());
	m_usbPollTimer = new QTimer(this);
	m_usbPollTimer->setInterval(2000);
	connect(m_usbPollTimer, SIGNAL(timeout()), this, SLOT(timerTimeout()));
	m_usbPollTimer->start();
}

DLP4500Test::~DLP4500Test()
{
	DLPC350_USB_Close();
	DLPC350_USB_Exit();
}

void DLP4500Test::ShowError(const char *str)
{
	QString title("LightCrafter Error Message");
	QString text(str);
	QMessageBox msgBox(QMessageBox::Warning, title, text, QMessageBox::NoButton, this);
	msgBox.exec();
}

void DLP4500Test::on_connectButton_clicked()
{
	//ui.connectButton->setEnabled(DLPC350_USB_IsConnected());
	ShowError("projector has been connected");
	
}

void DLP4500Test::timerTimeout(void)
{
	if (DLPC350_USB_IsConnected())
	{
				ui.connectButton->setEnabled(DLPC350_USB_IsConnected());
	}
	else
	{
		if (DLPC350_USB_Open() == 0)
		{
			ui.connectButton->setEnabled(DLPC350_USB_IsConnected());
			ShowError("projector has been connected");
			unsigned char firmwareTag[33];
			if (DLPC350_GetFirmwareTagInfo(&firmwareTag[0]) == 0)
			{
				QString str((char *)firmwareTag);
				ui.label_firmwareTagInfo->setText(str);
			}
			//emit on_connectButton_clicked();
		}
	}
}

void DLP4500Test::on_checkBox_SLMode_clicked()
{
	int trigMode = 0;
	bool isExtPatDisplayMode = false;


	SetDLPC350InPatternMode();



	//Update all the settings under the page
	if (DLPC350_GetPatternTriggerMode(&trigMode) == 0)
	{
		if (trigMode <= 2)
		{
			if (DLPC350_GetPatternDisplayMode(&isExtPatDisplayMode) == 0)
			{

				
				if (!isExtPatDisplayMode)
				{
					//ui.radioButton_PatSeqSrcFrmFlash->setChecked(true);
					//emit on_radioButton_PatSeqSrcFrmFlash_clicked();
				}
			}
		}
	}

}

void DLP4500Test::SetDLPC350InPatternMode()
{
	int i = 0;
	bool mode;
	unsigned int patMode;

	//Check if it is in Pattern Mode
	DLPC350_GetMode(&mode);
	if (mode == false)
	{
		//Switch to Pattern Mode
		DLPC350_SetMode(true);
		SleeperThread::msleep(100);
		while (1)
		{
			DLPC350_GetMode(&mode);
			if (mode)
				break;
			SleeperThread::msleep(100);
			if (i++ > MAX_NUM_RETRIES)
				break;
		}
	}
	else
	{
		//First stop pattern sequence
		DLPC350_GetPatternDisplay(&patMode);
		//if it is in PAUSE or RUN mode
		if (patMode != 0)
		{
			//emit on_pushButton_PatSeqCtrlStop_clicked();
		}
	}

	return;
}

void DLP4500Test::on_project_Button_clicked()
{
	
	DLPC350_ClearPatLut();
	//格雷码图案
	if (DLPC350_AddToPatLut(0, 0, 4, 7, 0, 0, 1, 0) < 0)
	{
		ShowError("error Updating LUT");
	}
	if (DLPC350_AddToPatLut(0, 1, 4, 7, 0, 1, 0, 0) < 0)
	{
		ShowError("error Updating LUT");
	}
	if (DLPC350_AddToPatLut(0, 2, 4, 7, 0, 1, 0, 0) < 0)
	{
		ShowError("error Updating LUT");
	}
	if (DLPC350_AddToPatLut(0, 3, 4, 7, 0, 1, 0, 0) < 0)
	{
		ShowError("error Updating LUT");
	}
	if (DLPC350_AddToPatLut(0, 4, 4, 7, 0, 1, 0, 0) < 0)
	{
		ShowError("error Updating LUT");
	}
	if (DLPC350_AddToPatLut(0, 5, 4, 7, 0, 1, 0, 0) < 0)
	{
		ShowError("error Updating LUT");
	}

	//相移图案
	if (DLPC350_AddToPatLut(0, 0, 6, 7, 0, 1, 1, 0) < 0)
	{
		ShowError("error Updating LUT");
	}
	if (DLPC350_AddToPatLut(0, 1, 6, 7, 0, 1, 0, 0) < 0)
	{
		ShowError("error Updating LUT");
	}
	if (DLPC350_AddToPatLut(0, 2, 6, 7, 0, 1, 0, 0) < 0)
	{
		ShowError("error Updating LUT");
	}
	if (DLPC350_AddToPatLut(0, 3, 6, 7, 0, 1, 0, 0) < 0)
	{
		ShowError("error Updating LUT");
	}


	/*for (int i = 0; i < 6; i++)
	{
		if (DLPC350_AddToPatLut(0, i, 4, 7, 0, 0, 0, 0) < 0)
		{
			ShowError("error Updating LUT");

		}
	}
	if (DLPC350_AddToPatLut(0, 0, 6, 7, 0, 0, 1, 0) < 0)
	{
		ShowError("error Updating LUT");

	}
	for (int i = 1; i < 4; i++)
	{
		if (DLPC350_AddToPatLut(0, i, 6, 7, 0, 0, 0, 0) < 0)
		{
			ShowError("error Updating LUT");

		}
	}*/
	
	if (DLPC350_SetPatternDisplayMode(0)<0)
	{
		ShowError("error set from flash");
	}
	/*int r = DLPC350_SetPatternDisplayMode(0);
	QMessageBox msgBox(QMessageBox::Warning, "", QString::number(r), QMessageBox::NoButton, this);
	msgBox.exec();*/


	if (ui.radioButton_PatSeqDispRunOnce->isChecked())
	{
		numPatterns = 10;
	}
	else
	{
		numPatterns = 1;
	}

	if (DLPC350_SetPatternConfig(10, ui.radioButton_PatSeqDispRunContinuous->isChecked(), numPatterns, 2) < 0)
	{
		ShowError("error Sending Pattern Config");

	}


	if (DLPC350_SetExposure_FramePeriod(ui.lineEdit_PatSeqPatExpTime->text().toInt(), ui.lineEdit_PatSeqPatPeriod->text().toInt()) < 0)
	{
		ShowError("error Sending Exposure period");

	}



	//Configure Trigger Mode - 0(External) or 1(internal)
	if (DLPC350_SetPatternTriggerMode(1) < 0)
	{
		ShowError("error Sending trigger Mode");

	}


	//Send Pattern LUT
	if (DLPC350_SendPatLut() < 0)
	{

		ShowError("error Sending Pattern LUT");

	}

	unsigned char splashLut[2];
	//for (int i = 0; i < 10; i++)
	//{
		//if (i < 6)
			splashLut[0] = 0x03;
		//else
			splashLut[1] = 0x04;
	//}

	if (DLPC350_SendImageLut(&splashLut[0], 2) < 0)
	{

		ShowError("error Sending Image LUT");

	}
	/*int r = DLPC350_SendImageLut(&splashLut[0], 6);
	QMessageBox msgBox(QMessageBox::Warning, "", QString::number(r), QMessageBox::NoButton, this);
	msgBox.exec();*/

	/************************开始投影**********************************/
	if (DLPC350_StartPatLutValidate() < 0)
	{
		ShowError("error check LUT data");

	}



	int i = 0;
	unsigned int status;
	bool ready;

	QEventLoop loop;

	do
	{
		if (DLPC350_CheckPatLutValidate(&ready, &status) < 0)
		{
			ShowError("error validating LUT data");
		}

		if (ready)
		{
			break;
		}
		else
		{
			QTimer::singleShot(1000, &loop, SLOT(quit()));
			loop.exec();
		}

		if (i++ > MAX_NUM_RETRIES)
			break;
	} while (1);

	if (status != 0)
	{
		ShowError("Sequence validation FAILED!");
	}

	if ((status & BIT0) == BIT0)
	{
		ShowError("Exposure or frame period OUT OF RANGE");
	}
	if ((status & BIT1) == BIT1)
	{
		ShowError("Pattern number in lookup table INVALID");
	}
	if ((status & BIT2) == BIT2)
	{
		ShowError("Continued output trigger OVERLAPS black vector");
	}
	if ((status & BIT3) == BIT3)
	{
		ShowError("Black vector MISSING when exposure less than frame period");
	}
	if ((status & BIT4) == BIT4)
	{
		ShowError("Difference between exposure and frame period less than 230us");
	}

	if (DLPC350_PatternDisplay(2) < 0)
	{
		ShowError("error play");
	}

}


void DLP4500Test::on_stopButton_clicked()
{
	int i = 0;
	unsigned int patMode;

	DLPC350_PatternDisplay(0);
	SleeperThread::msleep(100);
	while (1)
	{
		DLPC350_GetPatternDisplay(&patMode);
		if (patMode == 0)
			break;
		else
			DLPC350_PatternDisplay(0);
		SleeperThread::msleep(100);
		if (i++ > MAX_NUM_RETRIES)
			break;
	}
}



void DLP4500Test::on_testButton_clicked()
{
	DLPC350_ClearPatLut();

	for (int i = 0; i < 4; i++)
	{
		if (DLPC350_AddToPatLut(0, i, 6, 7, 0, 0, 0, 0) < 0)
		{
			ShowError("error Updating LUT");

		}
	}


	if (DLPC350_SetPatternDisplayMode(0)<0)
	{
		ShowError("error set from flash");
	}
	/*int r = DLPC350_SetPatternDisplayMode(0);
	QMessageBox msgBox(QMessageBox::Warning, "", QString::number(r), QMessageBox::NoButton, this);
	msgBox.exec();*/


	if (ui.radioButton_PatSeqDispRunOnce->isChecked())
	{
		numPatterns = 4;
	}
	else
	{
		numPatterns = 1;
	}

	if (DLPC350_SetPatternConfig(4, ui.radioButton_PatSeqDispRunContinuous->isChecked(), numPatterns, 2) < 0)
	{
		ShowError("error Sending Pattern Config");

	}


	if (DLPC350_SetExposure_FramePeriod(ui.lineEdit_PatSeqPatExpTime->text().toInt(), ui.lineEdit_PatSeqPatPeriod->text().toInt()) < 0)
	{
		ShowError("error Sending Exposure period");

	}



	//Configure Trigger Mode - 0(External) or 1(internal)
	if (DLPC350_SetPatternTriggerMode(1) < 0)
	{
		ShowError("error Sending trigger Mode");

	}


	//Send Pattern LUT
	if (DLPC350_SendPatLut() < 0)
	{

		ShowError("error Sending Pattern LUT");

	}

	unsigned char splashLut[1];
	//for (int i = 0; i < 4; i++)
	//{
		splashLut[0] = 0x04;
	//}
	if (DLPC350_SendImageLut(&splashLut[0], 1) < 0)
	{

		ShowError("error Sending Image LUT");

	}
	/*int r = DLPC350_SendImageLut(&splashLut[0], 6);
	QMessageBox msgBox(QMessageBox::Warning, "", QString::number(r), QMessageBox::NoButton, this);
	msgBox.exec();*/

	/************************开始投影**********************************/
	if (DLPC350_StartPatLutValidate()<0)
	{
		ShowError("error check LUT data");

	}



	int i = 0;
	unsigned int status;
	bool ready;

	QEventLoop loop;

	do
	{
		if (DLPC350_CheckPatLutValidate(&ready, &status) < 0)
		{
			ShowError("error validating LUT data");
		}

		if (ready)
		{
			break;
		}
		else
		{
			QTimer::singleShot(1000, &loop, SLOT(quit()));
			loop.exec();
		}

		if (i++ > MAX_NUM_RETRIES)
			break;
	} while (1);

	if (status != 0)
	{
		ShowError("Sequence validation FAILED!");
	}

	if ((status & BIT0) == BIT0)
	{
		ShowError("Exposure or frame period OUT OF RANGE");
	}
	if ((status & BIT1) == BIT1)
	{
		ShowError("Pattern number in lookup table INVALID");
	}
	if ((status & BIT2) == BIT2)
	{
		ShowError("Continued output trigger OVERLAPS black vector");
	}
	if ((status & BIT3) == BIT3)
	{
		ShowError("Black vector MISSING when exposure less than frame period");
	}
	if ((status & BIT4) == BIT4)
	{
		ShowError("Difference between exposure and frame period less than 230us");
	}

	if (DLPC350_PatternDisplay(2) < 0)
	{
		ShowError("error play");
	}
}