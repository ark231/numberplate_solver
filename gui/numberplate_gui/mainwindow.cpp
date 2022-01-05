#include "mainwindow.hpp"

#include <QDebug>
#include <QString>
#include <sstream>

#include "./ui_mainwindow.h"
#include "numberplate_solver.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) { ui->setupUi(this); }

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
    int A = this->ui->spinBox_A->value();
    int B = this->ui->spinBox_B->value();
    int C = this->ui->spinBox_C->value();
    int D = this->ui->spinBox_D->value();
    auto type = ui->comboBox->currentText();
    auto solutions = numberplate::solve_numberplate(A, B, C, D, 10, false, true);
    std::string output;
    for (const auto &solution : solutions) {
        output += solution + "\n";
    }
    ui->textEdit->setPlainText(QString::fromStdString(output));
}
