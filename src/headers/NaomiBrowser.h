#include <QMainWindow>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QWebEngineView>
#include <QObject>

class NaomiBrowser : public QMainWindow {
Q_OBJECT
public:
	explicit NaomiBrowser();
private:
	void initUI();
	void initCentralWidget();
	void initTabs();
	QTabWidget* tabWidget;
	QWebEngineView* mainView;
};
