//��������� ������������ ������ Position-Based �������



#include "hge.h"                              //����������� ������������ ������ ������ HGE
#include "hgefont.h"
#include <math.h>                       //����������� ����������
//#include <iostream>  ������������� ��� �������


#define SCREEN_WIDTH  1024          //������ ������
#define SCREEN_HEIGHT 768           //������ ������

#define MIN_OBJECTS	10                    //����������� ����� ��������
#define MAX_OBJECTS 300                //������������ ����� ��������

struct sprObject                  //��������� ������ ���������� �� ����� ������
{
	float curX,curY;               //curX ������� ��������� ������ �� X, �������������� �� Y.
	float preX,preY;               //preX ���������� ��������� ������ �� X, �������������� �� Y.
	float dx,dy;                         //�������� ��������� X � Y
	float  rad;                             //������ ����
};

sprObject*	pObjects;           // pObjects ������ �� ��������� ����
int			nObjects;                   //����� �����
double penetr,dxb,dyb;  //���������� ��� ���������� ������ ������������
double s;                                 //���������� ������������� ����� ���� ��� ������ timeFrame,
float timeFrame=0.05f;          //�������� ����
float grav = 0;                              //����������
float rub=0.01f;                         //������ ��� ����� �� ���

HGE *hge=0;                            //��������� �� ��������� ������


HTEXTURE			tex;        //��������� ��������
hgeSprite			*spr;     //������ ������
hgeFont				*fnt;           //�����




double dist(int x1, int y1, int x2, int y2)                        //������� ���������� ���������� ����� �������
    {
        return  sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1));
    }


bool FrameFunc()                                                 //������� ��� ����������� ��� ������,  ���������� ��� �� ����
{
	float dt=hge->Timer_GetDelta();               //����� � �������� ������ �������


    switch(hge->Input_GetKey())                          //���������� ����� � ������� ������
	{
		case HGEK_UP:		if(nObjects<MAX_OBJECTS) nObjects+=10; break;                                     //������� ����� -��������� ���������� ��������
		case HGEK_DOWN:		if(nObjects>MIN_OBJECTS) nObjects-=10; break;                                // ������� ���� ���������
        case HGEK_LEFT:      timeFrame=0.01f ; break;                                                                                     //������� ������ ����� ��� ������ ��������
        case HGEK_RIGHT:   timeFrame=0.005f; break;
        case HGEK_SPACE:    if(grav==0) {grav=1;} else {grav=0;}  break;                                            //������ ���������/���������� ����������(������������� ���� ����������...)
		case HGEK_ESCAPE:	return true;                               //esc �����
	}


if(s>timeFrame)   //����� ����� ����� �������� �����
  {
      s=0;     //��������� ����� �������

for(int i=0;i<nObjects;i++)                 //������ �� ���� ��������
	{
                //������� ������� ������������� �������� ����� ��� � ���������� ��������
               // �������������� ���������� ������� ������������� ������ ������� ��������
                  pObjects[i].dx=pObjects[i].curX-pObjects[i].preX;
                  pObjects[i].dy=pObjects[i].curY-pObjects[i].preY;
                  pObjects[i].preX = pObjects[i].curX;
                  pObjects[i].preY = pObjects[i].curY;
                  pObjects[i].curY+= pObjects[i].dy+grav;  //� �������� �� Y ����������� ����������
                  pObjects[i].curX+= pObjects[i].dx;


            if(pObjects[i].curX>SCREEN_WIDTH-pObjects[i].rad|| pObjects[i].curX<0+pObjects[i].rad)                   //���� ���� �� ����� ��� ������ ����� ����� ��������
                {                                                                                                                                                                                                           //������� � ���������� ���������, ��� ����� ������� �����������
                    pObjects[i].dx=pObjects[i].curX;                                                                                                                                     //�������� �� X �� ���������������
                    pObjects[i].curX=pObjects[i].preX;
                    pObjects[i].preX=pObjects[i].dx;
                }

            if(pObjects[i].curY>SCREEN_HEIGHT -pObjects[i].rad|| pObjects[i].curY<0+pObjects[i].rad)                 //���� ����� � ����� � ��������
                {
                    pObjects[i].dy=pObjects[i].curY;
                    pObjects[i].curY=pObjects[i].preY;
                    pObjects[i].preY=pObjects[i].dy;

                    if(pObjects[i].dx>0){pObjects[i].curX-=rub; }      //������ ��� ����� �� ��� ��� �������
                   if(pObjects[i].dx<0){pObjects[i].curX+=rub; }     //

                }


	}


//���������� ������ ����������� �� Position-Based �������
             for(int i = 0; i <nObjects-1; i++)
               {
                 for(int j = i + 1; j < nObjects; j++)
                   {

                       if(dist(pObjects[i].curX, pObjects[i].curY, pObjects[j].curX, pObjects[j].curY) <(pObjects[i].rad + pObjects[j].rad))   //���� ���������� ����� ������ ������ ����� ��������
                          {

                              penetr=pObjects[i].rad + pObjects[j].rad-dist(pObjects[i].curX, pObjects[i].curY, pObjects[j].curX, pObjects[j].curY)+0.001;  //������� ������������� ���� � ���

                             //������������
                            dxb=(pObjects[j].curX-pObjects[i].curX)/sqrt(((pObjects[j].curX-pObjects[i].curX)*(pObjects[j].curX-pObjects[i].curX)+(pObjects[j].curY-pObjects[i].curY)*(pObjects[j].curY-pObjects[i].curY)));
                            dyb=(pObjects[j].curY-pObjects[i].curY)/sqrt(((pObjects[j].curX-pObjects[i].curX)*(pObjects[j].curX-pObjects[i].curX)+(pObjects[j].curY-pObjects[i].curY)*(pObjects[j].curY-pObjects[i].curY)));

                            //�������������� ����� ����� ����������� ������ ��� ���� ����������� ���� ����������, ��� ���� ��� �� ���� �� ����������� ���� ����� �� ���
                            pObjects[i].curX-=dxb*penetr*0.2f;
                            if((pObjects[i].curY-dyb*penetr*0.2f)< (SCREEN_HEIGHT -pObjects[i].rad) )
                                { pObjects[i].curY-=dyb*penetr*0.2f; } else {pObjects[i].curY+=dyb*penetr*0.1f; }

                              pObjects[j].curX+=dxb*penetr*0.2f;
                              if((pObjects[j].curY-dyb*penetr*0.2f)< (SCREEN_HEIGHT -pObjects[j].rad))
                               {pObjects[j].curY+=dyb*penetr*0.2f; } else {pObjects[j].curY-=dyb*penetr*0.1f; }

                          }
                    }
                 }

      }   else s+=dt;    //���������� ������� ��� �������� �����������
	return false;
}


