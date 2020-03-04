#include "tabNode.h"
#include "node.h"

tabNode* table_creer(int tailleTableau){
	tabNode* T = malloc(sizeof(node)*tailleTableau);
	return(T);
}
aeroport tableHachage_get(aeroport a,tableAero T){
	int hash = hachage(a->nom,T->taille);
	return(listAeroport_rech(T->tableau[hash],a->id));
}
void tableHachage_ajout(aeroport a,tableAero T){
	int hash = hachage(a->nom,T->taille);
	T->tableau[hash]=listAeroport_ajoutFin(T->tableau[hash],a);
}
void tableHachage_supprime(aeroport a,tableAero T){
	int hash = hachage(a->nom,T->taille);
	aeroport a1=malloc(sizeof(aeroport));
	a1=listAeroport_rech(T->tableau[hash],a->id);
	if(a1!=NULL){
		T->tableau[hash]=listAeroport_remove(T->tableau[hash],a1);
	}
}
void tableHachage_visualiser(tableAero T){
	for(int i=0;i<T->taille;i++){
		printf("Liste %d\n",i);
		listAeroport_visualiser(T->tableau[i]);
	}
}

tableNode* remplitTableNode(char* chemin)
{
	FILE* src = fopen(chemin,"r");
	if(src!=NULL)
	{
		tableNode* T=tableHachage_creer(10);
		int cpt1=0;
		int cpt2=0;
		do
		{
			
			char* lat=malloc(sizeof(char)*30);
			char* lon=malloc(sizeof(char)*30);
			char* nom=malloc(sizeof(char)*128);
			char* id=malloc(sizeof(char)*20);
			char* heuristique=malloc(sizeof(char)*50);
			
			cpt1=fgetc(src);

			if(cpt1==EOF)
			{
				free(lat);
				free(lon);
				free(nom);
				free(id);
				break;
			}

			while(cpt1!=',')
			{
				if(cpt1==EOF){
					break;
				}
				*(id+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}

			if(cpt1==EOF)
			{
				free(lat);
				free(lon);
				free(nom);
				free(id);
				free(icao);
				break;
			}
			id[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(nom+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			nom[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(lat+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);

			}
			lat[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(lon+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			lon[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;

				while(cpt1!=','){
					if(cpt1==EOF){
						break;
					}
					*(iata+cpt2)=cpt1;
					cpt2++;
					cpt1=fgetc(src);
				}
				iata[cpt2]='\0';
			

			
			cpt1=fgetc(src);
			cpt2=0;
				while(cpt1!=','){
					if(cpt1==EOF){
						break;
					}
					*(icao+cpt2)=cpt1;
					cpt2++;
					cpt1=fgetc(src);
					
				}
				icao[cpt2]='\0';
			
			
			while(cpt1!='\n'&&cpt1!=EOF){
				if(cpt1==EOF){
					break;
				}
				cpt1=fgetc(src);
			}
			cpt2=0;
			//printf("yolo\n");
			if(cpt1==EOF){
				free(id);
				free(iata);
				free(icao);
				free(nom);
				free(lat);
				free(lon);
				break;
			}

			tableHachage_ajout(initialiseAeroport(atof(lat),atof(lon),strndup(nom,128),atoi(id),strndup(iata,10),strndup(icao,10)),T,nom);
			//listAeroport_affiche(initialiseAeroport(atof(lat),atof(lon),nom,atoi(id),iata,icao));
			free(id);
			free(nom);
			free(lat);
			free(lon);
		}while(cpt1!= EOF);

		fclose(src);
		printf("Fin parsage airports\n");
		return(T);
	}
	else
	{
		printf("Nom de source incorrect \n");
		return(NULL);
	}
}