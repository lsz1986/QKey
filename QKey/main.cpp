#include "qkey.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QKey w;
	w.show();
	return a.exec();
}
