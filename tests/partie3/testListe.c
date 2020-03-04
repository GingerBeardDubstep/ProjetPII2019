#include "testListe.h"
void testListAeroport_creer(){
	liste L = list_creer();
	CU_ASSERT(L!=NULL);
}

void testListAeroport_est_vide(){
	liste L = list_creer();
	CU_ASSERT(list_est_vide(L)==1);
	aeroport a1 = initialiseAeroport(0.0,0.0,"Test1",0,"IATA","ICA");
	L->val=a1;
	L->suiv=list_creer();
	CU_ASSERT(list_est_vide(L)==0);
}

void testListAeroport_ajoutTete(){
	liste L = list_creer();
	aeroport a1 =initialiseAeroport(0.0,0.0,"Test1",0,"IATA","ICA");
	aeroport a2 = initialiseAeroport(10.0,0.0,"Test2",1,"IAATi","IAC");
	CU_ASSERT(list_taille(L)==0);
	L=list_ajoutTete(L,a1);
	CU_ASSERT(list_taille(L)==1);
	CU_ASSERT(((aeroport) L->val)->id==0);
	L=list_ajoutTete(L,a2);
	CU_ASSERT(list_taille(L)==2);
	CU_ASSERT(((aeroport) L->val)->id==1);
}

void testListAeroport_ajoutFin(){
	liste L = list_creer();
	aeroport a1 = initialiseAeroport(0.0,0.0,"Test1",0,"IATA","ICA");
	aeroport a2 = initialiseAeroport(10.0,0.0,"Test2",1,"IAATi","IAC");
	L=list_ajoutFin(L,a1);
	CU_ASSERT(((aeroport) L->val)->id==0);
	L=list_ajoutFin(L,a2);
	CU_ASSERT(((aeroport) L->val)->id==0);
	CU_ASSERT(((aeroport) L->suiv->val)->id==1);
}

void testListAeroport_ajoutN(){
	liste L = list_creer();
	aeroport a1 = initialiseAeroport(0.0,0.0,"Test1",0,"IATA","ICA");
	aeroport a2 = initialiseAeroport(10.0,0.0,"Test2",1,"IAATi","IAC");
	aeroport a3 = initialiseAeroport(20.0,0.0,"Test3",2,"IAAT","IACp");
	L=list_ajoutN(L,a1,0);
	CU_ASSERT(((aeroport) L->val)->id==0);
	L=list_ajoutN(L,a2,1);
	CU_ASSERT(((aeroport) L->val)->id==0);
	CU_ASSERT(((aeroport) L->suiv->val)->id==1);
	L=list_ajoutN(L,a3,1);
	//listAeroport_visualiser(L);
	CU_ASSERT(((aeroport) L->val)->id==0);
	CU_ASSERT(((aeroport) L->suiv->val)->id==2);
	CU_ASSERT(((aeroport) L->suiv->suiv->val)->id==1);
}

void testListAeroport_rechN(){
	liste L = list_creer();
	aeroport a1 = initialiseAeroport(0.0,0.0,"Test1",0,"IATA","ICA");
	aeroport a2 = initialiseAeroport(10.0,0.0,"Test2",1,"IAATi","IAC");
	aeroport a3 = initialiseAeroport(20.0,0.0,"Test3",2,"IAAT","IACp");
	L=list_ajoutFin(L,a1);
	L=list_ajoutFin(L,a2);
	L=list_ajoutFin(L,a3);
	CU_ASSERT(listAeroport_rechN(L,0,2)==a1);
	CU_ASSERT(listAeroport_rechN(L,1,2)==a2);
	CU_ASSERT(listAeroport_rechN(L,2,2)==a3);
	CU_ASSERT(listAeroport_rechN(L,5,2)==NULL);
	CU_ASSERT(listAeroport_rechN(L,2,1)==NULL);
}

void testListAeroport_rech(){
	liste L = list_creer();
	aeroport a1 = initialiseAeroport(0.0,0.0,"Test1",0,"IATA","ICA");
	aeroport a2 = initialiseAeroport(10.0,0.0,"Test2",1,"IAATi","IAC");
	aeroport a3 = initialiseAeroport(20.0,0.0,"Test3",2,"IAAT","IACp");
	L=list_ajoutFin(L,a1);
	L=list_ajoutFin(L,a2);
	L=list_ajoutFin(L,a3);
	CU_ASSERT(listAeroport_rechById(L,0)==a1);
	CU_ASSERT(listAeroport_rechById(L,1)==a2);
	CU_ASSERT(listAeroport_rechById(L,2)==a3);
	CU_ASSERT(listAeroport_rechById(L,5)==NULL);
}

void testListAeroport_remove(){
	liste L = list_creer();
	aeroport a1 = initialiseAeroport(0.0,0.0,strndup("Test1",8),0,strndup("IATA",8),strndup("ICA",8));
	aeroport a2 = initialiseAeroport(10.0,0.0,strndup("Test2",8),1,strndup("IAATi",8),strndup("IAC",8));
	aeroport a3 = initialiseAeroport(20.0,0.0,strndup("Test3",8),2,strndup("IAAT",8),strndup("IACp",8));
	L=list_ajoutFin(L,a1);
	L=list_ajoutFin(L,a2);
	L=list_ajoutFin(L,a3);
	L=listAeroport_remove(L,a1);
	CU_ASSERT(((aeroport) L->val)==a2);
	CU_ASSERT(((aeroport) L->suiv->val)==a3);
	L=list_ajoutTete(L,a1);
	L=listAeroport_remove(L,a2);
	//listAeroport_visualiser(L);
	CU_ASSERT(((aeroport) L->val)==a1);
	CU_ASSERT(((aeroport) L->suiv->val)==a3);
	L=list_ajoutN(L,a2,1);
	L=listAeroport_remove(L,a3);
	CU_ASSERT(((aeroport) L->val)==a1);
	CU_ASSERT(((aeroport) L->suiv->val)==a2);
	free_listAeroport(L);
}