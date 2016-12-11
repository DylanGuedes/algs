class Line {
public:
        double a;
        double b;
        double c;

        Line(double av, double bv, double cv) : a(av), b(bv), c(cv) {}

        Line(const Point& p, const Point& q)
        {
                a = p.y - q.y;
                b = q.x - p.x;
                c = p.x * q.y - p.y * q.x;

                auto k = a ? a : b;

                a /= k;
                b /= k;
                c /= k;
        }

        bool operator==(const Line& r) const
        {
                return equals(a, r.a) && equals(b, r.b) && equals(c, r.c);
        }

        bool parallel(const Line& r) const
        {
                return equals(a, r.a) && equals(b, r.b) && !equals(c, r.c);
        }

        bool orthogonal(const Line& r) const
        {
                return equals(a * r.a + b * r.b, 0);
        }

        double distance(const Point& p) const
        {
                return fabs(a*p.x + b*p.y + c)/hypot(a, b);
        }

        Point closest(const Point& p) const // Ponto da reta mais próximo de p
        {
                auto den = a*a + b*b;
                auto x = (b*(b*p.x - a*p.y) - a*c)/den;
                auto y = (a*(-b*p.x + a*p.y) - b*c)/den;

                return Point(x, y);
        }
};

#define INF -1

pair<int, Point> intersections(const Line& r, const Line& s)
{
        auto det = r.a * s.b - r.b * s.a;

        if (equals(det, 0))
        {
                // Coincidentes ou paralelas
                int qtd = (r == s) ? INF : 0;

                return pair<int, Point>(qtd, Point());
        } else {
                // Concorrentes
                auto x = (-r.c * s*b + s.c * r.b) / det;
                auto y = (-s.c * r.a + r.c * s.a) / det;

                return pair<int, Point>(1, Point(x, y));
        }
}

// // Ângulo entre os segmentos de reta PQ e RS
double angle(const Point& P, const Point& Q, const Point& R, const Point& S)
{
        auto ux = P.x - Q.x;
        auto uy = P.y - Q.y;

        auto vx = R.x - S.x;
        auto vy = R.y - S.y;

        auto num = ux * vx + uy * vy;
        auto den = hypot(ux, uy) * hypot(vx, vy);

        // Caso especial: se den == 0, algum dos vetores é degenerado: os dois
        // pontos são iguais. Neste caso, o ângulo não está definido

        return acos(num / den);
}

Line perpendicular_bisector(const Point& P, const  Point& Q)
{
        auto a = 2*(Q.x - P.x);
        auto b = 2*(Q.y - P.y);
        auto c = (P.x * P.x + P.y * P.y) - (Q.x * Q.x + Q.y * Q.y);

        return Line(a, b, c);
}

double D(const Point& P, const Point& Q, const Point& R)
{
        return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
}
