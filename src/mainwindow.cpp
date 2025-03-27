#include "mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
  setWindowTitle("neviewer");
  resize(1280, 720);
  
  QLabel* label = new QLabel("Simple label", this);
  }

MainWindow::~MainWindow() {}
