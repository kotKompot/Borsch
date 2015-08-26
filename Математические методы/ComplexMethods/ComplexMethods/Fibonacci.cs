using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ComplexMethods
{

    class Fibonacci
    {

        double Fun(double x)
        {
            return 7630*x * x - 965 * x + 34;
        }

        int Fib(int n)
        {
            int f, f1 = 1, f2 = 1, m = 0;

            while (m < n - 1)
            {
                f = f1 + f2;
                f1 = f2;
                f2 = f;
                ++m;
            }
            return f1;
        }

        public void Calculate() 
    {
   
    double eps=0.0005; 
    double a=-100, b=100;
    double x, y, _x, xf, yf;
    int k=0;
    int N=0;
    double fn1=1, fn2=1, fn, f = (b - a) / eps;

    while(fn1 <= f)
    {
        fn = fn1 + fn2;
        fn1 = fn2;
        fn2 = fn;
        ++N;
    }

    x = a + (double)Fib(N - 2) / Fib(N) * (b - a);
    y = a + b - x;
    xf = Fun(x);
    yf = Fun(y);
    
  while(k!=N-2)
  {
      Console.WriteLine("Итерация № " + (k + 1));
      
      Console.WriteLine("a(" + (k+1) + ") = " + a);
      Console.WriteLine("b(" + (k+1) + ") = " + b);
      Console.WriteLine("y(" + (k+1) + ") = " + y);
      Console.WriteLine("x(" + (k+1) + ") = " + x);
      Console.WriteLine("f( x(" + (k+1) + ") ) = " + xf);
      Console.WriteLine("f( y(" + (k+1) + ") ) = " + yf);
      
    ++k;
    if(xf > yf)
    {
        Console.WriteLine("\n" + "f(x) > f(y)");
        Console.WriteLine("новый отрезок от a=" + x + " до b=" + b);
        a = x;
        x = y;
        xf = yf;
        y = b - (x - a);
        yf = Fun(y);
        
    }
    else
    {
        Console.WriteLine("\n" + "f(x) <= f(y)");
        Console.WriteLine("новый отрезок от a=" + a + " до b=" + y);
        b = y;
        y = x;
        yf = xf;
        x = a + b-y;
        xf = Fun(x);
    }
    Console.WriteLine("\n");


    
 
  }

  xf = Fun(x); yf = Fun(y);
  if (xf == yf) { y += eps / 5; }
  yf = Fun(y);

  if (xf > yf)
  {
      a = x;
  }
  else
  {
      b = y;
  }

        _x = (a + b) / 2;
        Console.WriteLine("Результат:\nx = " + _x + "\t\tF(x) = " + Fun(_x) + "\nКоличество итераций: " + k);
}
    }

}