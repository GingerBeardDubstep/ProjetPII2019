#include "chargerGraphe.h"
#include "liste.h"


double distance (node* a1, node* a2){

	double lat1 = a1->la;
	double lat2 = a2->la;
	double long1 = a1->lo;
	double long2 = a2->lo;

	return 0.001*6378137*acos( sin(M_PI*lat1/180)*sin(M_PI*lat2/180) + cos(M_PI*lat1/180)*cos(M_PI*lat2/180)*cos(M_PI*(long1 - long2)/180) );


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
				tableNode[i]->heuristique = 0;
				tableNode[i]->pred = NULL;
				i++;
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




void chargeTableAeroport(char* chemin, node** tableN, int airdest)
{
	FILE* src = fopen(chemin,"r");
	if(src==NULL)
	{
		printf("FILE_NOT_FOUND \n");
	}

	else
	{
		char carEnCours=0;
		int curseur=0;
		int indice = 0;
		int virgule = 0;
		double heur;


		carEnCours = fgetc(src);
		while (carEnCours != EOF) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
        	virgule = 0;

        	char* id = malloc(sizeof(char)*100);
	        char* latitude = malloc(sizeof(char)*100);
	        char* longitude = malloc(sizeof(char)*100);


	        while (carEnCours != '\n')
	        { //On lit une ligne caractère par caractère

	            if (virgule == 0){
	            	while (carEnCours != ','){
	            		*(id + curseur) = carEnCours;
	            		curseur++;
	            		carEnCours = fgetc(src);
	            	}
	            	*(id + curseur) = '\0';
	            	//printf("%s,", id );
	            	curseur = 0;
	            }


	            if (virgule == 2){
	            	while (carEnCours != ','){
	            		*(latitude + curseur) = carEnCours;
	            		curseur++;
	            		carEnCours = fgetc(src);
	            	}
	            	*(latitude + curseur) = '\0';
	            	//printf("%s,", latitude );
	            	curseur = 0;
	            }


	            if (virgule == 3){
	            	while (carEnCours != ','){
	            		*(longitude + curseur) = carEnCours;
	            		curseur++;
	            		carEnCours = fgetc(src);
	            	}
	            	*(longitude + curseur) = '\0';
	            	//printf("%s,\n", longitude );
	            	curseur = 0;
	            }


            	if (carEnCours == ','){
            		virgule ++;
            	}
            	carEnCours = fgetc(src);
	        }

	        	tableN[indice]->id = atoi(id);
	        	tableN[indice]->la = atof(latitude);
	        	tableN[indice]->lo = atof(longitude);

	        	heur = distance(tableN[indice], tableN[airdest]);
	        	tableN[indice]->heuristique = heur;

	        	//printf("%d  %f  %f\n", tableN[indice]->id, tableN[indice]->la, tableN[indice]->lo );



	            free(latitude);
	            free(longitude);
	            free(id);
	            carEnCours = fgetc(src);
	            indice++;
        }//On a lu tout le fichier 

	}
	fclose(src);
}


void chargeTableNode(char* chemin, node** tableN, double* donnees, int taille)
{
	FILE* src = fopen(chemin,"r");
	if(src==NULL)
	{
		printf("FILE_NOT_FOUND \n");
	}

	else
	{
		char carEnCours=0;
		int curseur=0;
		int indice = 0;
		int virgule = 0;

		int numdep = -1;
		int numdest = -1;

		double dist = -1;


		carEnCours = fgetc(src);
		while (carEnCours != EOF) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
        	virgule = 0;

        	char* iddep = malloc(sizeof(char)*100);
	        char* iddest = malloc(sizeof(char)*100);


	        while (carEnCours != '\n')
	        { //On lit une ligne caractère par caractère

	            if (virgule == 4){
	            	while (carEnCours != ','){
	            		*(iddep + curseur) = carEnCours;
	            		curseur++;
	            		carEnCours = fgetc(src);
	            	}
	            	*(iddep + curseur) = '\0';
	            	//printf("%s,", iddep );
	            	curseur = 0;
	            }


	            if (virgule == 6){
	            	while (carEnCours != ','){
	            		*(iddest + curseur) = carEnCours;
	            		curseur++;
	            		carEnCours = fgetc(src);
	            	}
	            	*(iddest + curseur) = '\0';
	            	//printf("%s\n", iddest );
	            	curseur = 0;
	            }

            	if (carEnCours == ','){
            		virgule ++;
            	}
            	carEnCours = fgetc(src);
	        }


	        	if (atoi(iddep) != 0 && atoi(iddest) != 0){
	        		
	        		numdep = airport_getNum(tableN,atoi(iddep), taille);
	        		numdest = airport_getNum(tableN, atoi(iddest), taille);

	        		//printf("%d ---> %d\n",numdep, numdest );

	        		if (numdep != -1 && numdest !=-1 ){

	        			dist = distance(tableN[numdep], tableN[numdest]);

	        			donnees[numdep + taille*numdest] = dist;
	        		}

	        		
	        	}

	            free(iddep);
	            free(iddest);
	            carEnCours = fgetc(src);
	            indice++;
        }//On a lu tout le fichier 

	}
	fclose(src);
}

