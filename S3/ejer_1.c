///////////////////////////
//Pedro Velasco Santana  //
//S3 - Módulo II (SO)    //
///////////////////////////

/*
Ejercicio 1:

Implementa un programa en C que tenga como argumento un número entero. Este
programa debe crear un proceso hijo que se encargará de comprobar si dicho número es un
número par o impar e informará al usuario con un mensaje que se enviará por la salida estándar.
A su vez, el proceso padre comprobará si dicho número es divisible por 4, e informará si lo es o
no usando igualmente la salida estándar.
*/

#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>

int es_par;
int es_divisible;

int main(int argc, char *argv[]){

    //Filtro de argumentos
    if(argc != 2){
        printf("[-] ERROR en el número de argumentos\n Uso: <número_entero>\n");
        exit(EXIT_FAILURE);
    }

    int num_entero = atoi(argv[1]);
    pid_t pid;

    if((pid = fork()) < 0){
        perror("[-] ERROR en fork");
        exit(EXIT_FAILURE);
    }
    else if(pid == 0){ //Proceso hijo comprueba si es par o impar
        es_par = ((num_entero % 2) != 0) ? 1 : 0;
        if(es_par == 0)
            printf("Proceso hijo (PID = %d):\n %d es par\n\n", getpid(), num_entero);
        else
            printf("Proceso hijo (PID = %d):\n %d es impar\n\n", getpid(), num_entero);
    }
    else{ //Proceso padre comprueba si es divisible entre 4
        //sleep(1); Como no se accede a la misma variable global, podemos omitir la espera ociosa
        es_divisible = ((num_entero % 4) != 0) ? 1 : 0;
        if(es_divisible == 0)
            printf("Proceso padre (PID = %d):\n %d es divible entre 4\n\n", getpid(), num_entero);
        else
            printf("Proceso padre (PID = %d):\n %d es indivisible entre 4\n\n", getpid(), num_entero);
    }    

    return 0;
}