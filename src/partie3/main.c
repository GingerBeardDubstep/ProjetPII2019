#include "tableHachage.h"
#define RAYON 35

int main(int argc,char* argv[]){

	if(argc<2){
		printf("Pas assez d'arguuments\n");
	}else if(strcmp(argv[1],"-p")==0){ 					//Si option périmètre
		FILE* src = fopen("../communication/City.csv","r");
		FILE* rat = fopen("../communication/plusProche.csv","w");
		fclose(rat);
		//Parsage du csv produit par java
		if(src!=NULL){
		char cpt1=' ';
		int cpt2=0;

		char* lat=(char*) malloc(sizeof(char)*30);
		char* lon=(char*) malloc(sizeof(char)*30);

		cpt1=fgetc(src);
		while(cpt1!=','){
			cpt1=fgetc(src);
		}
		cpt1=fgetc(src);
		cpt2=0;
		while(cpt1!=','){
			cpt1=fgetc(src);
		}
		cpt1=fgetc(src);
		while(cpt1!=','){
			*(lat+cpt2)=cpt1;
			cpt2++;
			cpt1=fgetc(src);
		}
		lat[cpt2]='\0';

		cpt1=fgetc(src);
		cpt2=0;
		while(cpt1!=','){
			*(lon+cpt2)=cpt1;
			cpt2++;
			cpt1=fgetc(src);
		}
		lon[cpt2]='\0';
		cpt1=fgetc(src);
		fclose(src);
		//On charge le csv produit par java
		tableHachage T = chargeTHAeroport("../communication/Airport.csv");
		//On trouve tous les aéroports dans le périmètre recherché
		liste l = perimetre(T,atof(lat),atof(lon),RAYON);
		free(lat);
		free(lon);
		free_tHAeroport(T);
		//On écrit les aéroports dans un .csv
		listeAeroportEdit(l);
		free_listAeroport(l);
		}else{
			printf("Erreur ouverture du csv\n");
			exit(1);
		}

	}else if(strcmp(argv[1],"-p1")==0){  //Si option plus proche

		FILE* src = fopen("../../communication/City.csv","r");
		

		FILE* rat = fopen("../../communication/plusProche.csv","w");
		fclose(rat);
		//Parsage du csv produit par java (une city en entrée)
		if(src!=NULL){
		char cpt1=' ';
		int cpt2=0;

		char* lat=(char*) malloc(sizeof(char)*30);
		char* lon=(char*) malloc(sizeof(char)*30);

		cpt1=fgetc(src);
		while(cpt1!=','){
			cpt1=fgetc(src);
		}
		cpt1=fgetc(src);
		while(cpt1!=','){
			cpt1=fgetc(src);
		}
		cpt1=fgetc(src);
		while(cpt1!=','){
			*(lat+cpt2)=cpt1;
			cpt2++;
			cpt1=fgetc(src);
		}
		lat[cpt2]='\0';

		cpt1=fgetc(src);
		cpt2=0;
		while(cpt1!=','){
			*(lon+cpt2)=cpt1;
			cpt2++;
			cpt1=fgetc(src);
		}
		lon[cpt2]='\0';
		cpt1=fgetc(src);
		fclose(src);
		// On charge le csv des aéroports produit par java
		
		tableHachage T = chargeTHAeroport("../../communication/Airport.csv");

		//on trouve l'aéroport le plus proche de la ville donnée
		aeroport a = plusProcheTH(T,atof(lat),atof(lon));
		
		free_tHAeroport(T);
		//On écrit dans un csv les données contenues dans l'aéroport trouvé
		aeroportEdit(a);
		free_aeroport(a);
		
		free(lat);
		free(lon);
		}else{
			printf("Erreur ouverture du csv\n");
			exit(1);
		}

	}else{
		printf("Argument invalide\n");
	}

}