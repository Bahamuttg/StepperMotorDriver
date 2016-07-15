#include "mainwindow.h"
#include <QApplication>
#include "steppermotor.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	//Init GPIO
	wiringPiSetup();

	return a.exec();
}
