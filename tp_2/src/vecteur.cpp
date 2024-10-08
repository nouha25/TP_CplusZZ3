#include <vecteur.hpp>

Vecteur::Vecteur():tab(nullptr),taille(0){}
Vecteur::~Vecteur(){
    delete [] tab;
}
Vecteur::Vecteur(const Vecteur & v):taille(v.size()){
    tab= new int[taille];
    memcpy(tab,v.get(),taille*sizeof(int));
}

const int * Vecteur::get() const{
    return tab;
}


void Vecteur::set(const Vecteur & v)
{
    delete[] tab;
    taille=v.size();
    if(v.get()!=nullptr && taille>0)
    {
        this->tab=new int[taille];
        memcpy(this->tab,v.get(),taille*sizeof(int));
    }
    else {
        this->tab=nullptr;
    }
}

int Vecteur::size() const{
    return taille;
}
Vecteur& Vecteur::operator=(const Vecteur & v)
{
    delete[] tab;
    tab=new int[v.size()];
    memcpy(this->tab,v.get(),taille*sizeof(int));
    return *this;
}

const std::ostream & operator<<(std::ostream & o, const Vecteur & v)
{
    for(int i=0;i<v.size();i++)
    {
        o<<(v.get())[i]<<" ";
    }
    return o;
}

const Vecteur & operator+(const Vecteur & v)
{
    int newsize=this.taille+v.size();
    Vecteur a(newsize);

}