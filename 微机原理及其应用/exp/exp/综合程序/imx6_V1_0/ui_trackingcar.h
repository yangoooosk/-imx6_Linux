/********************************************************************************
** Form generated from reading UI file 'trackingcar.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRACKINGCAR_H
#define UI_TRACKINGCAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_trackingCar
{
public:
    QPushButton *startButton;
    QLabel *led0Label;
    QLabel *led1Label;
    QWidget *fm;
    QGridLayout *gridLayout;
    QLabel *label;
    QWidget *fm1;
    QGridLayout *gridLayout1;
    QLabel *label_2;

    void setupUi(QWidget *trackingCar)
    {
        if (trackingCar->objectName().isEmpty())
            trackingCar->setObjectName(QStringLiteral("trackingCar"));
        trackingCar->resize(800, 454);
        startButton = new QPushButton(trackingCar);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(650, 300, 120, 120));
        startButton->setFocusPolicy(Qt::NoFocus);
        startButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/trackbusStop.png);"));
        led0Label = new QLabel(trackingCar);
        led0Label->setObjectName(QStringLiteral("led0Label"));
        led0Label->setGeometry(QRect(190, 10, 30, 41));
        led0Label->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/trackbusDirLeftOff.png);"));
        led1Label = new QLabel(trackingCar);
        led1Label->setObjectName(QStringLiteral("led1Label"));
        led1Label->setGeometry(QRect(580, 10, 30, 41));
        led1Label->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/trackbusDirRightOff.png);"));
        fm = new QWidget(trackingCar);
        fm->setObjectName(QStringLiteral("fm"));
        fm->setGeometry(QRect(620, 30, 171, 171));
        gridLayout = new QGridLayout(fm);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(trackingCar);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(680, 10, 61, 17));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        fm1 = new QWidget(trackingCar);
        fm1->setObjectName(QStringLiteral("fm1"));
        fm1->setGeometry(QRect(10, 30, 171, 171));
        gridLayout1 = new QGridLayout(fm1);
        gridLayout1->setSpacing(0);
        gridLayout1->setContentsMargins(11, 11, 11, 11);
        gridLayout1->setObjectName(QStringLiteral("gridLayout1"));
        gridLayout1->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(trackingCar);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 10, 61, 17));
        label_2->setFont(font);

        retranslateUi(trackingCar);

        QMetaObject::connectSlotsByName(trackingCar);
    } // setupUi

    void retranslateUi(QWidget *trackingCar)
    {
        trackingCar->setWindowTitle(QApplication::translate("trackingCar", "trackingCar", Q_NULLPTR));
        startButton->setText(QString());
        led0Label->setText(QString());
        led1Label->setText(QString());
        label->setText(QApplication::translate("trackingCar", "\350\277\210\351\200\237\350\241\250", Q_NULLPTR));
        label_2->setText(QApplication::translate("trackingCar", "\350\247\222\345\272\246\350\241\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class trackingCar: public Ui_trackingCar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRACKINGCAR_H
