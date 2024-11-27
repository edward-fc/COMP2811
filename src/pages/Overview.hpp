#ifndef OVERVIEWPAGE_HPP
#define OVERVIEWPAGE_HPP

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class OverviewPage : public QWidget {
    Q_OBJECT

public:
    explicit OverviewPage(QWidget* parent = nullptr);


private slots:
    void onSearchClicked();

private:
    QLineEdit* searchBox;
    QPushButton* searchButton;
    QLabel* resultLabel;
};

#endif