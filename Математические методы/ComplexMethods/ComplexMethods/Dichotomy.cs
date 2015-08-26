using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ComplexMethods
{
    class Dichotomy
    {
        //поиск минимума

        double e;
        double step;
        double a, b;
        double x, y;
        int counter;
        double as1;
        double bs;

        public Dichotomy()
        {
            e = 0.5;
            step = 0.2;
            a = 0;
            b = 10;
            counter = 0;
            as1 = 0;
            bs = 10;
        }


        double f(double x)
        {
            /*
            if(x<=1&&x>=-1) { return x*x*x; }
            if(x>1) { return -x+2; }
            if(x<1) { return -x-2; }
            return x;
             */
            return x * x - 6 * x + 13;
        }

        public void calculate()
        {

            while ((b - a) >= 2 * e)
            {

                counter++;
                x = (a + b) / 2 - step;
                y = (a + b) / 2 + step;


                if (f(x) < f(y)) { b = x; }
                else
                {
                    a = y;
                }


            }
            Console.WriteLine("минимальная точка для унимодальной функции на отрезке [" + as1 + " ; " + bs + "]");
            Console.WriteLine("x = " + (a + b) / 2);
            Console.WriteLine("y = " + f((a + b) / 2));
            Console.WriteLine("Число итераций " + counter);
        }
    }

}
