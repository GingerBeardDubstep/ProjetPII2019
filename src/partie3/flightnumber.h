#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct flightnumber{
	int id;
	int arret;
	char* airlCode;
	char* fnum;
}flightnumber;

typedef struct flightnumber* flightNum;

flightNum initialiseFlightNum(int id, char* code, char* fnum, int arret);

void free_flightNum(flightNum f);

int getStops(flightNum f);

char* getFlightNum(flightNum f);

char* getFlightNumCode(flightNum f);

int getFlightNumId(flightNum f);