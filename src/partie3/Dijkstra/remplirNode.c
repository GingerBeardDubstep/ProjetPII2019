#include <stdio.h>
#include <stdlib.h>



// typedef struct node node;
// struct node
// {
//     int id;
//     int num;
//     double latitude;
//     double longitude;
//     double heuristique;
//     node* pred;
// };

typedef struct node node;
struct node
{
    int dep;
    int dest;
};




typedef struct airport airport;
struct airport
{
	double latitude;
	double longitude;
	int id;
	char* IATA;
	char* ICAO;
};



airport* initialiseAeroport(airport* a, double lat, double lon, int id, char* iata, char* icao)
{
	// airport* a = NULL;
	// a =  malloc(sizeof(airport));

	if(a != NULL)
	{
		a->latitude=lat;
		a->longitude=lon;
		a->id=id;
		a->IATA= iata;
		a->ICAO= icao;
	}

	return(a);
}



void free_aeroport(airport* a)
{
	free(a);
}

// void remplirTableAeroports(char* chemin, airport** table)
// {
// 	FILE* src = NULL;
// 	//airport ** table = NULL;

// 	src = fopen(chemin,"r");

// 	if(src==NULL)
// 	{
// 		printf("FILE NOT FOUND \n");
// 	}


// 	else if (table == NULL)
// 	{
// 		printf("TABLE NOT FOUND\n");
// 	}


// 	else
// 	{
// 		//airport** table = malloc(sizeof(airport)*100000);

		
// 		char carEnCours=0;
// 		int curseur=0;
// 		int indice = 0;
// 		int virgule = 0;

// 		airport* air = NULL;

// 		carEnCours = fgetc(src);
// 		while (carEnCours != EOF) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
//         	{
//         		virgule = 0;
//         		char* id = malloc(sizeof(char)*500);
//             	char* latitude = malloc(sizeof(char)*300);
//             	char* longitude = malloc(sizeof(char)*300);
//             	char* iata = malloc(sizeof(char)*300);
//             	char* icao = malloc(sizeof(char)*300);

//             	if (id == NULL || latitude == NULL || longitude == NULL || iata == NULL || icao == NULL)
//             	{
//             		printf("MALLOC FAILED\n");
//             	}

//             	else 
//             	{


//             		while (carEnCours != '\n')
//             		{ //On lit une ligne caractère par caractère
            	
//  		           		air = malloc(sizeof(airport)); //On initialise l'aéroport que l'on va remplir
//  		           		if (air == NULL)
//  		           		{
//  		           			printf("MALLOC FAILED\n");
//  		           		}

//  		           		else 
//  		           		{

//             				if (virgule == 0) //On est tombé sur l'id
//             				{
//             					while (carEnCours != ',')
//             					{
//             						*(id + curseur) = carEnCours;
//             						curseur++;
//             						carEnCours = fgetc(src);
//             					}
// 	            				*(id + curseur) = '\0';
// 	            				curseur = 0;
// 	            			}

//             				if (virgule == 2) //On est tombé sur la latitude
//             				{
//             					while (carEnCours != ',')
//             					{
//             						*(latitude + curseur) = carEnCours;
//             						curseur++;
//             						carEnCours = fgetc(src);
//             					}
// 	            				*(latitude + curseur) = '\0';
// 	            			    curseur = 0;

//             				}

//             				if (virgule == 3)//On est tombé sur la longitude
//             				{
//             					while (carEnCours != ',')
//             					{
//             						*(longitude + curseur) = carEnCours;
//             						curseur++;
//             						carEnCours = fgetc(src);
// 	            				}
// 	            				*(longitude + curseur) = '\0';
// 	            				curseur = 0;
//             				}

//             				if (virgule == 4)//On est tombé sur l'iata
//             				{
// 	            				while (carEnCours != ',')
// 	            				{
// 	            					*(iata + curseur) = carEnCours;
// 	            					curseur++;
// 	            					carEnCours = fgetc(src);
// 	            				}
// 	            				*(iata + curseur) = '\0';
// 	            			    curseur = 0;
//             				}


