#include "algo.h"
#include "liste.h"
#include "chargerGraphe.h"

double distance (node* a1, node* a2){

    double lat1 = a1->la;
    double lat2 = a2->la;
    double long1 = a1->lo;
    double long2 = a2->lo;

    return 0.001*6378137*acos( sin(M_PI*lat1/180)*sin(M_PI*lat2/180) + cos(M_PI*lat1/180)*cos(M_PI*lat2/180)*cos(M_PI*(long1 - long2)/180) );


}


int airport_getId(node** table,int num, int taille){

    if (num >= 0 && num < taille){
        return table[num]->id;
    }
    return -1;
}

int airport_getNum(node** table,int id, int taille){
    for(int i=0; i<taille; i++){
        if(table[i]->id == id){
            return i;
        }
    }
    return -1;
}

// void trajet(char * chemin, int* trajet){
//     FILE* fichier = NULL;
//     fichier = fopen(chemin, "r");

//     if (fichier == NULL){
//         printf("FILE_NOT_FOUND3\n");
//     }

//     else{
//         char id[100] = "";
//         int i = 0;
//         while (fgets(id, 100, fichier) != NULL){
//             trajet[i] = atoi(id);
//             i++;
//         }

//         for (int i = 0; i<100; i++){
//             printf("%c\n", *(trajet+i) );
//         }        
//     }
// }

void trajet(char * chemin, int* trajet){
    FILE* fichier = NULL;
    fichier = fopen(chemin, "r");

    if (fichier == NULL){
        printf("FILE_NOT_FOUND3\n");
    }
    else {
        char carEnCours=0;
        int curseur=0;
        int indice = 0;
        int virgule = 0;


        carEnCours = fgetc(fichier);
        while (carEnCours != EOF) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            virgule = 0;

            char* id = malloc(sizeof(char)*100);

            while (carEnCours != '\n')
            { //On lit une ligne caractère par caractère

                if (virgule == 0){
                    while (carEnCours != ','){
                        *(id + curseur) = carEnCours;
                        curseur++;
                        carEnCours = fgetc(fichier);
                    }
                    *(id + curseur) = '\0';
                    //printf("%s,", id );
                    curseur = 0;
                }



                if (carEnCours == ','){
                    virgule ++;
                }
                carEnCours = fgetc(fichier);
            }

                trajet[indice] = atoi(id);
                free(id);
                carEnCours = fgetc(fichier);
                indice++;
        }//On a lu tout le fichier 

 }

}

node** creer_table_noeud(int taille){
    node** tableNode = malloc(sizeof(node*)*taille);
    int nonSortie = 1;
    int i = 0;
    if (tableNode == NULL){
        printf("MALLOC_FAILED\n");
    }
    else {
        while (i< taille && nonSortie){
            tableNode[i] = malloc(sizeof(node));
            if (tableNode[i] == NULL)
            {
                printf("MALLOC_FAILED\n");
                nonSortie = 0;
            }
            else 
            {
                tableNode[i]->num = i;
                tableNode[i]->heuristique = 0;
                tableNode[i]->pred = NULL;
                i++;
            }

        }

    }
    
    return(tableNode);
}

void supprimer_table_node(node** table, int taille)
{
    for (int i = 0; i<taille; i++){
        free(table[i]);
    }
    free(table);
}




