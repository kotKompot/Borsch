using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ComplexMethods
{
    class GoldenRatio
    {
        static double Fun(double x)
        {
            //return x * x;
            return x * x - 6 * x + 13;
        }

        public void Calculate() 
    {
        double eps = 0.5;
        double tay = (3-Math.Sqrt(5))/2;         //золотое сечение
        double a=0, b=10;
        double x, y, _x, xf, yf;
        int iter=0;
        
        
        x = a +  tay *(b-a);     
        y = a + b-x;
        xf = Fun(x);
        yf = Fun(y);
        
        double check;
        double as1=a;    //для вывода 
        double bs=b;             
        
     while((Math.Abs(b - a) >= 2*eps) )
     {
        check = b-a;
        iter++;
        
                Console.WriteLine("\n");
                Console.WriteLine("a("+iter+") = "+a);
                Console.WriteLine("b("+iter+") = "+b);
                Console.WriteLine("y("+iter+") = "+y);
                Console.WriteLine("x("+iter+") = "+x);   
                Console.WriteLine("f( x("+iter+") ) = "+xf);
                Console.WriteLine("f( y("+iter+") ) = "+yf);
        
        if(xf > yf)
        {
            Console.WriteLine("\n"+"f(x) > f(y)");
            Console.WriteLine("новый отрезок от a="+x+" до b="+b);
                a = x;
                x = y;
                xf = yf;
                y = a + b-x;
                //y = a + tay * (b - a);
                yf = Fun(y);
        }
        else
        {
            Console.WriteLine("\n" + "f(x) <= f(y)");
            Console.WriteLine("новый отрезок от a=" + a + " до b=" + y);
                b = y;
                y = x;
                yf = xf;
                x = a + b - x;
                //x = a + tay * (b - a);
                xf = Fun(x);
                      
        }
            
        if(check==b-a)  { Console.WriteLine("Achtung!!!"); break;  }
     } 
     
     _x = (a + b) / 2;
      Console.WriteLine("\n"+"минимальная точка для унимодальной функции на отрезке ["+as1+" ; "+bs+"]");
      Console.WriteLine("Результат:\nx = "+_x+"\t\tF(x) = "+Fun(_x)+"\nКоличество итераций: "+iter);
              
    }
    }
}
