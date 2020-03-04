#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "aeroport.h"
#include "plane.h"


double conversionRad(double entree){
	return (entree * M_PI)/180;
}

//Fonction distance qui renvoie la distance en kilomètres

double distance(aeroport air1, aeroport air2){
	double lat1 = conversionRad(air1->latitude);
	double lat2 = conversionRad(air2->latitude);
	double long1 = air1->longitude;
	double long2 = air2->longitude;
	double dl = conversionRad(long2 - long1);

	int R = 6378137;

	double s0 = sin(lat1)*sin(lat2)+cos(lat1)*cos(lat2)*cos(dl);

	return (R*acos(s0))/1000;

}

aeroport initialiseAeroport(double lat,double lon, char* nom, int id, char* iata, char* icao){
	aeroport a=NULL;
	a = (aeroport) malloc(sizeof(aeroport));
	if(a==NULL){
		exit(1);
	}
	a->latitude=lat;
	a->longitude=lon;
	a->nom=NULL;
	a->IATA=NULL;
	a->nom=NULL;
	a->nom=malloc(sizeof(char)*128);
	a->IATA=malloc(sizeof(char)*5);
	a->ICAO=malloc(sizeof(char)*5);
	if(a->IATA==NULL){
		exit(1);
	}
	if(a->ICAO==NULL){
		exit(1);
	}
	if(a->nom==NULL){
		exit(1);
	}
	a->nom=nom;
	a->id=id;
	a->IATA=iata;
	a->ICAO=icao;
	return(a);
}

void free_aeroport(aeroport a){
	free(a->nom);
	free(a->ICAO);
	free(a->IATA);
	free(a);
}

double consommation(aeroport dep, aeroport dest,plane app ){
	int co2 = 285;
	co2 /= app->sieges;
	co2/=distance(dep, dest);
	return co2;
}

int main(int argc, char const *argv[])
{
	aeroport a1 = initialiseAeroport(-6.081689834590001, 145.391998291, "Goroka Airport",1, "GKA", "AYGA");

	aeroport a2 = initialiseAeroport(-5.20707988739, 145.789001465,  "Madang Airport", 2, "MAG", "AYMD" );


	printf("%f\n", distance(a1,a2) );
	printf("%f\n", distance(a1,a1) );
	free(a1);
	free(a2);
	return 0;
}
