#include "nuage.hpp"
#include "cartesien.hpp"

void Nuage::ajouter(Point &p) {
    vecteur.push_back(&p);
}

int Nuage::size() const {
    return vecteur.size();
}

std::vector<Point*>::const_iterator Nuage::begin() const {
    return vecteur.begin();  
}

std::vector<Point*>::const_iterator Nuage::end() const {
    return vecteur.end();  
}

Cartesien barycentre(const Nuage &n) {
    double x = 0.0, y = 0.0;

    for (Nuage::const_iterator it = n.begin(); it != n.end(); ++it) {
        Cartesien c;
        (*it)->convertir(c);  
        x += c.getX();
        y += c.getY();
    }

    Cartesien c;
    if (n.size() > 0) {
        c.setX(x / n.size());
        c.setY(y / n.size());
    }
    return c; 
}

Cartesien BarycentreCartesien::operator()(const Nuage & n)
{
    return barycentre(n);
}

Polaire BarycentrePolaire::operator()(const Nuage & n)
{
    Polaire p;
    barycentre(n).convertir(p);
    return p;
}