//Программа визуализация физики Position-Based подхода



#include "hge.h"                              //подключение заголовочных файлов движка HGE
#include "hgefont.h"
#include <math.h>                       //стандартная математика
//#include <iostream>  использовался для отладки


#define SCREEN_WIDTH  1024          //ширина экрана
#define SCREEN_HEIGHT 768           //высота экрана

#define MIN_OBJECTS	10                    //минимальное число объектов
#define MAX_OBJECTS 300                //максимальное число объектов

struct sprObject                  //структура хранит информацию об одной шарике
{
	float curX,curY;               //curX текушие положение шарика по X, соответственно по Y.
	float preX,preY;               //preX предыдущее положение шарика по X, соответственно по Y.
	float dx,dy;                         //величины изменений X и Y
	float  rad;                             //Радиус шара
};

sprObject*	pObjects;           // pObjects ссылка на структуру шара
int			nObjects;                   //число шаров
double penetr,dxb,dyb;  //переменные для реализации физики столкновений
double s;                                 //переменная накапливающая время пока оно меньше timeFrame,
float timeFrame=0.05f;          //скорость игры
float grav = 0;                              //гравитация
float rub=0.01f;                         //трение при ударе об пол

HGE *hge=0;                            //указатель на интерфейс движка


HTEXTURE			tex;        //текстовые текстуры
hgeSprite			*spr;     //спрайт шарика
hgeFont				*fnt;           //текст




double dist(int x1, int y1, int x2, int y2)                        //функция нахождения расстояния между точками
    {
        return  sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1));
    }


bool FrameFunc()                                                 //Функция где реализуется вся физика,  вызывается раз за кадр
{
	float dt=hge->Timer_GetDelta();               //время с прошлого вызова функции


    switch(hge->Input_GetKey())                          //управление игрой с помощью кнопок
	{
		case HGEK_UP:		if(nObjects<MAX_OBJECTS) nObjects+=10; break;                                     //стрелка вверх -увеличить количество объектов
		case HGEK_DOWN:		if(nObjects>MIN_OBJECTS) nObjects-=10; break;                                // стрелка вниз уменьшить
        case HGEK_LEFT:      timeFrame=0.01f ; break;                                                                                     //стрелки вправо влево два режима скорости
        case HGEK_RIGHT:   timeFrame=0.005f; break;
        case HGEK_SPACE:    if(grav==0) {grav=1;} else {grav=0;}  break;                                            //пробел включение/отключение гравитации(недоработанно шары тромбуются...)
		case HGEK_ESCAPE:	return true;                               //esc выход
	}


if(s>timeFrame)   //вызов кадра через заданное время
  {
      s=0;     //обнуление суммы времени

for(int i=0;i<nObjects;i++)                 //проход по всем объектам
	{
                //текущей позиции присваивается разность между ней и предыдущей позицией
               // соответственно предыдущей позиции присваивается старое текущее значение
                  pObjects[i].dx=pObjects[i].curX-pObjects[i].preX;
                  pObjects[i].dy=pObjects[i].curY-pObjects[i].preY;
                  pObjects[i].preX = pObjects[i].curX;
                  pObjects[i].preY = pObjects[i].curY;
                  pObjects[i].curY+= pObjects[i].dy+grav;  //к движению по Y добавляется гравитация
                  pObjects[i].curX+= pObjects[i].dx;


            if(pObjects[i].curX>SCREEN_WIDTH-pObjects[i].rad|| pObjects[i].curX<0+pObjects[i].rad)                   //если удар об левую или правую стену тогда поменять
                {                                                                                                                                                                                                           //текущее и предыдущее положение, тем самым поменяв направление
                    pObjects[i].dx=pObjects[i].curX;                                                                                                                                     //движение по X на противоположное
                    pObjects[i].curX=pObjects[i].preX;
                    pObjects[i].preX=pObjects[i].dx;
                }

            if(pObjects[i].curY>SCREEN_HEIGHT -pObjects[i].rad|| pObjects[i].curY<0+pObjects[i].rad)                 //таже штука с полом и потолком
                {
                    pObjects[i].dy=pObjects[i].curY;
                    pObjects[i].curY=pObjects[i].preY;
                    pObjects[i].preY=pObjects[i].dy;

                    if(pObjects[i].dx>0){pObjects[i].curX-=rub; }      //трение при ударе об пол или потолок
                   if(pObjects[i].dx<0){pObjects[i].curX+=rub; }     //

                }


	}


//реализация физики стокновений по Position-Based подходу
             for(int i = 0; i <nObjects-1; i++)
               {
                 for(int j = i + 1; j < nObjects; j++)
                   {

                       if(dist(pObjects[i].curX, pObjects[i].curY, pObjects[j].curX, pObjects[j].curY) <(pObjects[i].rad + pObjects[j].rad))   //если расстояние между шарами меньше суммы радиусов
                          {

                              penetr=pObjects[i].rad + pObjects[j].rad-dist(pObjects[i].curX, pObjects[i].curY, pObjects[j].curX, pObjects[j].curY)+0.001;  //степень проникновение шара в шар

                             //нормализация
                            dxb=(pObjects[j].curX-pObjects[i].curX)/sqrt(((pObjects[j].curX-pObjects[i].curX)*(pObjects[j].curX-pObjects[i].curX)+(pObjects[j].curY-pObjects[i].curY)*(pObjects[j].curY-pObjects[i].curY)));
                            dyb=(pObjects[j].curY-pObjects[i].curY)/sqrt(((pObjects[j].curX-pObjects[i].curX)*(pObjects[j].curX-pObjects[i].curX)+(pObjects[j].curY-pObjects[i].curY)*(pObjects[j].curY-pObjects[i].curY)));

                            //расстаскивание вдоль линии соеденяющей центры при этом добавляется пара механизмов, для того что бы шары не выдавливали друг друга за пол
                            pObjects[i].curX-=dxb*penetr*0.2f;
                            if((pObjects[i].curY-dyb*penetr*0.2f)< (SCREEN_HEIGHT -pObjects[i].rad) )
                                { pObjects[i].curY-=dyb*penetr*0.2f; } else {pObjects[i].curY+=dyb*penetr*0.1f; }

                              pObjects[j].curX+=dxb*penetr*0.2f;
                              if((pObjects[j].curY-dyb*penetr*0.2f)< (SCREEN_HEIGHT -pObjects[j].rad))
                               {pObjects[j].curY+=dyb*penetr*0.2f; } else {pObjects[j].curY-=dyb*penetr*0.1f; }

                          }
                    }
                 }

      }   else s+=dt;    //накопление времени для скорости отображения
	return false;
}


