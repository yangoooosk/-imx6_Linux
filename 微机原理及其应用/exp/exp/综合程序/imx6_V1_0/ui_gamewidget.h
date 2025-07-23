/********************************************************************************
** Form generated from reading UI file 'gamewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWIDGET_H
#define UI_GAMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWidget
{
public:
    QPushButton *pausebtn;
    QPushButton *downbtn;
    QPushButton *startbtn;
    QLabel *levellabel;
    QLabel *gameoverlabel;
    QLabel *scoreshow;
    QPushButton *upbtn;
    QPushButton *rightbtn;
    QLabel *levelshow;
    QLabel *scorelabel;
    QPushButton *leftbtn;

    void setupUi(QWidget *GameWidget)
    {
        if (GameWidget->objectName().isEmpty())
            GameWidget->setObjectName(QStringLiteral("GameWidget"));
        GameWidget->resize(800, 454);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GameWidget->sizePolicy().hasHeightForWidth());
        GameWidget->setSizePolicy(sizePolicy);
        GameWidget->setAutoFillBackground(false);
        pausebtn = new QPushButton(GameWidget);
        pausebtn->setObjectName(QStringLiteral("pausebtn"));
        pausebtn->setGeometry(QRect(670, 320, 71, 41));
        pausebtn->setFocusPolicy(Qt::NoFocus);
        pausebtn->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/snakestop.png);"));
        downbtn = new QPushButton(GameWidget);
        downbtn->setObjectName(QStringLiteral("downbtn"));
        downbtn->setGeometry(QRect(600, 230, 60, 60));
        downbtn->setFocusPolicy(Qt::NoFocus);
        downbtn->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/snakedown.png);"));
        startbtn = new QPushButton(GameWidget);
        startbtn->setObjectName(QStringLiteral("startbtn"));
        startbtn->setGeometry(QRect(530, 320, 71, 41));
        startbtn->setFocusPolicy(Qt::NoFocus);
        startbtn->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/snakestart.png);"));
        levellabel = new QLabel(GameWidget);
        levellabel->setObjectName(QStringLiteral("levellabel"));
        levellabel->setGeometry(QRect(530, 50, 51, 21));
        QFont font;
        font.setFamily(QStringLiteral("Courier"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        levellabel->setFont(font);
        gameoverlabel = new QLabel(GameWidget);
        gameoverlabel->setObjectName(QStringLiteral("gameoverlabel"));
        gameoverlabel->setGeometry(QRect(130, 130, 351, 71));
        gameoverlabel->setAutoFillBackground(false);
        scoreshow = new QLabel(GameWidget);
        scoreshow->setObjectName(QStringLiteral("scoreshow"));
        scoreshow->setGeometry(QRect(580, 20, 51, 21));
        scoreshow->setFont(font);
        upbtn = new QPushButton(GameWidget);
        upbtn->setObjectName(QStringLiteral("upbtn"));
        upbtn->setGeometry(QRect(600, 90, 60, 60));
        upbtn->setFocusPolicy(Qt::NoFocus);
        upbtn->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/snakeup.png);"));
        rightbtn = new QPushButton(GameWidget);
        rightbtn->setObjectName(QStringLiteral("rightbtn"));
        rightbtn->setGeometry(QRect(670, 160, 60, 60));
        rightbtn->setFocusPolicy(Qt::NoFocus);
        rightbtn->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/snakeright.png);"));
        levelshow = new QLabel(GameWidget);
        levelshow->setObjectName(QStringLiteral("levelshow"));
        levelshow->setGeometry(QRect(580, 50, 51, 21));
        levelshow->setFont(font);
        scorelabel = new QLabel(GameWidget);
        scorelabel->setObjectName(QStringLiteral("scorelabel"));
        scorelabel->setGeometry(QRect(530, 20, 51, 21));
        scorelabel->setFont(font);
        leftbtn = new QPushButton(GameWidget);
        leftbtn->setObjectName(QStringLiteral("leftbtn"));
        leftbtn->setGeometry(QRect(530, 160, 60, 60));
        leftbtn->setFocusPolicy(Qt::NoFocus);
        leftbtn->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/snakeleft.png);"));

        retranslateUi(GameWidget);

        QMetaObject::connectSlotsByName(GameWidget);
    } // setupUi

    void retranslateUi(QWidget *GameWidget)
    {
        GameWidget->setWindowTitle(QApplication::translate("GameWidget", "GameWidget", Q_NULLPTR));
        pausebtn->setText(QString());
        downbtn->setText(QString());
        startbtn->setText(QString());
        levellabel->setText(QApplication::translate("GameWidget", "\347\255\211\347\272\247:", Q_NULLPTR));
        gameoverlabel->setText(QString());
        scoreshow->setText(QString());
        upbtn->setText(QString());
        rightbtn->setText(QString());
        levelshow->setText(QString());
        scorelabel->setText(QApplication::translate("GameWidget", "\345\210\206\346\225\260:", Q_NULLPTR));
        leftbtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GameWidget: public Ui_GameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET_H
