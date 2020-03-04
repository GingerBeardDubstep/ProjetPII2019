#include "matrice.h"

Matrice creer_matrice(int lignes , int colonnes)
{
  Matrice m = NULL;
  m = malloc(sizeof(Matrice));

  if (m == NULL)
  {
    printf("Problèmes avec le malloc\n");
    abort();
  }
  
  m->lignes=lignes;
  m->colonnes=colonnes;
  m->dynamic = 0;
  m->data = NULL;

  m->data =malloc(lignes*sizeof(double*));
  if (m->data == NULL)
  {
    printf("Problèmes avec le malloc\n");
    abort();
  }  

  for (int i = 0; i<lignes; i++)
  {
    m->data[i] = NULL;
    m->data[i] = malloc(sizeof(double)*colonnes);
    if (m->data[i] == NULL)
    {
      printf("Problèmes avec le malloc\n");
      abort();
    }
  }

  return m;
}

void supprimer_matrice(Matrice m )
{
  for (int i = 0; i<m->lignes; i++)
  {
    free(m->data[i]);
  }

  free(m->data);
  free(m);

}

void matrice_dynamique(Matrice m)
{
  m->dynamic = 1;
}

double* matrice_cellaffiche(Matrice m, unsigned int i, unsigned int j) 
{
  double* result = NULL;
  if (m==NULL){
    abort();
  }

  if(i < m->lignes && j < m->colonnes){
    result = &(m->data[i][j]);
  }
  else if (m->dynamic){

    if (i>= m->lignes){
      m->data = realloc(m->data, (i+1)*sizeof(double*));
      if (m->data == NULL){
        abort();
      }
    for (int k = m->lignes; k<i+1; k++){
      m->data[k] = malloc(sizeof(double)*m->colonnes);
      if (m->data[k] == NULL){
        abort();
      }
    }
    m->lignes=i+1;
    }


    if (j>= m->colonnes){
      for (int i=0; i< m->lignes; i++){
        m->data[i]=realloc(m->data[i], (j+1)*sizeof(double));
        if (m->data[i] == NULL){
          abort();
        }
      }
      m->colonnes = j+1;
    }


    result = &(m->data[i][j]);

  }

  return result;
}

void matrice_initialisation(int l, int c, double* donnees, Matrice m) 
{

  //m = creer_matrice(l, c);
  for (int i = 0; i < l; i++)
      for (int j = 0; j < c; j++){
          *matrice_cellaffiche(m, i, j) = donnees[i * c + j];
          //printf("%f\n", donnees[i*c+j] );
        }
}


void matrice_affiche(Matrice m) 
{
  
  for (int i = 0; i < m->lignes; i++) {
    printf("[ ");
    for (int j = 0; j < m->colonnes; j++)
      printf("%g ",*matrice_cellaffiche(m, i, j));
    printf("]\n");
  }

}



// int main(int argc, char const *argv[])
// {
//   Matrice m;
//   double *donnees = malloc(sizeof(double)*(3*3));

//   for (long i =0; i<(7526*7526); i++){
//     donnees[i] = i+1;
//   }
//   m= matrice_initialisation(3, 3, donnees);
//   printf("%f\n", matrice_cellaffiche(m, 13, 1));
//   //matrice_affiche(m);
//   supprimer_matrice(m);
//   free(donnees);


//   return 0;
// }
