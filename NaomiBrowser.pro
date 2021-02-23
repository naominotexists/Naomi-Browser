TEMPLATE = app
TARGET = NaomiBrowser
INCLUDEPATH += .

QT += widgets
QT += webenginewidgets

# Input
HEADERS += src/headers/NaomiBrowser.h \
	src/headers/NaomiWebView.h \
	src/headers/NaomiTabManager.h \
	src/headers/StackManager.h

SOURCES += src/app.cpp src/sources/NaomiBrowser.cpp \
	src/sources/NaomiWebView.cpp \
	src/sources/NaomiTabManager.cpp \
	src/sources/StackManager.cpp

# Build directories
DESTDIR = build/
OBJECTS_DIR = build/objects/
MOC_DIR = build/mocs/
