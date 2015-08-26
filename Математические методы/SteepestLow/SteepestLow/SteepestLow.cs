using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SteepestLow
{
    class SteepestLow
    {
        Point next;
        double e1, e2;
        Point first;
        Point grad;
        Point answer;
        double step;
        static GoldenRatio GR;

        SteepestLow(double e1, double e2, double x, double y)
        {
            this.e1 = e1;
            this.e2 = e2;
            first = new Point(x,y);
            next = new Point(first.x, first.y);
            answer = new Point();
            GR = new GoldenRatio();
        }

        static void Main()
        {
            SteepestLow SL = new SteepestLow(0.0001, 0.01, 2, 2);
             GR = new GoldenRatio();
            for (int k = 0; ; k++)
            {
                Console.WriteLine("-------------------------------------------------------------");
                SL.grad = SL.gradF(SL.next);
                if (SL.normV(SL.grad) < SL.e1) { SL.answer = SL.next; break; }
                SL.step = GR.Calculate(SL.next, SL.grad);

                SL.first.x = SL.next.x;


                SL.first.y = SL.next.y;

                SL.next.x = SL.first.x - SL.step * SL.grad.x;
                SL.next.y = SL.first.y - SL.step * SL.grad.y;
                Console.WriteLine("-------------------------------------------------------------");
                Console.WriteLine(SL.step);
                Console.WriteLine(k);
                Console.WriteLine("-------------------------------------------------------------");
                if (SL.normV(new Point(SL.next.x - SL.first.x, SL.next.y - SL.first.y)) < SL.e2) { 
                    if (Math.Abs(SL.F(SL.next.x, SL.next.y) - SL.F(SL.first.x, SL.first.y)) < SL.e2) 
                    { SL.answer = SL.next; break; } }
               
            }

            SL.answer.x = SL.next.x;
            SL.answer.y = SL.next.y;
            Console.WriteLine();
            Console.WriteLine("\nОтвет:"+ SL.answer.x + " " + SL.answer.y);
            Console.WriteLine(SL.normV(SL.grad));
            Console.Read();


        }

        Point gradF(double x1, double x2)
        {
            return new Point(16*x1-x2+1, 2*x2-x1);        
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
    }
}
