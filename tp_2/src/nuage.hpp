#ifndef NUAGE_HPP
#define NUAGE_HPP

#include <vector>
#include <point.hpp>

class Point;
class Cartesien;
class Polaire;


class Nuage {
private:
    std::vector<Point*> vecteur;

public:
    typedef std::vector<Point*>::const_iterator const_iterator;
    void ajouter(Point &p);
    int size() const;
    std::vector<Point*>::const_iterator begin() const;
    std::vector<Point*>::const_iterator end() const;
    friend Cartesien barycentre(const Nuage &);
};

class BarycentreCartesien{
    public:
        BarycentreCartesien(){}
        Cartesien operator()(const Nuage &);
};

class BarycentrePolaire{
    public:
        BarycentrePolaire(){}
        Polaire operator()(const Nuage &);
};

#endif
