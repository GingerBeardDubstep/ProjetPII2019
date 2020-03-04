#include "liste.h"

liste list_creer(){
	liste l = malloc(sizeof(listeChainee));
	l->val=NULL;
	l->suiv=NULL;
	return(l);
}

int list_est_vide(liste L){
	if(L->suiv==NULL){
		return(1);
	}else{
		return(0);
	}
}

aeroport plusProche(liste L,aeroport a,double lat,double lon){
	if(list_est_vide(L)!=1){
		if(a->id==-8){
			return(plusProche(L->suiv,L->val,lat,lon));
		}else if(distance(a,lat,lon)>distance(L->val,lat,lon)){
			return(plusProche(L->suiv,L->val,lat,lon));
		}else{
			return(plusProche(L->suiv,a,lat,lon));
		}
	}else{
		return(a);
	}
}

void listeAeroportEdit(liste L){
	if(list_est_vide(L)!=1){
		aeroportEdit(L->val);
		listeAeroportEdit(L->suiv);
	}
}

int list_taille(liste L){
	if(list_est_vide(L)==1){
		return(0);
	}else{
		return(list_taille(L->suiv)+1);
	}
}

liste list_ajoutTete(liste L, void * a){
	liste l = list_creer();
	l->val=L->val;
	l->suiv = L->suiv;
	L->val=a;
	L->suiv=l;
	return(L);
}

liste list_ajoutFin(liste L, void * a){
	if(list_est_vide(L)==1){
		L->val=a;
		L->suiv=list_creer();
		return(L);
	}else{
		L->suiv=list_ajoutFin(L->suiv,a);
		return(L);
	}
}

liste list_ajoutN(liste L, void * a, int n){
	if(n==0){
		L=list_ajoutTete(L,a);
		return(L);
	}else{
		if(list_est_vide(L)==1){
			printf("Error : out of bounds\n");
			return(L);
		}else{
			L->suiv=list_ajoutN(L->suiv,a,n-1);
			return(L);
		}
	}
}

aeroport listAeroport_rechN(liste L,int id,int n){
	if(list_est_vide(L)==1){
		printf("Error : out of bounds\n");
		return(NULL);
	}else{
		if(((aeroport) L->val)->id==id){
			return((aeroport) L->val);
		}else{
			if(n!=0){
				return(listAeroport_rechN(L->suiv,id,n-1));
			}else{
				printf("L'aéroport d'id \"%d\" n'est pas dans la liste \n",id);
				return(NULL);
			}
		}
	}
}
liste listAeroport_remove(liste L, aeroport a){
	if(listAeroport_rechById(L,a->id)==NULL){
		printf("L'aéroport d'id \"%d\" n'est pas dans la liste \n",a->id);
		return(L);
	}else{
		if(((aeroport) L->val)->id==a->id){
			liste l=list_creer();
			*l=*(L->suiv);
			free(L->suiv);
			free_aeroport(L->val);
			free(L);
			return(l);
		}else{
			L->suiv=listAeroport_remove(L->suiv,a);
			return(L);
		}
	}
}

aeroport listAeroport_rechById(liste L,int id){
	if(list_est_vide(L)==1){
		return(NULL);
	}else{
		if(((aeroport) L->val)->id==id){
			return((aeroport) L->val);
		}else{
			return(listAeroport_rechById(L->suiv,id));
		}
	}
}

aeroport listAeroport_rechByIataIcao(liste L,char* code){
	if(list_est_vide(L)==1){
		return(NULL);
	}else{
		if(strcmp(((aeroport) L->val)->IATA,code)==0||strcmp(((aeroport) L->val)->ICAO,code)==0){
			return((aeroport) L->val);
		}else{
			return(listAeroport_rechByIataIcao(L->suiv,code));
		}
	}
}


