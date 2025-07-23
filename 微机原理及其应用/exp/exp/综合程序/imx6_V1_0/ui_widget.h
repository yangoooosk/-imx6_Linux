/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page_5;
    QWidget *layoutWidget_5;
    QGridLayout *gridLayout_2;
    QFrame *snakeframe;
    QGridLayout *snakeGridLayout;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *ledPageButton2;
    QPushButton *homePageButton3;
    QPushButton *cameraPageButton2;
    QPushButton *billboardPageButton2;
    QPushButton *itmsPageButton3;
    QPushButton *trackingCarPageButton3;
    QWidget *page_6;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer_5;
    QFrame *itmsframe;
    QGridLayout *itmsGridLayout;
    QPushButton *ledPageButton3;
    QPushButton *homePageButton4;
    QPushButton *billboardPageButton3;
    QPushButton *cameraPageButton3;
    QPushButton *snakePageButton3;
    QPushButton *trackingCarPageButton4;
    QWidget *page_7;
    QWidget *layoutWidget_3;
    QGridLayout *gridLayout_7;
    QFrame *trackingCarFrame;
    QGridLayout *trackingCarGridLayout;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *ledPageButton4;
    QPushButton *homePageButton5;
    QPushButton *billboardPageButton4;
    QPushButton *cameraPageButton4;
    QPushButton *snakePageButton4;
    QPushButton *itmsPageButton4;
    QWidget *page;
    QWidget *page_2;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_4;
    QFrame *ledframe;
    QGridLayout *ledGridLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cameraPageButton;
    QPushButton *homePageButton;
    QPushButton *billboardPageButton;
    QPushButton *snakePageButton;
    QPushButton *itmsPageButton;
    QPushButton *trackingCarPageButton;
    QWidget *page_3;
    QWidget *layoutWidget_6;
    QGridLayout *gridLayout;
    QFrame *cameraframe;
    QGridLayout *cameraGridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *ledPageButton;
    QPushButton *homePageButton1;
    QPushButton *billboardPageButton1;
    QPushButton *snakePageButton1;
    QPushButton *itmsPageButton1;
    QPushButton *trackingCarPageButton1;
    QWidget *page_4;
    QWidget *layoutWidget_4;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *ledPageButton1;
    QPushButton *homePageButton2;
    QFrame *billboardframe;
    QGridLayout *billboardGridLayout;
    QPushButton *cameraPageButton1;
    QPushButton *snakePageButton2;
    QPushButton *itmsPageButton2;
    QPushButton *trackingCarPageButton2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(801, 480);
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 800, 480));
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        layoutWidget_5 = new QWidget(page_5);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(0, 0, 801, 421));
        gridLayout_2 = new QGridLayout(layoutWidget_5);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(1);
        gridLayout_2->setVerticalSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        snakeframe = new QFrame(layoutWidget_5);
        snakeframe->setObjectName(QStringLiteral("snakeframe"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(snakeframe->sizePolicy().hasHeightForWidth());
        snakeframe->setSizePolicy(sizePolicy);
        snakeframe->setFrameShape(QFrame::StyledPanel);
        snakeframe->setFrameShadow(QFrame::Raised);
        snakeGridLayout = new QGridLayout(snakeframe);
        snakeGridLayout->setSpacing(0);
        snakeGridLayout->setContentsMargins(11, 11, 11, 11);
        snakeGridLayout->setObjectName(QStringLiteral("snakeGridLayout"));
        snakeGridLayout->setContentsMargins(0, 0, 0, 0);

        gridLayout_2->addWidget(snakeframe, 0, 0, 1, 7);

        horizontalSpacer_4 = new QSpacerItem(608, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        ledPageButton2 = new QPushButton(layoutWidget_5);
        ledPageButton2->setObjectName(QStringLiteral("ledPageButton2"));
        ledPageButton2->setMinimumSize(QSize(80, 25));
        ledPageButton2->setFocusPolicy(Qt::NoFocus);
        ledPageButton2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/LEDico.png);"));

        gridLayout_2->addWidget(ledPageButton2, 1, 5, 1, 1);

        homePageButton3 = new QPushButton(layoutWidget_5);
        homePageButton3->setObjectName(QStringLiteral("homePageButton3"));
        homePageButton3->setMinimumSize(QSize(80, 25));
        homePageButton3->setFocusPolicy(Qt::NoFocus);
        homePageButton3->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/homeico.png);"));

        gridLayout_2->addWidget(homePageButton3, 1, 6, 1, 1);

        cameraPageButton2 = new QPushButton(layoutWidget_5);
        cameraPageButton2->setObjectName(QStringLiteral("cameraPageButton2"));
        cameraPageButton2->setMinimumSize(QSize(80, 25));
        cameraPageButton2->setFocusPolicy(Qt::NoFocus);
        cameraPageButton2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/cameraico.png);"));

        gridLayout_2->addWidget(cameraPageButton2, 1, 4, 1, 1);

        billboardPageButton2 = new QPushButton(layoutWidget_5);
        billboardPageButton2->setObjectName(QStringLiteral("billboardPageButton2"));
        billboardPageButton2->setMinimumSize(QSize(80, 25));
        billboardPageButton2->setFocusPolicy(Qt::NoFocus);
        billboardPageButton2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/billboardico.png);"));

        gridLayout_2->addWidget(billboardPageButton2, 1, 3, 1, 1);

        itmsPageButton3 = new QPushButton(layoutWidget_5);
        itmsPageButton3->setObjectName(QStringLiteral("itmsPageButton3"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(itmsPageButton3->sizePolicy().hasHeightForWidth());
        itmsPageButton3->setSizePolicy(sizePolicy1);
        itmsPageButton3->setMinimumSize(QSize(80, 25));
        itmsPageButton3->setFocusPolicy(Qt::NoFocus);
        itmsPageButton3->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/itmsico.png);"));

        gridLayout_2->addWidget(itmsPageButton3, 1, 2, 1, 1);

        trackingCarPageButton3 = new QPushButton(layoutWidget_5);
        trackingCarPageButton3->setObjectName(QStringLiteral("trackingCarPageButton3"));
        sizePolicy1.setHeightForWidth(trackingCarPageButton3->sizePolicy().hasHeightForWidth());
        trackingCarPageButton3->setSizePolicy(sizePolicy1);
        trackingCarPageButton3->setMinimumSize(QSize(80, 25));
        trackingCarPageButton3->setFocusPolicy(Qt::NoFocus);
        trackingCarPageButton3->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/trackingbusico.png);"));

        gridLayout_2->addWidget(trackingCarPageButton3, 1, 1, 1, 1);

        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        layoutWidget_2 = new QWidget(page_6);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(0, 0, 801, 421));
        gridLayout_6 = new QGridLayout(layoutWidget_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setHorizontalSpacing(1);
        gridLayout_6->setVerticalSpacing(0);
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_5 = new QSpacerItem(608, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        itmsframe = new QFrame(layoutWidget_2);
        itmsframe->setObjectName(QStringLiteral("itmsframe"));
        sizePolicy.setHeightForWidth(itmsframe->sizePolicy().hasHeightForWidth());
        itmsframe->setSizePolicy(sizePolicy);
        itmsframe->setFrameShape(QFrame::StyledPanel);
        itmsframe->setFrameShadow(QFrame::Raised);
        itmsGridLayout = new QGridLayout(itmsframe);
        itmsGridLayout->setSpacing(0);
        itmsGridLayout->setContentsMargins(11, 11, 11, 11);
        itmsGridLayout->setObjectName(QStringLiteral("itmsGridLayout"));
        itmsGridLayout->setContentsMargins(0, 0, 0, 0);

        gridLayout_6->addWidget(itmsframe, 0, 0, 1, 7);

        ledPageButton3 = new QPushButton(layoutWidget_2);
        ledPageButton3->setObjectName(QStringLiteral("ledPageButton3"));
        ledPageButton3->setMinimumSize(QSize(80, 25));
        ledPageButton3->setFocusPolicy(Qt::NoFocus);
        ledPageButton3->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/LEDico.png);"));

        gridLayout_6->addWidget(ledPageButton3, 1, 5, 1, 1);

        homePageButton4 = new QPushButton(layoutWidget_2);
        homePageButton4->setObjectName(QStringLiteral("homePageButton4"));
        homePageButton4->setMinimumSize(QSize(80, 25));
        homePageButton4->setFocusPolicy(Qt::NoFocus);
        homePageButton4->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/homeico.png);"));

        gridLayout_6->addWidget(homePageButton4, 1, 6, 1, 1);

        billboardPageButton3 = new QPushButton(layoutWidget_2);
        billboardPageButton3->setObjectName(QStringLiteral("billboardPageButton3"));
        billboardPageButton3->setMinimumSize(QSize(80, 25));
        billboardPageButton3->setFocusPolicy(Qt::NoFocus);
        billboardPageButton3->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/billboardico.png);"));

        gridLayout_6->addWidget(billboardPageButton3, 1, 3, 1, 1);

        cameraPageButton3 = new QPushButton(layoutWidget_2);
        cameraPageButton3->setObjectName(QStringLiteral("cameraPageButton3"));
        cameraPageButton3->setMinimumSize(QSize(80, 25));
        cameraPageButton3->setFocusPolicy(Qt::NoFocus);
        cameraPageButton3->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/cameraico.png);"));

        gridLayout_6->addWidget(cameraPageButton3, 1, 4, 1, 1);

        snakePageButton3 = new QPushButton(layoutWidget_2);
        snakePageButton3->setObjectName(QStringLiteral("snakePageButton3"));
        snakePageButton3->setMinimumSize(QSize(80, 25));
        snakePageButton3->setFocusPolicy(Qt::NoFocus);
        snakePageButton3->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/snakeico.png);"));

        gridLayout_6->addWidget(snakePageButton3, 1, 2, 1, 1);

        trackingCarPageButton4 = new QPushButton(layoutWidget_2);
        trackingCarPageButton4->setObjectName(QStringLiteral("trackingCarPageButton4"));
        trackingCarPageButton4->setMinimumSize(QSize(80, 25));
        trackingCarPageButton4->setFocusPolicy(Qt::NoFocus);
        trackingCarPageButton4->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/trackingbusico.png);"));

        gridLayout_6->addWidget(trackingCarPageButton4, 1, 1, 1, 1);

        stackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName(QStringLiteral("page_7"));
        layoutWidget_3 = new QWidget(page_7);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(0, 0, 801, 421));
        gridLayout_7 = new QGridLayout(layoutWidget_3);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setHorizontalSpacing(1);
        gridLayout_7->setVerticalSpacing(0);
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        trackingCarFrame = new QFrame(layoutWidget_3);
        trackingCarFrame->setObjectName(QStringLiteral("trackingCarFrame"));
        sizePolicy.setHeightForWidth(trackingCarFrame->sizePolicy().hasHeightForWidth());
        trackingCarFrame->setSizePolicy(sizePolicy);
        trackingCarFrame->setFrameShape(QFrame::StyledPanel);
        trackingCarFrame->setFrameShadow(QFrame::Raised);
        trackingCarGridLayout = new QGridLayout(trackingCarFrame);
        trackingCarGridLayout->setSpacing(0);
        trackingCarGridLayout->setContentsMargins(11, 11, 11, 11);
        trackingCarGridLayout->setObjectName(QStringLiteral("trackingCarGridLayout"));
        trackingCarGridLayout->setContentsMargins(0, 0, 0, 0);

        gridLayout_7->addWidget(trackingCarFrame, 0, 0, 1, 7);

        horizontalSpacer_6 = new QSpacerItem(608, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_6, 1, 0, 1, 1);

        ledPageButton4 = new QPushButton(layoutWidget_3);
        ledPageButton4->setObjectName(QStringLiteral("ledPageButton4"));
        ledPageButton4->setMinimumSize(QSize(80, 25));
        ledPageButton4->setFocusPolicy(Qt::NoFocus);
        ledPageButton4->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/LEDico.png);"));

        gridLayout_7->addWidget(ledPageButton4, 1, 5, 1, 1);

        homePageButton5 = new QPushButton(layoutWidget_3);
        homePageButton5->setObjectName(QStringLiteral("homePageButton5"));
        homePageButton5->setMinimumSize(QSize(80, 25));
        homePageButton5->setFocusPolicy(Qt::NoFocus);
        homePageButton5->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/homeico.png);"));

        gridLayout_7->addWidget(homePageButton5, 1, 6, 1, 1);

        billboardPageButton4 = new QPushButton(layoutWidget_3);
        billboardPageButton4->setObjectName(QStringLiteral("billboardPageButton4"));
        billboardPageButton4->setMinimumSize(QSize(80, 25));
        billboardPageButton4->setFocusPolicy(Qt::NoFocus);
        billboardPageButton4->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/billboardico.png);"));

        gridLayout_7->addWidget(billboardPageButton4, 1, 3, 1, 1);

        cameraPageButton4 = new QPushButton(layoutWidget_3);
        cameraPageButton4->setObjectName(QStringLiteral("cameraPageButton4"));
        cameraPageButton4->setMinimumSize(QSize(80, 25));
        cameraPageButton4->setFocusPolicy(Qt::NoFocus);
        cameraPageButton4->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/cameraico.png);"));

        gridLayout_7->addWidget(cameraPageButton4, 1, 4, 1, 1);

        snakePageButton4 = new QPushButton(layoutWidget_3);
        snakePageButton4->setObjectName(QStringLiteral("snakePageButton4"));
        snakePageButton4->setMinimumSize(QSize(80, 25));
        snakePageButton4->setFocusPolicy(Qt::NoFocus);
        snakePageButton4->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/snakeico.png);"));

        gridLayout_7->addWidget(snakePageButton4, 1, 2, 1, 1);

        itmsPageButton4 = new QPushButton(layoutWidget_3);
        itmsPageButton4->setObjectName(QStringLiteral("itmsPageButton4"));
        itmsPageButton4->setMinimumSize(QSize(80, 25));
        itmsPageButton4->setFocusPolicy(Qt::NoFocus);
        itmsPageButton4->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/itmsico.png);"));

        gridLayout_7->addWidget(itmsPageButton4, 1, 1, 1, 1);

        stackedWidget->addWidget(page_7);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        layoutWidget = new QWidget(page_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 801, 421));
        gridLayout_4 = new QGridLayout(layoutWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(1);
        gridLayout_4->setVerticalSpacing(0);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        ledframe = new QFrame(layoutWidget);
        ledframe->setObjectName(QStringLiteral("ledframe"));
        ledframe->setFrameShape(QFrame::StyledPanel);
        ledframe->setFrameShadow(QFrame::Raised);
        ledGridLayout = new QGridLayout(ledframe);
        ledGridLayout->setSpacing(5);
        ledGridLayout->setContentsMargins(11, 11, 11, 11);
        ledGridLayout->setObjectName(QStringLiteral("ledGridLayout"));
        ledGridLayout->setContentsMargins(0, 0, 0, 0);

        gridLayout_4->addWidget(ledframe, 0, 0, 1, 7);

        horizontalSpacer_2 = new QSpacerItem(608, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        cameraPageButton = new QPushButton(layoutWidget);
        cameraPageButton->setObjectName(QStringLiteral("cameraPageButton"));
        cameraPageButton->setMinimumSize(QSize(80, 25));
        cameraPageButton->setFocusPolicy(Qt::NoFocus);
        cameraPageButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/cameraico.png);"));

        gridLayout_4->addWidget(cameraPageButton, 1, 5, 1, 1);

        homePageButton = new QPushButton(layoutWidget);
        homePageButton->setObjectName(QStringLiteral("homePageButton"));
        homePageButton->setMinimumSize(QSize(80, 25));
        homePageButton->setFocusPolicy(Qt::NoFocus);
        homePageButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/homeico.png);"));

        gridLayout_4->addWidget(homePageButton, 1, 6, 1, 1);

        billboardPageButton = new QPushButton(layoutWidget);
        billboardPageButton->setObjectName(QStringLiteral("billboardPageButton"));
        billboardPageButton->setMinimumSize(QSize(80, 25));
        billboardPageButton->setFocusPolicy(Qt::NoFocus);
        billboardPageButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/billboardico.png);"));

        gridLayout_4->addWidget(billboardPageButton, 1, 4, 1, 1);

        snakePageButton = new QPushButton(layoutWidget);
        snakePageButton->setObjectName(QStringLiteral("snakePageButton"));
        snakePageButton->setMinimumSize(QSize(80, 25));
        snakePageButton->setFocusPolicy(Qt::NoFocus);
        snakePageButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/snakeico.png);"));

        gridLayout_4->addWidget(snakePageButton, 1, 3, 1, 1);

        itmsPageButton = new QPushButton(layoutWidget);
        itmsPageButton->setObjectName(QStringLiteral("itmsPageButton"));
        itmsPageButton->setMinimumSize(QSize(80, 25));
        itmsPageButton->setFocusPolicy(Qt::NoFocus);
        itmsPageButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/itmsico.png);"));

        gridLayout_4->addWidget(itmsPageButton, 1, 2, 1, 1);

        trackingCarPageButton = new QPushButton(layoutWidget);
        trackingCarPageButton->setObjectName(QStringLiteral("trackingCarPageButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(trackingCarPageButton->sizePolicy().hasHeightForWidth());
        trackingCarPageButton->setSizePolicy(sizePolicy2);
        trackingCarPageButton->setMinimumSize(QSize(80, 25));
        trackingCarPageButton->setFocusPolicy(Qt::NoFocus);
        trackingCarPageButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/trackingbusico.png);"));

        gridLayout_4->addWidget(trackingCarPageButton, 1, 1, 1, 1);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        layoutWidget_6 = new QWidget(page_3);
        layoutWidget_6->setObjectName(QStringLiteral("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(0, 0, 801, 421));
        gridLayout = new QGridLayout(layoutWidget_6);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(1);
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        cameraframe = new QFrame(layoutWidget_6);
        cameraframe->setObjectName(QStringLiteral("cameraframe"));
        cameraframe->setFrameShape(QFrame::StyledPanel);
        cameraframe->setFrameShadow(QFrame::Raised);
        cameraGridLayout = new QGridLayout(cameraframe);
        cameraGridLayout->setSpacing(0);
        cameraGridLayout->setContentsMargins(11, 11, 11, 11);
        cameraGridLayout->setObjectName(QStringLiteral("cameraGridLayout"));
        cameraGridLayout->setContentsMargins(0, 0, 0, 0);

        gridLayout->addWidget(cameraframe, 0, 0, 1, 7);

        horizontalSpacer = new QSpacerItem(608, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        ledPageButton = new QPushButton(layoutWidget_6);
        ledPageButton->setObjectName(QStringLiteral("ledPageButton"));
        ledPageButton->setMinimumSize(QSize(80, 25));
        ledPageButton->setFocusPolicy(Qt::NoFocus);
        ledPageButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/LEDico.png);"));

        gridLayout->addWidget(ledPageButton, 1, 5, 1, 1);

        homePageButton1 = new QPushButton(layoutWidget_6);
        homePageButton1->setObjectName(QStringLiteral("homePageButton1"));
        homePageButton1->setMinimumSize(QSize(80, 25));
        homePageButton1->setFocusPolicy(Qt::NoFocus);
        homePageButton1->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/homeico.png);"));

        gridLayout->addWidget(homePageButton1, 1, 6, 1, 1);

        billboardPageButton1 = new QPushButton(layoutWidget_6);
        billboardPageButton1->setObjectName(QStringLiteral("billboardPageButton1"));
        billboardPageButton1->setMinimumSize(QSize(80, 25));
        billboardPageButton1->setFocusPolicy(Qt::NoFocus);
        billboardPageButton1->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/billboardico.png);"));

        gridLayout->addWidget(billboardPageButton1, 1, 4, 1, 1);

        snakePageButton1 = new QPushButton(layoutWidget_6);
        snakePageButton1->setObjectName(QStringLiteral("snakePageButton1"));
        snakePageButton1->setMinimumSize(QSize(80, 25));
        snakePageButton1->setFocusPolicy(Qt::NoFocus);
        snakePageButton1->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/snakeico.png);"));

        gridLayout->addWidget(snakePageButton1, 1, 3, 1, 1);

        itmsPageButton1 = new QPushButton(layoutWidget_6);
        itmsPageButton1->setObjectName(QStringLiteral("itmsPageButton1"));
        itmsPageButton1->setMinimumSize(QSize(80, 25));
        itmsPageButton1->setFocusPolicy(Qt::NoFocus);
        itmsPageButton1->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/itmsico.png);"));

        gridLayout->addWidget(itmsPageButton1, 1, 2, 1, 1);

        trackingCarPageButton1 = new QPushButton(layoutWidget_6);
        trackingCarPageButton1->setObjectName(QStringLiteral("trackingCarPageButton1"));
        trackingCarPageButton1->setMinimumSize(QSize(80, 25));
        trackingCarPageButton1->setFocusPolicy(Qt::NoFocus);
        trackingCarPageButton1->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/trackingbusico.png);"));

        gridLayout->addWidget(trackingCarPageButton1, 1, 1, 1, 1);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        layoutWidget_4 = new QWidget(page_4);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(0, 0, 801, 421));
        gridLayout_3 = new QGridLayout(layoutWidget_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(1);
        gridLayout_3->setVerticalSpacing(0);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(608, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        ledPageButton1 = new QPushButton(layoutWidget_4);
        ledPageButton1->setObjectName(QStringLiteral("ledPageButton1"));
        ledPageButton1->setMinimumSize(QSize(80, 25));
        ledPageButton1->setFocusPolicy(Qt::NoFocus);
        ledPageButton1->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/LEDico.png);"));

        gridLayout_3->addWidget(ledPageButton1, 1, 5, 1, 1);

        homePageButton2 = new QPushButton(layoutWidget_4);
        homePageButton2->setObjectName(QStringLiteral("homePageButton2"));
        homePageButton2->setMinimumSize(QSize(80, 25));
        homePageButton2->setFocusPolicy(Qt::NoFocus);
        homePageButton2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/homeico.png);"));

        gridLayout_3->addWidget(homePageButton2, 1, 6, 1, 1);

        billboardframe = new QFrame(layoutWidget_4);
        billboardframe->setObjectName(QStringLiteral("billboardframe"));
        sizePolicy.setHeightForWidth(billboardframe->sizePolicy().hasHeightForWidth());
        billboardframe->setSizePolicy(sizePolicy);
        billboardframe->setFrameShape(QFrame::StyledPanel);
        billboardframe->setFrameShadow(QFrame::Raised);
        billboardGridLayout = new QGridLayout(billboardframe);
        billboardGridLayout->setSpacing(0);
        billboardGridLayout->setContentsMargins(11, 11, 11, 11);
        billboardGridLayout->setObjectName(QStringLiteral("billboardGridLayout"));
        billboardGridLayout->setContentsMargins(0, 0, 0, 0);

        gridLayout_3->addWidget(billboardframe, 0, 0, 1, 7);

        cameraPageButton1 = new QPushButton(layoutWidget_4);
        cameraPageButton1->setObjectName(QStringLiteral("cameraPageButton1"));
        cameraPageButton1->setMinimumSize(QSize(80, 25));
        cameraPageButton1->setFocusPolicy(Qt::NoFocus);
        cameraPageButton1->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/cameraico.png);"));

        gridLayout_3->addWidget(cameraPageButton1, 1, 4, 1, 1);

        snakePageButton2 = new QPushButton(layoutWidget_4);
        snakePageButton2->setObjectName(QStringLiteral("snakePageButton2"));
        snakePageButton2->setMinimumSize(QSize(80, 25));
        snakePageButton2->setFocusPolicy(Qt::NoFocus);
        snakePageButton2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/snakeico.png);"));

        gridLayout_3->addWidget(snakePageButton2, 1, 3, 1, 1);

        itmsPageButton2 = new QPushButton(layoutWidget_4);
        itmsPageButton2->setObjectName(QStringLiteral("itmsPageButton2"));
        itmsPageButton2->setMinimumSize(QSize(80, 25));
        itmsPageButton2->setFocusPolicy(Qt::NoFocus);
        itmsPageButton2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/itmsico.png);"));

        gridLayout_3->addWidget(itmsPageButton2, 1, 2, 1, 1);

        trackingCarPageButton2 = new QPushButton(layoutWidget_4);
        trackingCarPageButton2->setObjectName(QStringLiteral("trackingCarPageButton2"));
        trackingCarPageButton2->setMinimumSize(QSize(80, 25));
        trackingCarPageButton2->setFocusPolicy(Qt::NoFocus);
        trackingCarPageButton2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/trackingbusico.png);"));

        gridLayout_3->addWidget(trackingCarPageButton2, 1, 1, 1, 1);

        stackedWidget->addWidget(page_4);

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        ledPageButton2->setText(QString());
        homePageButton3->setText(QString());
        cameraPageButton2->setText(QString());
        billboardPageButton2->setText(QString());
        itmsPageButton3->setText(QString());
        trackingCarPageButton3->setText(QString());
        ledPageButton3->setText(QString());
        homePageButton4->setText(QString());
        billboardPageButton3->setText(QString());
        cameraPageButton3->setText(QString());
        snakePageButton3->setText(QString());
        trackingCarPageButton4->setText(QString());
        ledPageButton4->setText(QString());
        homePageButton5->setText(QString());
        billboardPageButton4->setText(QString());
        cameraPageButton4->setText(QString());
        snakePageButton4->setText(QString());
        itmsPageButton4->setText(QString());
        cameraPageButton->setText(QString());
        homePageButton->setText(QString());
        billboardPageButton->setText(QString());
        snakePageButton->setText(QString());
        itmsPageButton->setText(QString());
        trackingCarPageButton->setText(QString());
        ledPageButton->setText(QString());
        homePageButton1->setText(QString());
        billboardPageButton1->setText(QString());
        snakePageButton1->setText(QString());
        itmsPageButton1->setText(QString());
        trackingCarPageButton1->setText(QString());
        ledPageButton1->setText(QString());
        homePageButton2->setText(QString());
        cameraPageButton1->setText(QString());
        snakePageButton2->setText(QString());
        itmsPageButton2->setText(QString());
        trackingCarPageButton2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