// void chargeTableNode(char* chemin)
// {
// 	FILE* src = fopen(chemin,"r");
// 	printf("On entre");
// 	if(src==NULL)
// 	{
// 		printf("FILE_NOT_FOUND \n");
// 	}

// 	else
// 	{
// 		char carEnCours=0;
// 		int curseur=0;
// 		int virgule = 0;
// 		double dist;
// 		int numdep;
// 		int numdest;


// 		carEnCours = fgetc(src);
// 		while (carEnCours != EOF) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
//         {
//         	virgule = 0;

// 	        char* iddep = malloc(sizeof(char)*100);
// 	        char* iddest = malloc(sizeof(char)*100);


// 	        while (carEnCours != '\n')
// 	        { //On lit une ligne caractère par caractère

// 	            if (virgule == 3){
// 	            	while (carEnCours != ','){
// 	            		*(iddep + curseur) = carEnCours;
// 	            		curseur++;
// 	            		carEnCours = fgetc(src);
// 	            	}
// 	            	*(iddep + curseur) = '\0';
// 	            	//printf("%s,", id );
// 	            	curseur = 0;
// 	            }


// 	            if (virgule == 4){
// 	            	while (carEnCours != ','){
// 	            		*(iddest + curseur) = carEnCours;
// 	            		curseur++;
// 	            		carEnCours = fgetc(src);
// 	            	}
// 	            	*(iddest + curseur) = '\0';
// 	            	//printf("%s,", latitude );
// 	            	curseur = 0;
// 	            }



//             	if (carEnCours == ','){
//             		virgule ++;
//             	}
//             	carEnCours = fgetc(src);
// 	        }




// 	            //On converti iddep et iddest en numdep et numdest
// 	        	// if (atoi(iddep)!= 0 && atoi(iddest)!=0){
// 	        	// 	printf("L'ID EST NON NUL\n");
// 		        //     numdep = airport_getNum(tableN, atoi(iddep), taille);
// 		        //     numdest = airport_getNum(tableN, atoi(iddest), taille);
// 		        //     dist = distance(tableN[numdep], tableN[numdest]);

// 		        //     printf("%d\n", numdep + 7526*numdest );
// 		        //     donnees[numdep + 7526*numdest] = dist;
// 		        //     free(iddep);
// 		        //     free(iddest);
// 		        //     carEnCours = fgetc(src);
// 		        // }
//         }//On a lu tout le fichier 

// 	}
// 	fclose(src);
// }




int main(int argc, char const *argv[])
{
	node** table = creer_table_noeud(7526);
	printf("NUKNUK\n");
	double* donnees = malloc(sizeof(double)*7526*7526);

	for (int i = 0; i<7526*7526; i++ ){
		donnees[i] = 0;
	}

	chargeTableAeroport("airports.csv", table, 6789);
	//printf("Le num 1567 correspond à l'id %d\n",table[1567]->id  );

	chargeTableNode("routes.csv", table, donnees, 7526);



	printf("ON EST PASSÉ\n");

	int compt = 0;

	for (int i = 0; i < 7526*7526; ++i)
	{
		if (donnees[i] != 0)
		{
			compt++;
		}
	}

	printf("%d\n", compt );

	//printf("%s\n", donnees );

	//chargeTableNode("routes.csv");


	// for (int i = 0; i < 7526; ++i)
	// {
	// 	printf("%d :A la case n°%d, on trouve : %d, %f, %f\n",i, table[i]->num, table[i]->id, table[i]->la, table[i]->lo );	
	// }


	supprimer_table_node(table, 7526);
	free(donnees);



	return 0;
}