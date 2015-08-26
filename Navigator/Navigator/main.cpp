
#include <QApplication>
#include <QDialog>
#include <QtGui>
#include <QPainter>
#include <QPaintDevice>
#include <Node.h>
#include "MouseObserver.h"
#include "Dijkstra.h"
#include "inic.h"
#include "pSlot.h"

int main(int argc, char *argv[])

 {
    Node *mar[1000];
    QComboBox *SP;
    QComboBox *TP;
    MyWidget *tab1;
   // QLineEdit *tf2;
   // QLineEdit *tf;
    QTabWidget *tab;
    int w;
    int h;

    QApplication app(argc, argv);       //главный класс Qt приложения
    QIcon *img = new QIcon("icon.png");
    app.setWindowIcon(*img);


    QWidget *mw = new QWidget();
    mw->showMaximized();
    w = mw->geometry().width();
    h = mw->geometry().height();


     QVBoxLayout *LayoutM = new QVBoxLayout();
     QHBoxLayout *layout2 = new QHBoxLayout();


     SP= new QComboBox();

     QStringList StartPlace;
     StartPlace<<"Entry"<<"101" << "102" << "103" << "104"<< "106"
              <<"107"<<"108"<<"109"<<"110"<<"111"<<"112"<<"113"
             <<"114"<<"115"<<"116"<<"117"<<"117a"<<"118"<<"119"<<"120"<<"121"
            <<"122"<<"123"<<"124"<<"125"<<"rMainAccounting"<<"126"<<"127"<<"128"<<"129"<<"130_DeanOfAppMath"<<"131"
           <<"132"<<"133"<<"134"<<"135"<<"135a"<<"136"<<"137"<<"138"<<"139"<<"140"<<"141"<<"141a"<<"142"<<"143"
          <<"144"<<"144a"<<"145"<<"146"<<"147"<<"148"<<"149"<<"150"<<"151"<<"151a"<<"152"<<"152a"<<"153"<<"153a"
         <<"154"<<"155"<<"157a"<<"160"<<"161"<<"161a"<<"162"<<"162a"<<"163"<<"164"<<"165"<<"166"<<"166a"<<"167"<<"168"
        <<"169"<<"170"<<"170a"<<"171"<<"172"<<"173"<<"174"<<"175"<<"176"<<"178"<<"179"<<"180"<<"181"<<"182"<<"182a"<<"183"<<"184"<<"185"<<"186";
          SP->addItems(StartPlace);
          SP->setEditable(true);
          //SP->setGeometry(0,0,0.05*w,0.028*h);
          //SP->setGeometry(100,100,100,100);
          SP->setFixedWidth(0.1*w);
          SP->setFixedHeight(0.028*h);
          layout2->addWidget(SP);


     TP = new QComboBox();

     QStringList TargetPlace;
     TargetPlace<<"Entry"<<"101" << "102" << "103" << "104"<< "106"
               <<"107"<<"108"<<"109"<<"110"<<"111"<<"112"<<"113"
              <<"114"<<"115"<<"116"<<"117"<<"117a"<<"118"<<"119"<<"120"<<"121"
             <<"122"<<"123"<<"124"<<"125"<<"rMainAccounting"<<"126"<<"127"<<"128"<<"129"<<"130_DeanOfAppMath"<<"131"
            <<"132"<<"133"<<"134"<<"135"<<"135a"<<"136"<<"137"<<"138"<<"139"<<"140"<<"141"<<"141a"<<"142"<<"143"
           <<"144"<<"144a"<<"145"<<"146"<<"147"<<"148"<<"149"<<"150"<<"151"<<"151a"<<"152"<<"152a"<<"153"<<"153a"
          <<"154"<<"155"<<"157a"<<"160"<<"161"<<"161a"<<"162"<<"162a"<<"163"<<"164"<<"165"<<"166"<<"166a"<<"167"
         <<"168"<<"169"<<"170"<<"170a"<<"171"<<"172"<<"173"<<"174"<<"175"<<"176"<<"178"<<"179"<<"180"<<"181"<<"182"
        <<"182a"<<"183"<<"184"<<"185"<<"186";

               TP->addItems(TargetPlace);
               TP->setEditable(true);
               TP->setFixedWidth(0.1*w);
               TP->setFixedHeight(0.028*h);
               layout2->addWidget(TP);



     QPushButton *b = new QPushButton(QString::fromLocal8Bit("проложить маршрут"));
     b->setFixedWidth(0.1*w);
     b->setFixedHeight(0.028*h);
     layout2->addWidget(b);

//TP->setCurrentIndex(4);



     Node *end =inic(SP->currentIndex(),TP->currentIndex(),mar);


     //size of screen
     //QWidget *scr = QApplication::desktop()->screen(0); // 0 - это номер экрана (если он один то всегда 0)
     //int w = scr->width(); // ширина экрана
     //int h = scr->height(); // высота экрана
     ///size of screen


     QImage pix;
     pix.load("\plan.jpg");



     //mw->showFullScreen();
     //mw->setMinimumSize(w,h);



      tab = new QTabWidget();
      //tab->setFixedSize(w-0.05*w, h-50-0.028*h);

      tab1 = new MyWidget(&pix,end);
      tab1->setFixedSize(1343,670); //w-0.05*w+50,h-60-0.028*h);

      QScrollArea *scrollArea = new QScrollArea();
      scrollArea->setWidget(tab1);

      scrollArea->viewport()->setAutoFillBackground(true);
      scrollArea->setWidgetResizable(true);
      scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
      scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);



       tab->addTab(scrollArea,QString::fromLocal8Bit("первый этаж"));


//pSlot - класс велосипед
//---------------------------------------------------------------

      pSlot *ps = new pSlot(new QImage("\plan.jpg"),tab1,SP,TP,tab,w,h,mar);
      QObject::connect(b, SIGNAL(clicked()),
                       ps, SLOT(rep())
                       );
//---------------------------------------------------------------

      //tf2 = new QLineEdit;
      //tf = new QLineEdit;

     // layout2->addWidget(tf);
     // layout2->addWidget(tf2);


     // tf2->setText(QString::number(inic(SP->currentIndex(),TP->currentIndex(),mar)->mw));   //снести маркер
      //tf->setText(inic(SP->currentIndex(),TP->currentIndex(),mar)->name);                   //снести маркер

      /*
      QString s="";
      while(end!=0)
      {
          s+=end->name+" "+QString::number(end->x)+" "+QString::number(end->y);
          end=end->prevN;
      }
     // tf->setText(s);
      */

      LayoutM->addLayout(layout2);
      LayoutM->addWidget(tab);

      mw->setLayout(LayoutM);
      mw->show();

//-----------------
      MouseObserver wgt(mw,w,h);
      wgt.setGeometry(1000,100,300,300);
      wgt.show();
//-----------------
      return app.exec();
}




