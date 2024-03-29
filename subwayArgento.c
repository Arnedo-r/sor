# include  <stdio.h>       // libreria estandar
# include  <stdlib.h>      // para usar exit y funciones de la libreria standard
# include  <string.h>
# include  <pthread.h>     // para usar hilos
# include  <semaphore.h>   // para usar semaforos
# include  <unistd.h>


# define  LIMITE  100

// creo los pasos de la receta
	char cad1 [LIMITE];
	char cad2 [LIMITE];
	char cad3 [LIMITE];
	char cad4 [LIMITE];
	char cad5 [LIMITE];
	char cad6 [LIMITE];
	char cad7 [LIMITE];
	char cad8 [LIMITE];
	char cad9 [LIMITE];
	char cad10 [LIMITE];
	char cad11 [LIMITE];
	char cad12 [LIMITE];

// creo estructura de semaforos
struct semaforos {
	// poner demas semaforos aqui
    sem_t sem_mezclarHuevo;
    sem_t sem_salar;
    sem_t sem_agregarCarne;
    sem_t sem_empanar;
    sem_t sem_fritar;
    sem_t sem_hornear;
    sem_t sem_prepararExtras;
    sem_t sem_armar;
};

// creo semaforos compartidos
	sem_t sem1;
	sem_t sem2;
	sem_t sem3;


// creo los pasos con los ingredientes
struct paso {
   char accion [LIMITE];
   char ingredientes[4][LIMITE];

};

// creo los parametros de los hilos
struct parametro {
    int equipo_param;
    struct semaforos semaforos_param;
    struct paso pasos_param [8];
};

FILE* salida;

// funcion para tomar de ejemplo
void * cortar ( void *datos) {
	// creo el nombre de la accion de la funcion
	char *accion = "cortar" ;
	// creo el puntero para pasarle la referencia de memoria (data) del struct pasado por parametro (la cual es un puntero).
	struct parametro *mydata = datos;
	// llamo a la funcion imprimir le paso el struct y la accion de la funcion
	printf("\tEquipo %d -",mydata->equipo_param);
	puts (cad1);
	//guardo en el archivo de salida
	fprintf(salida,"\tEquipo %d -",mydata->equipo_param);
	fputs (cad1,salida);
	// uso sleep para simular que que pasa tiempo
	usleep (30000);
	// doy la señal a la siguiente accion
   	 sem_post (& mydata-> semaforos_param . sem_mezclarHuevo );
}

void * mezclarHuevo(void *datos){
	char *accion = "mezclarHuevo";
	struct parametro *mydata = datos;
	sem_wait (&mydata-> semaforos_param . sem_mezclarHuevo);
	printf("\tEquipo %d -",mydata->equipo_param);
	puts(cad2);
	//guardo en el archivo de salida
	fprintf(salida,"\tEquipo %d -",mydata->equipo_param);
	fputs (cad2,salida);
	usleep (3000);
	sem_post(&mydata-> semaforos_param . sem_salar);
}

void *salar (void *datos){
	char *accion = "salar";
	struct parametro *mydata = datos;
	sem_wait (&mydata-> semaforos_param . sem_salar);
	sem_wait (&sem1);
	printf("\tEquipo %d -",mydata->equipo_param);
	puts(cad3);
	//guardo en el archivo de salida
	fprintf(salida,"\tEquipo %d -",mydata->equipo_param);
	fputs (cad3,salida);
	usleep (20000);
	printf("\tEquipo %d -",mydata->equipo_param);
	puts(cad4);
	//guardo en el archivo de salida
	fprintf(salida,"\tEquipo %d -",mydata->equipo_param);
	fputs (cad4,salida);
	sem_post(&sem1);
	sem_post (&mydata-> semaforos_param . sem_agregarCarne);
}

void *agregarCarne (void * datos){
	char *accion = "agregarCarne";
	struct parametro *mydata = datos;
	sem_wait (&mydata-> semaforos_param . sem_agregarCarne);
	printf("\tEquipo %d -",mydata->equipo_param);
	puts(cad5);
	fprintf(salida,"\tEquipo %d -",mydata->equipo_param);
	fputs (cad5,salida);
	usleep(20000);
	sem_post (&mydata-> semaforos_param . sem_empanar);

}

void *empanar (void *datos){
	char *accion = "empanar";
	struct parametro * mydata = datos;
	sem_wait(&mydata-> semaforos_param . sem_empanar);
	printf("\tEquipo %d -",mydata->equipo_param);
	puts(cad6);
	fprintf(salida,"\tEquipo %d -",mydata->equipo_param);
	fputs (cad6,salida);
	usleep(40000);
	sem_post(&mydata-> semaforos_param . sem_fritar);

}

