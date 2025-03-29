#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QMenu>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QCheckBox>
#include <QSpinBox>
#include <QComboBox>
#include <QSlider>
#include <QInputDialog>

class Widget : public QWidget {
private:
  Q_OBJECT

public:
  Widget(QWidget *parent = nullptr);
  ~Widget();

private:
  QLabel* _label;
  QRadioButton* _radbtn1;
  QRadioButton* _radbtn2;
  QRadioButton* _radbtn3;
  QLineEdit*    _ledit;

public slots:
  void ChangeText();
  void getMyItem();

};
#endif // MAINWINDOW_H
