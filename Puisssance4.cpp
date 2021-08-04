#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include "puissanc4.h"



int xy2i (int colonne,int ligne) { // attention xy2i(y,x) retourne l'indice (l'adresse) du tableau en fonction de la postion x,y du point.
    return 7*(ligne -1) +(colonne -1);

}

void init(Tableau2D* t, unsigned int nbColonnes,
                unsigned int nbLignes) {

    t->nbColonnes = nbColonnes;
    t->nbLignes = nbLignes;
    t->cases = (char*) malloc (nbColonnes * nbLignes * sizeof(char)); //alloue memoire tableau  dimension 42

    for(unsigned int i=0; i< nbColonnes * nbLignes ; ++i)
        t->cases[i] = vide;
}

void afficher (Tableau2D* t) {
        printf("\n");
 //2 boucle = 2dimensions
    for (int y=1;y<=6;y++) { // ligne=y
         for(int x=1;x<=7;x++){  // colonnes = x

        printf(" ");
        if (t->cases[xy2i(x,y)] == vide){
        printf(".");
			}
        if (t->cases[xy2i(x,y)]== rouge){
				printf("X");
			}
        if (t->cases[xy2i(x,y)]== jaune){
				printf("O");
			}
		}
		printf("\n");
	}
	printf(" 1 2 3 4 5 6 7\n");
}

 int placerGrille(Tableau2D* t,int x,int couleur){
	//place et fait descendre le jeton
	int y=1;
    while(t->cases[xy2i(x,y+1)]==vide && y<6 )
           y++;// si tu place le jeton dans la grille il cherche si la case est vide
	       t->cases[xy2i(x,y)]=couleur;
	return y; // c'est la ligne ou se trouve le jeton du joueur

}

// l'entier 0 indique la fin de la partie pour une couleur donée
int  quatre_diago1N(Tableau2D* t,int x,int y,int couleur){//en bas a en haut
	if(t->cases[xy2i(x,y)]==couleur && t->cases[xy2i(x+1,y-1)]==couleur && t->cases[xy2i(x+2,y-2)]==couleur && t->cases[xy2i(x+3,y-3)]==couleur){
            //printf("diag1:(x,y)=%d %d, (x+1,y-1)=%d %d, (x+2,y-2)=%d %d,(x+3,y-3)=%d %d",x,y,x+1,y-1,x+2,y-2,x+3,y-3);
				return 0;
			}
	return 1;
}


int quatre_diago2N(Tableau2D* t,int x,int y,int couleur){
	if(t->cases[xy2i(x,y)]==couleur && t->cases[xy2i(x+1,y+1)]==couleur && t->cases[xy2i(x+2,y+2)]==couleur && t->cases[xy2i(x+3,y+3)]==couleur){
				printf("diag2:(x,y)=%d %d,(x+1,y+1)=%d %d,(x+2,y+2)=%d %d,(x+3,y+3)=%d %d",x,y,x+1,y+1,x+2,y+2,x+3,y+3);
				return 0;
			}
		return 1;
}

//Pour une ligne y donnée cette fontion test
// si t'a les 4 jetons alligner sur 4 colonnes x,x+1,x+2,x+3  tu gagne
int ligneN(Tableau2D* t,int x,int y,int couleur){

	if(t->cases[xy2i(x,y)]==couleur && t->cases[xy2i(x+1,y)]==couleur && t->cases[xy2i(x+2,y)]==couleur && t->cases[xy2i(x+3,y)]==couleur){
			return 0;
		}
		return 1;
}
//Pour une colonne x donnée cette fontion test
// si t'a les 4 jetons alligner sur 4 lignes y,y+1,y+2,y+3  tu gagne
int colonneN(Tableau2D* t,int x,int y,int couleur){
	if(t->cases[xy2i(x,y)]==couleur && t->cases[xy2i(x,y+1)]==couleur && t->cases[xy2i(x,y+2)]==couleur && t->cases[xy2i(x,y+3)]==couleur){
			return 0;
		}
		return 1;
}
//probablement trop lourd, on peut tester que les cases à proximité du jetons ajouté.

int gagneN(Tableau2D* t,int couleur){
	// renvoit 0 si 4 pions sont alignés et renvoit 1 sinon
	//teste la victoire sur l'horizontale
	for (int y=1;y<=7;y++){
		for(int x=1;x<=4;x++){
			if(ligneN(t,x,y,couleur)==0){
				return 0;
			}
		}
	}
	//teste sur la verticale
	for (int x=1;x<=7;x++){
		for(int y=1;y<=3;y++){
			if(colonneN(t,x,y,couleur)==0){
				return 0;
			}
		}
	}
	//teste la victoire sur les deux diagonales
	//digonale 1
	for (int x=1;x<=4;x++){
		for(int y=4;y<=6;y++){
			if (quatre_diago1N(t,x,y,couleur)==0){
				return 0;
			}
		}
	}
	//digonale 2
	for (int x=1;x<=4;x++){
		for(int y=1;y<=3;y++){
			if (quatre_diago2N(t,x,y,couleur)==0){
				return 0;
			}
		}
	}
	return 1;
}

