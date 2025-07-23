#include "chessform.h"
#include "ui_chessform.h"
#include <cstdlib> // 包含 system() 函数的头文件
#include <QDebug>
#include "led_control.h"
#include "led_matrix_func.h"

chessForm::chessForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chessForm)
{
    ui->setupUi(this);
    Init();//初始化主界面
//    this->setWindowIcon(QIcon(":/res/中文.png"));
    connect(ui->openGameBtn,&QPushButton::clicked,this,&chessForm::doProcessStartGame);
    connect(ui->exitBtn,&QPushButton::clicked,this,&chessForm::doProcessExitGame);



}

chessForm::~chessForm()
{
    delete ui;
}

void chessForm::paintEvent(QPaintEvent *)
{
    //绘制主界面背景
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/res/back.jpg"));

}

void chessForm::closeEvent(QCloseEvent *event)
{
    if(QMessageBox::Yes==QMessageBox::information(this,"提示","是否退出",QMessageBox::Yes,QMessageBox::No))
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void chessForm::Init()
{
    //申请棋盘类空间
    myPlate = new chessPlate();
    //把棋盘放在主界面的容器中
    ui->gridLayout->addWidget(myPlate);
    //设置Title、图标
    this->setWindowTitle("五子棋");
    //设置标题字
    //ui->titleLab->setPixmap(QPixmap(":/res/title.png"));
    //添加争先选择部件
    QStringList list;
    list.clear();
    list.append("白子先");
    list.append("黑子先");
    ui->comboBox->addItems(list);
    //显示白棋、黑棋行走标识
    showRole(":/res/white.png",":/res/black.png");
    //播放音乐  // 移除这里原本播放音乐的代码

}

void chessForm::showRole(const QString whiteFileName, const QString blackFileName)
{
    ui->whiteLab->setPixmap(QPixmap(whiteFileName));
    ui->whiteLab->setScaledContents(true);
    ui->blackLab->setPixmap(QPixmap(blackFileName));
    ui->blackLab->setScaledContents(true);
}
void chessForm::setRole(chessPlate::ChessType Role)
{
    currentRole = Role;
    if(Role == chessPlate::Black)
    {
        ui->blackLab->setVisible(true);
        ui->whiteLab->setVisible(false);
    }
    else
    {
        ui->blackLab->setVisible(false);
        ui->whiteLab->setVisible(true);
    }

}
void chessForm::setChessInit()
{
    for (int i=0;i<15 ;i++ ) {
        for (int j = 0;j<15 ;j++ ) {
            formChessData[i][j]=chessPlate::Empty;
        }
    }
    myPlate->setChessStatus(formChessData);
    white_cnt=0;
    black_cnt=0;
    ui->lcdNumBlack->display(black_cnt);
    ui->lcdNumWhite->display(white_cnt);
}

bool chessForm::isGot(int i, int j)
{
    //扫面方式决定了，这种判断方式
    chessPlate::ChessType a;
    a= chessPlate::ChessType(formChessData[i][j]);
    if(i>10)//向右判断
    {
        //不向右判断
    }
    else
    {
        qDebug()<<"111111";
        if(formChessData[i+1][j]==a&&formChessData[i+2][j]==a&&formChessData[i+3][j]==a&&formChessData[i+4][j]==a)
        {return true;}
    }

    if(j>10)//向下判断
    {
        //不向下判断
    }
    else
    {

        if(formChessData[i][j+1]==a&&formChessData[i][j+2]==a&&formChessData[i][j+3]==a&&formChessData[i][j+4]==a)
        {return true;}
    }
    if(j>10||i>10)//向斜下判断
    {
        //不向斜下判断
    }
    else
    {

        if(formChessData[i+1][j+1]==a&&formChessData[i+2][j+2]==a&&formChessData[i+3][j+3]==a&&formChessData[i+4][j+4]==a)
        {return true;}
    }
    if(j<4||i>10)
    {
        //不向斜上判断
    }
    else
    {

        if(formChessData[i+1][j-1]==a&&formChessData[i+2][j-2]==a&&formChessData[i+3][j-3]==a&&formChessData[i+4][j-4]==a)
        {return true;}
    }
    return false;




}

// 使用外部命令播放声音
void chessForm::playSound(const QString &soundFilePath) {
    QString command = QString("aplay -q %1").arg(soundFilePath); // 使用 aplay 播放声音，-q 表示静默模式
    // 可根据实际情况选择其他播放命令，例如:
    // QString command = QString("mplayer -slave -quiet %1").arg(soundFilePath);
    // 或者特定于 i.MX6 的命令

    system(command.toStdString().c_str());
}

void chessForm::doProcessStartGame()
{
    // QSound *sound = new QSound(":/res/startSound.wav",this); // 移除 QSound

    // 播放开始音效
    // sound->play(); // 移除 QSound 的 play()
    playSound(":/res/startSound.wav"); // 使用 playSound 函数播放
    // 设置循环次数 -1代表无线
    // sound->setLoops(3); // QSound 的循环设置也需要移除

    //界面初始化
    if(ui->comboBox->currentText().contains("白"))
    {
        setRole(chessPlate::White);
    }
    else
    {
        setRole(chessPlate::Black);
    }
    //棋盘初始化
    setChessInit();
    //可以开始下棋，连接信号槽
    connect(myPlate,&chessPlate::mousePosSend,this,&chessForm::doProcessFrushPlate);

}
void chessForm::doProcessExitGame()
{
    this->close();
}
void chessForm::doProcessFrushPlate(int p, int q)
{
    // QSound *gameSound = new QSound(":/res/gamesound.wav",this); // 移除 QSound
    //判断能否下子
    if(formChessData[p][q]==chessPlate::Empty)
    {
        //可以下子 下哪一个子
        if(currentRole==chessPlate::Black)
        {
            formChessData[p][q]=chessPlate::Black;
            black_cnt++;
            currentRole = chessPlate::White;
        }
        else
        {
            formChessData[p][q] = chessPlate::White;
            white_cnt++;
            currentRole = chessPlate::Black;
        }

        myPlate->setChessStatus(formChessData);
        // gameSound->play(); // 移除 QSound 的 play()
        playSound(":/res/gamesound.wav"); // 使用 playSound 函数播放
        ui->lcdNumBlack->display(black_cnt);
        ui->lcdNumWhite->display(white_cnt);
         //判断是否胜利
        int i=0,j=0;
        for (i=0;i<15 ;i++ ) {
            for (j=0;j<15 ;j++ ) {
                if(formChessData[i][j]==0)
                {}
                else
                {
                    if(isGot(i,j))//这个棋子是否构成成功棋形判断函数
                    {break;}
               }
            }
            if(j!=15)
            {break;}

        }
        if((i!=15)&&formChessData[p][q] == chessPlate::White)
        {
            QMessageBox::information(this,"提示","恭喜白棋胜利！",QMessageBox::Ok);
            displayLedMatrix("恭喜白棋");
            setChessInit();
            showRole(":/res/white.png",":/res/black.png");
            disconnect(myPlate,&chessPlate::mousePosSend,this,&chessForm::doProcessFrushPlate);
        }
        else if((i!=15)&&formChessData[p][q] == chessPlate::Black)
        {
           QMessageBox::information(this,"提示","恭喜黑棋胜利！",QMessageBox::Ok);
           displayLedMatrix("恭喜黑棋");
           setChessInit();
           showRole(":/res/white.png",":/res/black.png");
           disconnect(myPlate,&chessPlate::mousePosSend,this,&chessForm::doProcessFrushPlate);
        }
        else
        {}
    }
    else
    {}
}

