CC = gcc
FLAGS = -Wall -g

astar : liste.o matrice.o 
	$(CC) $(FLAGS) liste.o matrice.o untitled.c -o astar -lm -g
	./astar 

liste.o : liste.c
	$(CC) $(FLAGS) -c liste.c

matrice.o : matrice.c
	$(CC) $(FLAGS) -c matrice.c

clean :
	rm matrice.o
	rm liste.o
	rm astar
	rm sortie.txt