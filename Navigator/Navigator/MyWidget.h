#ifndef MYWIDGET_H
#define MYWIDGET_H

#endif // MYWIDGET_H

#include <QComboBox>
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QTextCodec>
#include <QDesktopWidget>
#include <QPainter>
#include <QPaintDevice>
#include "Node.h"



 class  MyWidget : public QWidget
{
     //Q_OBJECT

 public :
     int w,h;
     QImage pixl;
     Node *end,*save;
     QRect *r;

     MyWidget(QImage *pixo, Node *end=0)
     {
          pixl=*pixo;

          this->end=end;
          this->r = new QRect(0,0,1343,670); //w-0.05*w+50,h-60-0.028*h); //w-28,h-77);
     }


   void paintEvent(QPaintEvent *)
    {
        QPainter painter(this);
        painter.setBrush(QBrush(Qt::red));
        //painter.drawPoint(748,172);
        painter.drawImage(*r,pixl);
        //painter.drawRect(500*(w*10/9)/1000,700*(h*10/9)/1000,10,10);   //mouseObs:  z=1000*realpointX/w


        QPen pen(QBrush(QColor(136,38,179)), 4, Qt::SolidLine,Qt::RoundCap, Qt::RoundJoin);  //38,155,50

        painter.setPen(pen);
        //неработающая старая но логичная отрисовка--------------------------------------------
        //end=end->prevN;
       // painter.drawLine(end->prevN->x,end->prevN->y,end->prevN->prevN->x, end->prevN->prevN->y);
        //end=end->prevN;
        //painter.drawLine(end->prevN->prevN->x,end->prevN->prevN->y,end->prevN->prevN->prevN->x, end->prevN->prevN->y);
        //end=end->prevN;
       // painter.drawLine(end->prevN->prevN->prevN->x,end->prevN->prevN->prevN->y,end->prevN->prevN->prevN->prevN->x, end->prevN->prevN->prevN->prevN->y);
       //--------------------------------------------------------------------------------------
       save=end;
       //Node *s;
       //s=save;

        if (end!=0) if(end->prevN!=0)
        {

           painter.drawLine(end->x,end->y,end->prevN->x, end->prevN->y);
           while(save->prevN!=0)
            {
            painter.drawLine(save->x,save->y,save->prevN->x, save->prevN->y);
            save=save->prevN;
            }
        }
       //painter.drawEllipse(s->x,s->y,10,10);
       //painter.drawRect(save->x,save->y,5,5);
 }

};


