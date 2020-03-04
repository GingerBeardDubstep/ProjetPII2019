#include "tableHachage.h"

//Fonctions génériques

aeroport plusProcheTH(tableHachage T,double lat,double lon){
	aeroport a = initialiseAeroport(0.0,0.0,strndup("n",8),-8,strndup("iata",8),strndup("icao",8));

	for(int i=0;i<T->taille;i++){
		a = plusProche(T->tableau[i],a,lat,lon);
	}

	aeroport a1 = initialiseAeroport(a->latitude,a->longitude,strndup(a->nom,128),a->id,strndup(a->IATA,8),strndup(a->ICAO,8));
	return(a1);
}

int hachage(char *s, int mod){
    int i = 0, cpt = 0;
    while (s[i] != '\0'){
        cpt += (int)s[i];
        i++;
    }
    cpt += strlen(s);
    cpt = cpt % mod;
    return cpt;
}

tableHachage tableHachage_creer(int tailleTableau){
	tableHachage T = malloc(sizeof(*T));
	T->tableau=malloc(sizeof(listeChainee)*tailleTableau);
	for(int i=0;i<tailleTableau;i++){
		T->tableau[i]=list_creer();
	}
	T->taille=tailleTableau;
	return(T);
}



aeroport tHAeroport_getByIataIcao(tableHachage T,char* code){
	for(int i=0;i<T->taille;i++){
		if(listAeroport_rechByIataIcao(T->tableau[i],code)!=NULL){
			return(listAeroport_rechByIataIcao(T->tableau[i],code));
		}
	}
	return(NULL);
}

void tableHachage_ajout(void* a,tableHachage T,char* code){
	int hash = hachage(code,T->taille);
	T->tableau[hash]=list_ajoutTete(T->tableau[hash],a);
}

void tHAeroport_supprime(aeroport a,tableHachage T){
	int hash = hachage(a->nom,T->taille);
	aeroport a1=malloc(sizeof(aeroport));
	a1=listAeroport_rechById(T->tableau[hash],a->id);
	if(a1!=NULL){
		T->tableau[hash]=listAeroport_remove(T->tableau[hash],a1);
	}
}

aeroport tHAeroport_getById(tableHachage T,int id){
	for(int i=0;i<T->taille;i++){
		if(listAeroport_rechById(T->tableau[i],id)!=NULL){
			return(listAeroport_rechById(T->tableau[i],id));
		}
	}
	return(NULL);
}

void tHAeroport_visualiser(tableHachage T){
	for(int i=0;i<T->taille;i++){
		printf("Liste %d\n",i);
		listAeroport_visualiser(T->tableau[i]);
	}
}

liste perimetre(tableHachage T,double lat,double lon,int rayon){
	aeroport a=initialiseAeroport(lat,lon,strndup("",20),0,strndup("",20),strndup("",20));
	liste output = list_creer();
	for(int i=0;i<T->taille;i++){
		output=dans_perimetre(T->tableau[i],a,output,rayon);
	}
	free_aeroport(a);
	return(output);
}

void free_tHAeroport(tableHachage T){
	for(int i=0;i<T->taille;i++){
		free_listAeroport(T->tableau[i]);
	}
	free(T->tableau);
	free(T);
}

void free_tHAirl(tableHachage T){
	for(int i=0;i<T->taille;i++){
		free_listAirl(T->tableau[i]);
	}
	free(T->tableau);
	free(T);
}
void free_tHStops(tableHachage T){
	for(int i=0;i<T->taille;i++){
		free_listStops(T->tableau[i]);
	}
	free(T->tableau);
	free(T);
}
void free_tHRoute(tableHachage T){
	for(int i=0;i<T->taille;i++){
		free_listRoute(T->tableau[i]);
	}
	free(T->tableau);
	free(T);
}
void free_tHFlightNum(tableHachage T){
	for(int i=0;i<T->taille;i++){
		free_listFlightNum(T->tableau[i]);
	}
	free(T->tableau);
	free(T);
}
void free_tHEquip(tableHachage T){
	for(int i=0;i<T->taille;i++){
		free_listEquip(T->tableau[i]);
	}
	free(T->tableau);
	free(T);
}
void free_tHPlane(tableHachage T){
	for(int i=0;i<T->taille;i++){
		free_listPlane(T->tableau[i]);
	}
	free(T->tableau);
	free(T);
}
void free_tHLocal(tableHachage T){
	for(int i=0;i<T->taille;i++){
		free_listLocal(T->tableau[i]);
	}
	free(T->tableau);
	free(T);
}


