/*
Permet d'alleger le fichier principale
fonctions :
    - affiche le menu
    - ouvre les fichiers csv
    - compte le nombre de lignes des fichiers csv
*/

#define CLEAR_STDIN { int c; while((c = getchar()) != '\n' && c != EOF); } //car fflush(stdin) n'est pas parfait

/***ouvre les fichiers***/
FILE* ouvrirfich(const char* nomfichier, const char* mode){

    FILE* fichier = NULL;
    fichier = fopen(nomfichier, mode); // ouvre le fichier
    return fichier;
    
}

/***nombre de ligne dans les fichiers***/
int comptelivre(FILE* fichier){
    int nligne = 0;
    int c;
    for (c = getc(fichier); c != EOF; c = getc(fichier))  // boucle jusqu'au End Of File
        if (c == '\n') // augmente le compteur de ligne si il rencontre un '\n' 
            nligne = nligne + 1;
    printf("il y a: %i livres\n", nligne+1);
    return nligne+1; // retourne le nombre de ligne
}
int compteauteur(FILE* fichier){
    int nligne = 0;
    int c;
    for (c = getc(fichier); c != EOF; c = getc(fichier)) 
        if (c == '\n') 
            nligne = nligne + 1;
    printf("il y a: %i auteurs\n", nligne+1);
    return nligne+1;
}
int compteclient(FILE* fichier){
    int nligne = 0;
    int c;
    for (c = getc(fichier); c != EOF; c = getc(fichier)) 
        if (c == '\n') 
            nligne = nligne + 1;
    printf("il y a: %i clients\n", nligne+1);
    printf("\n");
    return nligne+1;
}

/***menu***/
char menu(){

    char choix;
    printf("Menu: \n\n"); // affiche le menu
    printf("a. afficher livres\n");
    printf("b. afficher auteurs\n");
    printf("c. afficher clients\n");
    printf("d. ajouter livre\n");
    printf("e. ajouter auteur\n");
    printf("f. ajouter clients\n");
    printf("g. modifier livre\n");
    printf("h. modifier auteur\n");
    printf("i. modifier clients\n");
    printf("j. supprimer livres\n");
    printf("k. supprimer auteurs\n");
    printf("l. supprimer clients\n");
    printf("m. pret de livre\n");
    printf("n. quitter\n");
    printf("o. sauvegarder et quitter\n");
    printf("> ");
    scanf("%c", &choix); // char -> un nombre    -> plante pas
    printf("\n");        // int  -> un carcatere -> plante 
    CLEAR_STDIN;
    return choix;
}
