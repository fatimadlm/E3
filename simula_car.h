#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define N_COCHES 8

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
/* Tipo de datos que representa un coche*/
typedef struct {
    int id;
    char *cadena;
} coche_t;

/* Array de datos de tipo coche_t*/
coche_t coches[N_COCHES];

void *funcion_coche(coche_t *pcoche);
