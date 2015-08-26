using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace NewtonRaphson
{
    class newtonRaphson
    {
        Point next;
        double e1, e2;
        Point first;
        Point grad;
        Point answer;
        Point d;
        Point preGrad;
        Point preD;
        double step;
        static GoldenRatio GR;
        Matrix m;
        double k;

        newtonRaphson(double e1, double e2, double x, double y)
        {
            this.e1 = e1;
            this.e2 = e2;
            first = new Point(x, y);
            next = new Point(first.x, first.y);
            grad = gradF(next);
            answer = new Point();
            d = new Point(-grad.x, -grad.y);
            preGrad = new Point(grad.x, grad.y);
            preD = new Point(d.x, d.y);
            GR = new GoldenRatio();
            m = new Matrix(16, -1, -1, 2);
        }

        static void Main()
        {
            newtonRaphson SL = new newtonRaphson(0.0001, 0.01, 2, 2);
            GR = new GoldenRatio();
            for (SL.k = 0; ; SL.k++)
            {

                Console.WriteLine();
                Console.WriteLine("--------------------------------------");           
                Console.WriteLine("\nточка:" + SL.next.x + " " + SL.next.y);
                Console.WriteLine("итерация: " + SL.k);
                Console.WriteLine("градиент: " + SL.grad.x+" "+SL.grad.y);
                Console.WriteLine("норма градиента: " + SL.normV(SL.grad));

                if (SL.normV(SL.grad) <= SL.e1) { SL.answer = SL.next; break; }


                if ((SL.m.Invert().Det()) > 0)
                {
                    SL.d = -((SL.m.Invert()) * SL.grad); 
                    
                }
                else
                {
                    SL.d.x = -SL.grad.x;
                    SL.d.y = -SL.grad.y;
                    
                }

                SL.step = GR.Calculate(SL.next, SL.d);
                Console.WriteLine("шаг: " + SL.step);
                //if(k>1000) { break;}

                SL.next.x = SL.first.x + SL.step * SL.d.x;
                SL.next.y = SL.first.y + SL.step * SL.d.y;

                // Console.WriteLine(k);



                if (SL.normV(new Point(SL.next.x - SL.first.x, SL.next.y - SL.first.y)) < SL.e2)
                {
                    if (Math.Abs(SL.F(SL.next.x, SL.next.y) - SL.F(SL.first.x, SL.first.y)) < SL.e2)
                    { SL.answer = SL.next; break; }
                }

                SL.first.x = SL.next.x;
                SL.first.y = SL.next.y;

                SL.grad = SL.gradF(SL.next);
           

         

            }

            SL.answer.x = SL.next.x;
            SL.answer.y = SL.next.y;
            Console.WriteLine();
            Console.WriteLine("--------------------------------------");
            Console.WriteLine("--------------------------------------");
            Console.WriteLine("\nОтвет:" + SL.answer.x + " " + SL.answer.y);
            Console.WriteLine("итерация: " + SL.k);
            Console.WriteLine("норма градиента: " +SL.normV(SL.grad));
            Console.Read();


        }

        Point gradF(double x1, double x2)
        {
            return new Point(16 * x1 - x2 + 1, 2 * x2 - x1);
        }

        Point gradF(Point p)
        {
            return new Point(16 * p.x - p.y + 1, 2 * p.y - p.x);
        }

        double normV(Point p)
        {
            return Math.Sqrt(p.x * p.x + p.y * p.y);
        }

        double F(double x1, double x2)
        {
            return 8 * x1 * x1 + x2 * x2 - x1 * x2 + x1;
        }

        //double H(Point p)
        //{
          //  return 1 / 31;// 1 / (16 * p.x * p.x - 2 * p.x * p.y + 2 * p.y * p.y);
        //}
    }
}