void chargeTableAeroport(char* chemin, node** tableN, int airdest)
{
    FILE* src = fopen(chemin,"r");
    if(src==NULL)
    {
        printf("FILE_NOT_FOUND2 \n");
    }

    else
    {
        char carEnCours=0;
        int curseur=0;
        int indice = 0;
        int virgule = 0;
        double heur;


        carEnCours = fgetc(src);
        while (carEnCours != EOF) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            virgule = 0;

            char* id = malloc(sizeof(char)*100);
            char* latitude = malloc(sizeof(char)*100);
            char* longitude = malloc(sizeof(char)*100);


            while (carEnCours != '\n')
            { //On lit une ligne caractère par caractère

                if (virgule == 0){
                    while (carEnCours != ','){
                        *(id + curseur) = carEnCours;
                        curseur++;
                        carEnCours = fgetc(src);
                    }
                    *(id + curseur) = '\0';
                    //printf("%s,", id );
                    curseur = 0;
                }


                if (virgule == 2){
                    while (carEnCours != ','){
                        *(latitude + curseur) = carEnCours;
                        curseur++;
                        carEnCours = fgetc(src);
                    }
                    *(latitude + curseur) = '\0';
                    //printf("%s,", latitude );
                    curseur = 0;
                }


                if (virgule == 3){
                    while (carEnCours != ','){
                        *(longitude + curseur) = carEnCours;
                        curseur++;
                        carEnCours = fgetc(src);
                    }
                    *(longitude + curseur) = '\0';
                    //printf("%s,\n", longitude );
                    curseur = 0;
                }


                if (carEnCours == ','){
                    virgule ++;
                }
                carEnCours = fgetc(src);
            }

                tableN[indice]->id = atoi(id);
                tableN[indice]->la = atof(latitude);
                tableN[indice]->lo = atof(longitude);

                // heur = distance(tableN[indice], tableN[airdest]);
                // tableN[indice]->heuristique = heur;

                //printf("%d  %f  %f\n", tableN[indice]->id, tableN[indice]->la, tableN[indice]->lo );



                free(latitude);
                free(longitude);
                free(id);
                carEnCours = fgetc(src);
                indice++;
        }//On a lu tout le fichier 

    }
    fclose(src);
}

void chargeHeuristique(node ** table, int numdest, int taille)
{
    double heur = 0.0;
    for (int i = 0; i<taille ; i++ ){
        heur = distance(table[i], table[numdest]);
        table[i]->heuristique = heur;
    }
}


void chargeTableNode(char* chemin, node** tableN, double* donnees, int taille)
{
    FILE* src = fopen(chemin,"r");
    if(src==NULL)
    {
        printf("FILE_NOT_FOUND1 \n");
    }

    else
    {
        char carEnCours=0;
        int curseur=0;
        int indice = 0;
        int virgule = 0;

        int numdep = -1;
        int numdest = -1;

        double dist = -1;


        carEnCours = fgetc(src);
        while (carEnCours != EOF) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            virgule = 0;

            char* iddep = malloc(sizeof(char)*100);
            char* iddest = malloc(sizeof(char)*100);


            while (carEnCours != '\n')
            { //On lit une ligne caractère par caractère

                if (virgule == 4){
                    while (carEnCours != ','){
                        *(iddep + curseur) = carEnCours;
                        curseur++;
                        carEnCours = fgetc(src);
                    }
                    *(iddep + curseur) = '\0';
                    //printf("%s,", iddep );
                    curseur = 0;
                }


                if (virgule == 6){
                    while (carEnCours != ','){
                        *(iddest + curseur) = carEnCours;
                        curseur++;
                        carEnCours = fgetc(src);
                    }
                    *(iddest + curseur) = '\0';
                    //printf("%s\n", iddest );
                    curseur = 0;
                }

                if (carEnCours == ','){
                    virgule ++;
                }
                carEnCours = fgetc(src);
            }


                if (atoi(iddep) != 0 && atoi(iddest) != 0){
                    
                    numdep = airport_getNum(tableN,atoi(iddep), taille);
                    numdest = airport_getNum(tableN, atoi(iddest), taille);

                    //printf("%d ---> %d\n",numdep, numdest );

                    if (numdep != -1 && numdest !=-1 ){

                        dist = distance(tableN[numdep], tableN[numdest]);

                        donnees[numdep + taille*numdest] = dist;
                    }

                    
                }

                free(iddep);
                free(iddest);
                carEnCours = fgetc(src);
                indice++;
        }//On a lu tout le fichier 

    }
    fclose(src);
}


