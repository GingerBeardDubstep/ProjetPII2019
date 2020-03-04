#include "liste.h"

typedef struct table{
	liste* tableau;
	int taille;
}table;

typedef struct table* tableHachage;



int hachage(char *s, int mod);
void tableHachage_ajout(void* a,tableHachage T,char* code);
tableHachage tableHachage_creer(int tailleTableau);

aeroport tHAeroport_getById(tableHachage T,int id);
aeroport tHAeroport_getByIataIcao(tableHachage T,char* code);
void tHAeroport_supprime(aeroport a,tableHachage T);
void tHAeroport_visualiser(tableHachage T);
liste perimetre(tableHachage T,double lat,double lon,int rayon);
tableHachage chargeTHAeroport(char* chemin);
aeroport plusProcheTH(tableHachage T,double lat,double lon);

stops tHStops_get(stops s,tableHachage T);
void tHStops_supprime(stops s,tableHachage T);
void tHStops_visualiser(tableHachage T);
tableHachage chargeTHStops(char* chemin);

equip tHEquip_get(equip e,tableHachage T);
void tHEquip_supprime(equip e,tableHachage T);
void tHEquip_visualiser(tableHachage T);
tableHachage chargeTHEquip(char* chemin);

airl tHAirl_get(airl a,tableHachage T);
void tHAirl_supprime(airl a,tableHachage T);
void tHAirl_visualiser(tableHachage T);
tableHachage chargeTHAirl(char* chemin);

local tHLocal_get(local lo,tableHachage T);
void tHLocal_supprime(local lo,tableHachage T);
void tHLocal_visualiser(tableHachage T);
tableHachage chargeTHLocal(char* chemin);

plane tHPlane_get(plane p,tableHachage T);
void tHPlane_supprime(plane p,tableHachage T);
void tHPlane_visualiser(tableHachage T);
tableHachage chargeTHPlane(char* chemin);

route tHRoute_get(route r,tableHachage T);
void tHRoute_supprime(route r,tableHachage T);
void tHRoute_visualiser(tableHachage T);
tableHachage chargeTHRoute(char* chemin);

flightNum tHFlightNum_get(flightNum f,tableHachage T);
void tHFlightNum_supprime(flightNum f,tableHachage T);
void tHFlightNum_visualiser(tableHachage T);
tableHachage chargeTHFlightNum(char* chemin);

void free_tHAeroport(tableHachage T);
void free_tHAirl(tableHachage T);
void free_tHStops(tableHachage T);
void free_tHRoute(tableHachage T);
void free_tHFlightNum(tableHachage T);
void free_tHEquip(tableHachage T);
void free_tHPlane(tableHachage T);
void free_tHLocal(tableHachage T);