#include "testAeroport.h"

void testInitialise(){
	aeroport a1 = initialiseAeroport(0.0,0.0,"Test1",0,"IATA","ICA");
	aeroport a2 = initialiseAeroport(10.0,0.0,"Test2",1,"IAATi","IAC");
	aeroport a3 = initialiseAeroport(20.0,0.0,"Test3",2,"IAAT","IACp");
	aeroport a4 = initialiseAeroport(20.0,0.0,"Test4",3,"IAA","IAC");
	aeroport a5 = initialiseAeroport(20.0,0.0,"Test5",4,"IAAT","IA");
	CU_ASSERT(a1!=NULL);
	CU_ASSERT(a2!=NULL);
	CU_ASSERT(a3!=NULL);
	CU_ASSERT(a4!=NULL);
	CU_ASSERT(a5!=NULL);
}

void testPerimetre(){
	aeroport a1 = initialiseAeroport(0.0,0.0,"Test1",0,"IATA","ICA");
	aeroport a2 = initialiseAeroport(10.0,0.0,"Test2",1,"IAAT","IAC");
	aeroport a3 = initialiseAeroport(20.0,0.0,"Test3",2,"IAAT","IAC");
	aeroport a4 = initialiseAeroport(-10.0,-10.0,"Test4",3,"IAAT","IAC");
	aeroport a5 = initialiseAeroport(10.0,10.0,"Test5",4,"IAAT","IAC");
	CU_ASSERT(est_dans_perimetre(a1,a2,1120)==1);
	CU_ASSERT(est_dans_perimetre(a2,a3,15)==0);
	CU_ASSERT(est_dans_perimetre(a1,a3,15)==0);
	CU_ASSERT(est_dans_perimetre(a1,a4,15)==0);
	CU_ASSERT(est_dans_perimetre(a1,a5,15)==0);
	CU_ASSERT(est_dans_perimetre(a1,a4,10)==0);
	CU_ASSERT(est_dans_perimetre(a1,a5,10)==0);
}

void testICAO(){
	aeroport a1 = initialiseAeroport(0.0,0.0,"Test1",0,"IATA","ICA");
	aeroport a2 = initialiseAeroport(10.0,0.0,"Test2",1,"IAAT","IAC");
	CU_ASSERT(strcmp(getICAO(a1),"ICA")==0);
	CU_ASSERT(strcmp(getICAO(a2),"IAC")==0);
}

void testIATA(){
	aeroport a1 = initialiseAeroport(0.0,0.0,"Test1",0,"IATA","ICA");
	aeroport a2 = initialiseAeroport(10.0,0.0,"Test2",1,"IAAT","IAC");
	CU_ASSERT(strcmp(getIATA(a1),"IATA")==0);
	CU_ASSERT(strcmp(getIATA(a2),"IAAT")==0);
}

void testNom(){
	aeroport a1 = initialiseAeroport(0.0,0.0,"Test1",0,"IATA","ICA");
	aeroport a2 = initialiseAeroport(10.0,0.0,"Test2",1,"IAAT","IAC");
	CU_ASSERT(strcmp(getNom(a1),"Test1")==0);
	CU_ASSERT(strcmp(getNom(a2),"Test2")==0);
}

void testId(){
	aeroport a1 = initialiseAeroport(0.0,0.0,"Test1",0,"IATA","ICA");
	aeroport a2 = initialiseAeroport(10.0,0.0,"Test2",1,"IAAT","IAC");
	CU_ASSERT(getId(a1)==0);
	CU_ASSERT(getId(a2)==1);
}