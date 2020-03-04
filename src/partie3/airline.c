#include "airline.h"

airl initialiseAirl(int id,char* nom,char* iata,char* icao,char* pays){
		airl a =(airl) malloc(sizeof(airline));
		//a->nom=(char*) malloc(sizeof(char)*128);
		//a->iata=(char*) malloc(sizeof(char)*4);
		//a->icao=(char*) malloc(sizeof(char)*4);
		//a->pays=(char*) malloc(sizeof(char)*60);
		a->nom=nom;
		a->id=id;
		a->iata=iata;
		a->icao=icao;
		a->pays=pays;
		return(a);
}

void free_airl(airl a){
	free(a->nom);
	free(a->icao);
	free(a->iata);
	free(a->pays);
	free(a);
}

char* getAirlICAO(airl a){
	return(a->icao);
}

char* getAirlIATA(airl a){
	return(a->iata);
}

char* getAirlNom(airl a){
	return(a->nom);
}

int getAirlId(airl a){
	return(a->id);
}

char* getAirlPays(airl a){
	return(a->pays);
}

/*int main(){
	//airl a = (airl) malloc(sizeof(airline));
	airl a=initialiseAirl(1,"Test","IATA","ICA","FRANCE");
	free_airl(a);
}*/