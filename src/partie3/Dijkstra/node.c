#include "node.h"


node* initialiseNode(int id, int num,double latitude, double longitude, double heuristique, node* pred){
    node* n = malloc(sizeof(node*));

    n->id = id;
    n->num;
    n->latitude = latitude;
    n->longitude = longitude;
    n->heuristique = heuristique;
    n->pred = pred;

    return(n);
}



void supprimeNode(node* n){
	free(n);
}