liste list_removeN(liste L,int n){ //Eviter d'utiliser cette méthode aprés parsage : fuite mémoire assurée car on ne free pas touts les mallocs causés par strndup().
	if(list_est_vide(L)==1){
		printf("Error : out of bounds\n");
		return(L);
	}else{
		if(n!=0){
			L->suiv=list_removeN(L->suiv,n-1);
			return(L);
		}else{
			liste l=list_creer();
			*l=*(L->suiv);
			free(L->suiv);
			free(L->val); 
			free(L);
			return(l);
		}
	}
}
void listAeroport_affiche(aeroport a){
	printf("L'aéroport %s : id %d, IATA %s, ICAO %s, de coordonnées %f %f \n",a->nom,a->id,a->IATA,a->ICAO,a->latitude,a->longitude);
}
void listAeroport_visualiser(liste L){
	if(list_est_vide(L)!=1){
		listAeroport_affiche((aeroport) L->val);
		listAeroport_visualiser(L->suiv);
	}else{
		printf("\n");
	}
}

liste dans_perimetre(liste L,aeroport a,liste output,int rayon){
	if(output==NULL){
		output=list_creer();
	}
	if(list_est_vide(L)==1){
		return(output);
	}else{
		if(est_dans_perimetre(a,L->val,rayon)==1){
			output=list_ajoutTete(output,initialiseAeroport(((aeroport) L->val)->latitude,((aeroport) L->val)->longitude,strndup(((aeroport) L->val)->nom,128),((aeroport) L->val)->id,strndup(((aeroport) L->val)->IATA,8),strndup(((aeroport) L->val)->ICAO,8)));
		}
		return(dans_perimetre(L->suiv,a,output,rayon));
	}
}

equip listEquip_rechN(liste L,int id,int n){
	if(list_est_vide(L)==1){
		printf("Error : out of bounds\n");
		return(NULL);
	}else{
		if(((equip) L->val)->id==id){
			return((equip) L->val);
		}else{
			if(n!=0){
				return(listEquip_rechN(L->suiv,id,n-1));
			}else{
				printf("L'équipement d'id \"%d\" n'est pas dans la liste \n",id);
				return(NULL);
			}
		}
	}
}

equip listEquip_rech(liste L,int id){
	int cpt = list_taille(L);
	return(listEquip_rechN(L,id,cpt));
}

liste listEquip_remove(liste L, equip e){
	if(listEquip_rech(L,e->id)==NULL){
		printf("L'équipement d'id \"%d\" n'est pas dans la liste \n",e->id);
		return(L);
	}else{
		if(((equip) L->val)->id==e->id){
			liste l=list_creer();
			*l=*(L->suiv);
			free(L->suiv);
			free_equip(L->val);
			free(L);
			return(l);
		}else{
			L->suiv=listEquip_remove(L->suiv,e);
			return(L);
		}
	}
}

void listEquip_affiche(equip e){
	printf("L'équipement d'id %d, airline %s, airportDep %s,airportDest %s, code %s \n",e->id,e->airl,e->airpDep,e->airpDest,e->code);
}

void listEquip_visualiser(liste L){
	if(list_est_vide(L)!=1){
		listEquip_affiche((equip) L->val);
		listEquip_visualiser(L->suiv);
	}else{
		printf("\n");
	}
}

airl listAirl_rechN(liste L,int id,int n){
	if(list_est_vide(L)==1){
		printf("Error : out of bounds\n");
		return(NULL);
	}else{
		if(((airl) L->val)->id==id){
			return((airl) L->val);
		}else{
			if(n!=0){
				return(listAirl_rechN(L->suiv,id,n-1));
			}else{
				printf("L'airline d'id \"%d\" n'est pas dans la liste \n",id);
				return(NULL);
			}
		}
	}
}

airl listAirl_rech(liste L,int id){
	int cpt = list_taille(L);
	return(listAirl_rechN(L,id,cpt));
}

liste listAirl_remove(liste L, airl a){
	if(listAirl_rech(L,a->id)==NULL){
		printf("L'airline d'id \"%d\" n'est pas dans la liste \n",a->id);
		return(L);
	}else{
		if(((airl) L->val)->id==a->id){
			liste l=list_creer();
			*l=*(L->suiv);
			free(L->suiv);
			free_airl(L->val);
			free(L);
			return(l);
		}else{
			L->suiv=listAirl_remove(L->suiv,a);
			return(L);
		}
	}
}

