#include "qtpaint.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTPAINT w;
	w.show();
	return a.exec();
}
