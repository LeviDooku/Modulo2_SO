///////////////////////////
//Pedro Velasco Santana  //
//S3 - Módulo II (SO)    //
///////////////////////////

/*
Ejercicio 3:

Indica qué tipo de jerarquías de procesos se generan mediante la ejecución de cada
uno de los siguientes fragmentos de código. Comprueba tu solución implementando un código
para generar 20 procesos en cada caso, en donde cada proceso imprima su PID y el del padre,
PPID.
*/

#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>

int main(){

    const int nprocs = 20;
    pid_t childpid;

    //Jerarquía de procesos del primer tipo

    for(int i = 1; i < nprocs; i++){
        if ((childpid = fork()) == -1){
            fprintf(stderr, "Could not create child %d\n",i);
            exit(-1);
        }

        if(childpid)
            break;

        printf("\n[+] PROCESO %d:\n PID = %d, PPID = %d\n", i, getpid(), getppid());
    }

    //Jerarquía de procesos del segundo tipo

    for(int i = 1; i < nprocs; i++){
        if ((childpid = fork()) == -1){
            fprintf(stderr, "Could not create child %d\n",i);
            exit(-1);
        }

        if(!childpid)
            break;

        printf("\n[+] PROCESO %d:\n PID = %d, PPID = %d\n", i, getpid(), getppid());
    }
}