void listAirl_affiche(airl a){
	printf("L'airline %s : id %d, IATA %s, ICAO %s, pays %s\n",a->nom,a->id,a->iata,a->icao,a->pays);
}

void listAirl_visualiser(liste L){
	if(list_est_vide(L)!=1){
		listAirl_affiche((airl) L->val);
		listAirl_visualiser(L->suiv);
	}else{
		printf("\n");
	}
}

flightNum listFlightNum_rechN(liste L,int id,int n){
	if(list_est_vide(L)==1){
		printf("Error : out of bounds\n");
		return(NULL);
	}else{
		if(((flightNum) L->val)->id==id){
			return((flightNum) L->val);
		}else{
			if(n!=0){
				return(listFlightNum_rechN(L->suiv,id,n-1));
			}else{
				printf("Le no de vol \"%d\" n'est pas dans la liste \n",id);
				return(NULL);
			}
		}
	}
}

flightNum listFlightNum_rech(liste L,int id){
	int cpt = list_taille(L);
	return(listFlightNum_rechN(L,id,cpt));
}

liste listFlightNum_remove(liste L, flightNum f){
	if(listFlightNum_rech(L,f->id)==NULL){
		printf("Le no de vol \"%d\" n'est pas dans la liste \n",f->id);
		return(L);
	}else{
		if(((flightNum) L->val)->id==f->id){
			liste l=list_creer();
			*l=*(L->suiv);
			free(L->suiv);
			free_flightNum(L->val);
			free(L);
			return(l);
		}else{
			L->suiv=listFlightNum_remove(L->suiv,f);
			return(L);
		}
	}
}

void listFlightNum_affiche(flightNum f){
	printf("Le vol %s : Id %d, Airline code %s, Arrets  %d\n",f->fnum,f->id,f->airlCode,f->arret);
}

void listFlightNum_visualiser(liste L){
	if(list_est_vide(L)!=1){
		listFlightNum_affiche((flightNum) L->val);
		listFlightNum_visualiser(L->suiv);
	}else{
		printf("\n");
	}
}

local listLocal_rechN(liste L,double lat,double lon,int n){
	if(list_est_vide(L)==1){
		printf("Error : out of bounds\n");
		return(NULL);
	}else{
		if(((local) L->val)->lon==lon&&((local) L->val)->lat==lat){
			return((local) L->val);
		}else{
			if(n!=0){
				return(listLocal_rechN(L->suiv,lat,lon,n-1));
			}else{
				printf("Le point de coordonnées \"%f,%f\" n'est pas dans la liste \n",lat,lon);
				return(NULL);
			}
		}
	}
}

local listLocal_rech(liste L,double lat,double lon){
	int cpt = list_taille(L);
	return(listLocal_rechN(L,lat,lon,cpt));
}

liste listLocal_remove(liste L, local lo){
	if(listLocal_rech(L,lo->lat,lo->lon)==NULL){
		printf("Le point de coordonnées \"%f,%f\" n'est pas dans la liste \n",lo->lat,lo->lon);
		return(L);
	}else{
		if(((local) L->val)->lat==lo->lat&&((local) L->val)->lon==lo->lon){
			liste l=list_creer();
			*l=*(L->suiv);
			free(L->suiv);
			free_local(L->val);
			free(L);
			return(l);
		}else{
			L->suiv=listLocal_remove(L->suiv,lo);
			return(L);
		}
	}
}

void listLocal_affiche(local lo){
	printf("Le point de coordonnées \"%f,%f\" : Ville %s, Altitude %f\n",lo->lat,lo->lon,lo->ville,lo->alt);
}

void listLocal_visualiser(liste L){
	if(list_est_vide(L)!=1){
		listLocal_affiche((local) L->val);
		listLocal_visualiser(L->suiv);
	}else{
		printf("\n");
	}
}

plane listPlane_rechN(liste L,char* code,int n){
	if(list_est_vide(L)==1){
		printf("Error : out of bounds\n");
		return(NULL);
	}else{
		if(((strcmp(((plane) L->val)->iata,code)==0)&&(((plane) L->val)->iata!=NULL))||((strcmp(((plane) L->val)->icao,code)==0)&&((plane) L->val)->icao!=NULL)){
			return((plane) L->val);
		}else{
			if(n>0){
				return(listPlane_rechN(L->suiv,code,n-1));
			}else{
				printf("L'avion de code \"%s\" n'est pas dans la liste \n",code);
				return(NULL);
			}
		}
	}
}

