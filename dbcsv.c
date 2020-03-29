#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#define CLEAR_STDIN { int c; while((c = getchar()) != '\n' && c != EOF); } //car fflush(stdin) n'est pas parfait

/*** structures ***/
struct livre{

    int ID;
    char *titre;
    int pages;
    int id_auteur;
};
struct auteur{

    int ID;
    char *nom;
    char *prenom;
};
struct client{
    
    int ID;
    char *nom;
    char *prenom;
};

/*** raccourci des structures ***/
typedef struct livre s_livre;
typedef struct auteur s_auteur;
typedef struct client s_client;

/*** rempli les struct ***/
void remplir_struct_livre(FILE* fichier, int nlivre, s_livre *book){

    int i;
    char *ligne;
    char tmp[50];
    
    for ( i = 0; i < nlivre; i++){

        ligne = fgets(tmp, sizeof tmp, fichier);
        //ligne[strlen(tmp) - 1] = '\0';

        ligne = strtok(tmp, ".");
        book[i].ID = atoi(strdup(ligne));

        ligne = strtok(NULL, ".");
        book[i].titre = strdup(ligne);

        ligne = strtok(NULL, ".");
        book[i].pages = atoi(ligne);

        ligne = strtok(NULL, ".");
        book[i].id_auteur = atoi(ligne);

    }
    fclose(fichier);
}
void remplir_struct_auteur(FILE* fichier, int nauteur, s_auteur* writer){
    
    int i;
    char *ligne;
    char tmp[50];
    
    for ( i = 0; i < nauteur; i++){

        ligne = fgets(tmp, sizeof tmp, fichier);
        //ligne[strlen(tmp) - 1] = '\0';

        ligne = strtok(tmp, ".");
        writer[i].ID = atoi(strdup(ligne));

        ligne = strtok(NULL, ".");
        writer[i].nom = strdup(ligne);
        
        ligne = strtok(NULL, ".");
        writer[i].prenom = strdup(ligne);

    }
    fclose(fichier);
    
}
void remplir_struct_client(FILE* fichier, int nclient, s_client* reader){
    
    int i;
    char *ligne;
    char tmp[50];
    
    for ( i = 0; i < nclient; i++){

        ligne = fgets(tmp, sizeof tmp, fichier);
        //ligne[strlen(tmp) - 1] = '\0';

        ligne = strtok(tmp, ".");
        reader[i].ID = atoi(strdup(ligne));

        ligne = strtok(NULL, ".");
        reader[i].nom = strdup(ligne);

        ligne = strtok(NULL, ".");
        reader[i].prenom = strdup(ligne);

    }
    fclose(fichier);
}

/*** affiche les struct ***/
void afficherlivre(s_livre* book, int nlivre, s_livre* addbook, int pluslivre, s_auteur* writer){
    int i;
    
    for(i = 0; i < nlivre; i++){
        if(writer[book[i].id_auteur].ID != 0){
            printf("%i. ID: %i, Titre: %s, Pages: %i, Auteur: %s\n\n",i+1, book[i].ID, book[i].titre, book[i].pages, writer[book[i].id_auteur].nom);
        }
        else
            printf("%i. ID: %i, Titre: %s, Pages: %i, Auteur: ?\n\n",i+1, book[i].ID, book[i].titre, book[i].pages);
    }
    if(pluslivre != 0){
        for(i = 0;i < pluslivre; i++){
            if(writer[addbook[i].id_auteur].ID != 0){
                printf("%i. ID: %i, Titre: %s, Pages: %i, Auteur: %s\n\n",i+nlivre+1, addbook[i].ID, addbook[i].titre, addbook[i].pages, writer[addbook[i].id_auteur].nom);
            }
            else
                printf("%i. ID: %i, Titre: %s, Pages: %i, Auteur: ?\n\n",i+nlivre+1, addbook[i].ID, addbook[i].titre, addbook[i].pages);
        }
    }
}
void afficherauteur(s_auteur* writer, int nauteur, s_auteur* addauteur, int plusauteur){
    int i;
    
    for(i = 0; i < nauteur; i++){
        printf("%i. ID: %i, Nom: %s, Prenom: %s\n",i+1, writer[i].ID, writer[i].nom, writer[i].prenom);
    }
    if(plusauteur != 0){
        printf("\n");
        for(i = 0;i < plusauteur; i++){
            printf("%i. ID: %i, Nom: %s, Prenom: %s\n\n",i+nauteur+1, addauteur[i].ID, addauteur[i].nom, addauteur[i].prenom);
        }
    }
    printf("\n");
}
void afficherclient(s_client* reader, int nclient, s_client* addclient, int plusclient){
    int i;
    
    for(i = 0; i < nclient; i++){
        printf("%i. ID: %i, Nom: %s, Prenom: %s\n",i+1, reader[i].ID, reader[i].nom, reader[i].prenom);
    }
    if(plusclient != 0){
        printf("\n");
        for(i = 0;i < plusclient; i++){
            printf("%i. ID: %i, Nom: %s, Prenom: %s\n\n",i+nclient+1, addclient[i].ID, addclient[i].nom, addclient[i].prenom);
        }
    }
    printf("\n");
}