void *fritar(void *datos){
	char * accion = "fritar";
	struct parametro *mydata = datos;
	sem_wait (&mydata-> semaforos_param . sem_fritar);
	sem_wait (&sem2);
	printf("\tEquipo %d -",mydata->equipo_param);
	puts(cad7);

	fprintf(salida,"\tEquipo %d -",mydata->equipo_param);
	fputs (cad7,salida);
	usleep(5);
	printf("\tEquipo %d -",mydata->equipo_param);
	puts(cad8);
	fprintf(salida,"\tEquipo %d -",mydata->equipo_param);
	fputs (cad8,salida);
	sem_post (&sem2);
	sem_post (&mydata-> semaforos_param . sem_hornear);

}

void *hornear(void *datos){
	char *accion = "hornear";
	struct parametro *mydata = datos;
	sem_wait (&mydata-> semaforos_param . sem_hornear);
	sem_wait (&sem3);
	printf("\tEquipo %d -", mydata->equipo_param);
	puts(cad9);
	fprintf(salida,"\tEquipo %d -",mydata->equipo_param);
	fputs (cad9,salida);
	usleep(50000);
	printf("\tEquipo %d -",mydata->equipo_param);
	puts(cad10);
	fprintf(salida,"\tEquipo %d -",mydata->equipo_param);
	fputs (cad10,salida);
	sem_post(&sem3);
	sem_post(&sem3);
	sem_post (&mydata-> semaforos_param . sem_prepararExtras);

}
void *prepararExtras (void *datos){
	char *accion = "preparar";
	struct parametro *mydata = datos;
	sem_wait (&mydata-> semaforos_param.sem_prepararExtras);
	printf("\tEquipo %d -",mydata->equipo_param);
	usleep (6);
	puts(cad11);
	fprintf(salida,"\tEquipo %d -",mydata->equipo_param);
	fputs (cad11,salida);
	sem_post (&mydata-> semaforos_param . sem_armar);

}
void *armarSandwich (void * datos){
	char *accion = "armar";
	struct parametro * mydata = datos;
	sem_wait (&mydata-> semaforos_param . sem_armar);
	printf("\tEquipo %d -",mydata->equipo_param);
	puts(cad12);
	fprintf(salida,"\tEquipo %d -",mydata->equipo_param);
	fputs (cad12,salida);
	usleep(50000);

	pthread_exit(NULL);
}
void * ejecutarReceta ( void *i) {

	//leo la receta
	FILE *receta;
	receta = fopen ("RECETA.txt","rt"); // con "rt" abro el archivo para leer
	fgets (cad1, LIMITE, receta);
    	fgets (cad2, LIMITE, receta);
    	fgets (cad3, LIMITE, receta);
	fgets (cad4, LIMITE, receta);
	fgets (cad5, LIMITE, receta);
	fgets (cad6, LIMITE, receta);
	fgets (cad7, LIMITE, receta);
	fgets (cad8, LIMITE, receta);
	fgets (cad9, LIMITE, receta);
	fgets (cad10, LIMITE, receta);
	fgets (cad11, LIMITE, receta);
	fgets (cad12, LIMITE, receta);

	fclose(receta);

	salida = fopen ("Salida","a");
	//variables semaforos
	//crear variables semaforos aqui
	sem_t sem_mezclarHuevo;
	sem_t sem_salar;
    	sem_t sem_agregarCarne;
    	sem_t sem_empanar;
   	sem_t sem_fritar;
    	sem_t sem_hornear;
	sem_t sem_prepararExtras;
    	sem_t sem_armar;

	//variables hilos
	pthread_t p1;
	pthread_t p2;
	pthread_t p3;
	pthread_t p4;
	pthread_t p5;
	pthread_t p6;
	pthread_t p7;
	pthread_t p8;
	pthread_t p9;

	// crear variables hilos aqui

	// numero del equipo (casteo el puntero a un int)
	int p = *(( int *) i);

	printf ( "Ejecutando equipo %d \n " , p);

	// reservo memoria para el struct
	struct parametro *pthread_data = malloc (sizeof(struct parametro));

	// seteo los valores al estructura

	// seteo numero de grupo
	pthread_data-> equipo_param = p;

	// seteo semaforos
	// setear demas semaforos al struct aqui
	pthread_data-> semaforos_param.sem_mezclarHuevo = sem_mezclarHuevo;
	pthread_data-> semaforos_param.sem_salar = sem_salar;
	pthread_data-> semaforos_param.sem_agregarCarne = sem_agregarCarne;
	pthread_data-> semaforos_param.sem_empanar = sem_empanar;
	pthread_data-> semaforos_param.sem_fritar = sem_fritar;
	pthread_data-> semaforos_param.sem_hornear= sem_hornear;
	pthread_data-> semaforos_param.sem_prepararExtras = sem_prepararExtras;
	pthread_data-> semaforos_param.sem_armar = sem_armar;



	sem_init (&(pthread_data-> semaforos_param . sem_mezclarHuevo),0,0);
	// inicializar demas semaforos aqui
	sem_init (&(pthread_data-> semaforos_param . sem_salar),0,0);
	sem_init (&(pthread_data-> semaforos_param . sem_agregarCarne),0,0);
	sem_init (&(pthread_data-> semaforos_param . sem_empanar),0,0);
	sem_init (&(pthread_data-> semaforos_param . sem_fritar),0,0);
	sem_init (&(pthread_data-> semaforos_param . sem_hornear),0,0);
	sem_init (&(pthread_data-> semaforos_param . sem_prepararExtras),0,0);
	sem_init (&(pthread_data-> semaforos_param . sem_armar),0,0);


	// creo los hilos a todos les paso el struct creado (el mismo a todos los hilos) ya que todos comparten los semaforos
   	 int rc;
   	rc = pthread_create (& p1,                            // identificador unico
  	                     NULL ,                           // atributos del hilo
   	                            cortar,              // funcion a ejecutar
	                           pthread_data);                     // parametros de la funcion a ejecutar, pasado por referencia
	// crear demas hilos aqui
	rc = pthread_create(&p2, NULL, mezclarHuevo, pthread_data);
	rc = pthread_create(&p3, NULL, salar, pthread_data);
	rc = pthread_create(&p4, NULL, agregarCarne, pthread_data);
	rc = pthread_create(&p5, NULL, empanar, pthread_data);
	rc = pthread_create(&p6, NULL, fritar, pthread_data);
	rc = pthread_create(&p7, NULL, hornear, pthread_data);
	rc = pthread_create(&p8, NULL, prepararExtras, pthread_data);
	rc = pthread_create(&p9, NULL, armarSandwich, pthread_data);




	// join de todos los hilos
	pthread_join (p1, NULL );
	pthread_join (p2, NULL );
	pthread_join (p3, NULL );
	pthread_join (p4, NULL );
	pthread_join (p5, NULL );
	pthread_join (p6, NULL );
	pthread_join (p7, NULL );
	pthread_join (p8, NULL );
	pthread_join (p9, NULL );


	// crear unir de demas hilos


	// valido que el hilo se alla creado bien
    	if (rc) {
      	   printf ( "Error: no se puede crear el hilo, %d \n " , rc);
      	    exit (-1);
   	}


	// destruccion de los semaforos
	sem_destroy (&sem_mezclarHuevo);
	sem_destroy (&sem_salar);
	sem_destroy (&sem_agregarCarne);
	sem_destroy (&sem_empanar);
	sem_destroy (&sem_fritar);
	sem_destroy (&sem_hornear);
	sem_destroy (&sem_prepararExtras);
	sem_destroy (&sem_armar);

	// destruir demas semaforos
	//salida del hilo

	 pthread_exit (NULL);

}


