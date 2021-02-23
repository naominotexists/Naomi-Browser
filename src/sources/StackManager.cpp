#include "../headers/StackManager.h"
#include "../headers/NaomiWebView.h"
#include <QWidget>
#include <QProgressBar>
#include <iostream>
#include <QVBoxLayout>
#include <QFont>
#include <QTabWidget>

StackManager::StackManager(QTabWidget* parent, NaomiWebView* viewp, QUrl url) : QWidget(parent) {
	view = viewp;
	connect(viewp->page(), SIGNAL(loadProgress(int)), this, SLOT(handleProgress(int)));
	view->load(url);
	parentWidget = parent;
	start();
}

void StackManager::start() {
	this->setLayout(new QVBoxLayout());
	
	progressBar = new QProgressBar(this);
	progressBar->setMinimum(0);
	progressBar->setMaximum(100);
	progressBar->setValue(15);
	progressBar->setStyleSheet(tr("QProgressBar { border: solid grey; border-radius: 15px; color: black; } QProgressBar::chunk { background-color: #05B8CC; border-radius :15px; }"));
	progressBar->setFont(QFont("Arial", 10));
	progressBar->setAlignment(Qt::AlignCenter);
	
	this->layout()->addWidget(view);
	this->layout()->addWidget(progressBar);
}

void StackManager::handleProgress(int percent) {
	qDebug() << "Page loading:" << percent;
	progressBar->setValue(percent);
	if(percent == 100) {
		parentWidget->setTabText(view->ind(), view->title());
		progressBar->setVisible(false);
	}
}


