#include <iostream>
using namespace std;
//--------------------------------------------Classe mere---------------------------------------------------------------------
class Personnage
{
    protected:
    string nom;
    int pointsDeVie;
    int degatsAttaque;
    int distance;

public:
    bool IsD();
    virtual void attaquer(Personnage &p) =0;
    const int getPointsDeVie();
    const int getDistance();
    void setNom(string );
    void setDistance(int);
    const string getNom();
    const int getDegatsAttaque();
    void setPointsDeVie(int);
    void setDegatsAttaque(int);
    Personnage(string n="default", int pdv =200,int dgtatk=40,int dist = 40)
    {

        nom = n;
        pointsDeVie = pdv;
        degatsAttaque = dgtatk;
        distance = dist;
    }
    friend ostream& operator<<(ostream& os,  Personnage& p);

};
ostream& operator<<(ostream& os, Personnage& p)
{
    os  << p.getNom()<<'/' <<p.getPointsDeVie() << '/' << p.getDegatsAttaque()<<"\n";
    return os;
}

void Personnage ::setDistance(int dist)
{
    distance = dist;
}

bool Personnage :: IsD()
{
if(getPointsDeVie() <= 0)
{


    cout <<"le personnage a l'adresse " << this << " se denommant " << nom <<" est mort!";
    return true;
}

}


const string Personnage ::  getNom()
{
    return(nom);
}


const int Personnage ::  getDistance()
{
    return(distance);
}


const int Personnage ::  getPointsDeVie()
{
    return(pointsDeVie);
}

const int Personnage ::  getDegatsAttaque()
{
        return(degatsAttaque);
}


void Personnage:: setNom(string n)
{
    nom = n;
}

void Personnage::setPointsDeVie(int pdv)
{
    pointsDeVie = pdv;
}

void Personnage::setDegatsAttaque(int dgtAtk)
{
    degatsAttaque = dgtAtk;
}

//-------------------------------------------------------------- classe mage----------------------------
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

 void MageBlanc::ventGlacial(Personnage &p,int & cptr)
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


//-------------------------------------------------------------------------------------

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
 void charge(Personnage &,int &);
 void enrage(int & );
 void briseGenou(MageBlanc &);
};

Guerrier::Guerrier(string n = "le guerrier fou",int pdv=800,int dgtatk=60,int distanc = 40): Personnage( n, pdv, dgtatk, distanc)
{


}

 void Guerrier :: briseGenou(MageBlanc &m)
 {
    m.setPuissanceEvas(m.getPuissanceEvas() - 5);
    cout << "puissance d'evasion réduite de " << m.getNom() << " 5 !\n";
 }

void Guerrier :: bondHeroique(Personnage &p)
{
    const int degatsOndeDeChoc = 50;
    setDistance(getDistance() -20);
    p.setDistance(p.getDistance() -20);
    if(p.getDistance() <= 20 ) // onde de choc
        {
            p.setPointsDeVie(p.getPointsDeVie() - degatsOndeDeChoc);
            cout << p.getNom() << " a perdu " << degatsOndeDeChoc << " points de vie";
        }
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



/*class Voleur : public Personnage
{
public:
    Voleur(string,int,int);
    void marauder(Personnage p);  // augmente les degats de la prochaine attaque;
};


Voleur::Voleur(string n = "le maraudeur silencieux",int pdv=0,int dgtatk=0): Personnage( n, pdv, dgtatk)
 {

 }

*/
