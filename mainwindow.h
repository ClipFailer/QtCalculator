#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digit_numbers();
    void on_btnDot_clicked();
    void operation();
    void math_operation();
    void on_btnEqual_clicked();
    void on_btnClear_clicked();
};
#endif // MAINWINDOW_H
