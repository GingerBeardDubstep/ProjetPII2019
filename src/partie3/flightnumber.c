#include "flightnumber.h"

flightNum initialiseFlightNum(int id, char* code, char* fnum, int arret){
	flightNum f = malloc(sizeof(*f));
	f->arret=arret;
	f->id=id;
	f->airlCode=code;
	f->fnum=fnum;
	return(f);
}

void free_flightNum(flightNum f){
	free(f->airlCode);
	free(f->fnum);
	free(f);
}

int getStops(flightNum f){
	return(f->arret);
}

char* getFlightNum(flightNum f){
	return(f->fnum);
}

char* getFlightNumCode(flightNum f){
	return(f->airlCode);
}

int getFlightNumId(flightNum f){
	return(f->id);
}

/*int main(){
	flightNum f = initialiseFlightNum(0,"code","fnum",5);
	free(f);
}*/