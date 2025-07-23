#ifndef CHESSFORM_H
#define CHESSFORM_H

#include <QWidget>
#include "chessplate.h"
#include <QMessageBox>
// #include <QSound> // 移除 QSound 的头文件
// 定义控制 LED 的 ioctl 命令号，你需要根据你的驱动程序修改这些值
#define LED_ON_COMMAND  1
#define LED_OFF_COMMAND 0
#define LED_NUMBER 0 // 如果只有一个 LED，通常设为 0

namespace Ui {
class chessForm;
}

class chessForm : public QWidget
{
    Q_OBJECT

public:
    explicit chessForm(QWidget *parent = nullptr);
    ~chessForm();

protected:
    void paintEvent(QPaintEvent *);
    void closeEvent(QCloseEvent *);
private:
    Ui::chessForm *ui;
    chessPlate * myPlate;
    chessPlate::ChessType currentRole;
    int formChessData[15][15];
    int black_cnt = 0,white_cnt = 0;

    void Init();
    void showRole(const QString whiteFileName,const QString blackFileName);
    void setRole(chessPlate::ChessType currentRole);//设置谁先下
    void setChessInit();
    bool isGot(int i,int j);

    // 播放声音的函数
    void playSound(const QString &soundFilePath);

public slots:
    void doProcessStartGame();
    void doProcessExitGame();
    void doProcessFrushPlate(int p,int q );

};

#endif // CHESSFORM_H
