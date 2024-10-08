#ifndef POLAIRE_HPP
#define POLAIRE_HPP
#include <point.hpp>
#include <sstream>
#include <cmath>
#include <cartesien.hpp>

class Cartesien;

class Polaire : public Point {
    private :
        double a;
        double d;
    public :
        Polaire();
        Polaire(const double &,const double &);
        Polaire(const Cartesien &);
        const double & getAngle() const;
        const double & getDistance ()const;
        void setAngle(const double &);
        void setDistance(const double &);
        void afficher(std::ostream & ) const override;
        void convertir(Point &) const override;
        void convertir(Cartesien &) const;   
    
};
#endif
