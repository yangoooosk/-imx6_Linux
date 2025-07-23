/********************************************************************************
** Form generated from reading UI file 'led.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LED_H
#define UI_LED_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Led
{
public:
    QPushButton *led1Button;
    QPushButton *led2Button;
    QPushButton *led3Button;
    QPushButton *led4Button;

    void setupUi(QWidget *Led)
    {
        if (Led->objectName().isEmpty())
            Led->setObjectName(QStringLiteral("Led"));
        Led->resize(800, 454);
        led1Button = new QPushButton(Led);
        led1Button->setObjectName(QStringLiteral("led1Button"));
        led1Button->setGeometry(QRect(141, 91, 121, 191));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(led1Button->sizePolicy().hasHeightForWidth());
        led1Button->setSizePolicy(sizePolicy);
        led1Button->setFocusPolicy(Qt::NoFocus);
        led2Button = new QPushButton(Led);
        led2Button->setObjectName(QStringLiteral("led2Button"));
        led2Button->setGeometry(QRect(266, 91, 121, 191));
        sizePolicy.setHeightForWidth(led2Button->sizePolicy().hasHeightForWidth());
        led2Button->setSizePolicy(sizePolicy);
        led2Button->setFocusPolicy(Qt::NoFocus);
        led3Button = new QPushButton(Led);
        led3Button->setObjectName(QStringLiteral("led3Button"));
        led3Button->setGeometry(QRect(391, 91, 121, 191));
        sizePolicy.setHeightForWidth(led3Button->sizePolicy().hasHeightForWidth());
        led3Button->setSizePolicy(sizePolicy);
        led3Button->setFocusPolicy(Qt::NoFocus);
        led4Button = new QPushButton(Led);
        led4Button->setObjectName(QStringLiteral("led4Button"));
        led4Button->setGeometry(QRect(515, 91, 121, 191));
        sizePolicy.setHeightForWidth(led4Button->sizePolicy().hasHeightForWidth());
        led4Button->setSizePolicy(sizePolicy);
        led4Button->setFocusPolicy(Qt::NoFocus);

        retranslateUi(Led);

        QMetaObject::connectSlotsByName(Led);
    } // setupUi

    void retranslateUi(QWidget *Led)
    {
        Led->setWindowTitle(QApplication::translate("Led", "Form", Q_NULLPTR));
        led1Button->setText(QString());
        led2Button->setText(QString());
        led3Button->setText(QString());
        led4Button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Led: public Ui_Led {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LED_H
