/********************************************************************************
** Form generated from reading UI file 'billboard.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BILLBOARD_H
#define UI_BILLBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_billboard
{
public:
    QTextEdit *fileNameTextEdit;
    QLabel *label;
    QWidget *widget;
    QGridLayout *gridLayout;
    QCheckBox *checkBox;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_7;
    QPushButton *startButton;

    void setupUi(QWidget *billboard)
    {
        if (billboard->objectName().isEmpty())
            billboard->setObjectName(QStringLiteral("billboard"));
        billboard->resize(800, 454);
        fileNameTextEdit = new QTextEdit(billboard);
        fileNameTextEdit->setObjectName(QStringLiteral("fileNameTextEdit"));
        fileNameTextEdit->setGeometry(QRect(487, 42, 270, 114));
        label = new QLabel(billboard);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(520, 40, 191, 111));
        widget = new QWidget(billboard);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(531, 179, 151, 97));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        checkBox = new QCheckBox(widget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setEnabled(true);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        checkBox->setFont(font);

        gridLayout->addWidget(checkBox, 0, 0, 1, 1);

        checkBox_3 = new QCheckBox(widget);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setFont(font);

        gridLayout->addWidget(checkBox_3, 0, 1, 1, 1);

        checkBox_5 = new QCheckBox(widget);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        checkBox_5->setFont(font);

        gridLayout->addWidget(checkBox_5, 1, 0, 1, 1);

        checkBox_7 = new QCheckBox(widget);
        checkBox_7->setObjectName(QStringLiteral("checkBox_7"));
        checkBox_7->setFont(font);

        gridLayout->addWidget(checkBox_7, 1, 1, 1, 1);

        startButton = new QPushButton(widget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setFont(font);
        startButton->setFocusPolicy(Qt::NoFocus);
        startButton->setStyleSheet(QStringLiteral("background-color: rgb(195, 195, 195);"));

        gridLayout->addWidget(startButton, 2, 0, 1, 2);


        retranslateUi(billboard);

        QMetaObject::connectSlotsByName(billboard);
    } // setupUi

    void retranslateUi(QWidget *billboard)
    {
        billboard->setWindowTitle(QApplication::translate("billboard", "billboard", Q_NULLPTR));
        fileNameTextEdit->setHtml(QApplication::translate("billboard", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        label->setText(QString());
        checkBox->setText(QApplication::translate("billboard", "100ms", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("billboard", "500ms", Q_NULLPTR));
        checkBox_5->setText(QApplication::translate("billboard", "1s", Q_NULLPTR));
        checkBox_7->setText(QApplication::translate("billboard", "2s", Q_NULLPTR));
        startButton->setText(QApplication::translate("billboard", "\345\274\200\345\247\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class billboard: public Ui_billboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BILLBOARD_H
