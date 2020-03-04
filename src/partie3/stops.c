#include "stops.h"

stops initialiseStops(int id,int fId,char* aD1,char* aD2,char* fnum, int ordre){
	stops s = malloc(sizeof(*s));
	s->id=id;
	s->flightId=fId;
	s->ordre=ordre;
	s->airpDep=aD1;
	s->airpDest=aD2;
	s->fnum=fnum;
	return(s);
}

void free_stops(stops s){
	free(s->airpDep);
	free(s->airpDest);
	free(s->fnum);
	free(s);
}

int getStopsId(stops s){
	return(s->id);
}

int getStopsFlightId(stops s){
	return(s->flightId);
}

char* getStopsairpDep(stops s){
	return(s->airpDep);
}

char* getStopsairpDest(stops s){
	return(s->airpDest);
}

char* getStopsFlightNumber(stops s){
	return(s->fnum);
}

int getStopsOrdre(stops s){
	return(s->ordre);
}

/*int main(){
	//stops s1= malloc(sizeof(*s1));
	stops s1 = initialiseStops(0,0,"KJT","ADJ","FRT",1);
	printf("Le stop d'id %d, de fId %d\n",getStopsId(s1),getStopsFlightId(s1));
	free_stops(s1);
}*/