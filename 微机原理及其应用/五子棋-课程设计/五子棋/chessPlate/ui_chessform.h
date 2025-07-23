/********************************************************************************
** Form generated from reading UI file 'chessform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESSFORM_H
#define UI_CHESSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chessForm
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QLCDNumber *lcdNumWhite;
    QLabel *whiteLab;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QFrame *frame_2;
    QLabel *blackLab;
    QLCDNumber *lcdNumBlack;
    QFrame *frame_3;
    QPushButton *exitBtn;
    QPushButton *openGameBtn;
    QComboBox *comboBox;

    void setupUi(QWidget *chessForm)
    {
        if (chessForm->objectName().isEmpty())
            chessForm->setObjectName(QStringLiteral("chessForm"));
        chessForm->resize(592, 385);
        gridLayout_2 = new QGridLayout(chessForm);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        frame = new QFrame(chessForm);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(120, 200));
        frame->setMaximumSize(QSize(130, 16777215));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        lcdNumWhite = new QLCDNumber(frame);
        lcdNumWhite->setObjectName(QStringLiteral("lcdNumWhite"));
        lcdNumWhite->setGeometry(QRect(30, 80, 71, 91));
        lcdNumWhite->setDigitCount(2);
        whiteLab = new QLabel(frame);
        whiteLab->setObjectName(QStringLiteral("whiteLab"));
        whiteLab->setGeometry(QRect(30, 10, 51, 51));

        gridLayout_2->addWidget(frame, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        verticalLayout->addLayout(gridLayout);


        gridLayout_2->addLayout(verticalLayout, 0, 1, 1, 1);

        frame_2 = new QFrame(chessForm);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setMinimumSize(QSize(120, 200));
        frame_2->setMaximumSize(QSize(130, 16777215));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        blackLab = new QLabel(frame_2);
        blackLab->setObjectName(QStringLiteral("blackLab"));
        blackLab->setGeometry(QRect(50, 10, 61, 51));
        lcdNumBlack = new QLCDNumber(frame_2);
        lcdNumBlack->setObjectName(QStringLiteral("lcdNumBlack"));
        lcdNumBlack->setGeometry(QRect(40, 80, 71, 91));
        lcdNumBlack->setDigitCount(2);

        gridLayout_2->addWidget(frame_2, 0, 2, 1, 1);

        frame_3 = new QFrame(chessForm);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setMinimumSize(QSize(450, 90));
        frame_3->setMaximumSize(QSize(16777215, 120));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        exitBtn = new QPushButton(frame_3);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        exitBtn->setGeometry(QRect(440, 30, 101, 51));
        exitBtn->setStyleSheet(QStringLiteral("border-image: url(:/res/exit.jpg);"));
        exitBtn->setIconSize(QSize(200, 30));
        exitBtn->setAutoDefault(false);
        openGameBtn = new QPushButton(frame_3);
        openGameBtn->setObjectName(QStringLiteral("openGameBtn"));
        openGameBtn->setGeometry(QRect(240, 40, 111, 31));
        openGameBtn->setStyleSheet(QStringLiteral("border-image: url(:/res/start.png);"));
        comboBox = new QComboBox(frame_3);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(50, 40, 69, 22));

        gridLayout_2->addWidget(frame_3, 1, 0, 1, 3);


        retranslateUi(chessForm);

        QMetaObject::connectSlotsByName(chessForm);
    } // setupUi

    void retranslateUi(QWidget *chessForm)
    {
        chessForm->setWindowTitle(QApplication::translate("chessForm", "Form", Q_NULLPTR));
        whiteLab->setText(QString());
        blackLab->setText(QString());
        exitBtn->setText(QString());
        openGameBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class chessForm: public Ui_chessForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSFORM_H
