#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>
#include <QtWidgets>
#include <QLabel>
#include <QHBoxLayout>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void slotChangeTimeLabel();
private:
    QLabel *timeLabel;
    QPoint last,pos;
    QHBoxLayout *layout;
    void mousePressEvent (QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
};

#endif // WIDGET_H
