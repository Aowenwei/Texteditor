#include "texteditor.h"
#include "./ui_texteditor.h"
texteditor::texteditor(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::texteditor) {
  ui->setupUi(this);
  group = new QActionGroup(this);
  this->setWindowTitle(tr("文本编辑器"));
  this->setWindowIcon(QIcon(":/image/font.png"));
  Menu();
  Creatslots();
}
texteditor::~texteditor() {
  delete ui;
  delete newMainWindow;
}

void texteditor::Creatslots() {
  //菜单 --- 文件
  connect(menu_file_New, &QAction::triggered, this,&texteditor::slot_menu_Newfile);
  connect(menu_file_Open, &QAction::triggered, this,&texteditor::slot_menu_Openfile);
  connect(menu_file_Save, &QAction::triggered, this,&texteditor::slot_menu_Savefile);
  connect(menu_file_Clear, &QAction::triggered, this,[this]() { ui->textEdit->clear(); });
  connect(menu_file_Close, &QAction::triggered, this,[this]() { this->close(); });

  //菜单 --- 编辑
  connect(menu_edit_undo, &QAction::triggered, this,[this](){ui->textEdit->undo();}); //使用QTextEdit自带的槽函数
  connect(menu_edit_cut, &QAction::triggered, this, [this](){ui->textEdit->cut();});
  connect(menu_edit_copy, &QAction::triggered, this,[this](){ui->textEdit->copy();});
  connect(menu_edit_paste, &QAction::triggered, this,[this](){ui->textEdit->paste();});
  connect(menu_edit_all, &QAction::triggered, this,[this](){ui->textEdit->selectAll();});
  connect(menu_edit_delete, &QAction::triggered, this, [this]() {ui->textEdit->cut();Clipboard->setText(" ");});

  //菜单 --- 格式
  connect(menu_format_font, &QAction::triggered, this,
          &texteditor::slot_menu_Setfont);
  connect(menu_format_backgroundcolor, &QAction::triggered, this,
          &texteditor::slot_menu_Backgroundcolor);
  connect(menu_format_fontColor, &QAction::triggered, this,
          &texteditor::slot_menu_fontcolor);

  //菜单 --- 关于
  connect(menu_help_about, &QAction::triggered, this,
          &texteditor::slot_menu_About);

  //判断文本框是否变更
  connect(ui->textEdit, &QTextEdit::cursorPositionChanged, this,
          &texteditor::slot_cursor_chang_state);
}

