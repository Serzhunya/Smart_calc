#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QVector>
#include <QtMath>

extern "C" {
#include "s21_calc.h"
}


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
  QVector<double> x, y;
 private slots:
  void digits_numbers();
  void on_pushButton_dot_clicked();
  void operations();
  void math_operations();
  void on_pushButton_clear_clicked();
  void on_pushButton_result_clicked();
  void braces_buttons();
  void trigeometry_operations();
  void create_graph();
  void on_pushButton_funx_clicked();
  void on_pushButton_build_graph_clicked();
};
#endif  // MAINWINDOW_H