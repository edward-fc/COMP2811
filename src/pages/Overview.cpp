#include "Overview.hpp"
#include "../utils/utils.hpp"

#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

OverviewPage::OverviewPage(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);

    QLabel* label = new QLabel("Welcome to the Overview Page", this);
    label->setAlignment(Qt::AlignCenter);

    layout->addWidget(label);

    searchBox = new QLineEdit(this);
    searchBox->setPlaceholderText("Enter keyword to search");

    searchButton = new QPushButton("Search", this);

    resultLabel = new QLabel("Results will be shown here", this);
    resultLabel->setWordWrap(true);

    layout->addWidget(searchBox);
    layout->addWidget(searchButton);
    layout->addWidget(resultLabel);

    setLayout(layout);

    connect(searchButton, &QPushButton::clicked, this, &OverviewPage::onSearchClicked);
}

void OverviewPage::onSearchClicked() {
    QString keyword = searchBox->text().trimmed();

    if (keyword.isEmpty()) {
        resultLabel->setText("Please enter a keyword to search.");
        return;
    }

    Records results = searchDatabase("determinand_label", keyword);

    if (results.isEmpty()) {
        resultLabel->setText("No matching records found.");
        return;
    }

    auto [minResult, maxResult] = findResultRange(results);

    resultLabel->setText(QString(
        "Found %1 matching records.\n"
        "Max Result: %2\n"
        "Min Result: %3"
    ).arg(results.size()).arg(maxResult).arg(minResult));
}