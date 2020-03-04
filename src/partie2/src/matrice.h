#include <stdlib.h>
#include<stdio.h>
#define SIZE_TAB 67645

struct matrice {
  int lignes;
  int colonnes;
  double** data;
  int dynamic;
};

typedef struct matrice* Matrice;


Matrice creer_matrice(int , int );
void supprimer_matrice(Matrice);
void matrice_dynamique(Matrice);
double* matrice_cellaffiche(Matrice, unsigned int, unsigned int);




