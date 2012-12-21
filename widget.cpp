#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowOpacity(0.7);
    this->setFixedSize(400,60);
    this->setObjectName("ClockMainWindow");
//    this->setStyleSheet("QWidget#ClockMainWindow{font: 20px;background:black;border-width:2px;border-color:red; border-radius: 7px;}");
    this->setWindowFlags (Qt::FramelessWindowHint| Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    timeLabel = new QLabel("Ctyle Corporation");
    timeLabel->setFixedWidth(300);
    timeLabel->setAlignment(Qt::AlignCenter);

    timeLabel->setStyleSheet("QLabel{background-color:black;color:white;font:bold 20px;border-radius:7px;border-width:2px;border-color:red;}");
    timeLabel->setFixedSize(200,40);
    layout = new QHBoxLayout();
    layout->addWidget(timeLabel,0,Qt::AlignCenter);
    this->setLayout(layout);

    QTimer *timer = new QTimer(this);
    timer->setSingleShot(false);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(slotChangeTimeLabel()));
    timer->start(1*1000);
}

Widget::~Widget()
{

}
void Widget::slotChangeTimeLabel()
{
    this->timeLabel->setText(QDateTime::currentDateTime().toString("HH:mm:ss"));
    //qDebug() << "Get Current Time and Change The TimeLabel";
}
void Widget::mousePressEvent (QMouseEvent *e)
{
    if(e->buttons () == Qt::LeftButton) {
        last = e->globalPos ();
    }
    pos = e->globalPos () - e->pos ();
}
void Widget::mouseMoveEvent (QMouseEvent *e)
{
    if(!e->buttons () & Qt::LeftButton) {
        return;
    } else {
        QPoint newpos = e->globalPos ();
        QPoint upleft = pos + newpos - last;
        //use Manhatten Style will need the diff qpoint
        //QPoint diff = QPoint(0,20);
        move(upleft);
    }
}
