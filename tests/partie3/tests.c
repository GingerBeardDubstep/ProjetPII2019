#include "testTableHachage.h"
int main(){
	CU_pSuite pSuite1 = NULL;
	CU_pSuite pSuite2 = NULL;
  CU_pSuite pSuite3 = NULL;

	if (CUE_SUCCESS != CU_initialize_registry()){
      return CU_get_error();
	}

	pSuite1 = CU_add_suite("Suite Aeroport", 0,0);
   	if (NULL == pSuite1) {
      CU_cleanup_registry();
      return CU_get_error();
   	}

   	if ((NULL == CU_add_test(pSuite1, "test of initialise()", testInitialise))
       || (NULL == CU_add_test(pSuite1, "test of est_dans_perimetre()", testPerimetre))
       || (NULL == CU_add_test(pSuite1, "test of getICAO()", testICAO))
       || (NULL == CU_add_test(pSuite1, "test of getIATA()", testIATA))
       || (NULL == CU_add_test(pSuite1, "test of getNom()", testNom))
       || (NULL == CU_add_test(pSuite1, "test of getId()", testId)))
   	{
      CU_cleanup_registry();
      return CU_get_error();
   	}


pSuite2 = CU_add_suite("Suite ListeAeroport", 0,0);
    if (NULL == pSuite2) {
      CU_cleanup_registry();
      return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite2, "test of creer()", testListAeroport_creer))
       || (NULL == CU_add_test(pSuite2, "test of est_vide()", testListAeroport_est_vide))
       || (NULL == CU_add_test(pSuite2, "test of ajoutTete()", testListAeroport_ajoutTete))
       || (NULL == CU_add_test(pSuite2, "test of ajoutFin()", testListAeroport_ajoutFin))
       || (NULL == CU_add_test(pSuite2, "test of ajoutN()", testListAeroport_ajoutN))
       || (NULL == CU_add_test(pSuite2, "test of rechN()", testListAeroport_rechN))
       || (NULL == CU_add_test(pSuite2, "test of rech()", testListAeroport_rech))
       || (NULL == CU_add_test(pSuite2, "test of remove()", testListAeroport_remove)))


    {  

      CU_cleanup_registry();
      return CU_get_error();
    }

   	CU_basic_set_mode(CU_BRM_VERBOSE);
   	CU_basic_run_tests();
   	CU_cleanup_registry();
   	return CU_get_error();
	return(0);
}