int  main ()
{
	//iniciliazo los semaforos compartidos
		sem_init(&sem1,0,1);
		sem_init(&sem2,0,1);
		sem_init(&sem3,0,2);

	// creo los nombres de los equipos
	int rc;
	int *equipoNombre1 = malloc ( sizeof (*equipoNombre1));
	int *equipoNombre2 = malloc ( sizeof (*equipoNombre2));
	int *equipoNombre3 = malloc (sizeof (*equipoNombre3));
	int *equipoNombre4 = malloc (sizeof (*equipoNombre4));
	// faltan equipos

	*equipoNombre1 = 1 ;
	*equipoNombre2 = 2 ;
	*equipoNombre3 = 3;
	*equipoNombre4 = 4;

	// creo las variables los hilos de los equipos
	pthread_t equipo1;
	pthread_t equipo2;
	pthread_t equipo3;
	pthread_t equipo4;
	// faltan hilos

	// inicializo los hilos de los equipos
   	 rc = pthread_create (& equipo1,                            // identificador unico
                            NULL ,                           // atributos del hilo
                                ejecutarReceta,              // funcion a ejecutar
                                equipoNombre1);

   	 rc = pthread_create (& equipo2,                            // identificador unico
                            NULL ,                           // atributos del hilo
                                ejecutarReceta,              // funcion a ejecutar
                                equipoNombre2);
  	// faltan inicializaciones
  	 rc = pthread_create(&equipo3, NULL, ejecutarReceta, equipoNombre3);
	 rc = pthread_create(&equipo4, NULL, ejecutarReceta, equipoNombre4);



       if (rc) {
          printf ( " Error: no se puede crear el hilo, %d  \n " , rc);
          exit (-1);
       }
	// join de todos los hilos
	pthread_join (equipo1, NULL );
	pthread_join (equipo2, NULL );
	pthread_join (equipo3, NULL);
	pthread_join (equipo4, NULL);
	// .. faltan se une


    	pthread_exit(NULL);
}


// Para compilar: gcc subwayArgento.c -o ejecutable -lpthread
// Para ejecutar: ./ejecutable
