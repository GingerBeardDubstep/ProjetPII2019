#include "aeroport.h"

aeroport initialiseAeroport(double lat,double lon, char* nom, int id, char* iata, char* icao){
	aeroport a = (aeroport) malloc(sizeof(*a));
	if(a==NULL){
		exit(1);
	}
	a->latitude=lat;
	a->longitude=lon;
	a->nom=nom;
	a->id=id;
	a->IATA=iata;
	a->ICAO=icao;
	return(a);
}

void free_aeroport(aeroport a){
	free(a->nom);
	free(a->IATA);
	free(a->ICAO);
	free(a);
}

int est_dans_perimetre(aeroport a1, aeroport a2,int rayon){
	if(a1->id==a2->id){
		return(0);
	}
	double res;
	res=sqrt((a1->latitude-a2->latitude)*(a1->latitude-a2->latitude)+(a1->longitude-a2->longitude)*(a1->longitude-a2->longitude));
	if(res<=((double) rayon/111.11)){
		return(1);
	}else{
		return(0);
	}
}

double distance(aeroport a,double lat,double lon){
	double res;
	res=sqrt((a->latitude-lat)*(a->latitude-lat)+(a->longitude-lon)*(a->longitude-lon));
	return(res);
}

char* getICAO(aeroport a){
	return(a->ICAO);
}

char* getIATA(aeroport a){
	return(a->IATA);
}

char* getNom(aeroport a){
	return(a->nom);
}

int getId(aeroport a){
	return(a->id);
}

void aeroportEdit(aeroport a){
	char* lat=malloc(sizeof(char)*30);
	char* lon=malloc(sizeof(char)*30);
	char* id=malloc(sizeof(char)*20);
	char* nom;
	char* iata;
	char* icao;
	sprintf(lat,"%f",a->latitude);
	sprintf(lon,"%f",a->longitude);
	nom=strndup(a->nom,128);
	sprintf(id,"%d",a->id);
	iata=strndup(a->IATA,10);
	icao=strndup(a->ICAO,10);
	FILE* dest = fopen("../../communication/plusProche.csv","a");
	for(int i=0;i<strlen(id);i++){
		putc(*(id+i),dest);
	}
	putc(',',dest);
	for(int i=0;i<strlen(nom);i++){
		putc(*(nom+i),dest);
	}
	putc(',',dest);
	for(int i=0;i<strlen(lat);i++){
		putc(*(lat+i),dest);
	}
	putc(',',dest);
	for(int i=0;i<strlen(lon);i++){
		putc(*(lon+i),dest);
	}
	putc(',',dest);
	for(int i=0;i<strlen(iata);i++){
		putc(*(iata+i),dest);
	}
	putc(',',dest);
	for(int i=0;i<strlen(icao);i++){
		putc(*(icao+i),dest);
	}
	putc(',',dest);
	putc(',',dest);
	putc('\n',dest);
	free(lat);
	free(lon);
	free(nom);
	free(id);
	free(iata);
	free(icao);
	fclose(dest);
}

/*int main(){
	aeroport a = initialiseAeroport(0.0,0.0,strndup("Nom",128),0,strndup("IATA",10),strndup("ICAO",10));
	aeroportEdit(a);
	free_aeroport(a);
}*/