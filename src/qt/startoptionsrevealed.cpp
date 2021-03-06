//
// Created by Kolby on 6/19/2019.
//

#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <startoptionsrevealed.h>
#include <ui_startoptionsrevealed.h>

StartOptionsRevealed::StartOptionsRevealed(std::vector<std::string> Words,
                                           int rows, QWidget *parent)
    : QWidget(parent), ui(new Ui::StartOptionsRevealed) {
    ui->setupUi(this);

    ui->seedLabel->setText(
        tr("The words below are your recovery phrase (mnemonic seed). Please "
           "write them down and/or securely save them. "));

    for (int i = 0; i < rows; i++) {
        for (int k = 0; k < 6; k++) {

            QLabel *label = new QLabel(this);
            label->setStyleSheet(
                "QLabel{background-color:transparent;padding-left:8px;padding-"
                "right:8px;border-radius:0px;color:#7578A2;border-bottom:2px "
                "solid #7578A2; text-align:center; font-size:18px;}");
            label->setMinimumSize(110, 50);
            label->setMaximumSize(110, 50);
            label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            label->setContentsMargins(8, 12, 8, 12);
            label->setAlignment(Qt::AlignCenter);
            labelsList.push_back(label);
            ui->gridLayoutRevealed->addWidget(label, i, k, Qt::AlignCenter);
        }
    }
    int i = 0;
    for (QLabel *label : labelsList) {
        label->setStyleSheet(
            "QLabel{background-color:transparent;padding-left:8px;padding-"
            "right:8px;border-radius:0px;color:#7578A2;border-bottom:2px solid "
            "#7578A2; text-align:center; font-size:18px;}");
        label->setContentsMargins(8, 12, 8, 12);
        label->setText(QString::fromStdString(Words[i]));
        i++;
    }
}

StartOptionsRevealed::~StartOptionsRevealed() {
    delete ui;
}
