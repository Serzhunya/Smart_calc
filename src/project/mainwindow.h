#ifndef SRC_PROJECT_MAINWINDOW_H_
#define SRC_PROJECT_MAINWINDOW_H_

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
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  Stack_sign sign_st;
  QString check_dot, input_real, value_X;
  bool isClickedX = false;
  std::string input_real_string;
  double X;
  QVector<double> x, y;
 private slots:
  void digits_numbers();
  void on_pushButton_dot_clicked();
  void math_operations();
  void on_pushButton_clear_clicked();
  void on_pushButton_result_clicked();
  void braces_buttons();
  void trigeometry_operations();
  void create_graph();
  void on_pushButton_funx_clicked();
  void on_pushButton_build_graph_clicked();
  void on_pushButton_X_clicked();
  std::string change_X(std::string X);
  void on_pushButton_backspace_clicked();
};
#endif  // SRC_PROJECT_MAINWINDOW_H_
