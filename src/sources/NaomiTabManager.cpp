#include "../headers/NaomiTabManager.h"
#include "../headers/NaomiWebView.h"
#include "../headers/StackManager.h"
#include <QTabWidget>
#include <iostream>

NaomiTabManager::NaomiTabManager(QWidget* parent) : QTabWidget(parent) {
	setTabsClosable(true);
};

void NaomiTabManager::createPage(QUrl url, QString title) {
	NaomiWebView* page = new NaomiWebView(this, count());
	StackManager* stack = new StackManager(this, page, url);
	addTab(stack, title);
}

void NaomiTabManager::createPage(QString html, QString title) {
	NaomiWebView* page = new NaomiWebView(this, count());
	page->setHtml(html);
	addTab(page, title);
}