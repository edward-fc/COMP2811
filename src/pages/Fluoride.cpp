#include "Fluoride.hpp"
#include <QVBoxLayout>
#include <QLabel>

FluoridePage::FluoridePage(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);

    QLabel* label = new QLabel("Welcome to the Fluoride Page", this);
    label->setAlignment(Qt::AlignCenter);

    layout->addWidget(label);
}