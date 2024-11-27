#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QMainWindow>

class QStackedWidget;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();

private:
    void createNavigationBar();
    void createPages();
    QWidget* navBar;
    QStackedWidget* pageStack;
};

#endif
