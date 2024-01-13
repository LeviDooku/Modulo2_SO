//tarea4.c
//Trabajo con llamadas al sistema del Subsistema de Procesos "POSIX 2.10 compliant"
//Prueba el programa tal y como está. Después, elimina los comentarios (1) y pruebalo de nuevo.

#include<sys/types.h>	//Primitive system data types for abstraction of implementation-dependent data types.
						//POSIX Standard: 2.6 Primitive System Data Types <sys/types.h>
#include<unistd.h>		//POSIX Standard: 2.10 Symbolic Constants         <unistd.h>
#include<stdio.h>
#include<errno.h>
#include <stdlib.h>

int global=6;
char buf[]="Usando fork\n";

int main(int argc, char *argv[])
{
int var;
pid_t pid;

var=88;

//Se escribe por la terminal el contenido de buf
if(write(STDOUT_FILENO,buf,sizeof(buf)) != sizeof(buf)) {
	perror("\nError en write");
	exit(EXIT_FAILURE);
}

//Este condicional consigue que el comportamiento de la salida estándar sea no bufer
if(setvbuf(stdout,NULL,_IONBF,0)) {
	perror("\nError en setvbuf");
}

//También podríamos omitir el condicional anterior y poner un \n al final xddd (\n vacía el búfer)

printf("\nMensaje previo a la ejecución de fork\n");

//Si el entero devuelto es <0, fork() ha fallado

if( (pid=fork())<0) {
	perror("\nError en el fork");
	exit(EXIT_FAILURE);
}
else if(pid==0) {  //Si el pid = 0, el proceso hijo está ejecutando
	//proceso hijo ejecutando el programa, no hay tiempo de espera
	global++;
	var++;
} else { //proceso padre ejecutando el programa
	sleep(1); //Duerme un segundo y ejecuta las líneas inferiores
	var = 33;
	global = 2;
}	
printf("\npid= %d, global= %d, var= %d\n", getpid(),global,var);
exit(EXIT_SUCCESS);
}
