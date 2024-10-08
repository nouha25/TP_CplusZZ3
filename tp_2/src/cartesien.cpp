#include <cartesien.hpp>


Cartesien::Cartesien():x(0.0),y(0.0){}
Cartesien::Cartesien(const double & a, const double & b) : x(a),y(b){}
const double & Cartesien::getX() const
{
    return x;
}
const double & Cartesien::getY() const
{
    return y;
}

void Cartesien::setX(const double & a)
{
    this->x=a;
}

void Cartesien::setY(const double & d)
{
    this->y=d;
} 

void Cartesien::afficher(std::ostream & str) const
{
    str<<"(x="<<this->getX()<<";y="<<this->getY()<<")";
}

void Cartesien::convertir(Polaire & p) const
{
    p.setAngle((double)(std::atan2(getY(), getX()) * 180 / M_PI));
    p.setDistance((double)(std::hypot(getX(), getY())));
}

void Cartesien::convertir(Point & p) const {
    if (auto* pCartesien = dynamic_cast<Cartesien*>(&p)) {
        pCartesien->setX(x);
        pCartesien->setY(y);
    } else if (auto* pPolaire = dynamic_cast<Polaire*>(&p)) {
        convertir(*pPolaire);
    }
}

Cartesien::Cartesien(const Polaire & p){
    x = p.getDistance() * std::cos(p.getAngle() * M_PI / 180);
    y = p.getDistance() * std::sin(p.getAngle() * M_PI / 180);
}