// 	            			if (virgule == 5)//On est tombé sur l'icao
// 	            			{
// 	            				while (carEnCours != ',')
// 	            				{
// 	            					*(icao + curseur) = carEnCours;
// 	            					curseur++;
// 	            					carEnCours = fgetc(src);
// 	            				}
// 	            				*(icao + curseur) = '\0';
// 	            			    curseur = 0;
// 	            			}

            

// 		            		if (carEnCours == ',')//On change de mot
// 		            		{
// 		            			virgule ++;
// 		            		}


// 		            		carEnCours = fgetc(src);
//             		}//On a fini la ligne

//             		air = initialiseAeroport(air, atof(latitude), atof(longitude), atoi(id), iata, icao);
//             		table[indice] = (airport*) air;
//             		free(id);
//             		free(latitude);
//             		free(longitude);
//             		free(iata);
//             		free(icao);
//             		free(air);
//             		carEnCours = fgetc(src);
//             		indice++;
//             	}


				
//  		  	}//On a fini de lire le fichier
//     }
//     fclose(src);
// }

// }

void remplir(node * noeud, int indice, node** tab){
	tab[indice] = malloc(sizeof(node*)*100000);
	if (tab[indice] == NULL){
		printf("MALLOC FAILES\n");
	}

	else{
		tab[indice] = noeud;
	}

}



void remplitTableNode(char* chemin)
{
	FILE* src = fopen(chemin,"r");
	//node ** table = malloc(sizeof(node*)*100000);
	if(src==NULL)
	{
		printf("FILE NOT FOUND \n");
	}
	// else if (table == NULL){
	// 	printf("MALLOC FAILED\n");
	// }
	else
	{
		char carEnCours=0;
		int curseur=0;
		int indice = 0;
		int virgule = 0;

		//char* chaine = malloc(sizeof(char)*100);

		carEnCours = fgetc(src);
		while (carEnCours != EOF) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
        	virgule = 0;
        	node* noeud = malloc(sizeof(node));
        	if (noeud == NULL){
        		printf("NUKNUK\n");
        	}
        	else {
        		char* dep = malloc(sizeof(char)*10);
	            char* dest = malloc(sizeof(char)*10);
	            while (carEnCours != '\n')
	            { //On lit une ligne caractère par caractère
	            	//printf("%c", carEnCours );


	            	if (virgule == 2){
	            		while (carEnCours != ','){
	            			*(dep + curseur) = carEnCours;
	            			curseur++;
	            			carEnCours = fgetc(src);
	            		}
	            		*(dep + curseur) = '\0';
	            		printf("%s,", dep );
	            		curseur = 0;
	            	}

	            	if (virgule == 4){
	            		while (carEnCours != ','){
	            			*(dest + curseur) = carEnCours;
	            			curseur++;
	            			carEnCours = fgetc(src);
	            		}
	            		*(dest + curseur) = '\0';
	            		printf("%s\n", dest );
	            		curseur = 0;

	            	}

	            	if (carEnCours == ','){
	            		virgule ++;
	            	}
	            	carEnCours = fgetc(src);
	            }

	            //noeud->dep = atoi(dep);
	            //noeud->dest = atoi(dest);
	            //printf("%d,", noeud->dep );
	            //remplir(noeud, indice, table);
	            //printf("%d\n", table[indice]->dep );
	            free(dep);
	            free(dest);
	            //free(noeud);

	            carEnCours = fgetc(src);
	            indice++;
	        	}


        }

	}
	fclose(src);
	//return table;
}



int main(int argc, char const *argv[])
{
	remplitTableNode("../../../cleaned_data/routes.csv");
	// node * noeud = malloc(sizeof(node));

	// for (int i = 0; i<67644; i++){
	// 	free(table[i]);
	// }

	//free(table);
// 	airport** table = malloc(sizeof(airport)*100000);
// ;
// 	table = remplirTableAeroports("../../../cleaned_data/airports.csv");
// 	//printf("%s\n", table[34]->ICAO );
// 	free(table);

	// airport** table = malloc(sizeof(airport)*100000);
	// remplirTableAeroports("../../../cleaned_data/airports.csv", table);
	// printf("%s\n", table[56]->ICAO);
	// free(table);


	return 0;
}