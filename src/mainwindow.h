#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QScrollBar>

#include <QMessageBox>

#include <QString>
#include <QList>
#include <QMap>

#include <QTextStream>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QFile>
#include <QFileDialog>
#include <QDataStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
private:
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  signals:

  public slots:
    void run();
    void on_pushButton_browse_clicked();

private:
  QString _filePath;

  Ui::MainWindow* ui;

};
#endif // MAINWINDOW_H
