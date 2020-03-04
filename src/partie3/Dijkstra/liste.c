#include "liste.h"


Liste* list_creer()
{
    Liste* nvl = malloc(sizeof(Liste));

    if (nvl == NULL){
        printf("Échec du malloc\n");
    }
    else{
        nvl->init = NULL;
    }
    return nvl;
}


int list_estVide(Liste* l)
{
    if (l->init==NULL || l==NULL){
        return 1;
    }
    return 0;
}


void list_ajoutTete(Liste* l, int val)
{
    //On gère le cas où la liste est pas initialisée
    if(l == NULL){
        printf("Il n'y a pas de liste\n");
    }

    cellule* cell = malloc(sizeof(cellule));
    if (cell == NULL)
    {
        printf("Echec du malloc\n");;
    }
    else{
        cell->num = val;
        cell->suiv = l->init;
        l->init = cell;
    }
}


void  list_supprime(Liste* l)
{

    cellule* supp = NULL;
    while (l->init != NULL){
        supp = l->init;
        l->init = l->init->suiv;
        free(supp); 
    }
    free(l);
}


int list_taille(Liste* l)
{
    if (l == NULL){
        printf("Il n'y a pas de liste.\n");
        return -1;
    }
    else {
        if (l->init == NULL){
            return 0;
        }
        else {
            int compteur = 1;
            cellule* parcourt = l->init;
            while (parcourt->suiv != NULL){ 
                compteur ++;
                parcourt = parcourt->suiv;
            }
            return compteur;
        }
    }
}

void liste_visualiser(Liste* l)
{
    if (list_estVide(l))
    {
        printf("NULL\n");
    }

    else 
    {
        cellule* parcourt = l->init;

        while (parcourt->suiv != NULL)
        {
            printf("%d -> ", parcourt->num );
            parcourt = parcourt->suiv;

        }
        printf("%d ->", parcourt->num );
        printf("NULL\n");

    }
}

void list_ajouttri(Liste* l, node** table, node* noeud)
{
   // printf("ON EST DANS LISTE AJOUT TRI\n");
   // printf("On regarde le noeud numéro %d\n", noeud->num );
   // double coucou = noeud->cout + noeud->heuristique;
   // printf("heuristique : %f\n", noeud->heuristique );
   // printf("Ce noeud à un cout de %f\n" ,coucou);

   int nonSortie = 1;

   if (l == NULL){
    printf("NO_LIST_FOUND\n");
   }

   if (table == NULL)
   {
       printf("TABLE_NOT_FOUND\n");
   }

   if (l->init == NULL)
   {
       list_ajoutTete(l,noeud->num);
   }

   else {
        cellule* cell = malloc(sizeof(cellule));
        //On crée la cellule que l'on va ajouter

        if (cell == NULL){
            printf("MALLOC_FAILED\n");
        }

        else {
            //Le malloc à marché
            cell->num = noeud->num;
            cell->suiv = NULL;

            //On commence à parcourir la liste
            cellule* parcourt = l->init;


            int valeurCellule = table[(parcourt)->num]->cout + table[(parcourt)->num]->heuristique;
            int valeurNode = noeud->cout;
            valeurNode += noeud->heuristique;


            if ( valeurCellule >= valeurNode )//Ici la valeur est plus petite que la plus petite valeur de la liste
            {
                list_ajoutTete(l, noeud->num);
            }
            else
            {
                while (nonSortie && parcourt->suiv != NULL ){
                    //printf("ON EST DANS LE WHILE\n");
                    if ( valeurNode < table[(parcourt->suiv)->num]->cout + table[(parcourt->suiv)->num]->heuristique)//On doit mettre la cellule ici
                    {
                        cell->suiv = parcourt->suiv;
                        parcourt->suiv = cell;
                        nonSortie = 0;
                    }
                    else {
                        parcourt = parcourt->suiv;
                    }
                }

                if (cell->suiv == NULL){
                    parcourt->suiv = cell;

                }
            }
        }




   }

   
}

// void list_supprime_elem(Liste* l, int val)
// {
//     if (l==NULL || list_estVide(l)){
//     }

//     if (!list_contient(l, val)){
//     }

//     else {
//         cellule* parcourt = l->init;
//         cellule* tamp = NULL;

//         //On vérifie d'abord que la valeur n'est pas sur la première case :
//         if (parcourt == val){
//             if (parcourt->suiv == NULL){
//                 free(parcourt);
//                 l->init = NULL;
//             }
//             else{

//             }
//         }

//         while(parcourt->suiv != NULL)
//         {
//             if ( (parcourt->suiv)->num == val)
//             {
//                 tamp = parcourt->suiv;
//                 if ( (parcourt->suiv)->suiv == NULL){
//                     parcourt->suiv = NULL;

//                 }
//                 else {
//                     parcourt->suiv = (parcourt->suiv)->suiv;

//                 }

//                 free(tamp);
//             }
//             parcourt = parcourt->suiv;  
//         }
//     }
// }

void list_supprime_elem(Liste* l, int val)
{
    int nonsortie = 1;
    printf("ON SUPPRIME %d\n",val );

    printf("\t\t LA LISTE AVANT :\n");
    liste_visualiser(l);
    if (l== NULL || l->init == NULL || !list_contient(l, val)){

    }

    else //Ici on est sûrs que l'élément est dans la liste 
    {
        int taille = list_taille(l);

        if (taille == 1 || l->init->num == val){
            free(l->init);
        }

        else if (taille == 2){
            free(l->init->suiv);
            l->init->suiv = NULL;
        }

        else {
            cellule *parcourt = l->init;
            while (nonsortie && parcourt->suiv->suiv != NULL){
                if (parcourt->suiv->num == val){
                    cellule* supp = parcourt->suiv;
                    parcourt->suiv = parcourt->suiv->suiv;
                    free(supp);
                    nonsortie = 0;
                }
                parcourt = parcourt->suiv;
                printf("%d\n", parcourt->num );
            }


        }

    }

    printf("\t\tLA LISTE APRÈS :\n");
    liste_visualiser(l);
}

void list_tri(Liste* l, node ** table){
    if (list_taille(l) < 2){
    }
    else {
        cellule* parcourt = l->init;
        int valeurCell = parcourt->num;
        while (parcourt->suiv != NULL){
            if (table[(parcourt->suiv)->num]->cout + table[(parcourt->suiv)->num]->heuristique > table[parcourt->num]->cout + table[parcourt->num]->heuristique ){
                parcourt = parcourt->suiv;
                valeurCell = parcourt->num;
            }
            else {
                parcourt->num = parcourt->suiv->num;
                parcourt->suiv->num = valeurCell; 
            }
        }
    }
}


int list_pop(Liste* l){
    //Cette fonction retire de la liste et renvoie le premeier ELEMENT qu'elle trouve (celui donc qui a la plus petite distance)
    int resultat;

    if (l!= NULL && l->init != NULL){
        resultat = (l->init)->num;
        //Maintenant que l'on a récupéré l'élément, il faut l'enlever de la liste

        cellule* supp = l->init;
        l->init= (l->init)->suiv;
        free(supp);
    }

    return resultat;
}

int list_contient(Liste* l, int val)
{
    int res=0;

    if (l != NULL && l->init != NULL){
        cellule* parcourt = l->init;
        int valeur = parcourt->num;

        // if (valeur == val){
        //     res = 1;
        // }

        while (parcourt->suiv !=NULL){
            if (valeur == val){
                res = 1;
            }
            parcourt = parcourt->suiv;
            valeur = parcourt->num;

        }

        if (valeur == val){
            res = 1;
        }

    }

    return res;
}

