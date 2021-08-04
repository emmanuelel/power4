#ifndef PUISSANC4_H_INCLUDED
#define PUISSANC4_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>
#include<time.h>

//-----------------Emmanuel-------------------------------------------------
struct Tableau2D {
    unsigned int nbColonnes;
    unsigned int nbLignes;
    char *cases;
};

struct joueur
{
    char nom[100];
	int couleur;   // numero du joueur
};

enum occupation{
	vide,rouge,jaune
};


int xy2i (int colonne,int ligne);
void init(Tableau2D*, unsigned int nbColonnes,unsigned int nbLignes);
void afficher (Tableau2D* t);
//-----------------David--------------------------------------------------
int placerGrille(Tableau2D* t,int x,int couleur);
int  quatre_diago1N(Tableau2D* t,int x,int y,int couleur);
int quatre_diago2N(Tableau2D* t,int x,int y,int couleur);
int ligneN(Tableau2D* t,int x,int y,int couleur);
int colonneN(Tableau2D* t,int x,int y,int couleur);
int gagneN(Tableau2D* t,int couleur);

//---------------TEST-------------------------------------------------
void testInit(Tableau2D *t);
void testPlacerGrille(Tableau2D* t,int x);
void testGagneN(Tableau2D* t);
void testLigneN(Tableau2D* t,int couleur);
void testColonneN(Tableau2D* t,int couleur);
void testDiago1N(Tableau2D* t,int couleur);
void testDiago2N(Tableau2D* t,int couleur);
#endif // PUISSANC4_H_INCLUDED
