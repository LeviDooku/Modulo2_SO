///////////////////////////
//Pedro Velasco Santana  //
//S3 - Módulo II (SO)    //
///////////////////////////

/*
Ejercicio 4:

Implementa un programa que lance cinco procesos hijo. Cada uno de ellos se
identificará en la salida estándar, mostrando un mensaje del tipo Soy el hijo PID. El proceso
padre simplemente tendrá que esperar la finalización de todos sus hijos y cada vez que detecte
la finalización de uno de sus hijos escribirá en la salida estándar un mensaje del tipo:
Acaba de finalizar mi hijo con <PID>
Sólo me quedan <NUM_HIJOS> hijos vivos

*/

#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>

int main(){

    pid_t pid_hijo;
    int estado;
    const int num_procesos = 5;
    int num_hijos_vivos = num_procesos;

    for(int i = 0; i < num_procesos; i++){
        if ((pid_hijo = fork()) == -1){
            fprintf(stderr, "[-] No se pudo crear un hijo %d\n",i);
            exit(-1);
        }

        if(pid_hijo == 0){
            printf("\n[+] Soy el hijo <%d>, mi padre es <%d>\n", getpid(), getppid());
            exit(0);
        }
    }

    for(int i = 0; i < num_procesos; i++){
        pid_t hijo_terminado = wait(&estado);
        num_hijos_vivos--;
        printf("\n[-] Proceso hijo con PID <%d> finalizó.\n QUEDAN %d HIJOS VIVOS \n", hijo_terminado, num_hijos_vivos);   
    }

    return 0;
}