/*** ajoute dans une struct faite pour ***/
int ajouterlivre(s_livre* addbook, int i, s_auteur* writer, int nauteur, int ID_livre){
    
    char choix;
    int j;
    int nlivre;
    char *titre;
    char tmp[50];
    printf("ajouter un livre ?(y/n)\n");
    printf("> ");
    scanf("%c", &choix);
    CLEAR_STDIN;
    if(choix == 'y'){
    do{
        int page;
        int auteur;
        printf("ajout d'un livre:\n\n");
        printf("Titre: ");
        titre = fgets(tmp, sizeof tmp, stdin);
        titre[strlen(titre) - 1] = '\0';
        printf("Pages: ");
        scanf("%i", &page);
        CLEAR_STDIN;
        //partie auteur
        printf("liste Auteur: \n");
        for(j = 0; j < nauteur; j++){
            printf("%d. %s %s",j+1, writer[j].nom, writer[j].prenom);
        }
        printf("\nAuteur: ");
        scanf("%d", &auteur);
        CLEAR_STDIN;
        printf("livre:\nTitre: %s\nPages: %i\nAuteur: %s %s\n", titre,page,writer[auteur-1].nom,writer[auteur-1].prenom);
        addbook[i].ID = ID_livre+1;
        addbook[i].pages = page;
        addbook[i].titre = strdup(titre);
        addbook[i].id_auteur = auteur-1;
        printf("ajouter encore un livre ?(y/n)\n");
        printf("> ");
        scanf("%c", &choix);
        CLEAR_STDIN;
        i++;
        ID_livre++;
    }while(choix != 'n' && choix == 'y');
    nlivre = i;
    printf("afficher les livres que vous allez ajouter ?(y/n)\n");
    printf("il y a %d livre(s) à afficher\n", i);
    printf("> ");
    scanf("%c", &choix);
    CLEAR_STDIN;
    if(choix == 'y'){
        for(j=0; j < nlivre; j++){
            printf("ID: %i, Titre: %s, Pages: %i, Auteur: %s %s\n",addbook[j].ID, addbook[j].titre, addbook[j].pages, writer[addbook[j].id_auteur].nom, writer[addbook[j].id_auteur].prenom);
        }
    }
    }
    return i;
}
int ajouterauteur(s_auteur* addwriter, int i, int ID_auteur){
    
    char choix;
    int j;
    int nauteur;
    char *nom;
    char *prenom;
    char tmpnom[50];
    char tmpprenom[50];
    printf("ajouter un auteur ?(y/n)\n");
    printf("> ");
    scanf("%c", &choix);
    CLEAR_STDIN;
    if(choix == 'y'){
    do{
        printf("ajout d'un auteur\n\n");
        printf("Prenom: ");
        nom = fgets(tmpnom, sizeof tmpnom, stdin);
        nom[strlen(nom) - 1] = '\0';
        printf("Nom: ");
        prenom = fgets(tmpprenom, sizeof tmpprenom, stdin);
        prenom[strlen(prenom) - 1] = '\0';
        printf("Auteur:\nPrenom: %s\nNom: %s\n", nom, prenom);
        addwriter[i].ID = ID_auteur+1;
        addwriter[i].nom = strdup(nom);
        addwriter[i].prenom = strdup(prenom);
        printf("ajouter encore un auteur ?(y/n)\n");
        printf("> ");
        scanf("%c", &choix);
        CLEAR_STDIN;
        ID_auteur++;
        i++;
    }while(choix != 'n' && choix == 'y');
    nauteur = i;
    printf("afficher les auteurs que vous allez ajouter ?(y/n)\n");
    printf("> ");
    scanf("%c", &choix);
    CLEAR_STDIN;
    if(choix == 'y'){
        for(j=0; j < nauteur; j++){
            printf("ID: %i, Prenom: %s, Nom: %s\n",addwriter[j].ID, addwriter[j].nom, addwriter[j].prenom);
        }
    }
    }
    return i;
}
int ajouterclient(s_client* addreader, int i, int ID_client){
    
    char choix;
    int j;
    int nclient;
    char *nom;
    char *prenom;
    char tmpnom[50];
    char tmpprenom[50];
    printf("ajouter un client ?(y/n)\n");
    printf("> ");
    scanf("%c", &choix);
    CLEAR_STDIN;
    if(choix == 'y'){
    do{
        printf("ajout d'un client\n\n");
        printf("Nom: ");
        nom = fgets(tmpnom, sizeof tmpnom, stdin);
        nom[strlen(nom) - 1] = '\0';
        printf("Prenom: ");
        prenom = fgets(tmpprenom, sizeof tmpprenom, stdin);
        prenom[strlen(prenom) - 1] = '\0';
        printf("Client:\nNom: %s\nPrenom: %s\n", nom, prenom);
        addreader[i].ID = ID_client+1;
        addreader[i].nom = strdup(nom);
        addreader[i].prenom = strdup(prenom);
        printf("ajouter encore un client ?(y/n)\n");
        printf("> ");
        scanf("%c", &choix);
        CLEAR_STDIN;
        ID_client++;
        i++;
    }while(choix != 'n' && choix == 'y');
    nclient = i;
    printf("afficher les clients que vous allez ajouter ?(y/n)\n");
    printf("> ");
    scanf("%c", &choix);
    CLEAR_STDIN;
    if(choix == 'y'){
        for(j=0; j < nclient; j++){
            printf("nom: %s, Prenom: %s\n", addreader[j].nom, addreader[j].prenom);
        }
    }
    }
    return i;
}

