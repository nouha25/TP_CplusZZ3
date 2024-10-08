#ifndef VECTEUR_HPP
#define VECTEUR_HPP

#include <vector>
#include <point.hpp>
#include <cstring>


class Vecteur {
    private:
        int * tab;
        int taille;
    public:
        Vecteur();
        Vecteur(const Vecteur &);
        ~Vecteur();
        const int * get() const;
        void set(const Vecteur &);
        int size() const;
        Vecteur& operator=(const Vecteur &);
        friend const std::ostream & operator<<(std::ostream &, const Vecteur &);
        friend const Vecteur & operator+(const Vecteur &);

};



#endif
