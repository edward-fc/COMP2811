#include "Compliance.hpp"
#include <QVBoxLayout>
#include <QLabel>

CompliancePage::CompliancePage(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);

    QLabel* label = new QLabel("Welcome to the Compliance Page", this);
    label->setAlignment(Qt::AlignCenter);

    layout->addWidget(label);
}