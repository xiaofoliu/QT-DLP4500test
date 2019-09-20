#include "DLP4500Test.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DLP4500Test w;
	w.show();
	return a.exec();
}
