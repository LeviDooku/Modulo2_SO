///////////////////////////
//Pedro Velasco Santana  //
//S2 - Módulo II (SO)    //
///////////////////////////

//Programa que obtiene el PID de un proceso y su proceso padre

#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main(void){

    //Variables para almacenar los proceso
    pid_t id_proceso;
    pid_t id_padre;

    id_proceso = getpid();  //Obtención del PID del proceso que ejecuta el programa
    id_padre = getppid();   //Y su proceso padre

    printf("Identificador de proceso: %d\n", id_proceso);
    printf("Identificador de proceso padre: %d\n", id_padre);

    //También es válido:

    //printf("Identificador de proceso: %d\n", getpid());
    //printf("Identificador de proceso padre: %d\n", getppid());
}