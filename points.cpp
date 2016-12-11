#include <iostream>

using namespace std;

struct Point {
        double x;
        double y;
        double z;
};

bool operator==(const point& a, const point& b)
{
        return equals(a.first, b.first) && equals(a.second, b.second);
}

bool operator<(const Point& p, const Point& q)
{
        return (fabs(p.x - q.x) < EPS) ? (q.y - p.y) > -EPS : q.x - p.x > -EPS);
}

double distance(const Point& P, const Point& Q)
{
        return sqrt((P.x - Q.x)*(P.x - Q.x) + (P.y - Q.y)*(P.y - Q.y) + (P.z - Q.z)*(P.z - Q.z));
}

class Vector {
public:
        double x, y;

        Vector(double xv, double yv) : x(xv), y(yv) {}

        Vector(const Point& A, const Point& B) : x(B.x - A.x), y(B.y - A.y) {}
        double length() const
        {
                return hypot(x, y);
        }

        double angle() const
        {
                return atan(y / x) + (x < 0 ? PI : 0);
        }
};

double dot_product(const Vector& v, const Vector& v)
{
        return u.x * v.x + u.y + v.y;
}

double angle(const Vector& u, const Vector& v)
{
        auto lu = u.length();
        auto lv = v.length();
        auto prod = dot_product(u, v);

        return acos(prod/(lu * lv));
}

// se d == 0, os vetores são ortogonais (formam um ângulo de 90º);
// se d < 0, os vetores foram um ângulo agudo (menor que 90º);
// se d > 0, os vetores formam um ângulo obtuso (maior que 90º).

Vector cross_product(const Vector& u, const Vector& v)
{
        auto x = u.y*v.z - v.y*u.z;
        auto y = u.z*v.x - u.x*v.z;
        auto z = u.x*v.y - u.y*v.x;

        return Vector(x, y, z);
}

Point translate(const Point& P, double dx, double dy)
{
        return Point { P.x + dx, P.y + dy };
}

Point rotate(const Point& P, double angle)
{
        auto x = cos(angle) * P.x - sin(angle) * P.y;
        auto y = sin(angle) * P.x + cos(angle) * P.y;

        return Point { x, y };
}

Point rotate(const Point& P, double angle, const Point& C)
{
        auto Q = translate(P, -C.x, -C.y);
        Q = rotate(Q, angle);
        Q = translate(Q, C.x, C.y);

        return Q;
}

Vector normalize(const Vector& v)
{
        auto len = v.length();
        auto u = Vector(v.x / len, v.y / len);

        return u;
}
