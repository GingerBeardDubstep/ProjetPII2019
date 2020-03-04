CC = gcc
FLAGS = -Wall -g

plusProche : clean structures liste2.o tableHachage.o main.o mainP

aeroport.o : ../../partie3/aeroport.c
	gcc -Wall -c ../../partie3/aeroport.c -o aeroport.o -lm

route.o : ../../partie3/route.c
	gcc -Wall -c ../../partie3/route.c -o route.o

plane.o : ../../partie3/plane.c
	gcc -Wall -c ../../partie3/plane.c -o plane.o

flightnumber.o : ../../partie3/flightnumber.c
	gcc -Wall -c ../../partie3/flightnumber.c -o flightnumber.o

airline.o : ../../partie3/airline.c
	gcc -Wall -c ../../partie3/airline.c -o airline.o

stops.o : ../../partie3/stops.c
	gcc -Wall -c ../../partie3/stops.c -o stops.o

equipement.o : ../../partie3/equipement.c
	gcc -Wall -c ../../partie3/equipement.c -o equipement.o

localisation.o : ../../partie3/localisation.c
	gcc -Wall -c ../../partie3/localisation.c -o localisation.o

structures : aeroport.o route.o plane.o flightnumber.o airline.o stops.o equipement.o localisation.o

liste2.o : aeroport.o ../../partie3/liste.c
	gcc -Wall -c ../../partie3/liste.c -o liste.o

tableHachage.o : liste.o ../../partie3/tableHachage.c
	gcc -Wall -c ../../partie3/tableHachage.c -o tableHachage.o

main.o : ../../partie3/main.c
	gcc -Wall -c ../../partie3/main.c -o main.o

mainP : tableHachage.o structures main.o
	gcc -Wall aeroport.o route.o plane.o flightnumber.o airline.o stops.o equipement.o localisation.o  liste.o tableHachage.o main.o -o main -lm
	./main -p1
	rm -f *.o
	rm -f main

astar : liste.o matrice.o 
	$(CC) $(FLAGS) liste.o matrice.o untitled.c -o astar -lm -g
	./astar

liste.o : liste.c
	$(CC) $(FLAGS) -c liste.c

matrice.o : matrice.c
	$(CC) $(FLAGS) -c matrice.c

clean :
	rm -f matrice.o
	rm -f *.o
	rm -f main
	rm -f astar
