#include <QTabWidget>
#include <QWidget>
#include "./NaomiWebView.h"

class NaomiTabManager : public QTabWidget {
Q_OBJECT
public:
	explicit NaomiTabManager(QWidget* parent);
	void createPage(QUrl url, QString title);
	void createPage(QString html, QString title);
};

