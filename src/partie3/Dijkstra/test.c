#include <stdio.h>
#include <stdlib.h>




//Cette fonction permet de recupérer les id des airports
int* creerTableauID(int taille){
	int* tab = malloc(taille * sizeof(int));
	return tab;
}

void supprimerTableauID(int* tab){
	free(tab);
}

int* creerTableauNumero(int taille){
	int* tab = malloc(taille*sizeof(int));
	return tab
}

void supprimerTableauNumero(int* tab){
	free(tab);
}

void chargerIdetNum(char* chemin, int* tableID, int* tableNum){
	FILE* fichier = NULL;
	fichier = fopen(chemin, 'r');
	int caractere=0;
	int i =0;


	if (fichier == NULL ){
		printf("FILE NOT FOUND\n");
	}
	else {
		do{
			char* id=malloc(sizeof(char)*20);
			while (caractere!=','){
				if(cpt1==EOF){
						break;
				}

				*id=caractere;
				caractere=fgetc(fichier);				
			}
			tableID[i] = atoi(id);
			tableNum[atoi(id)]=i;
			i++;


		}while(caractere!=EOF);

 
	}

}

int main(int argc, char const *argv[])
{
	int * tab = malloc(50000*sizeof(int));
	for (int i=0; i<50000; i++){
		tab[i] = -1;
	}


	return 0;
}