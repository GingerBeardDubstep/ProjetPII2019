#include "plane.h"

plane initialisePlane(char* nom, char* iata, char* icao, int sieges,double vitesse,int autonomie,int carburant){
	plane p = malloc(sizeof(*p));
	p->sieges=sieges;
	p->vitesse=vitesse;
	p->autonomie=autonomie;
	p->carburant=carburant;
	p->nom=nom;
	p->iata=iata;
	p->icao=icao;
	return(p);
}

void free_plane(plane p){
	free(p->nom);
	free(p->iata);
	free(p->icao);
	free(p);
}

char* getPlaneNom(plane p){
	return(p->nom);
}

char* getPlaneIATA(plane p){
	return(p->iata);
}

char* getPlaneICAO(plane p){
	return(p->icao);
}

int getPlaneNombreSieges(plane p){
	return(p->sieges);
}

double getPlaneVitesse(plane p){
	return(p->vitesse);
}

int getPlaneAutonomie(plane p){
	return(p->autonomie);
}

int getPlaneCarburant(plane p){
	return(p->carburant);
}

/*int main(){
	plane p = initialisePlane("Nom","IATA","ICAO",5,20.0,58,475);
	free_plane(p);
}*/