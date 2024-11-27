#include "Organic.hpp"
#include <QVBoxLayout>
#include <QLabel>

OrganicPage::OrganicPage(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);

    QLabel* label = new QLabel("Welcome to the Organic Page", this);
    label->setAlignment(Qt::AlignCenter);

    layout->addWidget(label);
}