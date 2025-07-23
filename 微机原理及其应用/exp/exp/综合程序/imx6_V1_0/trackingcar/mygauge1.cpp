#include "mygauge1.h"

myGauge1::myGauge1(QWidget *parent) :
        QWidget(parent)
{
    QFont font;
     font.setPointSize(6);
    this->setFont(font);

    m_value=0;
    m_currentValue=90;
    m_bReverse=false;
    updateTimer=new QTimer(this);
    updateTimer->setInterval(10);
    connect(updateTimer,SIGNAL(timeout()),this,SLOT(UpdateGraph()));

    m_outerRadius=width()>height() ? height()/2 : width()/2;
    m_innerRadius=0.8*m_outerRadius;
    m_colorPieRadius=m_outerRadius*0.7;
    m_coverCircleRadius=0.7*m_colorPieRadius;
    m_center=rect().center();
    m_longHand=(qreal)m_outerRadius/20;
    m_okHand=0.7*m_longHand;
    m_shortHand=0.5*m_longHand;
    m_space=0.1*m_longHand;
}

void myGauge1::resetVariables(QPainter *painter)
{
    m_outerRadius=width()>height() ? height()/2 : width()/2;
    m_innerRadius=0.8*m_outerRadius;
    m_center=rect().center();
    m_colorPieRadius=m_outerRadius*0.7;
    m_coverCircleRadius=0.7*m_colorPieRadius;
    m_longHand=(qreal)m_outerRadius/20;
    m_okHand=0.7*m_longHand;
    m_shortHand=0.5*m_longHand;
    m_space=0.1*m_longHand;
}

void myGauge1::paintEvent(QPaintEvent *)
{
        QPainter painter;
        painter.begin(this);
        painter.setRenderHints(QPainter::Antialiasing|QPainter::TextAntialiasing);
        resetVariables(&painter);
        drawOuterCircle(&painter);
        drawInnerCircle(&painter);
        drawColorPies(&painter);
        drawIndicator(&painter);
        drawCoverLines(&painter);
        drawCoverCircle(&painter);
        drawMarkAndText(&painter);
        drawTextRect(&painter);
        painter.end();
}

void myGauge1::drawOuterCircle(QPainter* painter)
{
    painter->save();

    QRadialGradient outerGradient(m_center,m_outerRadius,m_center);
    outerGradient.setColorAt(0.0,QColor(130,130,130));
    outerGradient.setColorAt(0.9,QColor(130,130,130));
    outerGradient.setColorAt(0.95,QColor(200,200,200));
    outerGradient.setColorAt(1.0,QColor(130,130,130));

    painter->setPen(Qt::NoPen);
    painter->setBrush(outerGradient);
    painter->drawEllipse(m_center,m_outerRadius,m_outerRadius);

    painter->restore();
}

void myGauge1::drawInnerCircle(QPainter* painter)
{
    painter->save();

    QRadialGradient innerGradient(m_center,m_innerRadius,m_center);
    innerGradient.setColorAt(0.0,QColor(180,180,180));
    innerGradient.setColorAt(1.0,QColor(130,130,130));

    painter->setPen(Qt::NoPen);
    painter->setBrush(innerGradient);
    painter->drawEllipse(m_center,m_innerRadius,m_innerRadius);

    painter->restore();
}

void myGauge1::drawColorPies(QPainter* painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);

    QPointF pieRectTopLeftPot(m_center.x()-m_colorPieRadius,m_center.y()-m_colorPieRadius);
    QPointF pieRectBottomRightPot(m_center.x()+m_colorPieRadius,m_center.y()+m_colorPieRadius);

    m_pieRect=QRectF(pieRectTopLeftPot,pieRectBottomRightPot);


    painter->setBrush(Qt::red);
    painter->drawPie(m_pieRect,0*16,30*16);

    // draw yellow pie
    painter->setBrush(Qt::green);
    painter->drawPie(m_pieRect,30*16,60*16);

    // draw blue pie
    painter->setBrush(Qt::green);
    painter->drawPie(m_pieRect,90*16,60*16);

    painter->setBrush(Qt::red);
    painter->drawPie(m_pieRect,150*16,30*16);



    painter->restore();

}

void myGauge1::drawCoverLines(QPainter* painter)
{
    painter->save();

    qreal startAngle=90;
    qreal dAngle=(qreal)180/6;
    painter->translate(m_center);
    painter->setPen(QColor(100,100,100));
    for(int i=0;i<=6;i++)
    {

        painter->save();
        painter->rotate(startAngle);
        QPointF topPot(0,m_colorPieRadius);
        QPointF bottomPot(0,m_coverCircleRadius);
        painter->drawLine(topPot,bottomPot);

        painter->restore();
        startAngle+=dAngle;
    }
    painter->restore();

}

