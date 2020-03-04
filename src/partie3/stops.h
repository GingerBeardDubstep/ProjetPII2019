#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct Stops{
	int id;
	int flightId;
	char* airpDep;
	char* airpDest;
	char* fnum;
	int ordre;
}Stops;

typedef struct Stops* stops;

stops initialiseStops(int id,int fId,char* aD1,char* aD2,char* fnum, int ordre);

void free_stops(stops s);

int getStopsId(stops s);

int getStopsFlightId(stops s);

char* getStopsairpDep(stops s);

char* getStopsairpDest(stops s);

char* getStopsFlightNumber(stops s);

int getStopsOrdre(stops s);