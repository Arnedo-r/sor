# SOR-Semáforos-1S-2021
Trabajo Práctico Semáforos primer semestre año 2021
INFORME - Arnedo Rocío 

Ejercicio Subway Argento
En la cocina de Subway Argento compiten cuatro equipos de cocineros para ganarse el puesto de trabajo en el local. ¿Quién será el primero en entregar 1 sándwich de milanesa terminado, de 15 cm, al dueño del local?
La dificultad de la competencia es que la cocina no cuenta con el equipamiento individual para cada equipo, sino que algunos de ellos son compartidos. Se tienen que ordenar para cocinar las milanesas ya que solo tienen un sartén para todos los equipos y este cocina una milanesa a la vez, existo solo un horno que cocina dos panes a la vez y un solo salero. ¿Cómo se arma un sándwich de milanesa?
Para armar un sándwich necesito cortar 2 dientes de ajo y un puñado de perejil, para luego mezclarlos con 1 huevo. Después utilizar sal a gusto, agregar la carne y luego empanar las milanesas. Una vez que tengo todo armado se cocinan por 5’ en el sartén bien caliente. Como corresponde una buena milanesa tiene panes recién horneados (por 10’ aproximadamente) junto a lechuga fresca, tomate, cebolla morada y pepino recién cortados Finalmente puedo armar el sándwich con todos los ingredientes.

PSEUDOCODIGO:

creo estructura de semaforos
	 sem_mezclarHuevo;
 	 sem_salar;
     	sem_agregarCarne;
     	sem_empanar;
    	sem_fritar;
     	sem_hornear;
     	sem_armar;
imprimirAccion( ) {
	declaro un fichero;
	fichero = fopen ( "Salida", "a");
	-
	-
	-
	-
	controlo,imprimo por consola yguardo en archivo cada accion e ingrediente.
}
// creo funciones de cada accion de la receta .
cortar( ){
imprimirAccion( )
sleep( )
V (sem_mezclarHuevo)
}

P(sem_mezclarHuevo)
mezclarHuevo( ){
imprimirAccion( )
sleep ( )
V (sem_salar)
}

P(sem_salar)
salar ( ){
imprimirAccion( )
sleep ( )
V(sem_agregarCarne)
}
P(sem_agregarCarne)
agregarCarne ( ){
imprimirAccion ( )
sleep ( )
V(sem_empanar)
}
P(sem_empanar )
empanar ( ){
imprimirAccion ( )
sleep ( )
V (sem_fritar)
}
P(fritar)
fritar( ){
imprimirAccion ( )
sleep ( )
V(sem_armar)
}
P(sem_hornear)
P(sem_hornear)
hornear ( ){
imprimirAccion  ( )
sleep ( )
V (sem_armar)
}
prepararExtras ( ){
imprimirAccion ( )
sleep ( )
V (sem_armar)
}
P(sem_armar)
P(sem_armar)
P(sem_armar)
armarSandwich ( ){
imprimirAccion( )
}

Creo variables de hilos para cada semaforo
Creo variables de semaforos
-
-
-
-
Para leer la receta desde un archivo:

declaro un archivo;
receta = fopen ("RECETA.txt","r"); 	// con "r" abro el archivo para leerlo
char car [cantidad de caracteres que leerá];
int k = 0;
mientras( no llegue al final del archivo){
	Leo una línea del texto
	paso la accion número k
	int j = 0;
	mientras (no llegue al final de la línea){
		paso la accion nro k y el ingrediente j;
	incremeto el valor j++;
	}
	incremento el valor de k++;
}

inicializo los semaforos

 	sem_mezclarHuevo = 0	
 	 sem_salar = 1		solo pueden usar el salero 1 equipo a la vez
     	sem_agregarCarne = 0
     	sem_empanar = 0
    	sem_fritar = 1		solo pueden fritar 1 equipo a la vez
     	sem_hornear = 2		solo pueden hornear 2 panes a la vez
     	sem_armar = 0

creo hilo de cada funcion 

join de todos los hilos

destruccion de los semaforos

main ( ){
	creo los nombres de los equipos

	creo variables de los hilos de cada equipo 
	inicializo cada hilo

	cierro hilos
	pthread_exit(NULL);
}









   
