/// Systeme de base de donnee relationnel d'une librairie

//les lib
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include <time.h>

//les couleurs (seulement sous linux)
//#define ROUGE "\033[00;31m" #define SOULIGNE "\033[04m" #define NORMAL "\033[00m"

//les structures

struct livre
{
	int ID_livre;
	char *titre;
	int auteur;
	int maison_edition;
};

struct auteur
{
	int ID_auteur;
	char nom[20];
	char prenom[20];
};

struct maison_edit
{
	int ID_maison;
	char maison[40];
};


typedef struct livre s_livre;
typedef struct auteur s_auteur;
typedef struct maison_edition s_maison_edition;


//les fonctions

int menu();
void add();
void removeb();
void read();
void emprunt();
void rendre();
int home();


int main(){

            //printf(ROUGE);
			printf("\n\t\t     _________________________________");
            printf("\n\t\t    /                                 /");
            printf("\n\t\t   /          Gestionnaire           / ");
            printf("\n\t\t  /              d\'une              /  ");
            printf("\n\t\t /            bibliotheque         /   ");
            printf("\n\t\t/_______________________________ _/\n\n\n\n\n");
			//printf(NORMAL);

s_livre livre1;
livre1.auteur = 3;
livre1.ID_livre = 1;
livre1.maison_edition = 3;
livre1.titre = strdup("Harry Potter");
printf("nom du livre1: %s\n", livre1.titre);

int menub = menu();
return 1;

}

//les menu

int menu(){

char choix;

printf(ROUGE SOULIGNE"Menu:\n\n"NORMAL);
printf("1. Lire la base de donnee\n");
printf("2. Ajouter un livre\n");
printf("3. Retirer un livre\n");
printf("4. emprunter un livre\n");
printf("5. rendre un livre\n");
printf("6. sauvegarder les modifications\n");
printf("7. Quitter\n\n");

printf("choix: ");

scanf("%c", &choix);
fflush(stdin);

switch(choix){

	case '1':

	read();
	break;

	case '2':

	add();
	break;

	case '3':

	removeb();
	break;

	case '4':

	emprunt();
	break;

	case '5':

	rendre();
	break;

	case '6':

	printf("en cours...\n");
	break;

	case '7':

	return 88;
	break;

	default:

	printf("mauvais numero: %c\n", choix);
	menu();
	break;

	}

return 2;

}

int home(){

int choix;

printf("\nHome\t(1/Menu 2/Exit) : ");

scanf("%d", &choix);
fflush(stdin);

switch(choix){

	case 1:

	menu();
	break;

	case 2:

	return 33;
	break;

	default:

	printf("Mauvais choix\n");
	home();
	break;

    }

	return 0;
}


// ========================== Programme principal =========================== //



void add(){

    printf("add\n");
    home();
}
void removeb(){

    printf("remove\n");
    home();
}
void read(){

    printf("read\n");
    home();
}
void emprunt(){

    printf("emprunt\n");
    home();
}
void rendre(){

    printf("rendre\n");
    home();
}

