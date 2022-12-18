#include "simula_car.h"
/*
#define N_COCHES 8
*/
/* Tipo de datos que representa un coche*/
/*typedef struct {
    int id;
    char *cadena;
} coche_t;*/

/* Array de datos de tipo coche_t*/
/*coche_t Coches[N_COCHES];*/


/* Funcion ejecutada por los hilos*/
void *funcion_coche(coche_t *pcoche)
{
    int aleatorio;
    unsigned int semilla = (pcoche->id) + pthread_self(); /* semilla generacion num. aleatorios*/


    printf("Salida de %s %d\n", pcoche->cadena, pcoche->id);
    
    fflush (stdout);

    /* generar numero aleatorios con funcion re-entrante rand_r()*/
    aleatorio = rand_r(&semilla) % 10;
    /*RAND_C:Es una funcion que genera un numero random con la semilla que la pasamos.En este caso creamos un aleatorio con etsa funcion para q nos de un numero entre 0 y 9*/

    sleep(aleatorio);
 
    printf("Llegada de %s %d\n", pcoche->cadena, pcoche->id);

    /* CODIGO 4 */


    /* CODIGO 2 */  
    pthread_exit(NULL);
  
}


int main(void)
{
    pthread_t hilosCoches[N_COCHES]; /* tabla con los identificadores de los hilos*/
    int i;
    
    printf("Se inicia proceso de creacion de hilos...\n\n");
    printf("SALIDA DE COCHES\n");
    
    for (i=0; i<N_COCHES; i++)/*Bucle para crear hasta N_COCHES*/
    {
        /* CODIGO 1 */
        /*Inicializamos la estructura coche */
        coches[i].id=i+1;
        coches[i].cadena="coche";
        /*Creamos los hilos*/
        pthread_create(&hilosCoches[i], NULL, *funcion_coche , &coches[i]);
    } 

    printf("Proceso de creacion de hilos terminado\n\n");
     
    
    for (i=0; i<N_COCHES; i++)
    {
        /* CODIGO 3 */
        pthread_join(hilosCoches[i], NULL);
    }
   
    printf("Todos los coches han LLEGADO A LA META \n");
    
    /* CODIGO 5 */       

    return 0;
}
/*3. Teenemos q asegurarnos de que los hilos han terminado porque sino el programa terminada segun termine el main,entonces no realizara todo lo q queremos que haga, ademas de que nos devuelve el valor de retorno de los hilos*/

