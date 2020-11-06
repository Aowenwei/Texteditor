#include "texteditor.h"
#include "./ui_texteditor.h"

texteditor::texteditor(QWidget *parent) : QMainWindow(parent), ui(new Ui::texteditor) {
  ui->setupUi(this);
  this->setWindowTitle(tr("文本编辑器"));


}

texteditor::~texteditor() {
  delete ui;
  delete newMainWindow;
}

void texteditor::Menu() {
  editMenu = ui->menubar->addMenu(tr("文件(&F)")); //创建一个菜单栏
  //新建文件
  New_file =
      editMenu->addAction(QIcon(":/image/file.png"), tr("新建文件"));
  New_file->setShortcut(QKeySequence("Ctrl+N"));
  connect(New_file, &QAction::triggered, this, &texteditor::CreatFile);
  //打开文件操作

  Open_file = editMenu->addAction(QIcon(":/image/file.png"),
                                  tr("打开文件"));
  Open_file->setShortcut(QKeySequence("Ctrl+O"));
  connect(Open_file, &QAction::triggered, this, &texteditor::openFile);

  //关闭文件操作
  close_file = editMenu->addAction(QIcon(":/image/closefile.png"),
                                   tr("关闭文件"));
  close_file->setShortcut(QKeySequence("Ctrl+Q"));
  connect(close_file, &QAction::triggered, this, &texteditor::closes);

  //保存文件操作
  save_file = editMenu->addAction(QIcon(":/image/save.png"),
                                  tr("保存文件"));
  save_file->setShortcut(QKeySequence("Ctrl+S"));
  connect(save_file, &QAction::triggered, this, &texteditor::save);

  //关于
  Help = ui->menubar->addMenu(tr("帮助(&H)"));
  about_text = Help->addAction(QIcon(":/image/about.png"),tr("仅关于记事本"));
  about_text->setShortcut(QKeySequence("Ctrl+A"));
  connect(about_text,&QAction::triggered,this,&texteditor::about);
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

void texteditor::closes() { this->close(); }

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
  QMessageBox::information(this,tr("about"),tr("个人练习使用"),QMessageBox::Ok);
}