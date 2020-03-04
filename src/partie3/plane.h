#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct Plane{
	char* nom;
	char* iata;
	char* icao;
	int sieges;
	double vitesse;
	int autonomie;
	int carburant;
}Plane;

typedef struct Plane* plane;

plane initialisePlane(char* nom, char* iata, char* icao, int sieges,double vitesse,int autonomie,int carburant);

void free_plane(plane p);

char* getPlaneNom(plane p);

char* getPlaneIATA(plane p);

char* getPlaneICAO(plane p);

int getPlaneNombreSieges(plane p);

double getPlaneVitesse(plane p);

int getPlaneAutonomie(plane p);

int getPlaneCarburant(plane p);