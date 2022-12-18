#include "simula_car.h"
/* Funcion ejecutada por los hilos*/
int clasificacionFinal[N_COCHES];
int finalCarrera=0;
void *funcion_coche(coche_t *pcoche)
{   int aleatorio;

    unsigned int semilla = (pcoche->id) + pthread_self(); /* Semilla para generar los números aleatorios*/

    printf("Salida de %s %d\n", pcoche->cadena, pcoche->id);
    
    fflush (stdout);

    /*Genera número aleatorio con funcion re-entrante rand_r()*/
    aleatorio = rand_r(&semilla) % 10;
  
    sleep(aleatorio);
 
    printf("Llegada de %s %d\n", pcoche->cadena, pcoche->id);

    /* CODIGO 4 */
    pthread_mutex_lock(&mutex);/*Bloqueamos el mutex,ya que accedemos a clasificacionFinal*/
    
    clasificacionFinal[finalCarrera]=pcoche->id;/*Llenamos el array con el id del coche*/
    
    finalCarrera++;/*Registro de la siguiente posicion vacia de clasificacionFinal*/
    
    pthread_mutex_unlock(&mutex);/*Desbloqueamos el mutex, ya que salimos de clasificacionFinal*/

    /* CODIGO 2 */  
    pthread_exit(NULL);
}


int main(void)
{   pthread_mutex_init(&mutex,NULL);/*Iniciamos el mutex*/
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
        pthread_join(hilosCoches[i], NULL);/*Esperamos a la finalizacion de los hilos*/
    }
    pthread_mutex_destroy(&mutex);/*Destruimos el mutex*/
    printf("Todos los coches han LLEGADO A LA META \n");
    
   /* CODIGO 5 */  
    for (i=0; i<N_COCHES; i++)
    {
       printf("Coche ganador %d:%d\n", i+1 ,clasificacionFinal[i]);/*Muestra los coches ganadores en su orden*/
    } 
   
    return 0;
}
