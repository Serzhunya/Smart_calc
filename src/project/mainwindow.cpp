#include "mainwindow.h"

#include "./ui_mainwindow.h"

Stack_sign sign_st;
QString check_dot;
QString input_real;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->widget->addGraph();
  ui->spinBox_min->setMinimum(-1000000);
  ui->spinBox_max->setMinimum(-1000000);
  ui->spinBox_min->setMaximum(1000000);
  ui->spinBox_max->setMaximum(1000000);
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
  if (!check_dot.contains(',')) {
    ui->label->setText(ui->label->text() + ".");
    input_real = input_real + ".";
  }
  check_dot += button->text();
}

void MainWindow::math_operations() {
  check_dot = 0;
  QPushButton *button = (QPushButton *)
      sender();
  if (ui->label->text() != "0") {
    ui->label->setText(ui->label->text() + button->text());
  } else {
    ui->label->setText(button->text());
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

void MainWindow::on_pushButton_clear_clicked() {
  ui->label->setText("0");
  input_real = "0";
  ui->widget->graph(0)->data()->clear();
  check_dot = 0;
  x.clear();
  y.clear();
}

void MainWindow::on_pushButton_result_clicked() {
  QString text = input_real;
  QByteArray str_bit = text.toLocal8Bit();
  char *input_str = str_bit.data();
  int code = validation(input_str);
  if (code) {
    ui->label->setText("Error");
  } else {
    double output = calc(input_str);
    QString str_output = QString::number(output);
    ui->label->setText(str_output);
  }
}

void MainWindow::braces_buttons() {
  check_dot = 0;
  QPushButton *button = (QPushButton *)sender();
  button->setChecked(true);
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
      input_real = input_real +"a(";
    } else {
      input_real ="a(";
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
      input_real = input_real + + "l(";
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
  QString text = input_real;
  QByteArray graph_bit = text.toLocal8Bit();
  char *graph_str = graph_bit.data();
  double output;
  int min = ui->spinBox_min->value();
  int max = ui->spinBox_max->value();
  // int code = validation(graph_str);
  // if (!code) {
  //   output = create_graphic(graph_str, max, min);
  // } else {
  //   ui->label->setText("Error");
  // }
  for (X = min; X <= max; X += 0.1) {
    x.push_back(X);
    output = create_graphic(graph_str, sign_st, X);
    y.push_back(output);
  }
  ui->widget->graph(0)->addData(x, y);
  ui->widget->xAxis->setRange(min, max);
  ui->widget->yAxis->setRange(min, max);
  ui->widget->replot();
}

void MainWindow::on_pushButton_funx_clicked()
{
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

void MainWindow::on_pushButton_build_graph_clicked()
{
    create_graph();
}