plane listPlane_rech(liste L,char* code){
	int cpt = list_taille(L);
	return(listPlane_rechN(L,code,cpt));
}

liste listPlane_remove(liste L, plane p){
	if(listPlane_rech(L,p->iata)==NULL){
		printf("L'avion \"%s\" n'est pas dans la liste \n",p->nom);
		return(L);
	}else{
		if(((strcmp(((plane) L->val)->iata,p->iata)==0)&&(((plane) L->val)->iata!=NULL))||((strcmp(((plane) L->val)->icao,p->icao)==0)&&((plane) L->val)->icao!=NULL)){
			liste l=list_creer();
			*l=*(L->suiv);
			free(L->suiv);
			free_plane(L->val);
			free(L);
			return(l);
		}else{
			L->suiv=listPlane_remove(L->suiv,p);
			return(L);
		}
	}
}

void listPlane_affiche(plane p){
	printf("L'avion \"%s\" : IATA %s, ICAO %s, Nombre de sièges %d, Vitesse %f, Autonomie %d, Carburant %d\n",p->nom,p->iata,p->icao,p->sieges,p->vitesse,p->autonomie,p->carburant);
}

void listPlane_visualiser(liste L){
	if(list_est_vide(L)!=1){
		listPlane_affiche((plane) L->val);
		listPlane_visualiser(L->suiv);
	}else{
		printf("\n");
	}
}

route listRoute_rechN(liste L,int id,int n){
	if(list_est_vide(L)==1){
		printf("Error : out of bounds\n");
		return(NULL);
	}else{
		if(id==((route) L->val)->id){
			return((route) L->val);
		}else{
			if(n>0){
				return(listRoute_rechN(L->suiv,id,n-1));
			}else{
				printf("La route d'id \"%d\" n'est pas dans la liste \n",id);
				return(NULL);
			}
		}
	}
}

route listRoute_rech(liste L,int id){
	int cpt = list_taille(L);
	return(listRoute_rechN(L,id,cpt));
}

liste listRoute_remove(liste L, route r){
	if(listRoute_rech(L,r->id)==NULL){
		printf("La route d'id \"%d\" n'est pas dans la liste \n",r->id);
		return(L);
	}else{
		if(r->id==((route) L->val)->id){
			liste l=list_creer();
			*l=*(L->suiv);
			free(L->suiv);
			free_route(L->val);
			free(L);
			return(l);
		}else{
			L->suiv=listRoute_remove(L->suiv,r);
			return(L);
		}
	}
}

void listRoute_affiche(route r){
	printf("La route d'id \"%d\" : Airline %s, AirlineID %d, AirportDep %s, AirportDepID %d, AirportDest %s, AirportDestID %d, CodeShare %s, Arrets %d\n",r->id,r->airl,r->airlId,r->airpDep,r->airpDepId,r->airpDest,r->airpDestId,r->codeShare,r->stops);
}

void listRoute_visualiser(liste L){
	if(list_est_vide(L)!=1){
		listRoute_affiche((route) L->val);
		listRoute_visualiser(L->suiv);
	}else{
		printf("\n");
	}
}

stops listStops_rechN(liste L,int id,int n){
	if(list_est_vide(L)==1){
		printf("Error : out of bounds\n");
		return(NULL);
	}else{
		if(id==((stops) L->val)->id){
			return((stops) L->val);
		}else{
			if(n>0){
				return(listStops_rechN(L->suiv,id,n-1));
			}else{
				printf("L'arret' d'id \"%d\" n'est pas dans la liste \n",id);
				return(NULL);
			}
		}
	}
}

stops listStops_rech(liste L,int id){
	int cpt = list_taille(L);
	return(listStops_rechN(L,id,cpt));
}

