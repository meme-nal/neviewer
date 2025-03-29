#include "mainwindow.h"
#include <QLabel>
#include <QPushButton>
#include <QMenu>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
  setWindowTitle("neviewer");
  resize(1280, 720); // 1280 x 720
  
  QLabel* label = new QLabel("Simple label", this);
  QPushButton* button = new QPushButton(this);
  button->setText("Click me");

  QMenu* menu = new QMenu();
  menu->addAction("Copy");
  menu->addAction("Cut");
  menu->addAction("Paste");
  button->setMenu(menu);

  QLineEdit* lineEdit = new QLineEdit(this);
  lineEdit->setGeometry(105, 5, 250, 250);

}

MainWindow::~MainWindow() {}
