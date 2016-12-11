class Segment {
public:
        // Verifica se um ponto da reta _r_ que contém _A_ e _B_ pertence ao segmento
        Point A, B;

        Segment(const Point& Av, const Point& Bv) : A(Av), B(Bv) {}

        double length() const
        {
                return hypot(A.x - B.x, A.y - B.y);
        }

        bool contains(const Point& P) const
        {
                if (A.x == B.x)
                        return min(A.y, B.y) <= P.y and P.y <= max(A.y, B.y);
                else
                        return min(A.x, B.x) <= P.x and P.x <= max(A.x, B.x);
        }

        // Ponto mais próximo de P no segmento 
        Point closest(const Point& P)
        {
                Line r(A, B);

                auto Q = r.closest(P);

                if (this->contains(Q))
                        return Q;

                auto distA = P.distance(A);
                auto distB = P.distance(B);

                if (distA <= distB)
                        return A;
                else
                        return B;
        }
        bool intersect(const Segment& s) const
        {
                auto d1 = D(A, B, s.A);
                auto d2 = D(A, B, s.B);

                if ((equals(d1, 0) && contains(s.A)) || (equals(d2, 0) && contains(s.B)))
                        return true;

                auto d3 = D(s.A, s.B, A);
                auto d4 = D(s.A, s.B, B);

                if ((equals(d3, 0) && s.contains(A)) || (equals(d4, 0) && s.contains(B)))
                        return true;

                return (d1 * d2 < 0) && (d3 * d4 < 0);
        }
}

