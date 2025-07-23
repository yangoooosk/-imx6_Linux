/********************************************************************************
** Form generated from reading UI file 'itms.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITMS_H
#define UI_ITMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ITMS
{
public:
    QPushButton *itmsButton;
    QLabel *stationNameLabel;
    QLabel *totalityLabel;
    QLabel *busTotalLabel;
    QLabel *getOnPeopleNumLabel;
    QLabel *getOffPeopleNumLabel;
    QLabel *totality;
    QLabel *busTotal;
    QLabel *getOnPeopleNum;
    QLabel *getOffPeopleNum;
    QLabel *label;
    QLabel *irdaLabel;
    QLabel *lightNorth;
    QLabel *lightSouth;
    QLabel *lightWest;
    QLabel *lightEast;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;

    void setupUi(QWidget *ITMS)
    {
        if (ITMS->objectName().isEmpty())
            ITMS->setObjectName(QStringLiteral("ITMS"));
        ITMS->resize(800, 454);
        itmsButton = new QPushButton(ITMS);
        itmsButton->setObjectName(QStringLiteral("itmsButton"));
        itmsButton->setGeometry(QRect(680, 260, 81, 29));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        itmsButton->setFont(font);
        itmsButton->setFocusPolicy(Qt::NoFocus);
        stationNameLabel = new QLabel(ITMS);
        stationNameLabel->setObjectName(QStringLiteral("stationNameLabel"));
        stationNameLabel->setGeometry(QRect(210, 10, 161, 31));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        stationNameLabel->setFont(font1);
        stationNameLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 0);"));
        totalityLabel = new QLabel(ITMS);
        totalityLabel->setObjectName(QStringLiteral("totalityLabel"));
        totalityLabel->setGeometry(QRect(550, 30, 111, 21));
        totalityLabel->setFont(font);
        busTotalLabel = new QLabel(ITMS);
        busTotalLabel->setObjectName(QStringLiteral("busTotalLabel"));
        busTotalLabel->setGeometry(QRect(550, 60, 111, 21));
        busTotalLabel->setFont(font);
        getOnPeopleNumLabel = new QLabel(ITMS);
        getOnPeopleNumLabel->setObjectName(QStringLiteral("getOnPeopleNumLabel"));
        getOnPeopleNumLabel->setGeometry(QRect(550, 90, 111, 21));
        getOnPeopleNumLabel->setFont(font);
        getOffPeopleNumLabel = new QLabel(ITMS);
        getOffPeopleNumLabel->setObjectName(QStringLiteral("getOffPeopleNumLabel"));
        getOffPeopleNumLabel->setGeometry(QRect(550, 120, 111, 21));
        getOffPeopleNumLabel->setFont(font);
        totality = new QLabel(ITMS);
        totality->setObjectName(QStringLiteral("totality"));
        totality->setGeometry(QRect(670, 30, 61, 21));
        totality->setFont(font);
        busTotal = new QLabel(ITMS);
        busTotal->setObjectName(QStringLiteral("busTotal"));
        busTotal->setGeometry(QRect(670, 60, 61, 21));
        busTotal->setFont(font);
        getOnPeopleNum = new QLabel(ITMS);
        getOnPeopleNum->setObjectName(QStringLiteral("getOnPeopleNum"));
        getOnPeopleNum->setGeometry(QRect(670, 90, 61, 21));
        getOnPeopleNum->setFont(font);
        getOffPeopleNum = new QLabel(ITMS);
        getOffPeopleNum->setObjectName(QStringLiteral("getOffPeopleNum"));
        getOffPeopleNum->setGeometry(QRect(670, 120, 61, 21));
        getOffPeopleNum->setFont(font);
        label = new QLabel(ITMS);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(680, 173, 60, 18));
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(0, 170, 0);"));
        irdaLabel = new QLabel(ITMS);
        irdaLabel->setObjectName(QStringLiteral("irdaLabel"));
        irdaLabel->setGeometry(QRect(400, 10, 131, 31));
        irdaLabel->setFont(font1);
        irdaLabel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        lightNorth = new QLabel(ITMS);
        lightNorth->setObjectName(QStringLiteral("lightNorth"));
        lightNorth->setGeometry(QRect(265, 185, 41, 9));
        lightSouth = new QLabel(ITMS);
        lightSouth->setObjectName(QStringLiteral("lightSouth"));
        lightSouth->setGeometry(QRect(265, 240, 41, 9));
        lightWest = new QLabel(ITMS);
        lightWest->setObjectName(QStringLiteral("lightWest"));
        lightWest->setGeometry(QRect(240, 200, 9, 41));
        lightEast = new QLabel(ITMS);
        lightEast->setObjectName(QStringLiteral("lightEast"));
        lightEast->setGeometry(QRect(320, 200, 9, 41));
        checkBox_3 = new QCheckBox(ITMS);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(680, 230, 38, 21));
        checkBox_3->setFont(font);
        checkBox_4 = new QCheckBox(ITMS);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setGeometry(QRect(750, 230, 41, 21));
        checkBox_4->setFont(font);
        checkBox_2 = new QCheckBox(ITMS);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(750, 197, 41, 21));
        checkBox_2->setFont(font);
        checkBox = new QCheckBox(ITMS);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(680, 197, 38, 21));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        font2.setKerning(true);
        checkBox->setFont(font2);

        retranslateUi(ITMS);

        QMetaObject::connectSlotsByName(ITMS);
    } // setupUi

    void retranslateUi(QWidget *ITMS)
    {
        ITMS->setWindowTitle(QApplication::translate("ITMS", "ITMS", Q_NULLPTR));
        itmsButton->setText(QString());
        stationNameLabel->setText(QString());
        totalityLabel->setText(QApplication::translate("ITMS", "\346\200\273\350\256\241\346\265\201\345\212\250\344\272\272\346\225\260\357\274\232", Q_NULLPTR));
        busTotalLabel->setText(QApplication::translate("ITMS", "\350\275\246\344\270\212\347\216\260\346\234\211\344\272\272\346\225\260\357\274\232", Q_NULLPTR));
        getOnPeopleNumLabel->setText(QApplication::translate("ITMS", "\346\234\254\347\253\231\344\270\212\350\275\246\344\272\272\346\225\260\357\274\232", Q_NULLPTR));
        getOffPeopleNumLabel->setText(QApplication::translate("ITMS", "\346\234\254\347\253\231\344\270\213\350\275\246\344\272\272\346\225\260\357\274\232", Q_NULLPTR));
        totality->setText(QString());
        busTotal->setText(QString());
        getOnPeopleNum->setText(QString());
        getOffPeopleNum->setText(QString());
        label->setText(QApplication::translate("ITMS", "\345\201\234\350\275\246\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        irdaLabel->setText(QString());
        lightNorth->setText(QString());
        lightSouth->setText(QString());
        lightWest->setText(QString());
        lightEast->setText(QString());
        checkBox_3->setText(QApplication::translate("ITMS", "5s", Q_NULLPTR));
        checkBox_4->setText(QApplication::translate("ITMS", "7s", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("ITMS", "3s", Q_NULLPTR));
        checkBox->setText(QApplication::translate("ITMS", "2s", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ITMS: public Ui_ITMS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITMS_H
