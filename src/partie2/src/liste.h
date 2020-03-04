#include <stdlib.h>
#include <stdio.h>


typedef struct cellule cellule;
struct cellule
{
	int num;
	cellule* suiv;
    
};

typedef struct Liste Liste;
struct Liste
{
    cellule* init;
};

//val correspond à la somme de l'heuristique et de la distance parcourue
typedef struct node node;
struct node
{
    int num;
    int id;
    double la;
    double lo;
    double cout;
    double heuristique;
    node* pred;
};

Liste* list_creer();
int list_estVide(Liste* l);
void list_ajoutTete(Liste* l, int val);
void  list_supprime(Liste* l);
int list_taille(Liste* l);
void liste_visualiser(Liste* l);
void list_ajouttri(Liste* l, node** table, node*);
void list_supprime_elem(Liste* l, int val);
int list_pop(Liste* l);
int list_contient(Liste* l, int val);
void list_tri(Liste* liste, node ** table);
