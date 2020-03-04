#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct node node;


double distance (node* a1, node* a2);
int airport_getId(node** table,int num, int taille);
int airport_getNum(node** table,int id, int taille);
node** creer_table_noeud(int taille);
void supprimer_table_node(node** table, int taille);
void chargeTableAeroport(char* chemin, node** tableN, int);

void chargeTableNode(char* chemin, node**, double*, int);
