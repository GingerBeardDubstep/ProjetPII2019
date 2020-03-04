all : cleanmain testAeroport.o testListe.o tests.o tests clean

clean :
	rm -f *.o

cleanmain :
	rm -f tests

testAeroport.o : testAeroport.c libaeroport.a
	gcc -Wall -c testAeroport.c -o testAeroport.o -lcunit

testListe.o : testListe.c libaeroport.a
	gcc -Wall -c testListe.c -o testListe.o -lcunit

tests.o : tests.c testAeroport.o testListe.o
	gcc -Wall -c tests.c -o tests.o -lcunit

tests : tests.o 
	gcc -Wall testAeroport.o testListe.o tests.o libaeroport.a -o tests -lcunit -lm