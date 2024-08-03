#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "power_both.h"
#include "power.h"
#include "qvalidator.h"
#include <QEvent>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString str,str1,str2;
public slots:
    void on_pushButton_clicked();
    void on_changed();
    void on_clicked();
signals:
public:
    Ui::MainWindow *ui;
    QDoubleValidator m_doubleValidator;
    Difference_of_squares *dif;
    Data_processing *data;
};
#endif // MAINWINDOW_H
