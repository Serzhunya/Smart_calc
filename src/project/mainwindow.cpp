#include "mainwindow.h"

#include <locale.h>

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  setlocale(LC_ALL, "");
  setlocale(LC_ALL, "en_US.UTF-8");
  ui->setupUi(this);
  ui->widget->addGraph();
  ui->spinBox_min->setMinimum(-1000000);
  ui->spinBox_max->setMinimum(-1000000);
  ui->spinBox_min->setMaximum(1000000);
  ui->spinBox_max->setMaximum(1000000);
  ui->spinBox_x->setMinimum(-1000000);
  ui->spinBox_x->setMaximum(1000000);
  ui->spinBox_min->setValue(-10);
  ui->spinBox_max->setValue(10);
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui->pushButton_sum, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui->pushButton_scale, SIGNAL(clicked()), this,
          SLOT(math_operations()));
  connect(ui->pushButton_opened_brace, SIGNAL(clicked()), this,
          SLOT(braces_buttons()));
  connect(ui->pushButton_closed_brace, SIGNAL(clicked()), this,
          SLOT(braces_buttons()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this,
          SLOT(trigeometry_operations()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(trigeometry_operations()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(trigeometry_operations()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this,
          SLOT(trigeometry_operations()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(trigeometry_operations()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this,
          SLOT(trigeometry_operations()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this,
          SLOT(trigeometry_operations()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(trigeometry_operations()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this,
          SLOT(trigeometry_operations()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::digits_numbers() {
  QPushButton *button = (QPushButton *)(sender());
  QString new_label;
  check_dot += button->text();
  if (ui->label->text() != "0") {
    new_label = ui->label->text() + button->text();
    input_real = input_real + button->text();
  } else {
    new_label = button->text();
    input_real = button->text();
  }
  ui->label->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked() {
  QPushButton *button = (QPushButton *)(sender());
  if (!check_dot.contains('.')) {
    ui->label->setText(ui->label->text() + ".");
    input_real = input_real + ".";
  }
  check_dot += button->text();
}

void MainWindow::math_operations() {
  check_dot = 0;
  bool isNotPressedOperatorLast = true;
  QPushButton *button = (QPushButton *)sender();
  QString input_check = ui->label->text();
  QString array[] = {"+", "-", "/", "*", "mod"};
  for (int i = 0; i < 5; i++) {
    if (input_check.endsWith(array[i])) {
      isNotPressedOperatorLast = false;
      break;
    }
  }
  if (isNotPressedOperatorLast) {
    if (ui->label->text() != "0") {
      ui->label->setText(ui->label->text() + button->text());
    } else {
      ui->label->setText("0" + button->text());
    }
    if (button->text() == "mod") {
      input_real = input_real + "m";
    } else {
      if (ui->label->text() != "0") {
        input_real = input_real + button->text();
      } else {
        input_real = button->text();
      }
    }
  }
}

void MainWindow::on_pushButton_clear_clicked() {
  ui->label->setText("0");
  ui->label_2->setText("0");
  ui->spinBox_x->setValue(0);
  ui->spinBox_min->setValue(-10);
  ui->spinBox_max->setValue(10);
  input_real = "0";
  isClickedX = false;
  ui->widget->graph(0)->data()->clear();
  check_dot = 0;
  x.clear();
  y.clear();
}

void MainWindow::on_pushButton_result_clicked() {
  QString text = input_real;
  if (isClickedX) {
    std::string X = std::to_string(ui->spinBox_x->value());
    std::string input_real_string = change_X(X);
    text = QString::fromStdString(input_real_string);
  }
  QByteArray str_bit = text.toLocal8Bit();
  char *input_str = str_bit.data();
  int code = validation(input_str);

  if (code) {
    ui->label_2->setText("Error");
  } else {
    double output = calc(input_str);
    QString str_output = QString::number(output, 'g', 10);
    ui->label_2->setText(str_output);
  }
}

void MainWindow::braces_buttons() {
  check_dot = 0;
  QPushButton *button = (QPushButton *)sender();
  if (ui->label->text() != "0") {
    ui->label->setText(ui->label->text() + button->text());
    input_real = input_real + button->text();
  } else {
    ui->label->setText(button->text());
    input_real = button->text();
  }
}

void MainWindow::trigeometry_operations() {
  check_dot = 0;
  QPushButton *button = (QPushButton *)sender();
  button->setChecked(true);
  if (button->text() == "sin") {
    if (ui->label->text() != "0") {
      input_real = input_real + "s(";
    } else {
      input_real = "s(";
    }
  }
  if (button->text() == "cos") {
    if (ui->label->text() != "0") {
      input_real = input_real + "c(";
    } else {
      input_real = "c(";
    }
  }
  if (button->text() == "tan") {
    if (ui->label->text() != "0") {
      input_real = input_real + "t(";
    } else {
      input_real = "t(";
    }
  }
  if (button->text() == "acos") {
    if (ui->label->text() != "0") {
      input_real = input_real + "a(";
    } else {
      input_real = "a(";
    }
  }
  if (button->text() == "asin") {
    if (ui->label->text() != "0") {
      input_real = input_real + "i(";
    } else {
      input_real = "i(";
    }
  }
  if (button->text() == "atan") {
    if (ui->label->text() != "0") {
      input_real = input_real + "n(";
    } else {
      input_real = "n(";
    }
  }
  if (button->text() == "sqrt") {
    if (ui->label->text() != "0") {
      input_real = input_real + "q(";
    } else {
      input_real = "q(";
    }
  }
  if (button->text() == "ln") {
    if (ui->label->text() != "0") {
      input_real = input_real + "l(";
    } else {
      input_real = "l(";
    }
  }
  if (button->text() == "log") {
    if (ui->label->text() != "0") {
      input_real = input_real + "o(";
    } else {
      input_real = "o(";
    }
  }
  if (ui->label->text() != "0") {
    ui->label->setText(ui->label->text() + button->text() + '(');
  } else {
    ui->label->setText(button->text() + "(");
  }
}

void MainWindow::create_graph() {
  ui->widget->graph(0)->data()->clear();
  x.clear();
  y.clear();
  QString text = input_real;
  if (isClickedX) {
    std::string X = std::to_string(ui->spinBox_x->value());
    std::string input_real_string = change_X(X);
    text = QString::fromStdString(input_real_string);
  }
  QByteArray graph_bit = text.toLocal8Bit();
  char *graph_str = graph_bit.data();
  double output;
  int min = ui->spinBox_min->value();
  int max = ui->spinBox_max->value();
  int code = validation(graph_str);
  if (code == 1) {
    ui->label_2->setText("Error");
  } else {
    for (X = min; X <= max; X += 0.01) {
      x.push_back(X);
      output = create_graphic(graph_str, sign_st, X);
      y.push_back(output);
    }
    ui->widget->xAxis->setRange(min, max);
    ui->widget->yAxis->setRange(min, max);
    ui->widget->graph(0)->setPen(QColor(Qt::black));
    ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget->graph(0)->setScatterStyle(
        QCPScatterStyle(QCPScatterStyle::ssDisc, 1));
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();
    if (max || min) {
      ui->label_2->setText("Graph is build");
    }
  }
}

void MainWindow::on_pushButton_funx_clicked() {
  QPushButton *button = (QPushButton *)(sender());
  QString new_label;
  if (ui->label->text() != "0") {
    new_label = ui->label->text() + button->text();
    input_real = input_real + button->text();
  } else {
    new_label = button->text();
    input_real = button->text();
  }
  ui->label->setText(new_label);
}

void MainWindow::on_pushButton_build_graph_clicked() { create_graph(); }

void MainWindow::on_pushButton_X_clicked() {
  QString new_label;
  if (ui->label->text() != "0") {
    new_label = ui->label->text() + "X";
    input_real = input_real + "X";
  } else {
    new_label = "X";
    input_real = "X";
  }
  isClickedX = true;
  ui->label->setText(new_label);
}

std::string MainWindow::change_X(std::string X) {
  std::string input_real_string = "";
  input_real_string = input_real.toStdString();
  size_t pos = 0;
  for (;;) {
    pos = input_real_string.find("X", pos);
    if (pos == std::string::npos) break;
    input_real_string.replace(pos, 1, X);
    pos += X.size();
  }

  return input_real_string;
}

void MainWindow::on_pushButton_backspace_clicked() {
  if (ui->label->text().endsWith("X")) {
    isClickedX = false;
  }
  if (ui->label->text().endsWith(".")) {
    check_dot = "";
  }
  bool endsArray3char = false;
  bool endsArray4char = false;
  QString array3char[] = {"cos", "sin", "log", "tan", "mod"};
  QString array4char[] = {"acos", "asin", "atan", "sqrt"};
  for (int i = 0; i < 4; i++) {
    if (ui->label->text().endsWith(array4char[i])) {
      endsArray4char = true;
      break;
    }
  }
  for (int i = 0; i < 5; i++) {
    if (ui->label->text().endsWith(array3char[i])) {
      endsArray3char = true;
      break;
    }
  }
  if (endsArray4char) {
    ui->label->setText(ui->label->text().chopped(4));
  } else if (endsArray3char) {
    ui->label->setText(ui->label->text().chopped(3));
  } else if (ui->label->text().endsWith("ln")) {
    ui->label->setText(ui->label->text().chopped(2));
  } else {
    ui->label->setText(ui->label->text().chopped(1));
  }
  input_real = input_real.chopped(1);
}
