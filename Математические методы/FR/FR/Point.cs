using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace FR
{
    public class Point
    {
        public double x, y;

        public Point(double x, double y)
        {
            this.x = x;
            this.y = y;
        }

        public Point()
        {
            x = 0; y = 0;
        }

        public void set(Point point)
        {
            set(point.x, point.y);
        }
        public void set(double x, double y)
        {
            this.x = x;
            this.y = y;
        }
    }

}