/*** modifier dans une struct ***/
void modiflivre(s_livre* book, s_livre* addbook, s_auteur* writer, int nauteur){

    int choix;
    char *titre;
    char tmp[50];
    int page;
    int auteur;
    int j;
    
    printf(" Entrez le numero du livre que vous souhaitez modifier\n");
    printf("> ");
    scanf("%d", &choix);
    CLEAR_STDIN;
    if(book[choix-1].pages != 0){
        
        printf("Nouveau titre: ");
        titre = fgets(tmp, sizeof tmp, stdin);
        titre[strlen(titre) - 1] = '\0';
        printf("Pages: ");
        scanf("%i", &page);
        CLEAR_STDIN;
        printf("liste Auteur: \n");
        for(j = 0; j < nauteur; j++){
            printf("%i, %s %s", j+1, writer[j].nom, writer[j].prenom);
        }
        printf("\nAuteur: ");
        scanf("%i", &auteur);
        CLEAR_STDIN;
        printf("livre:\nTitre: %s\nPages: %i\nAuteur: %s %s\n", titre,page,writer[auteur-1].nom,writer[auteur-1].prenom);
        book[choix-1].pages = page;
        book[choix-1].titre = strdup(titre);
        book[choix-1].id_auteur = writer[auteur].ID;

    }
    else if(addbook[choix-1].pages != 0){
        
        printf("Nouveau titre: ");
        titre = fgets(tmp, sizeof tmp, stdin);
        titre[strlen(titre) - 1] = '\0';
        printf("Pages: ");
        scanf("%i", &page);
        CLEAR_STDIN;
        printf("liste Auteur: \n");
        for(j = 0; j < nauteur; j++){
            printf("%i, %s %s", j+1, writer[j].nom, writer[j].prenom);
        }
        printf("\nAuteur: ");
        scanf("%i", &auteur);
        CLEAR_STDIN;
        printf("livre:\nTitre: %s\nPages: %i\nAuteur: %s %s\n", titre,page,writer[auteur-1].nom,writer[auteur-1].prenom);
        addbook[choix-1].pages = page;
        addbook[choix-1].titre = strdup(titre);
        addbook[choix-1].id_auteur = writer[auteur-1].ID;
    }
    else{
        printf("modification impossible...\n");
    }
}
void modifauteur(s_auteur* writer, s_auteur* addwriter){

    int choix;
    int j;
    char *nom;
    char *prenom;
    char tmpnom[50];
    char tmpprenom[50];
    
    printf(" Entrez le numero de l'auteur que vous souhaitez modifer\n");
    printf("> ");
    scanf("%d", &choix);
    CLEAR_STDIN;
    if(writer[choix-1].ID != 0){
        
        printf("Nouveau prenom: ");
        nom = fgets(tmpnom, sizeof tmpnom, stdin);
        nom[strlen(nom) - 1] = '\0';
        printf("Nouveau nom: ");
        prenom = fgets(tmpprenom, sizeof tmpprenom, stdin);
        prenom[strlen(prenom) - 1] = '\0';
        printf("Auteur:\nPrenom: %s\nNom: %s\n", nom, prenom);
        writer[choix-1].nom = strdup(nom);
        writer[choix-1].prenom = strdup(prenom);

    }
    else if(addwriter[choix-1].ID != 0){

        printf("Nouveau prenom: ");
        nom = fgets(tmpnom, sizeof tmpnom, stdin);
        nom[strlen(nom) - 1] = '\0';
        printf("Nouveau nom: ");
        prenom = fgets(tmpprenom, sizeof tmpprenom, stdin);
        prenom[strlen(prenom) - 1] = '\0';
        printf("Auteur:\nPrenom: %s\nNom: %s\n", nom, prenom);
        addwriter[choix-1].nom = strdup(nom);
        addwriter[choix-1].prenom = strdup(prenom);
    }
    else{
        printf("modification impossible...\n");
    }
}
void modifclient(s_client* reader, s_client* addreader){

    int choix;
    int j;
    char *nom;
    char *prenom;
    char tmpnom[50];
    char tmpprenom[50];
    
    printf(" Entrez le numero du client que vous souhaitez supprimer\n");
    printf("> ");
    scanf("%d", &choix);
    CLEAR_STDIN;
    if(reader[choix-1].ID != 0){

        printf("Nouveau prenom: ");
        nom = fgets(tmpnom, sizeof tmpnom, stdin);
        nom[strlen(nom) - 1] = '\0';
        printf("Nouveau nom: ");
        prenom = fgets(tmpprenom, sizeof tmpprenom, stdin);
        prenom[strlen(prenom) - 1] = '\0';
        printf("Auteur:\nPrenom: %s\nNom: %s\n", nom, prenom);
        reader[choix-1].nom = strdup(nom);
        reader[choix-1].prenom = strdup(prenom);
    }
    else if(addreader[choix-1].ID != 0){

        printf("Nouveau prenom: ");
        nom = fgets(tmpnom, sizeof tmpnom, stdin);
        nom[strlen(nom) - 1] = '\0';
        printf("Nouveau nom: ");
        prenom = fgets(tmpprenom, sizeof tmpprenom, stdin);
        prenom[strlen(prenom) - 1] = '\0';
        printf("Auteur:\nPrenom: %s\nNom: %s\n", nom, prenom);
        addreader[choix-1].nom = strdup(nom);
        addreader[choix-1].prenom = strdup(prenom);
    }
    else{
        printf("modification impossible...\n");
    }
}

