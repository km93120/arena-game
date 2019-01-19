#include "MageBlanc.h"
#include "jeu.h"

class Guerrier : public Personnage
{


 public:
     Guerrier(string,int,int,int);
void attaquer(Personnage &p)
{
    if(p.getDistance() < 5)
   {
       p.setPointsDeVie(p.getPointsDeVie() - degatsAttaque);
       cout << "le personnage " << p.getNom() << " a ete attaqué ! il perd "<< getDegatsAttaque()<<"pdv "<< "! il ne lui reste plus que " << p.getPointsDeVie()<<" points de vie "<< "\n";
   }
   else
   {
       p.setDistance(p.getDistance() - 5);
       setDistance(getDistance() - 5);
   }
}
 void insulter(Personnage &p);// diminue les degats infligés par l'adversaire
 void coupDevastateur(Personnage &p,int &);
 void secondSouffle(const int &);
 void bondHeroique(Personnage &);
 void charge(Personnage &p,int &cptr);
 void enrage( int & cptr);
 void briseGenou(MageBlanc &m,int &cptr );
};

Guerrier::Guerrier(string n = "le guerrier fou",int pdv=800,int dgtatk=60,int distanc = 40): Personnage( n, pdv, dgtatk, distanc)
{


}

 void briseGenou(MageBlanc &m,int &cptr )
 {
    m.setPuissanceEvas(m.getPuissanceEvas() - 5;cptr++;
 }

void Guerrier :: bondHeroique(Personnage &p)
{
    setDistance(getDistance() -20);
    p.setDistance(p.getDistance() -20);
    if(p.getDistance() < 15 ) // onde de choc
        p.setPointsDeVie(p.getPointsDeVie() - 50);
}
void Guerrier :: charge(Personnage &p,int &cptr)
 {
     if(distance <= 15)
    {setDistance(0);p.setDistance(0);cptr++;}
     else
    {cout << "cible trop \202loign\202e, la charge a \202chou\202";}

 }

void Guerrier :: enrage(int &cptr)
{
    setDegatsAttaque(getDegatsAttaque() +5);
}


void Guerrier :: secondSouffle(const int &pvMax)
{
        if (pointsDeVie < 0.3*pvMax)
        {


        pointsDeVie += 0.03*pvMax;
        cout<<"capacite passive activee,r\202cuperation de " << 0.03*pvMax << " points de vie\n";
        }
}
void Guerrier :: insulter(Personnage &p)
{
    p.setDegatsAttaque(p.getDegatsAttaque() - 10);
    cout<< "la puissance d'attaque de " <<p.getNom() << "a été diminuée de "<<p.getDegatsAttaque()<<"!\n";
}

void Guerrier :: coupDevastateur(Personnage &p,int &cptg)
{
    if(cptg == 0 )
    {
        p.setPointsDeVie(p.getPointsDeVie() - 3*degatsAttaque);
        cout << "l'attaque puissante de "<< getNom() << "a reussi et a inflige " <<3*degatsAttaque<< " a "<<p.getNom()<< " !\n";
        cout << " il ne lui reste plus que " << p.getPointsDeVie()<<" points de vie "<< "\n";
    }
    else
    {
        cout << "l'attaque a echoue !!! \n";
    }

}

