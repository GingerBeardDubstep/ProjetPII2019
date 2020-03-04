#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct Route{
	char* airl;
	int airlId;
	char* airpDep;
	int airpDepId;
	char* airpDest;
	int airpDestId;
	char* codeShare;
	int stops;
	int id;
}Route;

typedef struct Route* route;

route initialiseRoute(char* airl,int airlId,char* airpDep,int airDepId,char* airpDest,int airDestId,char* codeShare,int stops,int id);

void free_route(route r);

char* getRouteAirl(route r);

int getRouteAirlId(route r);

char* getRouteAipDep(route r);

int getRouteAipDepId(route r);

char* getRouteAipDest(route r);

int getRouteAipDestId(route r);

char* getRouteCodeShare(route r);

int getRouteStops(route r);

int getRouteId(route r);