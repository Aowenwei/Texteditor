#include "texteditor.h"
#include "./ui_texteditor.h"
texteditor::texteditor(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::texteditor) {
  ui->setupUi(this);
  group = new QActionGroup(this);
  this->setWindowTitle(tr("文本编辑器"));
  this->setWindowIcon(QIcon(":/image/font.png"));
}
texteditor::~texteditor() {
  delete ui;
  delete newMainWindow;
}

void texteditor::Menu() {
  editMenu = ui->menubar->addMenu(tr("文件(&F)")); //创建一个菜单栏
  //新建文件
  New_file = editMenu->addAction(QIcon(":/image/file.png"), tr("新建文件"));
  New_file->setShortcut(QKeySequence("Ctrl+N"));
  connect(New_file, &QAction::triggered, this, &texteditor::CreatFile);

  //打开文件操作
  Open_file = editMenu->addAction(QIcon(":/image/file.png"), tr("打开文件"));
  Open_file->setShortcut(QKeySequence("Ctrl+O"));
  connect(Open_file, &QAction::triggered, this, &texteditor::openFile);

  //保存文件操作
  editMenu->addSeparator(); //设置间隔期
  Save_file = editMenu->addAction(QIcon(":/image/save.png"), tr("保存文件"));
  Save_file->setShortcut(QKeySequence("Ctrl+S"));
  connect(Save_file, &QAction::triggered, this, &texteditor::save);

  //清空
  clear_file = editMenu->addAction(tr("清空"));
  connect(clear_file, &QAction::triggered, this,
          [this]() { ui->textEdit->clear(); });

  //退出
  editMenu->addSeparator(); //设置间隔期
  Close_file =
      editMenu->addAction(QIcon(":/image/exit.png"), tr("退出"));
  Close_file->setShortcut(QKeySequence("Ctrl+Q"));
  connect(Close_file, &QAction::triggered, this, [this]() { this->close(); });

  //格式， 设置一个QActionGroup类
  Format = ui->menubar->addMenu(tr("格式(&O)"));
  format = Format->addAction(QIcon(":/image/font.png"), tr("字体"));
  format->setShortcut(QKeySequence("Ctrl+F"));
  format->setCheckable(true); //设置选中状态
  connect(format, &QAction::triggered, this, &texteditor::set_font);

  //设置字体颜色
  fontColor = Format->addAction(QIcon(":/"), tr("字体颜色"));
  fontColor->setCheckable(true); //设置选中状态
  connect(fontColor, &QAction::triggered, this, &texteditor::set_fontcolor);

  //设置背景颜色
  backgroundcolor = Format->addAction(QIcon(":/ "), tr("背景颜色"));
  backgroundcolor->setCheckable(true); //设置选中状态
  connect(backgroundcolor, &QAction::triggered, this,
          &texteditor::setBackgroundcolor);
  Format->addSeparator(); //设置间隔期
  Format->addAction(format);
  Format->addAction(fontColor);
  Format->addAction(backgroundcolor);

  //关于
  Help = ui->menubar->addMenu(tr("帮助(&H)"));
  about_text = Help->addAction(QIcon(":/image/about.png"), tr("仅关于记事本"));
  about_text->setShortcut(QKeySequence("Ctrl+A"));
  connect(about_text, &QAction::triggered, this, &texteditor::about);
}

void texteditor::CreatFile() {
  newMainWindow = new texteditor;
  newMainWindow->show();
}

void texteditor::loadFile(QString filename) {
  QByteArray cpath = filename.toLocal8Bit();
  cout << "File name: " << cpath.data() << endl;
  QFile file(filename);
  if (file.open(QIODevice::ReadOnly | QIODevice ::Text)) {
    QTextStream textStream(&file);
    while (!textStream.atEnd()) {
      ui->textEdit->append(textStream.readLine());
      cout << "read line\n";
    }
    cout << "endl\n";
  }
}

void texteditor::openFile() {
  fileName = QFileDialog::getOpenFileName(this);
  if (!fileName.isEmpty()) {
    if (ui->textEdit->document()->isEmpty()) {
      loadFile(fileName);
    } else {
      newMainWindow = new texteditor;
      newMainWindow->show();
      newMainWindow->loadFile(fileName);
    }
  }
}

void texteditor::save() {
  QString path = QFileDialog::getSaveFileName(this, tr("打开文件"), ".",
                                              tr("文本文件(*.txt)"));
  if (!path.isEmpty()) {
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
      QMessageBox::warning(this, tr("保存文件"),
                           tr("不能打开文件:\n%1").arg(path));
      return;
    }
    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    file.close();
  } else {
    QMessageBox::warning(this, tr("Path"), tr("您没有选择任何文件."));
  }
}

void texteditor::about() {
  QMessageBox::information(this, tr("about"), tr("个人练习使用"),
                           QMessageBox::Ok);
}

void texteditor::set_font() {
  bool ok = false;
  QFont font = QFontDialog::getFont(&ok, this);
  if (ok) {
    ui->textEdit->setFont(font); //设置文本字体
  } else {
    cout << "not chose!";
  }
}

void texteditor::set_fontcolor() {
  QColor color = QColorDialog::getColor(Qt::red);
  QString sty = QString("color:%1").arg(color.name()); //动态获取字体颜色
  ui->textEdit->setStyleSheet(sty);                    //动态修改颜色
}

void texteditor::setBackgroundcolor() {
  QColor color = QColorDialog::getColor(Qt::red);
  QString sty =
      QString("background-color:%1").arg(color.name()); //动态获取背景颜色
  ui->textEdit->setStyleSheet(sty);                     //动态修改颜色
}