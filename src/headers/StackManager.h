#include <QWidget>
#include "./NaomiWebView.h"
#include <QProgressBar>
#include <QUrl>
#include <QTabWidget>

class StackManager : public QWidget {
Q_OBJECT
public:
	StackManager(QTabWidget* parent, NaomiWebView* viewp, QUrl url);
private:
	QProgressBar* progressBar;
	NaomiWebView* view;
	QTabWidget* parentWidget;
	void start();

public slots:
	void handleProgress(int percent);
};