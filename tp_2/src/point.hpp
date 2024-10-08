#ifndef POINT_HPP
#define POINT_HPP

#include <ostream>

class Point {
public:
    virtual void afficher(std::ostream & str) const = 0; 
    virtual void convertir(Point &) const = 0; 

    friend std::ostream& operator<<(std::ostream& out, const Point& point) {
        point.afficher(out);
        return out;
    }
};

#endif
