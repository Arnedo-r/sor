# sor

Trabajo Práctico Semáforos primer semestre año 2021
INFORME - Arnedo Rocío


![img](https://github.com/Arnedo-r/sor/blob/37e1822275450e23107264c7c1660d667d714629/img.png)

##Consigna del Trabajo Práctico
En la cocina de *Subway Argento* compiten cuatro equipos de cocineros para ganarse el puesto de trabajo en el local. ¿Quién será el primero en entregar 1 sándwich de milanesa terminado, de 15 cm, al dueño del local?
La dificultad de la competencia es que la cocina no cuenta con el equipamiento individual para cada equipo, sino que algunos de ellos son compartidos. Se tienen que ordenar para cocinar las milanesas ya que solo tienen un sartén para todos los equipos y este cocina una milanesa a la vez, existe solo un horno que cocina dos panes a la vez y un solo salero. ¿Cómo se arma un sándiwch de milanesa?**
Para armar un sandwich de milanesa necesito cortar 2 dientes de ajo y un puñado de perejil, para luego mezclarlos con 1 huevo. Después de utilizar sal a gusto, agregar la carne y luego empanar las milanesas. Una vez que tengo todo armado se cocinan por 5' en el sartén bien caliente.
Como corresponde una buena milanesa tiene panes recién horneados (por 10' aproximadamente) junto a lechuga fresca, tomate, cebolla morada y pepino recién cortados. 
Finalmente puedo armar el sándwich con todos los ingredientes.


##PSEUDOCODIGO 
*creo las  variables donde voy a guardar cada string de acción de la receta*
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

*creo estructura de semáforos*
	sem_mezclarHuevo;
	sem_salar;
	sem_agregarCarne;
	sem_empanar;
	sem_fritar;
	sem_hornear;
	sem_armar;

*por otro lado, creo los semáforos que serán compartidos entre el salero, la sarten y el horno*
	sem_t sem1;
	sem_t sem2;
	sem_t sem3;

*creo una variable de tipo FILE que llamo salida, para luego poder guardar las acciones en el archivo .txt*
FILE * salida;

*creo las funciones de cada acción de la receta*
cortar(){
creo el nombre de la acción
realizo printf para imprimir por pantalla la acción que se está realizando,  y con un fprintf lo guardo en el archivo. 
Con puts guardo en la variable pasada como parametro el string que se va a mostrar en pantalla.ss
V(sem_mezclarHuevo)
}
mezclarHuevo(){
P(sem_mezclarHuevo)
realizo lo mismo que en la funcion cortar.
V(sem_salar)
}
 salar(){
 P(sem_salar)
 P(sem1)
 realizo lo mismo que en las funciones anteriores
 V(sem1)              //lo vuelvo a señalizar para que otro equipo use el salero
 V(sem_agregarCarne)
}
agregarCarne(){
 P(sem_agregarCarne)
 realizo lo mismo que en las funciones anteriores
 V(sem_empanar)
}
empanar(){
 P(sem_empanar)
 realizo lo mismo que en las funciones anteriores
 V(sem_fritar)
}
fritar(){
 P(sem_fritar)
 P(sem2)
 realizo lo mismo que en las funciones anteriores
 V(sem2)                //lo vuelvo a señalizar, para que otro equipo use la sarten
 V(sem_hornear)
}
hornear(){
 P(sem_hornear)
 P(sem3)
 realizo lo mismo que en las funciones anteriores
 V(sem3)                //lo vuelvo a señalizar, para que otro equipo use el horno
 V(sem_prepararExtras)
}
prepararExtras(){
 P(sem_prepararExtras)
 realizo lo mismo que en las funciones anteriores
 V(sem_armar)             
}
armarSandwich(){
  P(sem_armar)
  realizo lo mismo que en las funciones anteriores.
}

ejecutaRecetar(){
  *código para leer la receta:*
  FILE *receta;
  receta = fopen ("RECETA.txt","rt") 
  con fopen abro el fichero y con "rt" leo el archivo.
  Luego con fgets , leo cada string de la receta, pasada por parametro.
  
  fclose(receta); cierro el archivo.
  
  salida = fopen ("Salida","a")
  con "a" creo y abro el archivo Salida para escribir al final del mismo lo que se imprime por pantalla.
  
  Creo las variables semáforos
  Creo las variables hilos
  Seteo los semaforos
  Inicializo los semaforos
  Creo los gilos para cada funcion
  Realizo los join de cada hilo
  Destruyo los semaforos
  
 main(){
  inicializo los semaforos compartidos
    sem1= 1
    sem2 = 1
    sem3 = 1
   Los señalizo para que esten listo para que el primer equipo que quiera realizar la acción pueda hacerlo.
   
   creo los nombres de los equipos
   creo las variables de los equipos
   creo los hilos que usaré para cada equipo
   inicializo cada hilo
   realizo join de todos los hilos
   y por ultimo, los cierro. 

  






