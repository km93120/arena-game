#include "jeu.h"

class MageBlanc : public Personnage
{
    int puissanceEvas;
public:
    MageBlanc(string,int,int, int,int);
    void attaquer(Personnage &p)
{
   p.setPointsDeVie(p.getPointsDeVie() - degatsAttaque);
   cout << "le personnage " << p.getNom() << " a ete attaqué ! il perd "<< getDegatsAttaque()<<"pdv "<< "! il ne lui reste plus que " << p.getPointsDeVie()<<" points de vie "<< "\n";

}
const int getPuissanceEvas()
    {
        return(puissanceEvas);
    }
    void setPuissanceEvas(int pde)
    {
        puissanceEvas = pde;

    }
    void soigner();  // rend des pv aux alliés
    void bouleDeFeuDevastatrice(Personnage &p,int&);
    void transfert(Personnage &); // déplace de 20m
    void ventGlacial(Personnage &,int&); // gele le guerrier sur place

};

MageBlanc::MageBlanc(string n = "le soigneur altruiste",int pdv=600,int dgtatk=50, int distanc = 40,int pde = 20):Personnage(n, pdv, dgtatk,distanc)
 {
puissanceEvas = pde;

 }
 void MageBlanc :: bouleDeFeuDevastatrice(Personnage &p,int &cptr)
 {
     if(cptr == 0)
    {
             p.setPointsDeVie(p.getPointsDeVie() - 4*getDegatsAttaque());
             cout << "l'attaque puissante de "<< getNom() << "a reussi et a inflige " <<3*degatsAttaque<< " a "<<p.getNom()<< " !\n";
             cout << " il ne lui reste plus que " << p.getPointsDeVie()<<" points de vie "<< "\n";
    }

    else
    {
        cout << "l'attaque a echoue !!! \n";

    }

 }




 void MageBlanc::soigner()
 {
    int soin = 150;
    setPointsDeVie(getPointsDeVie() + soin);
    cout << getNom() <<" a r\202cup\202r\202 "<<soin<<" points de vie!\n";
 }


 void MageBlanc::transfert(Personnage &p)
 {
     setDistance(getDistance() + getPuissanceEvas());
     p.setDistance(p.getDistance() +20);
 }

 void MageBlanc::ventGlacial(Personnage &p,int&cptr)
 {
     if(getDistance() <= 10)
     {
         cptr++;
         setDistance(getDistance() + 10);
         p.setDistance(p.getDistance() +10);
     }
     else
     {
         cout << "l'attaque a \202chou\202\n";
     }
 }
