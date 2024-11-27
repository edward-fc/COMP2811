#include <QtWidgets>
#include <QStackedWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include "window.hpp"
#include "pages/Overview.hpp"
#include "pages/Organic.hpp"
#include "pages/Fluoride.hpp"
#include "pages/Env_litter.hpp"
#include "pages/Compliance.hpp"


static const int MIN_WIDTH = 620;

MainWindow::MainWindow() : QMainWindow() {
    setMinimumWidth(MIN_WIDTH);
    setWindowTitle("Pollutant Monitor");

    createNavigationBar();
    createPages();

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(navBar);
    mainLayout->addWidget(pageStack);

    QWidget* centralWidget = new QWidget();
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

}


void MainWindow::createNavigationBar() {
    navBar = new QWidget();
    QHBoxLayout* layout = new QHBoxLayout(navBar);

    QPushButton* overviewButton = new QPushButton("Overview");
    QPushButton* organicButton = new QPushButton("Organic Compounds");
    QPushButton* fluorideButton = new QPushButton("Fluorides");
    QPushButton* envButton = new QPushButton("Env_litter");
    QPushButton* complianceButton = new QPushButton("Compliance");

    layout->addWidget(overviewButton);
    layout->addWidget(organicButton);
    layout->addWidget(fluorideButton);
    layout->addWidget(envButton);
    layout->addWidget(complianceButton);

    layout->addStretch();

    connect(overviewButton, &QPushButton::clicked, this, [this]() {
        pageStack->setCurrentIndex(0);
    });
    connect(organicButton, &QPushButton::clicked, this, [this]() {
        pageStack->setCurrentIndex(1);
    });
    connect(fluorideButton, &QPushButton::clicked, this, [this]() {
        pageStack->setCurrentIndex(2);
    });
    connect(envButton, &QPushButton::clicked, this, [this]() {
        pageStack->setCurrentIndex(3);
    });
    connect(complianceButton, &QPushButton::clicked, this, [this]() {
        pageStack->setCurrentIndex(4);
    });
}

void MainWindow::createPages() {
    pageStack = new QStackedWidget();

    pageStack->addWidget(new OverviewPage());
    pageStack->addWidget(new OrganicPage());
    pageStack->addWidget(new FluoridePage());
    pageStack->addWidget(new EnvPage());
    pageStack->addWidget(new CompliancePage());
}
