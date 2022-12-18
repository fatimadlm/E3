#Por defecto se generara un objeto all
all : simulacion_coches

#Definimos las variables 
CC = gcc
CFLAGS = -g -Wall -lpthread 

#Creacion de simula_coche
simulacion_coches: simula_car.o
		$(CC) $(CFLAGS) simula_car.o
simula_car.o:simula_car.c simula_car.h
	$(CC) $(CFLAGS) -c simula_car.c -lpthread 
	

#Usamos la funcion CLEAN
.PHONY:clean
clean:
	rm -f *.o simulacion_coches
