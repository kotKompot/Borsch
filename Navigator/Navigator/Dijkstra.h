#ifndef DIJKSTRA_H
#define DIJKSTRA_H


#include <string.h>
#include <Node.h>

class Dij
{

int inda;
Node *save;


void addarr(Node *cur[10], Node *n)
{
    cur[inda]=n;
    inda++;
    cur[inda]=0;
}

void poparr(Node *cur[10],int ind)
{
    for(ind; ind<10; ind++)
    {
        cur[ind]=cur[ind+1];
    }

    inda--;
    cur[inda]=0;
}

public: Node *DijF(Node *enter, Node *target)   //Должен возвращать *Node
    {
         Node *CurNode= enter;
         CurNode->mw=0;
         inda = 0;

         Node *cur[10]={0,0,0,0,0,0,0,0,0,0};

         int ind;
         int min=60000;

         CurNode->flag=1;
         CurNode->prevN=0;

    do
     {

       if(CurNode->neighbor[0].neigh!=0&&CurNode->neighbor[0].neigh->flag==0)
         {
             addarr(cur,CurNode->neighbor[0].neigh);
             if(CurNode->neighbor[0].neigh->mw > CurNode->mw+CurNode->neighbor[0].dist)
                   { CurNode->neighbor[0].neigh->mw = CurNode->mw+CurNode->neighbor[0].dist;
                     CurNode->neighbor[0].neigh->prevN=CurNode;}
         }

         if(CurNode->neighbor[1].neigh!=0&&CurNode->neighbor[1].neigh->flag==0)
         {
             addarr(cur,CurNode->neighbor[1].neigh);
             if(CurNode->neighbor[1].neigh->mw > CurNode->mw+CurNode->neighbor[1].dist)
                   { CurNode->neighbor[1].neigh->mw = CurNode->mw+CurNode->neighbor[1].dist;
                     CurNode->neighbor[1].neigh->prevN=CurNode;}
         }

         if(CurNode->neighbor[2].neigh!=0&&CurNode->neighbor[2].neigh->flag==0)
         {
             addarr(cur,CurNode->neighbor[2].neigh);
             if(CurNode->neighbor[2].neigh->mw > CurNode->mw+CurNode->neighbor[2].dist)
                   { CurNode->neighbor[2].neigh->mw = CurNode->mw+CurNode->neighbor[2].dist;
                     CurNode->neighbor[2].neigh->prevN=CurNode;}
         }

         if(CurNode->neighbor[3].neigh!=0&&CurNode->neighbor[3].neigh->flag==0)
         {
             addarr(cur,CurNode->neighbor[3].neigh);
             if(CurNode->neighbor[3].neigh->mw > CurNode->mw+CurNode->neighbor[3].dist)
                {  CurNode->neighbor[3].neigh->mw = CurNode->mw+CurNode->neighbor[3].dist;
                   CurNode->neighbor[3].neigh->prevN=CurNode;}

         }


         for(int i=0; cur[i]!=0; i++)
         {
             if(cur[i]->flag==0) if(cur[i]->mw<min)
             { min=cur[i]->mw;  ind=i; }
         }
         min=60000;  //уже н пмнб зчм эт, бз этг врд рбтт...

         CurNode=cur[ind];
         poparr(cur,ind);

         CurNode->flag=1;

     } while(target->flag!=1);

         return target;
    }

};



#endif // DIJKSTRA_H