liste listStops_remove(liste L, stops s){
	if(listStops_rech(L,s->id)==NULL){
		printf("L'arret d'id \"%d\" n'est pas dans la liste \n",s->id);
		return(L);
	}else{
		if(s->id==((stops) L->val)->id){
			liste l=list_creer();
			*l=*(L->suiv);
			free(L->suiv);
			free_stops(L->val);
			free(L);
			return(l);
		}else{
			L->suiv=listStops_remove(L->suiv,s);
			return(L);
		}
	}
}

void listStops_affiche(stops s){
	printf("L'arret d'id \"%d\" : ID du vol %d, AirportDep %s, AirportDest %s, Numéro de vol  %s, Ordre %d\n",s->id,s->flightId,s->airpDep,s->airpDest,s->fnum,s->ordre);
}

void listStops_visualiser(liste L){
	if(list_est_vide(L)!=1){
		listStops_affiche((stops) L->val);
		listStops_visualiser(L->suiv);
	}else{
		printf("\n");
	}
}

void free_listAeroport(liste L){
	if(list_est_vide(L)==1){
		free(L);
	}else{
		free_listAeroport(L->suiv);
		free_aeroport(L->val);
		free(L);
	}
}

void free_listEquip(liste L){
	if(list_est_vide(L)==1){
		free(L);
	}else{
		free_listEquip(L->suiv);
		free_equip(L->val);
		free(L);
	}
}
void free_listAirl(liste L){
	if(list_est_vide(L)==1){
		free(L);
	}else{
		free_listAirl(L->suiv);
		free_airl(L->val);
		free(L);
	}
}
void free_listAirlTest(liste L){
	if(list_est_vide(L)==1){
		free(L);
	}else{
		free_listAirlTest(L->suiv);
		free(L->val);
		free(L);
	}
}
void free_listFlightNum(liste L){
	if(list_est_vide(L)==1){
		free(L);
	}else{
		free_listFlightNum(L->suiv);
		free_flightNum(L->val);
		free(L);
	}
}
void free_listLocal(liste L){
	if(list_est_vide(L)==1){
		free(L);
	}else{
		free_listLocal(L->suiv);
		free_local(L->val);
		free(L);
	}
}
void free_listPlane(liste L){
	if(list_est_vide(L)==1){
		free(L);
	}else{
		free_listPlane(L->suiv);
		free_plane(L->val);
		free(L);
	}
}
void free_listStops(liste L){
	if(list_est_vide(L)==1){
		free(L);
	}else{
		free_listStops(L->suiv);
		free_stops(L->val);
		free(L);
	}
}
void free_listRoute(liste L){
	if(list_est_vide(L)==1){
		free(L);
	}else{
		free_listRoute(L->suiv);
		free_route(L->val);
		free(L);
	}
}



/*int main(){
	aeroport a1 = initialiseAeroport(0.0,0.0,strndup("Nom",128),0,strndup("IATA",10),strndup("ICAO",10));
	aeroport a2 = initialiseAeroport(0.0,0.0,strndup("Nom",128),1,strndup("IATA",10),strndup("ICAO",10));
	aeroport a3 = initialiseAeroport(0.0,0.0,strndup("Nom",128),2,strndup("IATA",10),strndup("ICAO",10));
	aeroport a4 = initialiseAeroport(0.0,0.0,strndup("Nom",128),3,strndup("IATA",10),strndup("ICAO",10));
	aeroport a5 = initialiseAeroport(0.0,0.0,strndup("Nom",128),4,strndup("THIS",10),strndup("ICAO",10));
	liste l = list_creer();
	l=list_ajoutTete(l,a1);
	l=list_ajoutTete(l,a2);
	l=list_ajoutFin(l,a4);
	l=list_ajoutFin(l,a5);
	l=list_ajoutN(l,a3,2);
	//l=listAirl_remove(l,a1);
	//listAeroport_visualiser(l);
	//liste out = malloc(sizeof(liste));
	//out=dans_perimetre(l,a1,out,220);
	listAeroport_affiche(listAeroport_rechById(l,0));
	printf("\n");
	listAeroport_affiche(listAeroport_rechByIataIcao(l,"THIS"));
	//listAirl_visualiser(l);
	//free_listAirl(l);
	listeAeroportEdit(l);
	free_listAeroport(l);
}*/