#include "aeroport.h"
#include "equipement.h"
#include "airline.h"
#include "flightnumber.h"
#include "localisation.h"
#include "plane.h"
#include "route.h"
#include "stops.h"

typedef struct listeChainee{
	struct listeChainee* suiv; 
	void * val; //type générique
}listeChainee;

typedef listeChainee* liste;

aeroport plusProche(liste L,aeroport a,double lat,double lon);

liste list_creer();
int list_est_vide(liste L);
int list_taille(liste L);
liste list_ajoutTete(liste L, void * a);
liste list_ajoutFin(liste L, void * a);
liste list_ajoutN(liste L, void * a, int n);
liste list_removeN(liste L,int n);
void free_listAeroport(liste L);
void free_listEquip(liste L);
void free_listAirl(liste L);
void free_listFlightNum(liste L);
void free_listLocal(liste L);
void free_listPlane(liste L);
void free_listStops(liste L);
void free_listRoute(liste L);


aeroport listAeroport_rechN(liste L,int id,int n);
void listeAeroportEdit(liste L);
aeroport listAeroport_rechById(liste L,int id);
aeroport listAeroport_rechByIataIcao(liste L,char* code);
liste listAeroport_remove(liste L, aeroport a);
void listAeroport_affiche(aeroport a);
void listAeroport_visualiser(liste L);
liste dans_perimetre(liste L,aeroport a,liste output, int rayon);

equip listEquip_rechN(liste L,int id,int n);
equip listEquip_rech(liste L,int id);
liste listEquip_remove(liste L, equip e);
void listEquip_affiche(equip e);
void listEquip_visualiser(liste L);

airl listAirl_rechN(liste L,int id,int n);
airl listAirl_rech(liste L,int id);
liste listAirl_remove(liste L, airl a);
void listAirl_affiche(airl a);
void listAirl_visualiser(liste L);

flightNum listFlightNum_rechN(liste L,int id,int n);
flightNum listFlightNum_rech(liste L,int id);
liste listFlightNum_remove(liste L, flightNum f);
void listFlightNum_affiche(flightNum f);
void listFlightNum_visualiser(liste L);

local listLocal_rechN(liste L,double lat,double lon,int n);
local listLocal_rech(liste L,double lat,double lon);
liste listLocal_remove(liste L, local lo);
void listLocal_affiche(local lo);
void listLocal_visualiser(liste L);

plane listPlane_rechN(liste L,char* code,int n);
plane listPlane_rech(liste L,char* code);
liste listPlane_remove(liste L, plane p);
void listPlane_affiche(plane p);
void listPlane_visualiser(liste L);

route listRoute_rechN(liste L,int id,int n);
route listRoute_rech(liste L,int id);
liste listRoute_remove(liste L, route r);
void listRoute_affiche(route r);
void listRoute_visualiser(liste L);

stops listStops_rechN(liste L,int id,int n);
stops listStops_rech(liste L,int id);
liste listStops_remove(liste L, stops s);
void listStops_affiche(stops s);
void listStops_visualiser(liste L);