//Fonctions pour les tables de Hachage de Airports

tableHachage chargeTHAeroport(char* chemin){
	FILE* src = fopen(chemin,"r");
	if(src!=NULL){
		tableHachage T=tableHachage_creer(10);
		int cpt1=0;
		int cpt2=0;
		do{
			
			char* lat=malloc(sizeof(char)*30);
			char* lon=malloc(sizeof(char)*30);
			char* nom=malloc(sizeof(char)*128);
			char* id=malloc(sizeof(char)*20);
			char* iata=malloc(sizeof(char)*10);
			char* icao=malloc(sizeof(char)*10);
			
			cpt1=fgetc(src);
			if(cpt1==EOF){
				free(lat);
				free(lon);
				free(nom);
				free(id);
				free(iata);
				free(icao);
				break;
			}
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(id+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			id[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(nom+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			nom[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(lat+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);

			}
			lat[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(lon+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			lon[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(iata+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			iata[cpt2]='\0';	
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(icao+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);		
			}
			icao[cpt2]='\0';
			while(cpt1!='\n'&&cpt1!=EOF){
				if(cpt1==EOF){
					break;
				}
				cpt1=fgetc(src);
			}
			cpt2=0;
			if(cpt1==EOF){
				free(id);
				free(iata);
				free(icao);
				free(nom);
				free(lat);
				free(lon);
				break;
			}
			tableHachage_ajout(initialiseAeroport(atof(lat),atof(lon),strndup(nom,128),atoi(id),strndup(iata,10),strndup(icao,10)),T,nom);
			free(id);
			free(iata);
			free(icao);
			free(nom);
			free(lat);
			free(lon);
		}while(cpt1!= EOF);
		fclose(src);
		return(T);
	}else{
		printf("Nom de source incorrect \n");
		return(NULL);
	}
}

//Fonctions pour les tables de Hachage de Stops

stops tHStops_get(stops s,tableHachage T){
	int hash = hachage(s->fnum,T->taille);
	return(listStops_rech(T->tableau[hash],s->id));
}

void tHStops_supprime(stops s,tableHachage T){
	int hash = hachage(s->fnum,T->taille);
	stops s1=malloc(sizeof(stops));
	s1=listStops_rech(T->tableau[hash],s->id);
	if(s1!=NULL){
		T->tableau[hash]=listStops_remove(T->tableau[hash],s);
	}
}

void tHStops_visualiser(tableHachage T){
	for(int i=0;i<T->taille;i++){
		printf("Liste %d\n",i);
		listStops_visualiser(T->tableau[i]);
	}
}

tableHachage chargeTHStops(char* chemin){
	FILE* src = fopen(chemin,"r");
	if(src!=NULL){
		tableHachage T=tableHachage_creer(10);
		int cpt1=0;
		int cpt2=0;
		
		do{
			char* id=malloc(sizeof(char)*8);
			char* fId=malloc(sizeof(char)*8);
			char* aD1=malloc(sizeof(char)*8);
			char* aD2=malloc(sizeof(char)*8);
			char* fnum=malloc(sizeof(char)*8);
			char* ordre=malloc(sizeof(char)*8);
			cpt1=fgetc(src);
			if(cpt1==EOF){
					break;
			}
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(id+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			id[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				*(fId+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);

			}
			fId[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(aD1+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			aD1[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(aD2+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			aD2[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(fnum+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			fnum[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!='\n'&&cpt1!=EOF){
				*(ordre+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			ordre[cpt2]='\0';
			cpt2=0;
			tableHachage_ajout(initialiseStops(atoi(id),atoi(fId),strndup(aD1,8),strndup(aD2,8),strndup(fnum,8),atoi(ordre)),T,fnum);
			free(id);
			free(fId);
			free(aD1);
			free(aD2);
			free(fnum);
			free(ordre);
		}while(cpt1!= EOF);
		fclose(src);
		return(T);
	}else{
		printf("Nom de source incorrect \n");
		return(NULL);
	}
}

//Fonctions pour les tables de Hachage de Equipements

equip tHEquip_get(equip e,tableHachage T){
	char* tot=malloc(sizeof(char)*12);
	int cpt=0;
	for(int i=0;i<strlen(e->airl);i++){
		*(tot+cpt)=*((e->airl)+i);
		cpt++;
	}
	for(int i=0;i<strlen(e->airl);i++){
		*(tot+cpt)=*((e->airpDep)+i);
		cpt++;
	}
	for(int i=0;i<strlen(e->airl);i++){
		*(tot+cpt)=*((e->airpDest)+i);
		cpt++;
	}
	int hash = hachage(tot,T->taille);
	return(listEquip_rech(T->tableau[hash],e->id));
}

void tHEquip_supprime(equip e,tableHachage T){
	char* tot=malloc(sizeof(char)*12);
	int cpt=0;
	for(int i=0;i<strlen(e->airl);i++){
		*(tot+cpt)=*((e->airl)+i);
		cpt++;
	}
	for(int i=0;i<strlen(e->airpDep);i++){
		*(tot+cpt)=*((e->airpDep)+i);
		cpt++;
	}
	for(int i=0;i<strlen(e->airpDest);i++){
		*(tot+cpt)=*((e->airpDest)+i);
		cpt++;
	}
	int hash = hachage(tot,T->taille);
	equip e1=malloc(sizeof(equip));
	e1=listEquip_rech(T->tableau[hash],e->id);
	if(e1!=NULL){
		T->tableau[hash]=listEquip_remove(T->tableau[hash],e);
	}
}

void tHEquip_visualiser(tableHachage T){
	for(int i=0;i<T->taille;i++){
		printf("Liste %d\n",i);
		listEquip_visualiser(T->tableau[i]);
	}
}

tableHachage chargeTHEquip(char* chemin){
	FILE* src = fopen(chemin,"r");
	if(src!=NULL){
		tableHachage T=tableHachage_creer(10);
		int cpt1=0;
		int cpt2=0;
		
		do{
			char* id=malloc(sizeof(char)*8);
			char* airl=malloc(sizeof(char)*8);
			char* aD1=malloc(sizeof(char)*8);
			char* aD2=malloc(sizeof(char)*8);
			char* rId=malloc(sizeof(char)*8);
			char* code=malloc(sizeof(char)*8);
			cpt1=fgetc(src);
			if(cpt1==EOF){
				free(id);
				free(airl);
				free(aD1);
				free(aD2);
				free(rId);
				free(code);
				break;
			}
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(id+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			id[cpt2]='\0';
			if(cpt1==EOF){
					break;
			}
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				*(rId+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);

			}
			rId[cpt2]='\0';
			if(cpt1==EOF){
					break;
			}
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(airl+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			airl[cpt2]='\0';
			if(cpt1==EOF){
					break;
			}
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(aD1+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			aD1[cpt2]='\0';
			if(cpt1==EOF){
					break;
			}
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(aD2+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			aD2[cpt2]='\0';
			if(cpt1==EOF){
					break;
			}
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!='\n'&&cpt1!=EOF){
				*(code+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			code[cpt2]='\0';
			cpt2=0;
			tableHachage_ajout(initialiseEquip(strndup(airl,8),strndup(aD1,8),strndup(aD2,8),strndup(code,8),atoi(rId),atoi(id)),T,code);		
			free(id);
			free(airl);
			free(aD1);
			free(aD2);
			free(rId);
			free(code);
		}while(cpt1!= EOF);
		fclose(src);
		return(T);
	}else{
		printf("Nom de source incorrect \n");
		return(NULL);
	}
	
	
}

//Fonctions pour les tables de Hachage de Airlines


airl tHAirl_get(airl a,tableHachage T){
	int hash = hachage(a->nom,T->taille);
	return(listAirl_rech(T->tableau[hash],a->id));
}

void tHAirl_supprime(airl a,tableHachage T){
	int hash = hachage(a->nom,T->taille);
	airl a1=malloc(sizeof(airl));
	a1=listAirl_rech(T->tableau[hash],a->id);
	if(a1!=NULL){
		T->tableau[hash]=listAirl_remove(T->tableau[hash],a);
	}
}

void tHAirl_visualiser(tableHachage T){
	for(int i=0;i<T->taille;i++){
		if(i<T->taille){
			printf("Liste %d\n",i);
			listAirl_visualiser(T->tableau[i]);
		}
		
	}
}

tableHachage chargeTHAirl(char* chemin){
	FILE* src = fopen(chemin,"r");
	if(src!=NULL){
		tableHachage T=tableHachage_creer(10);
		char cpt1=' ';
		int cpt2=0;
		do{
			char* id=(char*) malloc(sizeof(char)*10);
			char* nom=(char*) malloc(sizeof(char)*128);
			char* iata=(char*) malloc(sizeof(char)*15);
			char* icao=(char*) malloc(sizeof(char)*15);
			char* pays=(char*) malloc(sizeof(char)*60);

			cpt1=fgetc(src);
			if(cpt1==EOF){
					free(id);
					free(nom);
					free(iata);
					free(icao);
					free(pays);
					break;
			}
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(id+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			id[cpt2]='\0';
			if(cpt1==EOF){
					break;
			}
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				*(nom+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);

			}
			nom[cpt2]='\0';

			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				cpt1=fgetc(src);

			}
			cpt1=fgetc(src);

			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(iata+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			iata[cpt2]='\0';

			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(icao+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			icao[cpt2]='\0';

			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				cpt1=fgetc(src);

			}

			cpt1=fgetc(src);
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(pays+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			pays[cpt2]='\0';

			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!='\n'&&cpt1!=EOF){
				if(cpt1==EOF){
					break;
				}
				cpt1=fgetc(src);
			}

			cpt2=0;
			if(atoi(id)!=20608&&atoi(id)!=18860&&atoi(id)!=18863){
				tableHachage_ajout(initialiseAirl(atoi(id),strndup(nom,128),strndup(iata,15),strndup(icao,15),strndup(pays,60)),T,nom);
			}
			free(id);
			free(nom);
			free(iata);
			free(icao);
			free(pays);
		}while(cpt1!= EOF);	
		fclose(src);
		return(T);
	}else{
		printf("Nom de source incorrect \n");
		return(NULL);
	}
}

//Fonctions pour les tables de Hachage de Localisations

local tHLocal_get(local lo,tableHachage T){
	int hash = hachage(lo->ville,T->taille);
	return(listLocal_rech(T->tableau[hash],lo->lat,lo->lon));
}

void tHLocal_supprime(local lo,tableHachage T){
	int hash = hachage(lo->ville,T->taille);
	local lo1=malloc(sizeof(local));
	lo1=listLocal_rech(T->tableau[hash],lo->lat,lo->lon);
	if(lo1!=NULL){
		T->tableau[hash]=listLocal_remove(T->tableau[hash],lo);
	}
}

void tHLocal_visualiser(tableHachage T){
	for(int i=0;i<T->taille;i++){
		printf("Liste %d\n",i);
		listLocal_visualiser(T->tableau[i]);
	}
}

tableHachage chargeTHLocal(char* chemin){
	FILE* src = fopen(chemin,"r");
	if(src!=NULL){
		tableHachage T=tableHachage_creer(10);
		char cpt1=' ';
		int cpt2=0;
		do{
			char* lat=(char*) malloc(sizeof(char)*30);
			char* lon=(char*) malloc(sizeof(char)*30);
			char* alt=(char*) malloc(sizeof(char)*30);
			char* ville=(char*) malloc(sizeof(char)*60);
			char* pays=(char*) malloc(sizeof(char)*60);
			cpt1=fgetc(src);
			if(cpt1==EOF){
					free(lat);
					free(lon);
					free(alt);
					free(ville);
					free(pays);
					break;
			}
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(lat+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			lat[cpt2]='\0';
			if(cpt1==EOF){
					break;
			}
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				*(lon+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);

			}
			lon[cpt2]='\0';

			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(ville+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			ville[cpt2]='\0';

			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(pays+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			pays[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(alt+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			alt[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!='\n'&&cpt1!=EOF){
				if(cpt1==EOF){
					break;
				}
				cpt1=fgetc(src);
			}
			cpt2=0;
			tableHachage_ajout(initialiseLocal(atof(lat),atof(lon),atof(alt),strndup(ville,60),strndup(pays,60)),T,ville);
			free(lat);
			free(lon);
			free(alt);
			free(ville);
			free(pays);
		}while(cpt1!= EOF);
		fclose(src);
		return(T);
	}else{
		printf("Nom de source incorrect \n");
		return(NULL);
	}
}

//Fonctions pour les tables de Hachage de Planes

plane tHPlane_get(plane p,tableHachage T){
	int hash = hachage(p->nom,T->taille);
	if(listPlane_rech(T->tableau[hash],p->iata)==NULL){
		return(listPlane_rech(T->tableau[hash],p->icao));
	}else{
		return(listPlane_rech(T->tableau[hash],p->iata));
	}
}

void tHPlane_supprime(plane p,tableHachage T){
	int hash = hachage(p->nom,T->taille);
	plane p1=malloc(sizeof(plane));
	p1=listPlane_rech(T->tableau[hash],p->iata);
	if(p1==NULL){
		p1=listPlane_rech(T->tableau[hash],p->icao);
	}
	if(p1!=NULL){
		T->tableau[hash]=listPlane_remove(T->tableau[hash],p1);
	}
}

void tHPlane_visualiser(tableHachage T){
	for(int i=0;i<T->taille;i++){
		printf("Liste %d\n",i);
		listPlane_visualiser(T->tableau[i]);
	}
}

tableHachage chargeTHPlane(char* chemin){
	FILE* src = fopen(chemin,"r");
	if(src!=NULL){
		tableHachage T=tableHachage_creer(10);
		
		char cpt1=' ';
		int cpt2=0;
		
		do{
			char* nom=malloc(sizeof(char)*128);
			char* iata=malloc(sizeof(char)*8);
			char* icao=malloc(sizeof(char)*8);
			char* sie=malloc(sizeof(char)*8);
			char* vit=malloc(sizeof(char)*30);
			char* aut=malloc(sizeof(char)*8);
			char* carb=malloc(sizeof(char)*8);

			cpt1=fgetc(src);
			if(cpt1==EOF){
				free(nom);
				free(iata);
				free(icao);
				free(sie);
				free(vit);
				free(aut);
				free(carb);
				break;
			}
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				cpt1=fgetc(src);
			}
			cpt1=fgetc(src);
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				nom[cpt2]=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			nom[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				iata[cpt2]=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			iata[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				icao[cpt2]=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			icao[cpt2]='\0';
			
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				sie[cpt2]=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			sie[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;

			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				vit[cpt2]=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			vit[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				aut[cpt2]=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			aut[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!='\n'&&cpt1!=EOF){
				if(cpt1==EOF){
					break;
				}
				carb[cpt2]=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			carb[cpt2]='\0';
			cpt2=0;
			tableHachage_ajout(initialisePlane(strndup(nom,128),strndup(iata,8),strndup(icao,8),atoi(sie),atof(vit),atoi(aut),atoi(carb)),T,nom);
			free(nom);
			free(iata);
			free(icao);
			free(sie);
			free(vit);
			free(aut);
			free(carb);
		}while(cpt1!= EOF);
		fclose(src);
		return(T);
	}else{
		printf("Nom de source incorrect \n");
		return(NULL);
	}
}

//Fonctions pour les tables de Hachage de Routes

route tHRoute_get(route r,tableHachage T){
	char* tot=malloc(sizeof(char)*12);
	int cpt=0;
	for(int i=0;i<strlen(r->airl);i++){
		*(tot+cpt)=*((r->airl)+i);
		cpt++;
	}
	for(int i=0;i<strlen(r->airpDep);i++){
		*(tot+cpt)=*((r->airpDep)+i);
		cpt++;
	}
	for(int i=0;i<strlen(r->airpDest);i++){
		*(tot+cpt)=*((r->airpDest)+i);
		cpt++;
	}
	int hash = hachage(tot,T->taille);
	return(listRoute_rech(T->tableau[hash],r->id));
}

void tHRoute_supprime(route r,tableHachage T){
	char* tot=malloc(sizeof(char)*12);
	int cpt=0;
	for(int i=0;i<strlen(r->airl);i++){
		*(tot+cpt)=*((r->airl)+i);
		cpt++;
	}
	for(int i=0;i<strlen(r->airpDep);i++){
		*(tot+cpt)=*((r->airpDep)+i);
		cpt++;
	}
	for(int i=0;i<strlen(r->airpDest);i++){
		*(tot+cpt)=*((r->airpDest)+i);
		cpt++;
	}
	int hash = hachage(tot,T->taille);
	route r1=malloc(sizeof(route));
	r1=listRoute_rech(T->tableau[hash],r->id);
	if(r1!=NULL){
		T->tableau[hash]=listRoute_remove(T->tableau[hash],r);
	}
}

void tHRoute_visualiser(tableHachage T){
	for(int i=0;i<T->taille;i++){
		printf("Liste %d\n",i);
		listRoute_visualiser(T->tableau[i]);
	}
}

tableHachage chargeTHRoute(char* chemin){
	FILE* src = fopen(chemin,"r");
	if(src!=NULL){
		tableHachage T=tableHachage_creer(10);
		char cpt1=' ';
		int cpt2=0;
		do{
			char* id=malloc(sizeof(char)*8);
			char* code=malloc(sizeof(char)*8);
			char* airl=malloc(sizeof(char)*8);
			char* airlId=malloc(sizeof(char)*8);
			char* aD1=malloc(sizeof(char)*8);
			char* aD2=malloc(sizeof(char)*8);
			char* aD1Id=malloc(sizeof(char)*8);
			char* aD2Id=malloc(sizeof(char)*8);
			char* arret=malloc(sizeof(char)*8);
			cpt1=fgetc(src);
			if(cpt1==','){
				id[0]='-';
				id[1]='1';
				id[2]='\0';
			}
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				id[cpt2]=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			id[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			if(cpt1==','){
				airl[0]='N';
				airl[1]='U';
				airl[2]='L';
				airl[3]='L';
				airl[4]='\0';
			}
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				airl[cpt2]=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			airl[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			if(cpt1==','){
				airlId[0]='-';
				airlId[1]='1';
				airlId[2]='\0';
			}
				while(cpt1!=','){
					if(cpt1==EOF){
						break;
					}
					airlId[cpt2]=cpt1;
					cpt2++;
					cpt1=fgetc(src);
				}
				airlId[cpt2]='\0';
			
			cpt1=fgetc(src);
			cpt2=0;
			if(cpt1==','){
				aD1[0]='N';
				aD1[1]='U';
				aD1[2]='L';
				aD1[3]='L';
				aD1[4]='\0';
			}
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				aD1[cpt2]=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			aD1[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			if(cpt1==','){
				aD1Id[0]='-';
				aD1Id[1]='1';
				aD1Id[2]='\0';
			}
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				aD1Id[cpt2]=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			aD1Id[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				aD2[cpt2]=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			aD2[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			if(cpt1==','){
				aD2Id[0]='-';
				aD2Id[1]='1';
				aD2Id[2]='\0';
			}
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				aD2Id[cpt2]=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			aD2Id[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			if(cpt1==','){
				code[0]='N';
				code[1]='U';
				code[2]='L';
				code[3]='L';
				code[4]='\0';
			}
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				code[cpt2]=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			code[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!='\n'&&cpt1!=EOF){
				if(cpt1==EOF){
					break;
				}
				arret[cpt2]=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			arret[cpt2]='\0';
			cpt2=0;
			char* ID1 = strndup(airlId,8);
			char* ID2 = strndup(aD1Id,8);
			char* ID3 = strndup(aD2Id,8);
			char* ID5 = strndup(id,8);
			char* ID4 = strndup(arret,8);
			tableHachage_ajout(initialiseRoute(strndup(airl,3),atoi(ID1),strndup(aD1,8),atoi(ID2),strndup(aD2,8),atoi(ID3),strndup(code,8),atoi(ID4),atoi(ID5)),T,aD1);
			free(ID1);
			free(ID2);
			free(ID3);
			free(ID4);
			free(ID5);
			free(id);
			free(code);
			free(airl);
			free(airlId);
			free(aD1);
			free(aD2);
			free(aD1Id);
			free(aD2Id);
			free(arret);
		}while(cpt1!= EOF);
		fclose(src);
		return(T);
	}else{
		printf("Nom de source incorrect \n");
		return(NULL);
	}
}

//Fonctions pour les tables de Hachage de FlightNumbers

flightNum tHFlightNum_get(flightNum f,tableHachage T){
	int hash = hachage(f->fnum,T->taille);
	return(listFlightNum_rech(T->tableau[hash],f->id));
}

void tHFlightNum_supprime(flightNum f,tableHachage T){
	int hash = hachage(f->fnum,T->taille);
	flightNum f1=malloc(sizeof(flightNum));
	f1=listFlightNum_rech(T->tableau[hash],f->id);
	if(f1!=NULL){
		T->tableau[hash]=listFlightNum_remove(T->tableau[hash],f);
	}
}

void tHFlightNum_visualiser(tableHachage T){
	for(int i=0;i<T->taille;i++){
		printf("Liste %d\n",i);
		listFlightNum_visualiser(T->tableau[i]);
	}
}

tableHachage chargeTHFlightNum(char* chemin){
	FILE* src = fopen(chemin,"r");
	if(src!=NULL){
		tableHachage T = tableHachage_creer(10);
		int cpt1=0;
		int cpt2=0;
		
		do{	
			char* id=malloc(sizeof(char)*8);
			char* code=malloc(sizeof(char)*8);
			char* fnum=malloc(sizeof(char)*8);
			char* arret=malloc(sizeof(char)*8);
			cpt1=fgetc(src);
			if(cpt1==EOF){
				free(id);
				free(code);
				free(fnum);
				free(arret);
				break;
			}
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(id+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			id[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(code+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);

			}
			code[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!=','){
				if(cpt1==EOF){
					break;
				}
				*(fnum+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			fnum[cpt2]='\0';
			cpt1=fgetc(src);
			cpt2=0;
			while(cpt1!='\n'&&cpt1!=EOF){
				if(cpt1==EOF){
					break;
				}
				*(arret+cpt2)=cpt1;
				cpt2++;
				cpt1=fgetc(src);
			}
			arret[cpt2]='\0';
			cpt2=0;
			
			tableHachage_ajout(initialiseFlightNum(atoi(id),strndup(code,8),strndup(fnum,8),atoi(arret)),T,fnum);
			free(id);
			free(code);
			free(fnum);
			free(arret);
		}while(cpt1!= EOF);
		fclose(src);
		return(T);
	}else{
		printf("Nom de source incorrect \n");
		return(NULL);
	}
}
int main(){	
	tableHachage TFlightNum = chargeTHFlightNum("../../cleaned_data/flightnumbers.csv");

	tableHachage TLocal = chargeTHLocal("../../cleaned_data/localisations.csv");

	tableHachage TPlane = chargeTHPlane("../../cleaned_data/planes2.csv");

	tableHachage TStops = chargeTHStops("../../cleaned_data/stops.csv");

	tableHachage TRoute = chargeTHRoute("../../cleaned_data/routes.csv");

	tableHachage TEquip = chargeTHEquip("../../cleaned_data/equipements.csv");

	tableHachage TAirp = chargeTHAeroport("../../cleaned_data/airports.csv");

	tableHachage TAirl = chargeTHAirl("../../cleaned_data/airlines.csv");

	/*tHAeroport_visualiser(TAirp);
	tHStops_visualiser(TStops);
	tHRoute_visualiser(TRoute);
	tHRoute_visualiser(TRoute);
	tHEquip_visualiser(TEquip);
	tHFlightNum_visualiser(TFlightNum);
	tHPlane_visualiser(TPlane);
	tHAirl_visualiser(TAirl);*/
	/*liste l = perimetre(TAirp,65.66004,-18.072701,100);
	listeAeroportEdit(l);
	free_listAeroport(l);*/
	free_tHFlightNum(TFlightNum);
	free_tHLocal(TLocal);
	free_tHPlane(TPlane);
	free_tHStops(TStops);
	free_tHRoute(TRoute);
	free_tHEquip(TEquip);
	free_tHAeroport(TAirp);
	free_tHAirl(TAirl);
	//tHAeroport_visualiser(TAirp);
	/*liste out = malloc(sizeof(liste));
	out=perimetre(T,a1->latitude,a1->longitude,220);
	printf("\n");
	listAeroport_visualiser(out);
	free_listAeroport(out);*/
	//listAirl_visualiser(TAirl->tableau[2]);
}