bool RenderFunc()    //������� ���������
{

    hge->Gfx_BeginScene();  //������ �����
	hge->Gfx_Clear(0);            //������� ������


	for(int i=0;i<nObjects;i++) //������ �� ���� ����� � �� ���������
	{
           spr->RenderEx(pObjects[i].curX, pObjects[i].curY, 0, 1);
	}

	fnt->printf(7, 7, HGETEXT_LEFT, "UP and DOWN to adjust number of hares: %d\nSPACE to change blending mode: %d\nFPS: %d", nObjects, 0, hge->Timer_GetFPS());  //��������� ������
	hge->Gfx_EndScene();  //����� �����

	return false;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)          //����������� ����� ����� � ���������� windows
{

	hge = hgeCreate(HGE_VERSION);   //��������� �� ��������� hge

    hge->System_SetState(HGE_LOGFILE, "hge log bubbles.log");                                            //���� ����
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);                                                      //������� ������� �����
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);                                                  //������� ������� ���������
	hge->System_SetState(HGE_TITLE, "HGE  Bubbles");                                                               //������� ���������
	hge->System_SetState(HGE_USESOUND, false);                                                                        //������������� �����(���)
	hge->System_SetState(HGE_WINDOWED, true);                                                                       //������� �� ����������
	hge->System_SetState(HGE_SCREENWIDTH, SCREEN_WIDTH);                                         //������� ����
	hge->System_SetState(HGE_SCREENHEIGHT, SCREEN_HEIGHT);
	hge->System_SetState(HGE_SCREENBPP, 32);                                                                             //���-�� � ������� ���������...   =_=

	if(hge->System_Initiate())        //������������� ���������� � ������ �������� ��������� ���� ��������
	{


		tex=hge->Texture_Load("tr2.png"); //�������� ������� ����

		if( !tex)   //�������� ��������� �������� �������
		{
			MessageBox(NULL, "Can't load BG2.PNG or TR.PNG", "Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);    //����� ���� ������
			hge->System_Shutdown();   // ��������� ����������
			hge->Release();        //���������� �������
			return 0;
		}



		fnt=new hgeFont("font2.fnt");
		spr=new hgeSprite(tex,0,0,64,64);
		spr->SetHotSpot(32,32);

        pObjects=new sprObject[MAX_OBJECTS];  //�������� ������� �����
		nObjects=5;  //��������� ���������� ��������

		for(int i=0;i<MAX_OBJECTS;i++)       //������ �� ���� �������� � ������� �� �������
		{
		    pObjects[i].rad=30;  //������
			pObjects[i].curX=hge->Random_Float(0+100, SCREEN_WIDTH-100); //������� ��������� ������� �������
			pObjects[i].curY=hge->Random_Float(0+100, SCREEN_HEIGHT-100);
			pObjects[i].preX=pObjects[i].curX+hge->Random_Float(-2,+2);  //������� ��������� ���������� �������(�������� ������� �� ���� �������� �� ������� �������)
			pObjects[i].preY=pObjects[i].curY+hge->Random_Float(-2,+2);
			//pObjects[i].rot=hge->Random_Float(0,M_PI*2);                              //��������������� �������� �����
			//pObjects[i].drot=hge->Random_Float(-1.0f,1.0f);
		}




		hge->System_Start();    //������ ����� ����

		delete[] pObjects;                   //������������ ���� �������� � ����� �� ����
		delete fnt;
		delete spr;
		hge->Texture_Free(tex);
	}


	hge->System_Shutdown();
	hge->Release();
	return 0;
}
