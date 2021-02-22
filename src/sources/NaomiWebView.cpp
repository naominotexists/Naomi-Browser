#include "../headers/NaomiWebView.h"
#include "../headers/NaomiTabManager.h"
#include <QWebEngineView>
#include <QWidget>
#include <iostream>
#include <QWebEnginePage>

NaomiWebView::NaomiWebView(QWidget* parent, int indp) : QWebEngineView(parent) {
	indq = indp;
	connect(this->page(), &QWebEnginePage::loadFinished, this, &NaomiWebView::handleFinished);
	connect(this, &NaomiWebView::loadStarted, this, &NaomiWebView::handleStarted);
	connect(this->page(), &QWebEnginePage::loadProgress, this, &NaomiWebView::handleProgress);
}

void NaomiWebView::handleFinished(bool ok) {
	if(ok) emit loadFinishedSend(this);
}

void NaomiWebView::handleStarted() {
	std::cout << "Page loading..." << std::endl;
}

void NaomiWebView::handleProgress(int prog) {
	std::cout << "Page loading: %" << prog << std::endl;
}

int NaomiWebView::ind() {
	return indq;
}
