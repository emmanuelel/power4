#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "puissanc4.h"
#include <assert.h>
#include "unittest.h"
//La grille de jeu fait 7 colonnes par 6 lignes

int main(){
    Tableau2D t;
    srand(time(0));//La fonction srand permet d'initialiser le générateur de nombres aléatoires (la fonction rand)
	int nbColonnes=7;
    int  nbLignes=6;
    struct joueur j1={"Joueur 1",rouge};
	struct joueur j2={"Joueur 2",jaune};
    struct joueur *pjoueur=&j1;     //pointe sur l'adresse j1
	struct joueur *padversaire=&j2;//pointe sur l'adresse j2
    int cte=1; //compteur des 42 cases
	int x=0;
	int y ;
    int fin=1;  // compteur du jeu.
    bool cond;
    cond = true;
    puts("Bienvenue sur le jeu Puissance 4 de David et Emmanuel.\n");
     puts("Definisser entre vous qui est le joueur 1 et le joueur 2 .\n");
     puts("Le programme definira lequel d'entre vous commencera .\n");
//------------------------Choix Aleatoire du Joueur--------------

    int commence=rand()%2;//le reste diviser par 2 (0/1)
                          //tire une valeur parmis les 2 joueurs
        if (commence){
		struct joueur *ptemp=pjoueur;
		pjoueur = padversaire;
		padversaire=ptemp;

    }
//------------------------Initialisation de la grille: toutes les cases = vide --------------
    t.nbColonnes =nbColonnes;
    t.nbLignes   =nbLignes;
    init(&t,nbColonnes,nbLignes); //Creation de la grille initiale du jeu

// ------------- Test de la fonction assertTrue et assertFalse------------------
    puts("Partie Test\n");
     puts("Pour activer la partie Test enlever les \\ dans le 'main' sur les fonctions test .\n");
     //assertTrue(cond,"resultat  assertTrue" );
     //assertFalse(cond,"resultat assertFalse" );// car cond = true

// ------------- Test de la fonction Placer --------------------------------------
     //testInit(&t);
     puts("Partie jeu");
     afficher(&t);

// ------------- Test de la fonction Placer -----------------------------------
    x=1;
     //testPlacerGrille(&t,x);
 //--------------------------------JEU---------------------------------------------
   while (fin==1){ //tant qu'aucun joueur a pas gagner on reste dans la condition

		printf("%s peux tu entrer la colonne entre 1 et 7: \n",pjoueur->nom);
		scanf("%d",&x);

		while((t.cases[xy2i(x,1)] != vide) || x<1 || x>7 ){

            printf("Erreur le programme s'est arette.\n");
			//scanf("%d",&x);
            return 0;
			;
		}

		placerGrille(&t,x,pjoueur->couleur);// elle fait descendre le jeton dans les colonnes (x)
		cte++;
        if (cte==42){
			printf("Match nul");
			fin =0; //fin de la partie gagnée
		}

		afficher(&t);
        if (gagneN(&t,pjoueur->couleur)==0){ //si tu gagne tu sort de la boucle
			printf("Bravo %s \n",pjoueur->nom);
// ------------- Test de la fonction Gagner -----------------------------------
        //testGagneN(&t);  // test si tu as gagner

			fin=0;// tu as gagner
		}
        //testGagneN(&t);//  test si tu as pas encore gagner
        //testLigneN(&t,pjoueur->couleur);
        //testColonneN(&t,pjoueur->couleur);
        //testDiago1N(&t,pjoueur->couleur);
        //testDiago2N(&t,pjoueur->couleur);

        //passage a l'autre joueur
		struct joueur *ptemp=pjoueur; //ptemp (= pjoueur) =j1
		pjoueur = padversaire;       // pjoueur= j2
		padversaire=ptemp;          // padversaire = j1
	}
	free(t.cases);
}
