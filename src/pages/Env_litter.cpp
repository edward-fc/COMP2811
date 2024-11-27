#include "Env_litter.hpp"
#include <QVBoxLayout>
#include <QLabel>

EnvPage::EnvPage(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);

    QLabel* label = new QLabel("Welcome to the Environment Litter Page", this);
    label->setAlignment(Qt::AlignCenter);

    layout->addWidget(label);
}