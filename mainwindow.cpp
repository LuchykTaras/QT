#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_addButton_clicked(){
    QString task = ui->lineEdit->text();

    if (task.isEmpty()){
        ui->label->setText("Write a text!");
        return;
    }

    QListWidgetItem *item = new QListWidgetItem(task);
    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
    item->setCheckState(Qt::Unchecked);

    ui->listWidget->addItem(item);

    ui->lineEdit->clear();
    ui->label->setText("Added successfully!");
}
void MainWindow::on_deleteButton_clicked(){
    QListWidgetItem *item = ui->listWidget->currentItem();

    if (!item) {
        ui->label->setText("Select a task!");
        return;
    }

    delete ui->listWidget->takeItem(ui->listWidget->row(item));
    ui->label->setText("Deleted!");
}
