
#include <QWidget>
#include <Node.h>
//#include <inic.h>
#include <QObject>
#include "inic.h"
#include "MyWidget.h"


class pSlot : public QWidget
{
    Q_OBJECT


public:

    QComboBox *SP;
    QComboBox *TP;
    QTabWidget *tab;
    MyWidget *tab1;
    int w,h;
    QImage *pix;
    Node *mar[1000];



    pSlot(QImage *pix, MyWidget *tab1, QComboBox *SP, QComboBox *TP,QTabWidget *tab,int w,int h, Node *mar[1000])
    {
        this->SP=SP;
        this->TP=TP;
        this->tab=tab;
        this->tab1=tab1;
        this->pix = pix;

        this->w=w;
        this->h=h;
        for(int i=0; i<1000;i++)
        this->mar[i]=mar[i];

    }


private slots:
    void rep()
    {
        for(int i=0; i<=100;i++)
        {
            delete mar[i];
        }




    delete tab1;
    tab->removeTab(0);
    tab1 = new MyWidget(pix,inic(SP->currentIndex(),TP->currentIndex(),mar));

    tab1->setFixedSize(1343,670); //w-0.05*w+50,h-60-0.028*h);
    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setWidget(tab1);

    scrollArea->viewport()->setAutoFillBackground(true);
    scrollArea->setWidgetResizable(true);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    tab->addTab(scrollArea,QString::fromLocal8Bit("первый этаж"));

    }

};
