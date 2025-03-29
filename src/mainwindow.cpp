#include "mainwindow.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent) {
  setWindowTitle("neviewer");
  resize(1280, 720); // 1280 x 720

  /*
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
  */

  /*
  QPushButton* btn1 = new QPushButton(this);
  btn1->setText("Change text");
  connect(btn1, SIGNAL(clicked()), this, SLOT(ChangeText()));

  _label = new QLabel(this);
  _label->setText("Hello");

  QHBoxLayout* hbox = new QHBoxLayout(this);
  hbox->addWidget(btn1);
  hbox->addWidget(_label); 
  */

  /*
  QHBoxLayout* hbox = new QHBoxLayout(this);

  _radbtn1 = new QRadioButton(this);
  _radbtn1->setText("Python");

  _radbtn2 = new QRadioButton(this);
  _radbtn2->setText("C++");

  _radbtn3 = new QRadioButton(this);
  _radbtn3->setText("Java");

  hbox->addWidget(_radbtn1);
  hbox->addWidget(_radbtn2);
  hbox->addWidget(_radbtn3);
  */

  /*
  QHBoxLayout* hbox = new QHBoxLayout(this);
  QCheckBox* chbox = new QCheckBox(this);
  chbox->setText("Use filter");

  hbox->addWidget(chbox);
  */

  /*
  QHBoxLayout* hbox = new QHBoxLayout(this);
  QLabel* label = new QLabel(this);
  label->setText("Frequency: ");

  QLineEdit* ledit1 = new QLineEdit(this);
  QSpinBox* spinbox = new QSpinBox(this);
  QLineEdit* ledit2 = new QLineEdit(this);

  hbox->addWidget(label);
  hbox->addWidget(ledit1);
  hbox->addWidget(spinbox);
  hbox->addWidget(ledit2);
  */

  /*
  QHBoxLayout* hbox = new QHBoxLayout(this);
  QLabel* label = new QLabel(this);
  label->setText("Signal type:    ");

  QComboBox* signalTypes = new QComboBox(this);
  signalTypes->addItem("EEG");
  signalTypes->addItem("ECG");
  signalTypes->addItem("EMG");
  
  hbox->addWidget(label);
  hbox->addWidget(signalTypes);
  */

  /*
  QHBoxLayout* hbox = new QHBoxLayout(this);
  QSlider* slider = new QSlider(this);
  slider->setOrientation(Qt::Horizontal);

  hbox->addWidget(slider);
  */

  QHBoxLayout* hbox = new QHBoxLayout(this);
  QLabel* label = new QLabel(this);
  label->setText("Choose languages: ");

  _ledit = new QLineEdit(this);
  QPushButton* btn = new QPushButton(this);
  btn->setText("Choose language");
  connect(btn, SIGNAL(clicked()), this, SLOT(getMyItem()));

  QScrollBar* scrollbar = new QScrollBar(this);
  scrollbar->setOrientation(Qt::Vertical);

  hbox->addWidget(label);
  hbox->addWidget(_ledit);
  hbox->addWidget(btn);
  hbox->addWidget(scrollbar);
  
}

Widget::~Widget() {}

void Widget::ChangeText() {
  _label->setText("This is changed");
}

void Widget::getMyItem() {
  QList<QString> languages = {"C++", "Python", "Java", "C#"};
  QString text = QInputDialog::getItem(this, "InputDialog", "List of languages", languages, 0, false);
  if (!text.isEmpty()) {
    _ledit->setText(text);
  }
}