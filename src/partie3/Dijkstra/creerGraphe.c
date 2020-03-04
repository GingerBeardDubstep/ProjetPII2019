#include "creerGraphe.h"
#include "liste.h"
#include "matrice.h"


typedef struct node node;


node** creer_table_noeud(int taille){
	node** tableNode = malloc(sizeof(node*)*taille);
	int nonSortie = 1;
	int i = 0;
	if (tableNode == NULL){
		printf("MALLOC_FAILED\n");
	}
	else {
		while (i< taille && nonSortie){
			tableNode[i] = malloc(sizeof(node));
			if (tableNode[i] == NULL)
			{
				printf("MALLOC_FAILED\n");
				nonSortie = 0;
			}
			else 
			{
				tableNode[i]->num = i;
				tableNode[i]->heuristique = 0:
				tableNode[i]->pred = NULL;
				i++
			}

		}

	}
	
	return(tableNode);
}

void supprimer_table_node(node** table, int taille)
{
	for (int i = 0; i<taille; i++){
		free(table[i]);
	}
	free(table);
}




int airport_getId(node** table,int num, int taille){

	if (num >= 0 && num < taille){
		return table[num]->id;
	}
	return -1;
}

int airport_getNum(node** table,int id, int taille){
	for(int i=0; i<taille; i++){
		if(table[i]->id == id){
			return i;
		}
	}
	return -1;
}


