#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct localisation{
	double lat;
	double lon;
	double alt;
	char* ville;
	char* pays;
}localisation;

typedef struct localisation* local;

local initialiseLocal(double lat,double lon, double alt, char* ville,char* pays);

void free_local(local lo);

char* getLocalVille(local lo);

char* getLocalPays(local lo);

double getLocalLatitude(local lo);

double getLocalLongitude(local lo);

double getLocalAltitude(local lo);