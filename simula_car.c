#include "simula_car.h"
/* Funcion ejecutada por los hilos*/
int clasificacionFinal[N_COCHES];
int finalCarrera=0;
void *funcion_coche(coche_t *pcoche)
{
    int aleatorio;
    /*pthread_mutex_unlock(&mutex);*/
    unsigned int semilla = (pcoche->id) + pthread_self(); /* semilla generacion num. aleatorios*/


    printf("Salida de %s %d\n", pcoche->cadena, pcoche->id);
    
    fflush (stdout);

    /* generar numero aleatorios con funcion re-entrante rand_r()*/
    aleatorio = rand_r(&semilla) % 10;
  
    sleep(aleatorio);
 
    printf("Llegada de %s %d\n", pcoche->cadena, pcoche->id);

    /* CODIGO 4 */

    /*pthread_mutex_lock(&mutex);*/


    /* CODIGO 2 */  
    pthread_exit(NULL);
  
}


int main(void)
{  pthread_mutex_init(&mutex,NULL);
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
        pthread_create(&hilosCoches[i], NULL, (void *)*funcion_coche , (void *)&coches[i]);
    } 

    printf("Proceso de creacion de hilos terminado\n\n");
     
    
    for (i=0; i<N_COCHES; i++)
    {
        /* CODIGO 3 */
        pthread_join(hilosCoches[i], NULL);
        pthread_join(clasificacionFinal[i],NULL);
    }
   
    printf("Todos los coches han LLEGADO A LA META \n");
    
   /* CODIGO 5 */   
    for (i=0; i<N_COCHES; i++)
    {
       printf(clasificacionFinal[i]);   

    } 
   
    return 0;
}
