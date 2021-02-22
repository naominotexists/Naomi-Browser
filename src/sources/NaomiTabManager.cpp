#include "../headers/NaomiTabManager.h"
#include "../headers/NaomiWebView.h"
#include <QTabWidget>
#include <iostream>

NaomiTabManager::NaomiTabManager(QWidget* parent) : QTabWidget(parent) {
	setTabsClosable(true);
};

void NaomiTabManager::createPage(QUrl url, QString title) {
	NaomiWebView* page = new NaomiWebView(this, count());
	connect(page, SIGNAL(loadFinishedSend(NaomiWebView*)), this, SLOT(pageLoadFinished(NaomiWebView*)));
	page->load(url);
	addTab(page, title);
}

void NaomiTabManager::createPage(QString html, QString title) {
	NaomiWebView* page = new NaomiWebView(this, count());

	page->setHtml(html);
	addTab(page, title);
}

void NaomiTabManager::pageLoadFinished(NaomiWebView* page) {
	setTabText(page->ind(), page->title());
}