/*** retire un element des struct ***/
void retirerlivre(s_livre* book, s_livre* addbook){

    int choix;
    
    printf(" Entrez le numero du livre que vous souhaitez supprimer\n");
    printf("> ");
    scanf("%d", &choix);
    CLEAR_STDIN;
    if(book[choix-1].pages != 0){
        book[choix-1].pages = 0;
    }
    else if(addbook[choix-1].pages != 0){
        addbook[choix-1].pages = 0;
    }
    else{
        printf("suppression impossible...\n");
    }
}
void retirerauteur(s_auteur* writer,s_auteur* addwriter){

    int choix;
    
    printf(" Entrez le numero de l'auteur que vous souhaitez supprimer\n");
    printf("> ");
    scanf("%d", &choix);
    CLEAR_STDIN;
    printf("Suppression d'auteur impossible...\n");
    // if(writer[choix-1].ID != 0){
    //     writer[choix-1].ID = -1;
    // }
    // else if(addwriter[choix-1].ID != 0){
    //     addwriter[choix-1].ID = -1;
    // }
    // else{
    //     printf("suppression impossible...\n");
    // }
}
void retirerclient(s_client* reader, s_client* addclient){

    int choix;
    
    printf(" Entrez le numero du client que vous souhaitez supprimer\n");
    printf("> ");
    scanf("%d", &choix);
    CLEAR_STDIN;
    if(reader[choix-1].ID != 0){
        reader[choix-1].ID = -1;
    }
    else if(addclient[choix-1].ID != 0){
        addclient[choix-1].ID = -1;
    }
    else{
        printf("suppression impossible...\n");
    }
}