void texteditor::Menu() {
  //添加菜单栏 --文件
  menu_file = ui->menubar->addMenu(tr("文件(&F)")); //创建一个菜单栏
  menu_file_New =
      menu_file->addAction(QIcon(":/image/file.png"), tr("新建文件"));
  menu_file_New->setShortcut(QKeySequence("Ctrl+N"));

  menu_file_Open =
      menu_file->addAction(QIcon(":/image/file.png"), tr("打开文件"));
  menu_file_Open->setShortcut(QKeySequence("Ctrl+O"));

  menu_file->addSeparator(); //设置间隔期
  menu_file_Save =
      menu_file->addAction(QIcon(":/image/save.png"), tr("保存文件"));
  menu_file_Save->setShortcut(QKeySequence("Ctrl+S"));

  menu_file_Clear = menu_file->addAction(tr("清空"));

  menu_file->addSeparator(); //设置间隔期
  menu_file_Close = menu_file->addAction(QIcon(":/image/exit.png"), tr("退出"));
  menu_file_Close->setShortcut(QKeySequence("Ctrl+Q"));

  //添加菜单栏 --编辑
  menu_edit = ui->menubar->addMenu(tr("编辑(&E)"));
  menu_edit_undo = menu_edit->addAction(QIcon(":/"), tr("撤销"));
  menu_edit_undo->setShortcut(QKeySequence::Undo);
  menu_edit_undo->setEnabled(false);
  menu_edit->addSeparator();

  menu_edit_cut = menu_edit->addAction(QIcon(":/"), tr("剪切"));
  menu_edit_cut->setShortcut(QKeySequence::Cut);
  menu_edit_cut->setEnabled(false);

  menu_edit_copy = menu_edit->addAction(QIcon(":/"), tr("复制"));
  menu_edit_copy->setShortcut(QKeySequence::Copy);
  menu_edit_copy->setEnabled(false);

  menu_edit_paste = menu_edit->addAction(QIcon(":/"), tr("粘贴"));
  menu_edit_paste->setShortcut(QKeySequence::Paste);

  menu_edit_delete = menu_edit->addAction(QIcon(":/"), tr("删除"));
  menu_edit_delete->setShortcut(QKeySequence::Delete);
  menu_edit_delete->setEnabled(false);
  menu_edit_delete->setShortcut(QKeySequence::Delete);
  menu_edit->addSeparator();

  menu_edit_all = menu_edit->addAction(QIcon(":/"), tr("全选"));
  menu_edit_all->setShortcut(QKeySequence::SelectAll);
  menu_edit_all->setEnabled(false);

  //添加菜单栏 --格式 设置一个QActionGroup类
  menu_format = ui->menubar->addMenu(tr("格式(&O)"));
  menu_format_font =
      menu_format->addAction(QIcon(":/image/font.png"), tr("字体"));
  menu_format_font->setShortcut(QKeySequence("Ctrl+F"));
  menu_format_font->setCheckable(true); //设置选中状态

  menu_format_fontColor = menu_format->addAction(QIcon(":/"), tr("字体颜色"));
  menu_format_fontColor->setCheckable(true); //设置选中状态

  menu_format_backgroundcolor =
      menu_format->addAction(QIcon(":/ "), tr("背景颜色"));
  menu_format_backgroundcolor->setCheckable(true); //设置选中状态

  menu_format->addSeparator(); //设置间隔期
  menu_format->addAction(menu_format_font);
  menu_format->addAction(menu_format_fontColor);
  menu_format->addAction(menu_format_backgroundcolor);

  //添加菜单栏 --关于
  menu_help = ui->menubar->addMenu(tr("帮助(&H)"));
  menu_help_about =
      menu_help->addAction(QIcon(":/image/about.png"), tr("关于记事本"));
  menu_help_about->setShortcut(QKeySequence("Ctrl+A"));
}

void texteditor::slot_menu_Newfile() {
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

void texteditor::slot_menu_Openfile() {
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

void texteditor::slot_menu_Savefile() {
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

void texteditor::slot_menu_About() {
  QMessageBox::information(this, tr("About"),
                           tr("开发者: "
                              "敖文伟\nQQ:790879586\n时间：2020/11/"
                              "7\n说明:仅个人学习使用\nversion:1.0 "),
                           QMessageBox::Ok);
}

void texteditor::slot_menu_Setfont() {
  bool ok = false;
  QFont font = QFontDialog::getFont(&ok, this);
  if (ok) {
    ui->textEdit->setFont(font); //设置文本字体
  } else {
    cout << "not chose!";
  }
}

void texteditor::slot_menu_fontcolor() {
  QColor color = QColorDialog::getColor(Qt::red);
  QString sty = QString("color:%1").arg(color.name()); //动态获取字体颜色
  ui->textEdit->setStyleSheet(sty);                    //动态修改颜色
}

void texteditor::slot_menu_Backgroundcolor() {
  QColor color = QColorDialog::getColor(Qt::red);
  QString sty =
      QString("background-color:%1").arg(color.name()); //动态获取背景颜色
  ui->textEdit->setStyleSheet(sty);                     //动态修改颜色
}

void texteditor::slot_cursor_chang_state() {
  int pos = 0;
  pos = ui->textEdit->textCursor().position();
  QString sbar_str = QString("第 %1 个字符").arg(pos);
  ui->statusbar->showMessage(sbar_str);
}