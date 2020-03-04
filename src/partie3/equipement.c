#include "equipement.h"

equip initialiseEquip(char* airl,char* airpD1,char* airpD2,char* code,int rId, int id){
	equip e = malloc(sizeof(*e));
	e->airl=airl;
	e->airpDep=airpD1;
	e->airpDest=airpD2;
	e->code=code;
	e->routeId=rId;
	e->id=id;
	return(e);
}

void free_equip(equip e){
	free(e->airl);
	free(e->airpDep);
	free(e->airpDest);
	free(e->code);
	free(e);
}

char* getAirline(equip e){
	return(e->airl);
}

char* getAirpDep(equip e){
	return(e->airpDep);
}

char* getAirpDest(equip e){
	return(e->airpDest);
}

int getEquipId(equip e){
	return(e->id);
}

int getEquipRouteId(equip e){
	return(e->routeId);
}

char* getCode(equip e){
	return(e->code);
}

/*int main(){
	equip e = initialiseEquip("airl","d1","d2","code",0,0);
	free(e);
}*/