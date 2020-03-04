#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct equipement{
	char* airl;
	char* airpDep;
	char* airpDest;
	char* code;
	int routeId;
	int id;
}equipement;

typedef struct equipement* equip;

equip initialiseEquip(char* airl,char* airpD1,char* airpD2,char* code,int rId, int id);

void free_equip(equip e);

char* getAirline(equip e);

char* getAirpDep(equip e);

char* getAirpDest(equip e);

int getEquipId(equip e);

int getEquipRouteId(equip e);

char* getCode(equip e);