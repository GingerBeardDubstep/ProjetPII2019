#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct airline{
	int id;
	char* nom;
	char* iata;
	char* icao;
	char* pays;
}airline;

typedef struct airline* airl;

airl initialiseAirl(int id,char* nom,char* iata,char* icao,char* pays);

void free_airl(airl a);

char* getAirlICAO(airl a);

char* getAirlIATA(airl a);

char* getAirlNom(airl a);

int getAirlId(airl a);

char* getAirlPays(airl a);