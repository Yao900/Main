#
##
CC = g++
FLAGS = -lm -std=c++11

tp3: TP3.o outil.o Sommet.o
	 $(CC) $(FLAGS) -o tp3 TP3.o outil.o Sommet.o
outil.o: outil.h
	$(CC) $(FLAGS) -c outil.cpp
Sommet.o: Sommet.h outil.h
	$(CC) $(FLAGS) -c Sommet.cpp	
TP3.o:Sommet.h outil.h
	$(CC) $(FLAGS) -c TP3.cpp 

clean:
	rm -f *.o tp3
