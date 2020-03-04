#include <stdio.h>
#include <stdlib.h>



typedef struct node node;
struct node
{
    int id;
    int num;
    double latitude;
    double longitude;
    double heuristique;
    node* pred;
};



node* initialiseNode(int,int,double,double,double,node*);
void supprimeNode(node*);