/*** sauvegarde les struct dans les fichiers ***/
void savelivre(FILE* fichier, s_livre* book, s_livre* addbook, int nlivre, int pluslivre){

    int i;

    for(i = 0; i < nlivre; i++){

        if(book[i].pages != 0){

            if(i != nlivre-1){
                fprintf(fichier, "%d.%s.%i.%i\n", book[i].ID, book[i].titre, book[i].pages, book[i].id_auteur);
            }
            else{
                fprintf(fichier, "%d.%s.%i.%i", book[i].ID, book[i].titre, book[i].pages, book[i].id_auteur);
            }
        }
        
    }
    if(pluslivre != 0){
        fprintf(fichier, "\n");
        for (i = 0;i < pluslivre; i++){

            if(addbook[i].pages != 0){

                if(i != pluslivre-1){
                    fprintf(fichier, "%d.%s.%i.%i\n", addbook[i].ID, addbook[i].titre, addbook[i].pages, addbook[i].id_auteur);
                }
                else{
                    fprintf(fichier, "%d.%s.%i.%i", addbook[i].ID, addbook[i].titre, addbook[i].pages, addbook[i].id_auteur);
                }  
            }
    }
    }
    printf("livres mis a jour\n");
    fclose(fichier);
}
void saveauteur(FILE* fichier, s_auteur* writer, s_auteur* addwriter, int auteur, int plusauteur){

    int i;

    for(i = 0; i < auteur; i++){
        if(writer[i].ID != -1){
            fprintf(fichier, "%d.%s.%s", writer[i].ID, writer[i].nom, writer[i].prenom);
        }
    }
    if(plusauteur != 0){
        fprintf(fichier, "\n");
        for (i = 0;i < plusauteur; i++){
            if(addwriter[i].ID != -1){
                if(i != plusauteur-1){
                    fprintf(fichier, "%d.%s.%s\n", addwriter[i].ID, addwriter[i].nom, addwriter[i].prenom);
                }
                else{
                    fprintf(fichier, "%d.%s.%s", addwriter[i].ID, addwriter[i].nom, addwriter[i].prenom);
                }
            }
        }
    }
    printf("auteurs mis a jour\n");
    fclose(fichier);
}
void saveclient(FILE* fichier, s_client* reader, s_client* addreader, int client, int plusclient){

    int i;

    for(i = 0; i < client; i++){
        fprintf(fichier, "%d.%s.%s", reader[i].ID, reader[i].nom, reader[i].prenom);
    }
    if(plusclient != 0){
        fprintf(fichier, "\n");
        for (i = 0;i < plusclient; i++){
            if(i != plusclient-1){
                fprintf(fichier, "%d.%s.%s\n", addreader[i].ID, addreader[i].nom, addreader[i].prenom);
            }
            else{
                fprintf(fichier, "%d.%s.%s", addreader[i].ID, addreader[i].nom, addreader[i].prenom);
            }
        }
        
    }
    printf("clients mis a jour\n");
    fclose(fichier);
}

