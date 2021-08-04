#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "puissanc4.h"
#include "unittest.h"
#include <iostream>
#include <string.h>
#include <math.h>

//------------Test FONCTION INIT---------

void testInit(Tableau2D* t){

printf("********* TEST FONCTION INIT **************\n");
    int nbColonnes=7;//->X
    int  nbLignes=6;//->Y
    t->nbColonnes =nbColonnes;
    t->nbLignes   =nbLignes;

    init(t,nbColonnes,nbLignes);
//------------Test Nombres Colonnes---------------------------
 printf("********* TEST Nombres Colonnes **************\n");
 int y = t->nbColonnes;
     assertEquals(5, y,"resultat test colonnes"); //TEST Echoue
     assertEquals(7, y,"resultat test colonnes"); //TEST Reussit

     printf("\n");
//------------Test Nombres Lignes-------------------------------
     printf("********* TEST Nombres Lignes **************\n");

  int x = t->nbLignes;
     assertEquals(5, x,"resultat test lignes"); //TEST Echoue
     assertEquals(6, x,"resultat test lignes"); //TEST Reussit

      printf("\n");

//------------Test des cases de la grille---------
printf("********* TEST des cases de la grille **************\n");
  char valCases; //valeur de la case de la grille

    for (int y=1;y<=6;y++) {// colonnes = x
        for(int x=1;x<=7;x++){  // lignes =y
        {
        valCases=t->cases[xy2i(x,y)]; // valeur courante de la case

        assertEquals(0, (int)valCases,"resultat test cases"); //TEST vide reussit
        assertEquals(1, (int)valCases,"resultat test cases"); //TEST rouge echoué
        assertEquals(2, (int)valCases,"resultat test cases"); //TEST jaune echoué
        }
      }
   }
printf("********* FIN TEST FONCTION INIT **************\n");
}

void testPlacerGrille(Tableau2D* t,int x){ // x = COLONNES definit par le joueur
  char valCases;
  int yPlacer,y ;// y est la ligne


   printf("**** TEST FONCTION PLACER GRILLE ********\n");

//----------------------couleur--------------------
// joueur 1
printf("********* TEST joueur1 , colonnes de la grille %d ********\n",x);
    int couleur =rouge;

    yPlacer = placerGrille(t,x,couleur);  // positionne la couleur dans la case disponible
    for(y=1;y<=6;y++)
    {
     assertEquals(y,yPlacer,"resultat  joueur 1"); //TEST vide reussit
     couleur =vide;
     assertEquals(y,yPlacer,"resultat vide"); //TEST vide reussit
    }

}
void testGagneN(Tableau2D* t)
{
    printf("**** TEST FONCTION Gagner ********\n");
     int res;
     // resutat de l'allignemment ou pas des 4 jetons; res=0 gagner
     //res=1 pas encore gagner
     int couleur =rouge;

     res = gagneN(t,couleur);

     assertEquals(0,res,"resultat gagner"); //TEST  reussit
     assertEquals(1,res,"resultat echouer"); //TEST  echouer
}

void testLigneN(Tableau2D* t,int couleur)
{
    printf("**** TEST FONCTION ligne ********\n");

     int res;  // resutat de l'allignemment ou pas des 4 jetons ligne

     for (int y=1;y<=7;y++){
		for(int x=1;x<=4;x++){
			res =ligneN(t,x,y,couleur);

     assertEquals(0,res,"resultat gagner"); //TEST  reussit
     assertEquals(1,res,"resultat echouer"); //TEST  echouer
        }
   }
}
void testColonneN(Tableau2D* t,int couleur){

printf("**** TEST FONCTION colonne ********\n");

     int res;  // resutat de l'allignemment ou pas des 4 jetons colonnes

     for (int y=1;y<=7;y++){
		for(int x=1;x<=4;x++){
			res =colonneN(t,x,y,couleur);

     assertEquals(0,res,"resultat gagner"); //TEST  reussit
     assertEquals(1,res,"resultat echouer"); //TEST  echouer
        }
   }
}
void testDiago1N(Tableau2D* t,int couleur){
    printf("**** TEST FONCTION Diag 1 ********\n");

     int res;  // resutat de l'allignemment ou pas des 4 jetons

     for (int y=1;y<=7;y++){
		for(int x=1;x<=4;x++){
			res =quatre_diago1N(t,x,y,couleur);

     assertEquals(0,res,"resultat gagner"); //TEST  reussit
     assertEquals(1,res,"resultat echouer"); //TEST  echouer
        }
   }
}
void testDiago2N(Tableau2D* t,int couleur){
    printf("**** TEST FONCTION Diag 2 ********\n");

     int res;  // resutat de l'allignemment ou pas des 4 jetons

     for (int y=1;y<=7;y++){
		for(int x=1;x<=4;x++){
			res =quatre_diago2N(t,x,y,couleur);

     assertEquals(0,res,"resultat gagner"); //TEST  reussit
     assertEquals(1,res,"resultat echouer"); //TEST  echouer
        }
   }
}
