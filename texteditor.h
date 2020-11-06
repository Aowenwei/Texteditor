#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H
#include <QAction>     //动作类
#include <QFile>       //文件操作
#include <QFileDialog> //文件对话框
#include <QMainWindow>
#include <QMessageBox>
#include <QTextStream>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

QT_BEGIN_NAMESPACE
namespace Ui {
class texteditor;
}
QT_END_NAMESPACE

class texteditor : public QMainWindow {
  Q_OBJECT

public:
  texteditor(QWidget *parent = nullptr);
  ~texteditor();
  void Menu();

private slots:
  void CreatFile();
  void loadFile(QString filename);
  void openFile();
  void closes();
  void save();
  void about();

private:
  Ui::texteditor *ui;
  QMenu *editMenu;
  QMenu *Help;
  QString fileName;
  QActionGroup *group;
  texteditor *newMainWindow; //创建新的窗口
  QAction *New_file, *Open_file, *close_file, *save_file;
  QAction *about_text;
};
#endif // TEXTEDITOR_H
