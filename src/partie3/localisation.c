#include "localisation.h"

local initialiseLocal(double lat,double lon, double alt, char* ville,char* pays){
	local lo = malloc(sizeof(*lo));
	lo->lat=lat;
	lo->lon=lon;
	lo->alt=alt;
	lo->pays=pays;
	//lo->ville=malloc(sizeof(char)*128);
	lo->ville=ville;
	return(lo);
}

void free_local(local lo){
	free(lo->ville);
	free(lo->pays);
	free(lo);
}

char* getLocalVille(local lo){
	return(lo->ville);
}

char* getLocalPays(local lo){
	return(lo->pays);
}

double getLocalLatitude(local lo){
	return(lo->lat);
}

double getLocalLongitude(local lo){
	return(lo->lon);
}

double getLocalAltitude(local lo){
	return(lo->alt);
}

/*int main(){
	local lo = initialiseLocal(0.0,0.0,0.0,"Madrid");
	free_local(lo);
}*/