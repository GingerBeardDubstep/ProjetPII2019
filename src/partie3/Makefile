all : structures liste.o tableHachage.o libaeroport.a clean

plusProche : clean structures liste.o tableHachage.o main.o mainP clean

TH : clean structures liste.o tableHachage.o tableHachage

clean :
	rm -f *.o
	rm -f main

cleanmain :
	rm -f main

aeroport.o : aeroport.c
	gcc -Wall -c aeroport.c -o aeroport.o -lm

route.o : route.c
	gcc -Wall -c route.c -o route.o

plane.o : plane.c
	gcc -Wall -c plane.c -o plane.o

flightnumber.o : flightnumber.c
	gcc -Wall -c flightnumber.c -o flightnumber.o

airline.o : airline.c
	gcc -Wall -c airline.c -o airline.o

stops.o : stops.c
	gcc -Wall -c stops.c -o stops.o

equipement.o : equipement.c
	gcc -Wall -c equipement.c -o equipement.o

localisation.o : localisation.c
	gcc -Wall -c localisation.c -o localisation.o

structures : aeroport.o route.o plane.o flightnumber.o airline.o stops.o equipement.o localisation.o

liste.o : aeroport.o liste.c
	gcc -Wall -c liste.c -o liste.o

liste : liste.o
	gcc -Wall aeroport.o airline.o route.o flightnumber.o stops.o localisation.o equipement.o plane.o liste.o -o liste -lm

tableHachage.o : liste.o tableHachage.c
	gcc -Wall -c tableHachage.c -o tableHachage.o

tableHachage : tableHachage.o structures liste.o
	gcc -Wall aeroport.o route.o plane.o flightnumber.o airline.o stops.o equipement.o localisation.o  liste.o tableHachage.o -o tableHachage -lm

main.o : main.c
	gcc -Wall -c main.c -o main.o

main : tableHachage.o structures main.o
	gcc -Wall aeroport.o route.o plane.o flightnumber.o airline.o stops.o equipement.o localisation.o  liste.o tableHachage.o main.o -o main -lm

mainP : tableHachage.o structures main.o
	gcc -Wall aeroport.o route.o plane.o flightnumber.o airline.o stops.o equipement.o localisation.o  liste.o tableHachage.o main.o -o main -lm
	./main -p1
	rm -f *.o
	rm -f main

libaeroport.a : structures liste.o tableHachage.o
	ar -r -v ../../tests/partie3/libaeroport.a aeroport.o localisation.o equipement.o route.o stops.o plane.o flightnumber.o airline.o liste.o tableHachage.o