#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct airport{
	double latitude;
	double longitude;
	char* nom;
	int id;
	char* IATA;
	char* ICAO;
}airport;

typedef struct airport* aeroport;

double distance(aeroport a,double lat,double lon);

void aeroportEdit(aeroport a);

aeroport initialiseAeroport(double lat,double lon, char* nom, int id, char* iata, char* icao);

void free_aeroport(aeroport a);

int est_dans_perimetre(aeroport a1,aeroport a2, int rayon);

char* getICAO(aeroport a);

char* getIATA(aeroport a);

char* getNom(aeroport a);

int getId(aeroport a);



int getByIataIcao(char* code);