#include <QApplication>
#include "headers/NaomiBrowser.h"

int main(int argc, char **argv) {
	QApplication app(argc, argv);
	NaomiBrowser browser;
	browser.show();
	return app.exec();
}