bool RenderFunc()    //функция отрисовки
{

    hge->Gfx_BeginScene();  //начало сцены
	hge->Gfx_Clear(0);            //очистка экрана


	for(int i=0;i<nObjects;i++) //проход по всем шарам и их отрисовка
	{
           spr->RenderEx(pObjects[i].curX, pObjects[i].curY, 0, 1);
	}

	fnt->printf(7, 7, HGETEXT_LEFT, "UP and DOWN to adjust number of hares: %d\nSPACE to change blending mode: %d\nFPS: %d", nObjects, 0, hge->Timer_GetFPS());  //отрисовка текста
	hge->Gfx_EndScene();  //конец сцены

	return false;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)          //стандартная точка входа в приложение windows
{

	hge = hgeCreate(HGE_VERSION);   //указатель на интерфейс hge

    hge->System_SetState(HGE_LOGFILE, "hge log bubbles.log");                                            //файл лога
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);                                                      //задание функции кадра
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);                                                  //задание функции отрисовки
	hge->System_SetState(HGE_TITLE, "HGE  Bubbles");                                                               //задание заголовка
	hge->System_SetState(HGE_USESOUND, false);                                                                        //использование звука(нет)
	hge->System_SetState(HGE_WINDOWED, true);                                                                       //оконное ли приложение
	hge->System_SetState(HGE_SCREENWIDTH, SCREEN_WIDTH);                                         //размеры окна
	hge->System_SetState(HGE_SCREENHEIGHT, SCREEN_HEIGHT);
	hge->System_SetState(HGE_SCREENBPP, 32);                                                                             //что-то с цветами связанное...   =_=

	if(hge->System_Initiate())        //инициализация интерфейса и заодно проверка удачности сего процесса
	{


		tex=hge->Texture_Load("tr2.png"); //загрузка спрайта шара

		if( !tex)   //проверка удачности загрузки спрайта
		{
			MessageBox(NULL, "Can't load BG2.PNG or TR.PNG", "Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);    //вывод окна ошибки
			hge->System_Shutdown();   // завершить приложение
			hge->Release();        //освободить ресурсы
			return 0;
		}



		fnt=new hgeFont("font2.fnt");
		spr=new hgeSprite(tex,0,0,64,64);
		spr->SetHotSpot(32,32);

        pObjects=new sprObject[MAX_OBJECTS];  //создание массива шаров
		nObjects=5;  //начальное количество объектов

		for(int i=0;i<MAX_OBJECTS;i++)       //проход по всем объектам и задание им свойств
		{
		    pObjects[i].rad=30;  //радиус
			pObjects[i].curX=hge->Random_Float(0+100, SCREEN_WIDTH-100); //задание начальной текущей позиции
			pObjects[i].curY=hge->Random_Float(0+100, SCREEN_HEIGHT-100);
			pObjects[i].preX=pObjects[i].curX+hge->Random_Float(-2,+2);  //задание начальной предыдущей позиции(рандомно смещена на пару пиксилей от текущей позиции)
			pObjects[i].preY=pObjects[i].curY+hge->Random_Float(-2,+2);
			//pObjects[i].rot=hge->Random_Float(0,M_PI*2);                              //нереализованное вращение шаров
			//pObjects[i].drot=hge->Random_Float(-1.0f,1.0f);
		}




		hge->System_Start();    //запуск цикла игры

		delete[] pObjects;                   //освобождение всех ресурсов и выход из игры
		delete fnt;
		delete spr;
		hge->Texture_Free(tex);
	}


	hge->System_Shutdown();
	hge->Release();
	return 0;
}
