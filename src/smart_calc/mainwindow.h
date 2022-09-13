#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QTimer>

#ifdef __cplusplus
extern "C" {
#endif

#include "s21_calc.h"

#ifdef __cplusplus
}
#endif

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  double xBegin, xEnd, h, X;
  int N;

  QVector<double> x, y;
  QTimer *timer; // создание объекта
  int time; // создание переменной

 private slots:
  void digits_numbers();
  void on_pushButton_dot_clicked();
  void operations();
  void math_operations();
  void on_pushButton_clear_clicked();
  void on_pushButton_result_clicked();
  void braces_buttons();
  void trigeometry_operations();
  void on_pushButton_build_graphic_clicked();
  void TimerSlot();
};
#endif  // MAINWINDOW_H
