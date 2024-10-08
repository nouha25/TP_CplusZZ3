#ifndef CARTESIEN_HPP
#define CARTESIEN_HPP
#include <point.hpp>
#include <polaire.hpp>
#include <cmath>

class Polaire;

class Cartesien : public Point {
        private :
            double x;
            double y;
        public :
            Cartesien();
            Cartesien(const double &,const double &);
            Cartesien(const Polaire &);
            const double & getX() const;
            const double & getY()const;
            void setX(const double &);
            void setY(const double &);
            void afficher(std::ostream & ) const override;
            void convertir(Point &) const override; 
            void convertir(Polaire &)const;   
};

#endif