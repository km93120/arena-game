#include <iostream>
#include "jeu.h"
#include <string>
using namespace std;

int main()
{
  /*string n1;
  string n2;
  cout << "nom du premier combattant";
  cin >> n1;
  cout << "nom du deuxieme combattant";
  cin >> n2;*/


  cout << "deux combattants sont entr\202s dans l'ar\138ne :\n";
  int choixM;
  int choixG;
  string a = "sorcier atman";
  string b = "guerrier sofian";
  int cpt_tour = 0;
  int cptrDFB= 0; //modelisation des temps de recharge
  int cptrLH = 0;
  int cptrTR = 0; // fin techniques mage
  int cptrDH = 0;
  int cptrCH = 0;
  int cptrBH = 0; // fin techniques guerrier
  int cptrAttaqueNormale = 0;
  MageBlanc mage(a,500,50,40,20);
  Guerrier guerrier(b,600,45);
  const int PV_MAX = guerrier.getPointsDeVie();
  cout <<mage;
  cout << guerrier;

  do
  {
        if (cptrDFB > 5 )
    {


        cptrDFB = 0;
        cout << "attaque puissante M disponible\n";
    }
    if (cptrDH >5)
    {


        cptrDH = 0;
        cout << "attaque puissante G disponible\n";

    }


      if (cpt_tour % 2 == 0)
      {


      cout << "les deux personnages sont distants de " << mage.getDistance() <<" metres\n";
      cout << mage.getNom() << " a l'initiative ! que va t'il faire?\n 0- attaque normale(100%)\n1-attaque puissante(500%) tous les 3 tours sinon \202choue.\n2-soin(100 pv)\n3-Transfert : distance + 20m\n4- Vent glacial : immobilise le guerrier sur place pendant 1 tour et distance + 10m: echoue si dist > 10m\n ";
      cin >> choixM;
      switch (choixM)
      {
          case 0 : mage.attaquer(guerrier);
          break;
          case 1 :  mage.bouleDeFeuDevastatrice(guerrier,cptrDFB);
                    cptrDFB++;
          break;
          case 2 : mage.soigner();
          break;
          case 3 : mage.transfert(guerrier);
          break;
          case 4 : mage.ventGlacial(guerrier,cpt_tour);
      }
      }
      else
      {

        guerrier.secondSouffle(PV_MAX);
        cout << "les deux personnages sont distants de " << guerrier.getDistance() <<" metres\n";
        cout << guerrier.getNom() << " a l'initiative ! que va t'il faire?\n 0- attaque normale(100%)\n1-attaque puissante(300%) tous les 3 tours sinon echoue.\n2-insulter l'adversaire \n3- Charge, \202choue si dist > 15. Applique Brise-Genou\n4-Bond heroique : inflige 50 pt de degats si dist < 15 m apres deduction de la distance";

      cin >> choixG;

      switch (choixG)
      {
          case 0 : guerrier.attaquer(mage);
                   cptrAttaqueNormale++;
                   guerrier.enrage(cptrAttaqueNormale);
          break;
          case 1 :guerrier.coupDevastateur(mage,cptrDH);
                    cptrDH++;
          break;
          case 2 : guerrier.insulter(mage);
          break;
          case 3 : guerrier.charge(mage,cpt_tour);
            //guerrier.briseGenou(mage);
          break;
          case 4: guerrier.bondHeroique(mage);
          break;
      }
      }
    if (cptrDFB >0)
    {


        cptrDFB++;
    }

    if (cptrDH > 0)
    {


        cptrDH++;

    }


cpt_tour++;

  }while(mage.IsD() == false && guerrier.IsD() == false);




}





