using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace newton
{
    struct Matrix
    {
        double M11;
        double M12;
        double M21;
        double M22;

        public Matrix(double m11, double m12, double m21, double m22)
        {
            M11 = m11; M12 = m12; M21 = m21; M22 = m22;
        }

        public double Det()
        {
            return M11 * M22 - M12 * M21;
        }

        public Matrix Invert()
        {
            return ( (1 / Det()) * new Matrix(
                        M22, -M12, -M21, M11) );
        }

        public static Matrix operator *(double c, Matrix m)
        {
            return ( new Matrix(
                c * m.M11, c * m.M12,
                c * m.M21, c * m.M22) );
        }

        public static Point operator *(Matrix m, Point v)
        {
            return ( new Point(
                m.M11 * v.x + m.M12 * v.y,
                m.M21 * v.x + m.M22 * v.y) );
        }
    }
}
