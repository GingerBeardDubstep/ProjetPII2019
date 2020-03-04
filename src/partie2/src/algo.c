#include "algo.h"
#include "liste.h"
#include "matrice.h"





double conversionRad(double entree){
    return (entree * M_PI)/180;
}

double distance(node* depart, node* destination){
    //On utilise la loi des sinus

    double lat1 = conversionRad(depart->la);
    double lat2 = conversionRad(destination->la);

    double long1 = depart->lo;
    double long2 = destination->lo;

    double dl = conversionRad(dl);

    double S = sin(lat1)*sin(lat2) + cos(lat1)*cos(lat2)*cos(dl);
    double Sf = acos(S);

    return (6378137*Sf);
}






double heuristique(node* destination, int j){

    if (j == 0){
        return 9.0;
    }
    if (j == 1){
        return 8.0;
    }
    if (j == 2){
        return 5.0;
    }
    if (j == 3){
        return 4.0;
    }
    if (j == 4){
        return 6.0;
    }
    if (j == 5){
        return 7.0;
    }
    if (j == 6){
        return 2.0;
    }
    if (j == 7){
        return 1.0;
    }
    if (j == 8){
        return 3.0;
    }
    if (j == 9){
        return 0.0;
    }


}




node* astar(Matrice mat, int dep, int dest, node** liste_noeud)
{
     
    Liste* ouverte = list_creer();
    Liste* ferme = list_creer();

    // node depart = *liste_noeud[dep];
    // node destination = *liste_noeud[dest];

    int num_encours = -1;
    double distance = 0;
    double heur = 0.0;

    list_ajoutTete(ouverte, dep); // On l'ajoute dans la liste ouverte


    while ( !list_estVide(ouverte) )
    {
        num_encours = list_pop(ouverte);
        printf("\t#########    SOMMET %d    #########\n", num_encours );
        list_ajoutTete(ferme, num_encours);
        for (int j=0; j<mat->colonnes; j++)
        {



            if ( *matrice_cellaffiche(mat, num_encours, j)>0 )
            {
                distance = *matrice_cellaffiche(mat, num_encours, j);
                heur = liste_noeud[j]->heuristique;

                printf("\n--------> On regarde le sommet n° %d qui a une distance de %f et une heuristique de %f \n",j, distance, heur );

                if (j == dest) // On est tombé sur l'aéroport de destination
                {   
                    liste_noeud[j]->pred = liste_noeud[num_encours];
                    return liste_noeud[dest];
                }

                //On doit vérifier qu'on ne l'a pas déja visité
                if ( list_contient(ferme, j))
                {

                    printf("On ne fait rien\n");
                }

                else if (list_contient(ouverte, j) && distance + heur > (liste_noeud[j]->cout + liste_noeud[j]->heuristique) ){
                    printf("On ne fait toujours r\n");
                } 
                else 
                {
                    liste_noeud[j]->cout = liste_noeud[num_encours]->cout + distance;
                    liste_noeud[j]->pred = liste_noeud[num_encours];
                    list_supprime_elem(ouverte, j);
                    list_ajouttri(ouverte, liste_noeud, liste_noeud[j]);
                }
            }

            
            
        }
        printf("\nListe ouverte :");
        liste_visualiser(ouverte);
        printf("\nListe ferme :");
        liste_visualiser(ferme);
        printf("\n");

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
        fprintf(fichier, "%d\n", destination->num );
    }
    else {
        while(parcourt->pred != depart){
            //list_ajoutTete(path, parcourt->num);
            fprintf(fichier, "%d\n", parcourt->num );
            parcourt = parcourt->pred;
        }
        //list_ajoutTete(path, parcourt->num);
        fprintf(fichier, "%d\n", parcourt->num );


    }
    fprintf(fichier, "%d\n", depart->num );
    //liste_visualiser(path);
    //list_supprime(path);
    fclose(fichier);

}


int main(int argc, char const *argv[])
{

    

    node ** tatable = malloc(sizeof(node*)*10);
    double tablo[10] = {3,5,0,1,8,6,4,9,7,2};
    for (int i = 0; i<10; i++){
        tatable[i] = malloc(sizeof(node));
        tatable[i]->num = i;
        tatable[i]->heuristique = tablo[i];
        tatable[i]->pred = NULL;
        //printf("Le noeud numéro %d à pour heuristique %f \n", tatable[i]->num, tatable[i]->heuristique);

    }






    // double donnees[100] = {0,2.4,3.6,0,0,0,0,7.8,0,0,
    //                    2.4,0,0,0,0,5.2,5.4,0,0,0,
    //                    3.6,0,0,1.2,0,0,0.9,0,0,0,
    //                    0,0,1.2,0,0,0,0,0,9.4,0,
    //                    0,0,0,0,0,0,0,0,0,0,
    //                    0,0,0,0,0.9,0,0,0,5.6,10.3,
    //                    0,0,0,0,4.3,0,0,0,0,0,
    //                    0,0,0,2.2,0,0,0,0,0,0,
    //                    0,0,0,0,0,0,0,0,0,5.4,
    //                    0,0,0,0,0,0,3.2,4.2,0,0};


    double donnees[100] = {0,0,2.0,0,0,0,0,8.0,0,5.0,
                          0,0,0,0,0,3.2,0,0,0,0,
                          0,0,0,0,0,0,0,0,0,0,
                          0,0,0.5,0,0,0,0,0,0,0,
                          0,0,0,0,0,0,0,0,0,0,
                          0,0,0,0,0,0,0,0,0.3,0.3,
                          0,0,0,2.3,0,1.2,0,0,1.2,0,
                          8.0,0,0,0,4.7,1.2,0,0,0,0,
                          0,0,0,0,0,0,1.2,3.4,0,0,
                          5.0,0,0,0,0,0,0.2,0,0,0};




    Matrice M =  creer_matrice(10,10);
    matrice_initialisation(10,10, donnees,M);

    // matrice_affiche(M);
    // printf("AAAAAAAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");


    node * marchestp = astar(M, 7, 2, tatable);
    printf("\n\n\n");

    getPath(marchestp, tatable[7], "sortie.txt");
    printf("%d\n", marchestp->num );
    printf("%d\n", marchestp->num );
    printf("%d\n", marchestp->pred->num );

    printf("%d\n", (marchestp->pred->pred)->num);

    printf("%d\n", (marchestp->pred->pred->pred)->num);
    printf("%d\n", (marchestp->pred->pred->pred->pred)->num);
    printf("%d\n", (marchestp->pred->pred->pred->pred->pred)->num);



    supprimer_matrice(M);

    for (int i = 0; i<10; i++){
        free(tatable[i]);

    }

    free (tatable);


    // double *donnees = malloc(sizeof(double)*(3*3));

    // for (int i =0; i<(3*3); i++){
    // donnees[i] = i+1;
    // }
    // Matrice m = creer_matrice(3,3);
    // printf("SKOURALÈD\n");
    // matrice_initialisation(3, 3, donnees,m);
    // printf("%d\n", m->lignes );
    // matrice_affiche(m);
    // supprimer_matrice(m);
    //free(donnees);


    return 0;
}

