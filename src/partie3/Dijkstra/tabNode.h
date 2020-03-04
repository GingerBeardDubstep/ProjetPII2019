#include <stdlib.h>
#include <stdio.h>

typedef struct tableNode;
struct tableNode
{
	node* noeud;
	int taille;
}


tableNode table_creer(int tailleTableau);
node* table_get(node* n,tableNode T);
void table_ajout(node* n,tableNode T);
void table_supprime(node* n,tableNode T);
void table_visualiser(tableNode T);
