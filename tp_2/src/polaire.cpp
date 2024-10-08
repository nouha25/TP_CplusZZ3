#include <polaire.hpp>


Polaire::Polaire():a(0.0),d(0.0){}
Polaire::Polaire(const double & a, const double & b) : a(a),d(b){}
const double & Polaire::getAngle() const
{
    return a;
}
const double & Polaire::getDistance() const
{
    return d;
}

void Polaire::setAngle(const double & a)
{
    this->a=a;
}

void Polaire::setDistance(const double & d)
{
    this->d=d;
} 

void Polaire::afficher(std::ostream & str) const
{
    str<<"(a="<<this->getAngle()<<";d="<<this->getDistance()<<")";
}

void Polaire::convertir(Cartesien & c) const
{
    c.setX((double)getDistance() * std::cos(getAngle() * M_PI / 180));
    c.setY((double)d * std::sin(getAngle() * M_PI / 180));
}

void Polaire::convertir(Point & p) const {
    if (auto* pPolaire = dynamic_cast<Polaire*>(&p)) {
        pPolaire->setAngle(a);
        pPolaire->setDistance(d);
    } else if (auto* pCartesien = dynamic_cast<Cartesien*>(&p)) {
        convertir(*pCartesien);
    }
}
Polaire::Polaire(const Cartesien & c){
    d = std::hypot(c.getX(), c.getY()); 
    a = std::atan2(c.getY(), c.getX()) * 180.0 / M_PI; 
}