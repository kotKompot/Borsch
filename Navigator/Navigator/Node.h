#ifndef NODE_H
#define NODE_H

#include <QtGui>
#include <QString>
#include <Node.h>
#include <math.h>

class Node
{
public:
struct neighbors
    {
        Node *neigh;
         int dist;
    };

public:
  //filds
    neighbors neighbor[4];
    QString name;
    int floor;
    int x;
    int y;
    int dir;      //загибание конца в север юг запад или восток
    int mw;       //минимальное расстояние до заданной вершины
    int flag;     //для дейкстры
    Node *prevN;
    int ind;      //номерн (не название) аудитории для QCombobox (велосипед)
  //filds


    Node(int ind, QString name, int floor, int dir, int x, int y, Node* mar[1000])
    {
        this->name=name;
        this->floor=floor;
        this->dir=dir;
        this->x=x;
        this->y=y;
        this->mw = 60000;
        this->flag = 0;
        this->ind=ind;
        mar[ind]=this;
        prevN=0;
    }

    int dist(int x1, int y1, int x2, int y2)
    {
        return (int)   sqrt(abs((double long)(y2-y1)*(y2-y1)+(x2-x1)*(x2-x1)));
    }

    void setNeighs(Node* neigh1=0, Node* neigh2=0, Node* neigh3=0, Node* neigh4=0)
    {
        this->neighbor[0].neigh=neigh1;
        this->neighbor[1].neigh=neigh2;
        this->neighbor[2].neigh=neigh3;
        this->neighbor[3].neigh=neigh4;

        if(neighbor[0].neigh!=0) this->neighbor[0].dist=dist(this->x,this->y, neighbor[0].neigh->x, neighbor[0].neigh->y);
        if(neighbor[1].neigh!=0) this->neighbor[1].dist=dist(this->x,this->y, neighbor[1].neigh->x, neighbor[1].neigh->y);
        if(neighbor[2].neigh!=0) this->neighbor[2].dist=dist(this->x,this->y, neighbor[2].neigh->x, neighbor[2].neigh->y);
        if(neighbor[3].neigh!=0) this->neighbor[3].dist=dist(this->x,this->y, neighbor[3].neigh->x, neighbor[3].neigh->y);
    }
};

#endif // NODE_H

