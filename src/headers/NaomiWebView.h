#include <QWebEngineView>
#include <QUrl>
#include <QWidget>

#ifndef _webview_included_
#define _webview_included_

class NaomiWebView : public QWebEngineView {
Q_OBJECT
public:
	explicit NaomiWebView(QWidget* parent, int indp);
	int ind();
signals:
	void loadFinished(bool ok);
	void loadFinishedSend(NaomiWebView* page);
	void loadProgress(int prog);
	void selectionChanged();
public slots:
	void handleFinished(bool ok);
	void handleStarted();
	void handleProgress(int prog);
private:
	int indq;
};

#endif