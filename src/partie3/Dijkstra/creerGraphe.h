#include <stdlib.h>
#include <stdio.h>

typedef struct airport airport;
struct airport
{
	int num;
	int id;
	double latitude;
	double longitude;    
};

typedef struct node node;

node** creer_table_noeud(int);
void supprimer_table_node(node**, int);
airport** creer_table_airport(int);
void supprimer_table_airport(airport**, int);
int airport_getId(node**,int, int);
int airport_getNum(node**,int, int);

