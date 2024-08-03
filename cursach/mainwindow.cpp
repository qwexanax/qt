#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "power_both.h"
#include "power.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),m_doubleValidator(-999999999999, 999999999999, 99999999, this)
{
    ui->setupUi(this);
    dif = new Difference_of_squares;
    data = new Data_processing;

    m_doubleValidator.setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit->setValidator(&m_doubleValidator);
    ui->lineEdit_2->setValidator(&m_doubleValidator);
    ui->lineEdit_3->setValidator(&m_doubleValidator);
    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_changed()));
    connect(ui->lineEdit_2, SIGNAL(textChanged(QString)), this, SLOT(on_changed()));
    connect(ui->lineEdit_3, SIGNAL(textChanged(QString)), this, SLOT(on_changed()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_changed() {
    str = ui->lineEdit->text();
    str1 = ui->lineEdit_2->text();
    str2 = ui->lineEdit_3->text();
}

void MainWindow::on_clicked() {
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    if(ui->lineEdit->text().isEmpty() && ui->lineEdit_2->text().isEmpty() && ui->lineEdit_3->text().isEmpty()){
        ui->lineEdit->setText("0");
        ui->lineEdit_2->setText("0");
        ui->lineEdit_3->setText("0");
        ui->lineEdit_6->setText("Все поля пустые");
        ui->lineEdit_4->setText("0");
        ui->lineEdit_5->setText("0");
    }
    else if(!ui->lineEdit->text().isEmpty() && !ui->lineEdit_2->text().isEmpty() && ui->lineEdit_3->text().isEmpty()){
        on_changed();
        dif->field_formation(str,str1);
        ui->lineEdit_5->setText("-");
        ui->lineEdit_6->setText("Одно из полей пустое");
        ui->lineEdit_4->setText(QString::number(dif->field_processing()));
    }
    else if(ui->lineEdit->text().isEmpty()){
        ui->lineEdit->setText("0");
        ui->lineEdit_6->setText("Одно из полей пустое");
    }
    else if(ui->lineEdit_2->text().isEmpty()){
        ui->lineEdit_2->setText("0");
        ui->lineEdit_6->setText("Одно из полей пустое");
    }
    else if(ui->lineEdit_3->text().isEmpty()){
        ui->lineEdit_3->setText("0");
        ui->lineEdit_6->setText("Одно из полей пустое");
    }
    else {
    on_changed();
    str.replace(",", ".");str1.replace(",", ".");str2.replace(",", ".");
    dif->field_formation(str,str1);
    data->field_formation2(str,str1,str2);
    ui->lineEdit_4->setText(QString::number(dif->field_processing()));
    ui->lineEdit_5->setText(QString::number(data->data_adaptation()));
    ui->lineEdit_6->setText("все правильно =(");
    }
}

void MainWindow::on_pushButton_clicked()
{
}

