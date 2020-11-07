#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H
#include <QAction>    //动作类
#include <QClipboard> //剪切板
#include <QColorDialog>
#include <QFile>       //文件操作
#include <QFileDialog> //文件对话框
#include <QFontDialog>
#include <QLabel>
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
  void loadFile(QString filename);
  void Creatslots();
private slots:
  //菜单信号 -- 文件
  void slot_menu_Newfile();
  void slot_menu_Openfile();
  void slot_menu_Savefile();
  //菜单信号 -- 编辑
  //  void slot_menu_edit_delete(void);

  //菜单信号 -- 格式
  void slot_menu_Setfont();
  void slot_menu_fontcolor();
  void slot_menu_Backgroundcolor();
  //菜单信号 -- 关于
  void slot_menu_About();
  //状态栏
  void slot_cursor_chang_state();

private:
  Ui::texteditor *ui;
  QActionGroup *group;
  //菜单栏 -- 文件相关功能：新建文件、打开、关闭、保存、清空
  QMenu *menu_file;
  QAction *menu_file_New, *menu_file_Open;
  QAction *menu_file_Close, *menu_file_Save, *menu_file_Clear;

  //菜单栏 -- 编辑相关功能：撤销、剪切、复制、粘贴、删除、替换、全选
  QMenu *menu_edit;
  QAction *menu_edit_undo;
  QAction *menu_edit_cut;
  QAction *menu_edit_copy;
  QAction *menu_edit_paste;
  QAction *menu_edit_delete;
  QAction *menu_edit_all;

  //菜单栏 -- 格式相关功能：字体、字体颜色、字体背景颜色
  QMenu *menu_format;
  QAction *menu_format_font, *menu_format_fontColor;
  QAction *menu_format_backgroundcolor;

  //菜单栏 -- 帮助相关功能:关于
  QMenu *menu_help;
  QAction *menu_help_about;

  //文件路径
  QString fileName;
  //剪切办， QTextEdit没有自带的删除信号，需要使用剪切板实现相同的功能
  QClipboard *Clipboard;
  //创建新的窗口
  texteditor *newMainWindow;
};
#endif // TEXTEDITOR_H
