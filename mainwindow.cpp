#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

double first_number{};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btn0, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->btn1, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->btn2, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->btn3, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->btn4, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->btn5, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->btn6, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->btn7, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->btn8, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->btn9, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->btnNegate, SIGNAL(clicked()), this, SLOT(operation()));
    connect(ui->btnPercent, SIGNAL(clicked()), this, SLOT(operation()));
    connect(ui->btnPlus, SIGNAL(clicked()), this, SLOT(math_operation()));
    connect(ui->btnMin, SIGNAL(clicked()), this, SLOT(math_operation()));
    connect(ui->btnMult, SIGNAL(clicked()), this, SLOT(math_operation()));
    connect(ui->btnDiv, SIGNAL(clicked()), this, SLOT(math_operation()));

    ui->btnPlus->setCheckable(true);
    ui->btnMin->setCheckable(true);
    ui->btnMult->setCheckable(true);
    ui->btnDiv->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_numbers()
{
    QPushButton *button = (QPushButton *) sender();

    double all_numbers;
    QString new_label;

    if(ui->lResult->text().contains(".") && button->text() == "0") {
        new_label = ui->lResult->text() + button->text();
    } else {
        all_numbers = (ui->lResult->text() + button->text()).toDouble();
        new_label = QString::number(all_numbers, 'g', 15);
    }

    ui->lResult->setText(new_label);
}

void MainWindow::on_btnDot_clicked()
{
    if(!ui->lResult->text().contains("."))
        ui->lResult->setText(ui->lResult->text() + ".");
}

void MainWindow::operation()
{
    QPushButton *button = (QPushButton *) sender();

    double all_numbers;
    QString new_label;

    if(button->text() == "+/-") {
        all_numbers = (ui->lResult->text()).toDouble() * -1;

        new_label = QString::number(all_numbers, 'g', 15);
        ui->lResult->setText(new_label);
    } else if(button->text() == "%") {
        all_numbers = (ui->lResult->text()).toDouble() * 0.01;

        new_label = QString::number(all_numbers, 'g', 15);
        ui->lResult->setText(new_label);
    }
}


void MainWindow::math_operation()
{
    QPushButton *button = (QPushButton *) sender();

    first_number = ui->lResult->text().toDouble();

    button->setChecked(true);
    ui->lResult->setText("");
}

void MainWindow::on_btnEqual_clicked()
{
    double result_number, second_number;
    QString new_label;

    second_number = ui->lResult->text().toDouble();

    if(ui->btnPlus->isChecked()) {
        result_number = first_number + second_number;
        new_label = QString::number(result_number, 'g', 15);

        ui->lResult->setText(new_label);
        ui->btnPlus->setChecked(false);
    } else if (ui->btnMin->isChecked()) {
        result_number = first_number - second_number;
        new_label = QString::number(result_number, 'g', 15);

        ui->lResult->setText(new_label);
        ui->btnMin->setChecked(false);
    } else if (ui->btnMult->isChecked()) {
        result_number = first_number * second_number;
        new_label = QString::number(result_number, 'g', 15);

        ui->lResult->setText(new_label);
        ui->btnMult->setChecked(false);
    } else if (ui->btnDiv->isChecked()) {
        if(second_number != 0) {
            result_number = first_number / second_number;
            new_label = QString::number(result_number, 'g', 15);

            ui->lResult->setText(new_label);
            ui->btnDiv->setChecked(false);
        } else {
            ui->lResult->setText("0");
            QMessageBox::warning(this, "Ошибка!", "Деление на 0!");
        }
    }


}


void MainWindow::on_btnClear_clicked()
{
    ui->lResult->setText("");

    ui->btnPlus->setChecked(false);
    ui->btnMin->setChecked(false);
    ui->btnMult->setChecked(false);
    ui->btnDiv->setChecked(false);
}