/*** ouvre les fichiers, lancer les fonctions ***/
int main(){

    system("clear");
    char choix;
    int ajjlivre = 0;
    int ajjauteur = 0;
    int ajjclient = 0;
    
    FILE* flivre = ouvrirfich("csv/livre.csv", "r");
    FILE* fauteur = ouvrirfich("csv/auteur.csv", "r");
    FILE* fclient = ouvrirfich("csv/client.csv", "r");

    int nlivre = comptelivre(flivre);//compter le nombre de ligne dans le fichier (c != EOF)
    int nauteur = compteauteur(fauteur);//compter le nombre de ligne dans le fichier (c != EOF)
    int nclient = compteclient(fclient);//compter le nombre de ligne dans le fichier (c != EOF)

    s_livre book[nlivre];
    s_auteur writer[nauteur]; //declare les struct adequat
    s_client reader[nclient];

    s_livre addbook[20];
    s_auteur addwriter[20];
    s_client addreader[20];

    rewind(flivre);
    rewind(fauteur);
    rewind(fclient);
    
    remplir_struct_livre(flivre, nlivre, book);
    remplir_struct_auteur(fauteur,nauteur,writer);
    remplir_struct_client(fclient,nclient,reader);

    int ID_livre = book[nlivre-1].ID;
    int ID_auteur = writer[nauteur-1].ID;
    int ID_client = reader[nclient-1].ID;

    do{
        choix = menu();
        switch (choix)
        {
        case 'a':
            system("clear");
            afficherlivre(book, nlivre, addbook, ajjlivre, writer);
            break;
        
        case 'b':
            system("clear");
            afficherauteur(writer, nauteur, addwriter, ajjauteur);
            break;

        case 'c':
            system("clear");
            afficherclient(reader, nclient, addreader, ajjclient);
            break;

        case 'd':
            system("clear");
            if(ajjlivre == 0)
            ajjlivre = ajouterlivre(addbook, ajjlivre, writer, nauteur, ID_livre);
            else
            {
                ID_livre = addbook[ajjlivre-1].ID;
                ajjlivre = ajouterlivre(addbook, ajjlivre, writer, nauteur, ID_livre);
            }
            
            break;

        case 'e':
            system("clear");
            if(ajjauteur == 0)
            ajjauteur = ajouterauteur(addwriter, ajjauteur, ID_auteur);
            else
            {
                ID_auteur = addwriter[ajjauteur-1].ID;
                ajjauteur = ajouterauteur(addwriter, ajjauteur, ID_auteur);
            }
            
            break;

        case 'f':
            system("clear");
            if(ajjclient == 0)
            ajjclient = ajouterclient(addreader, ajjclient, ID_client);
            else
            {
                ID_client = addreader[ajjclient-1].ID;
                ajjclient = ajouterclient(addreader, ajjclient, ID_client);
            }
            
            break;

        case 'g':
            system("clear");
            afficherlivre(book, nlivre, addbook, ajjlivre, writer);
            modiflivre(book, addbook, writer, nauteur);
            break;

        case 'h':
            system("clear");
            afficherauteur(writer, nauteur, addwriter, ajjauteur);
            modifauteur(writer, addwriter);
            break;

        case 'i':
            system("clear");
            afficherclient(reader, nclient, addreader, ajjclient);
            modifclient(reader, addreader);
            break;
        case 'j':
            system("clear");
            afficherlivre(book, nlivre, addbook, ajjlivre, writer);
            retirerlivre(book, addbook);
            break;

        case 'k':
            system("clear");
            afficherauteur(writer, nauteur, addwriter, ajjauteur);
            retirerauteur(writer, addwriter);
            break;

        case 'l':
            system("clear");
            afficherclient(reader, nclient, addreader, ajjclient);
            retirerclient(reader, addreader);
            break;

        case 'm':
            printf("voulez-vous vraiment quitter sans sauvegarder ?(y/n)\n");
            printf("> ");
            scanf("%c", &choix);
            CLEAR_STDIN;
            if(choix == 'y'){
                exit(1);
            }
            break;

        case 'n':

            flivre = ouvrirfich("csv/livre.csv", "w");
            fauteur = ouvrirfich("csv/auteur.csv", "w");
            fclient = ouvrirfich("csv/client.csv", "w");
            savelivre(flivre, book, addbook, nlivre, ajjlivre);
            saveauteur(fauteur, writer, addwriter, nauteur, ajjauteur);
            saveclient(fclient, reader, addreader, nclient, ajjclient);
            return 33;
        
        default:
            printf("mauvais numero...\n");
            system("sleep 1");
            system("clear");
            break;
        }
        printf("\n");
    }while(choix != 'n');

    return 0;
}
