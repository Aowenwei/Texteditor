#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H
#include <QAction>     //动作类
#include <QFile>       //文件操作
#include <QFileDialog> //文件对话框
#include <QColorDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QTextStream>
#include <iostream>
#include <QFontDialog>
#include <QLabel>
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
  void save();
  void about();
  void set_font();
  void set_fontcolor();
  void setBackgroundcolor();
private:
  Ui::texteditor *ui;
  QMenu *editMenu;
  QMenu *Help,*Format;
  QString fileName;
  QActionGroup *group;
  QLabel *label; //获取行号显示在左下角
  texteditor *newMainWindow; //创建新的窗口
  QAction *New_file, *Open_file, *Close_file, *Save_file, *clear_file;
  QAction *about_text ,*format, *fontColor, *backgroundcolor;
};
#endif // TEXTEDITOR_H