void myGauge1::drawCoverCircle(QPainter* painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);

    QRadialGradient coverGradient(m_center,m_coverCircleRadius,m_center);
    coverGradient.setColorAt(0.0,QColor(180,180,180));
    coverGradient.setColorAt(1.0,QColor(150,150,150));

    painter->setBrush(coverGradient);
    painter->drawEllipse(m_center,m_coverCircleRadius,m_coverCircleRadius);

    painter->restore();
}

void myGauge1::drawMarkAndText(QPainter* painter)
{
    painter->save();
    painter->translate(m_center);

    int value=90;
    QString strValue;
    qreal startAngle=90;
    qreal increment=(qreal)180/60;
    for(int i=0;i<=60;i++)
    {
        painter->save();
        painter->rotate(startAngle);
        if(i%10==0)
        {
            painter->setPen(QColor(16,49,98));
            QPointF bottomPot(0,m_colorPieRadius+m_space);
            QPointF topPot(0,m_colorPieRadius+m_space+m_longHand);
            painter->drawLine(bottomPot,topPot);

            strValue=tr("%1°").arg(value);
            qreal textWidth=fontMetrics().width(strValue);
            qreal textHeight=fontMetrics().height();
            QPointF textPot(-textWidth/2,m_colorPieRadius+2*m_space+m_longHand+textHeight);
            painter->save();
            painter->translate(textPot);
            painter->rotate(180);
            painter->drawText(QPointF(-textWidth,textHeight/2),strValue);
            painter->restore();
            value-=30;
        }
        else if(i%5==0)
        {

            painter->setPen(QColor(0,255,17));
            QPointF bottomPot(0,m_colorPieRadius+m_space);
            QPointF topPot(0,m_colorPieRadius+m_space+m_okHand);
            painter->drawLine(bottomPot,topPot);
        }
        else
        {

            painter->setPen(QColor(255,170,0));
            QPointF bottomPot(0,m_colorPieRadius+m_space);
            QPointF topPot(0,m_colorPieRadius+m_space+m_shortHand);
            painter->drawLine(bottomPot,topPot);
        }

        startAngle+=increment;
        painter->restore();
    }
    painter->restore();
}

void myGauge1::drawIndicator(QPainter* painter)
{
    painter->save();
    painter->setPen(QPen(Qt::blue,2));
    painter->translate(m_center);

    qreal increment=(qreal)180/180;
    qreal endAngle=90+m_currentValue*increment;
    painter->rotate(endAngle);
    painter->drawLine(QPointF(0,0),QPointF(0,m_colorPieRadius+m_longHand));

    painter->restore();
}

void myGauge1::drawTextRect(QPainter* painter)
{
    painter->save();
    qreal rectWidth=(m_colorPieRadius-m_coverCircleRadius)*1.2;

    painter->setOpacity(0.7);
    QPointF topLeftPot(m_center.x()-rectWidth,m_center.y()-rectWidth);
    QPointF bottomRightPot(m_center.x()+rectWidth,m_center.y()+rectWidth);
    QRectF textRect(topLeftPot,bottomRightPot);
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::cyan);
    painter->drawRoundRect(textRect,rectWidth*2,rectWidth*2);

    painter->setOpacity(1.0);
    painter->setPen(Qt::black);
    qreal fontSize=rectWidth*0.6;
    QFont font;
    font.setPointSize(fontSize);
    painter->setFont(font);
    painter->drawText(textRect,Qt::AlignVCenter|Qt::AlignHCenter,tr("%1°").arg(m_value));
    painter->restore();
}

void myGauge1::setValue(qreal value)
{
    m_value=value;
    m_currentValue=-1*value+90;
    update();
//    qDebug()<<m_currentValue<<m_value;
  /*  if(value>m_value)
    {
        m_bReverse=false;
        m_value=value;
        m_currentValue=value;
    }
    else if(value<m_value)
    {
        m_bReverse=true;
        m_value=value;
        m_currentValue=value;
    }
    else
    {
        return ;
    }
   qDebug()<<value<<m_value;
   */
  //  updateTimer->start();
}

void myGauge1::UpdateGraph()
{
    if(m_bReverse)
    {
        m_currentValue-=0.5;

        if(m_currentValue<=m_value)
        {
            updateTimer->stop();
        }
    }
    else
    {
        m_currentValue+=0.5;
        if(m_currentValue>=m_value)
        {
            updateTimer->stop();
        }
    }
    update();
}