node* astar(double* donnees, int dep, int dest, node** liste_noeud, int taille)
{
     
    Liste* ouverte = list_creer();
    Liste* ferme = list_creer();

    int num_encours = -1;
    double distance = 0;
    double heur = 0.0;

    list_ajoutTete(ouverte, dep); // On l'ajoute dans la liste ouverte


    while ( !list_estVide(ouverte) )
    {
        num_encours = list_pop(ouverte);
        //printf("\t#########    SOMMET %d    #########\n", num_encours );
        list_ajoutTete(ferme, num_encours);

        for (int j=0; j<taille; j++)
        {


            if ( donnees[j + taille*num_encours]>0 )
            {
                distance = donnees[num_encours + taille*j];
                heur = liste_noeud[j]->heuristique;

                //printf("\n--------> On regarde le sommet n° %d qui a une distance de %f et une heuristique de %f \n",j, distance, heur );

                if (j == dest) // On est tombé sur l'aéroport de destination
                {   
                    liste_noeud[j]->pred = liste_noeud[num_encours];
                    liste_noeud[j]->cout = liste_noeud[num_encours]->cout + distance;

                    return liste_noeud[dest];
                }
                //printf("J : %d\n",j);

                //On doit vérifier qu'on ne l'a pas déja visité
                if ( list_contient(ferme, j))
                {

                    //printf("On ne fait rien\n");
                }

                else if (list_contient(ouverte, j) && distance + heur > (liste_noeud[j]->cout + liste_noeud[j]->heuristique) ){
                    //printf("On ne fait toujours r\n");
                } 
                else 
                {
                    
                    //printf(" J %d\n",j );
                    liste_noeud[j]->cout = liste_noeud[num_encours]->cout + distance;
                   //printf("%f\n", liste_noeud[j]->heuristique);                    
                    liste_noeud[j]->pred = liste_noeud[num_encours];
                    //printf(" J %d\n",j );
                    // list_supprime_elem(ouverte, j);
                    // printf("ON A SUPPRIMÉ %d\n, j");
                    // list_ajouttri(ouverte, liste_noeud, liste_noeud[j]);

                    if (!list_contient(ouverte, j)){
                        list_ajouttri(ouverte, liste_noeud, liste_noeud[j]);
                    }
                    else {
                        list_tri(ouverte,liste_noeud);
                    }
                    
                }
            }

            
            
        }
        // printf("Liste ouverte : ");
        // liste_visualiser(ouverte);
        // printf("Liste fermée : ");
        // liste_visualiser(ferme);
        // printf("\n\n");


    }
    list_supprime(ouverte);
    list_supprime(ferme);


    printf("On a rien trouvé\n");
    return(NULL);
}

void getPath(node* destination, node* depart, char* chemin){
    //Liste* path = list_creer();
    node * parcourt = destination;
    FILE * fichier = NULL;
    fichier = fopen(chemin, "w");

    if (fichier == NULL){
        printf("FILE_CREATION_ERROR\n");
    }

    if (parcourt->pred == depart){
        //list_ajoutTete(path, destination->num);
        fprintf(fichier, "%d\n", destination->id );
    }
    else {
        while(parcourt->pred != depart){
            //list_ajoutTete(path, parcourt->num);
            fprintf(fichier, "%d\n", parcourt->id );
            parcourt = parcourt->pred;
        }
        //list_ajoutTete(path, parcourt->num);
        fprintf(fichier, "%d\n", parcourt->id );


    }
    fprintf(fichier, "%d\n", depart->id );
    //liste_visualiser(path);
    //list_supprime(path);
    printf("%f\n", destination->cout );
    fclose(fichier);

}


int main(int argc, char const *argv[])
{


    int traj[2] = {-1, -1};

    trajet("../../communication/Trajet.csv", traj);

    int dep = traj[0];
    int dest = traj[1];

    printf("%d %d\n", dep, dest );

    if (dep == -1 || dest == -1){
        printf("PATH_ERROR\n");
    }

    else {

        node** table = creer_table_noeud(7534);
        double* donnees = malloc(sizeof(double)*7534*7534);
        for (int i = 0; i<7534*7534; i++ ){
            donnees[i] = 0;
        }

        chargeTableAeroport("../../communication/Airport.csv", table, 2822);
        chargeTableNode("../../communication/route.csv", table, donnees, 7534);
        dep = airport_getNum(table, dep, 7534);
        dest = airport_getNum(table, dest, 7534);
        chargeHeuristique(table, dest, 7534);
        printf("%d %d\n",dep, dest );
        node * marchestp = astar(donnees, dep, dest, table, 7534);
        if (marchestp == NULL){

        }
        else {
            getPath(marchestp, table[dep], "../../communication/sortie.txt");
        }

        supprimer_table_node(table, 7534);  
        free(donnees);
    }

    return 0;
}
