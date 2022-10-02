#include "mainwindow.h"

#include "./ui_mainwindow.h"

Stack_sign sign_st;
//Stack_digit digit_st;
QString check_dot;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  // h = 0.1;
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

  connect(ui->pushButton_plus_minus, SIGNAL(clicked()), this,
          SLOT(operations()));
  connect(ui->pushButton_percent, SIGNAL(clicked()), this, SLOT(operations()));
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
  QString new_label_2;
  check_dot += button->text();
  if (ui->label->text() != "0") {
    new_label = ui->label->text() + button->text();
  } else {
    new_label = button->text();
  }
  ui->label->setText(new_label);
  if (ui->label_2->text() != "0") {
    new_label_2 = ui->label_2->text() + button->text();
  } else {
    new_label_2 = button->text();
  }
  ui->label_2->setText(new_label_2);
}

void MainWindow::on_pushButton_dot_clicked() {
  QPushButton *button = (QPushButton *)(sender());
  if (!check_dot.contains(',')) {
    ui->label->setText(ui->label->text() + ".");
  }
  if (!check_dot.contains(',')) {
    ui->label_2->setText(ui->label_2->text() + ".");
  }
  check_dot += button->text();
}

void MainWindow::operations() {
  QPushButton *button = (QPushButton *)sender();
  double numbers;
  double numbers_2;
  QString new_label;
  QString new_label_2;
  if (button->text() == "+/-") {
    numbers = (ui->label->text()).toDouble();
    numbers = numbers * -1;
    new_label = QString::number(numbers, 'g', 15);
    ui->label->setText(new_label);
  } else if (button->text() == "%") {
    numbers = (ui->label->text()).toDouble();
    numbers = numbers * 0.01;
    new_label = QString::number(numbers, 'g', 15);
    ui->label->setText(new_label);
  }
  if (button->text() == "+/-") {
    numbers_2 = (ui->label_2->text()).toDouble();
    numbers_2 = numbers_2 * -1;
    new_label_2 = QString::number(numbers_2, 'g', 15);
    ui->label_2->setText(new_label_2);
  } else if (button->text() == "%") {
    numbers_2 = (ui->label_2->text()).toDouble();
    numbers_2 = numbers_2 * 0.01;
    new_label_2 = QString::number(numbers_2, 'g', 15);
    ui->label_2->setText(new_label_2);
  }
}

void MainWindow::math_operations() {
  check_dot = 0;
  QPushButton *button = (QPushButton *)
      sender();  //  возвращает указатель на объект, пославший сигнал
  button->setChecked(true);
  if (ui->label->text() != "0") {
    ui->label->setText(ui->label->text() + button->text());
  } else {
    ui->label->setText(button->text());
  }
  if (button->text() == "mod") {
    ui->label_2->setText(ui->label_2->text() + "m");
  } 
  else {
    if (ui->label_2->text() != "0") {
      ui->label_2->setText(ui->label_2->text() + button->text());
    } else {
      ui->label_2->setText(button->text());
    }
  }
}

void MainWindow::on_pushButton_clear_clicked() {
  ui->label->setText("0");
  ui->label_2->setText("0");
  ui->widget->graph(0)->data()->clear();
  check_dot = 0;
  x.clear();
  y.clear();
}

void MainWindow::on_pushButton_result_clicked() {
  QString text = ui->label_2->text();
  QByteArray str_bit = text.toLocal8Bit();
  char *input_str = str_bit.data();
  int code = validation(input_str);
  if (code) {
    ui->label->setText("Error");
    ui->label_2->setText("Error");
  } else {
    double output = calc(input_str);
    QString str_output = QString::number(output);
    ui->label->setText(str_output);
    ui->label_2->setText(str_output);
  }
}

void MainWindow::braces_buttons() {
  check_dot = 0;
  QPushButton *button = (QPushButton *)sender();
  button->setChecked(true);
  if (ui->label->text() != "0") {
    ui->label->setText(ui->label->text() + button->text());
  } else {
    ui->label->setText(button->text());
  }
  if (ui->label_2->text() != "0") {
    ui->label_2->setText(ui->label_2->text() + button->text());
  } else {
    ui->label_2->setText(button->text());
  }
}

void MainWindow::trigeometry_operations() {
  check_dot = 0;
  QPushButton *button = (QPushButton *)sender();
  button->setChecked(true);
  if (button->text() == "sin") {
    if (ui->label_2->text() != "0") {
      ui->label_2->setText(ui->label_2->text() + "s(");
    } else {
      ui->label_2->setText("s(");
    }
  }
  if (button->text() == "cos") {
    if (ui->label_2->text() != "0") {
      ui->label_2->setText(ui->label_2->text() + "c(");
    } else {
      ui->label_2->setText("c(");
    }
  }
  if (button->text() == "tan") {
    if (ui->label_2->text() != "0") {
      ui->label_2->setText(ui->label_2->text() + "t(");
    } else {
      ui->label_2->setText("t(");
    }
  }
  if (button->text() == "acos") {
    if (ui->label_2->text() != "0") {
      ui->label_2->setText(ui->label_2->text() + "a(");
    } else {
      ui->label_2->setText("a(");
    }
  }
  if (button->text() == "asin") {
    if (ui->label_2->text() != "0") {
      ui->label_2->setText(ui->label_2->text() + "i(");
    } else {
      ui->label_2->setText("i(");
    }
  }
  if (button->text() == "atan") {
    if (ui->label_2->text() != "0") {
      ui->label_2->setText(ui->label_2->text() + "n(");
    } else {
      ui->label_2->setText("n(");
    }
  }
  if (button->text() == "sqrt") {
    if (ui->label_2->text() != "0") {
      ui->label_2->setText(ui->label_2->text() + "q(");
    } else {
      ui->label_2->setText("q(");
    }
  }
  if (button->text() == "ln") {
    if (ui->label_2->text() != "0") {
      ui->label_2->setText(ui->label_2->text() + "l(");
    } else {
      ui->label_2->setText("l(");
    }
  }
  if (button->text() == "log") {
    if (ui->label_2->text() != "0") {
      ui->label_2->setText(ui->label_2->text() + "o(");
    } else {
      ui->label_2->setText("o(");
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
  QString text = ui->label_2->text();
  QByteArray graph_bit = text.toLocal8Bit();
  char *graph_str = graph_bit.data();
  double output;
  int min = ui->spinBox_min->value();
  int max = ui->spinBox_max->value();
//  int code = validation(graph_str);
//  if (!code) {
//    output = create_graphic(graph_str, max, min);
//  }
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
    QString new_label_2;
    if (ui->label->text() != "0") {
      new_label = ui->label->text() + button->text();
    } else {
      new_label = button->text();
    }
    ui->label->setText(new_label);
    if (ui->label_2->text() != "0") {
      new_label_2 = ui->label_2->text() + button->text();
    } else {
      new_label_2 = button->text();
    }
    ui->label_2->setText(new_label_2);
}

void MainWindow::on_pushButton_build_graph_clicked()
{
    create_graph();
}
