#include "route.h"

route initialiseRoute(char* airl,int airlId,char* airpDep,int airDepId,char* airpDest,int airDestId,char* codeShare,int stops,int id){
	route r = malloc(sizeof(*r));
	r->id=id;
	r->stops=stops;
	r->airl=airl;
	r->airpDep=airpDep;
	r->airpDest=airpDest;
	r->codeShare=codeShare;
	r->airlId=airlId;
	r->airpDepId=airDepId;
	r->airpDestId=airDestId;
	return(r);
}

void free_route(route r){
	free(r->airl);
	free(r->airpDep);
	free(r->airpDest);
	free(r->codeShare);
	free(r);
}

char* getRouteAirl(route r){
	return(r->airl);
}

int getRouteAirlId(route r){
	return(r->airlId);
	
}

char* getRouteAipDep(route r){
	return(r->airpDep);
}

int getRouteAipDepId(route r){
	return(r->airpDepId);
}

char* getRouteAipDest(route r){
	return(r->airpDest);
}

int getRouteAipDestId(route r){
	return(r->airpDestId);
}

char* getRouteCodeShare(route r){
	return(r->codeShare);
}

int getRouteStops(route r){
	return(r->stops);
}

int getRouteId(route r){
	return(r->id);
}

/*int main(){
	route r = initialiseRoute("air",0,"Dep",0,"Arr",0,"code",0,0);
	free(r);
}*/