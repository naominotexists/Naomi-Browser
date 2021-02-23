#include "../headers/NaomiBrowser.h"
#include <QMainWindow>
#include <QLabel>
#include <QWidget>
#include <QWebEngineView>
#include <QUrl>
#include <QVBoxLayout>
#include <QTabWidget>
#include "../headers/NaomiWebView.h"
#include "../headers/NaomiTabManager.h"

NaomiBrowser::NaomiBrowser() : QMainWindow() {
	resize(500, 500);
	initUI();
}

void NaomiBrowser::initUI() {
	setWindowTitle("Naomi Browser");

	setCentralWidget(new QWidget(this));
	initCentralWidget();
}

void NaomiBrowser::initCentralWidget() {
	QVBoxLayout* widgetLayout = new QVBoxLayout();

	centralWidget()->setLayout(widgetLayout);

	initTabs();
}

void NaomiBrowser::initTabs() {
	NaomiTabManager* tabWidget = new NaomiTabManager(this);

	tabWidget->createPage(QUrl("https://github.com/naominotexists/Naomi-Browser"), tr("Loading"));

	centralWidget()->layout()->addWidget(tabWidget);
}
