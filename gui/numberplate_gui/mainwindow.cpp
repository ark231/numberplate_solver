#include "mainwindow.hpp"

#include <QString>

#include "./ui_mainwindow.h"
#include "numberplate_solver.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) { ui->setupUi(this); }

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
    int A = this->ui->spinBox_A->value();
    int B = this->ui->spinBox_B->value();
    int C = this->ui->spinBox_C->value();
    int D = this->ui->spinBox_D->value();
    QString type = ui->comboBox->currentText();
    ui->textEdit->setPlainText(type);
}
