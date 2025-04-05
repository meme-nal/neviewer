#include "mainwindow.h"
#include "forms/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setWindowTitle("neviewer");

  // run process
  connect(ui->pushButton_run, &QPushButton::clicked, this, &MainWindow::run);

  // find file
  connect(ui->pushButton_browse, &QPushButton::clicked, this, &MainWindow::on_pushButton_browse_clicked);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::run() {
  _filePath = ui->lineEdit_filepath->text();
  QMessageBox msg;
  msg.setText(_filePath);
  msg.exec();
}

void MainWindow::on_pushButton_browse_clicked() {
  QString filePath = QFileDialog::getOpenFileName(this, tr("Select File"), QCoreApplication::applicationDirPath(), tr("Signal Files(*.edf *.fif *.txt)"));
  ui->lineEdit_filepath->setText(filePath);
}
