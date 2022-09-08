#include "mainwindow.h"
#include "./ui_mainwindow.h"

Stack_sign sign_st;
Stack_digit digit_st;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));

    connect(ui->pushButton_plus_minus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_percent,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_div,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_mul,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_sum,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_sub,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_opened_brace,SIGNAL(clicked()),this,SLOT(braces_buttons()));
    connect(ui->pushButton_closed_brace,SIGNAL(clicked()),this,SLOT(braces_buttons()));

    connect(ui->pushButton_cos,SIGNAL(clicked()),this,SLOT(trigeometry_operations()));
    connect(ui->pushButton_acos,SIGNAL(clicked()),this,SLOT(trigeometry_operations()));
    connect(ui->pushButton_sqrt,SIGNAL(clicked()),this,SLOT(trigeometry_operations()));
    connect(ui->pushButton_sin,SIGNAL(clicked()),this,SLOT(trigeometry_operations()));
    connect(ui->pushButton_asin,SIGNAL(clicked()),this,SLOT(trigeometry_operations()));
    connect(ui->pushButton_ln,SIGNAL(clicked()),this,SLOT(trigeometry_operations()));
    connect(ui->pushButton_tan,SIGNAL(clicked()),this,SLOT(trigeometry_operations()));
    connect(ui->pushButton_atan,SIGNAL(clicked()),this,SLOT(trigeometry_operations()));
    connect(ui->pushButton_log,SIGNAL(clicked()),this,SLOT(trigeometry_operations()));

    ui->pushButton_div->setCheckable(false);
    ui->pushButton_mul->setCheckable(false);
    ui->pushButton_sum->setCheckable(false);
    ui->pushButton_sub->setCheckable(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton*)(sender());
    QString new_label;
    if(!(ui->label->text() == "0")) {
        new_label = ui->label->text() + button->text();
    } else {
        new_label = button->text();
    }
    ui->label->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!ui->label->text().contains('.')) {
        ui->label->setText(ui->label->text() + ".");
    }
}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton*)sender();
    double numbers;
    QString new_label;
    if (button->text() == "+/-") {
        numbers = (ui->label->text()).toDouble();
        numbers = numbers * -1;
        new_label = QString::number(numbers, 'g', 15);
        ui->label->setText(new_label);
    }
    else if (button->text() == "%") {
        numbers = (ui->label->text()).toDouble();
        numbers = numbers * 0.01;
        new_label = QString::number(numbers, 'g', 15); // преобразование в строку
        ui->label->setText(new_label);
    }
}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *)sender(); //  возвращает указатель на объект, пославший сигнал
    button->setChecked(true);
    ui->label->setText(ui->label->text() + button->text());
}

void MainWindow::on_pushButton_clear_clicked()
{
    ui->pushButton_div->setCheckable(false);
    ui->pushButton_mul->setCheckable(false);
    ui->pushButton_sum->setCheckable(false);
    ui->pushButton_sub->setCheckable(false);
    ui->label->setText("0");
    ui->label_2->setText("0");
}

void MainWindow::on_pushButton_result_clicked()
{
    QString text = ui->label->text();
    ui->label_2->setText(text);
    QByteArray str_bit =  text.toLocal8Bit(); // Преобразование QString в StringQByteArray
    char *input_str = str_bit.data();
    char* polish_notation = create_polish_notation(input_str, sign_st);
    double output = create_output(polish_notation, sign_st, digit_st);
    QString str_output = QString::number(output);
    ui->label->setText(str_output);
}

void MainWindow::braces_buttons()
{
    QPushButton *button = (QPushButton *)sender();
    button->setChecked(true);
    ui->label->setText(ui->label->text() + button->text());
}

void MainWindow::trigeometry_operations()
{
    QPushButton *button = (QPushButton *)sender(); //  возвращает указатель на объект, пославший сигнал
    button->setChecked(true);
    ui->label->setText(ui->label->text()  + button->text() + '(');
}
