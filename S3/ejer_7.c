///////////////////////////
//Pedro Velasco Santana  //
//S2 - Módulo II (SO)    //
///////////////////////////

/*
Ejercicio 7:

Escribe un programa que acepte como argumentos el nombre de un programa, sus
argumentos si los tiene, y opcionalmente la cadena “bg”. Nuesto programa deberá ejecutar el
programa pasado como primer argumento en foreground si no se especifica la cadena “bg” y en
background en caso contrario. Si el programa tiene argumentos hay que ejecutarlo con éstos.
*/

#include<sys/types.h>	
#include<sys/wait.h>	
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){

    if(argc < 2){
        printf("[-] Número de argumentos incorrecto\n");
        printf("USO: %s <programa> [<arg[1]...arg[n]>] [bg]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pid_t pid;
    int estado;

    if((pid = fork()) < 0){
        perror("\nError en el fork");
	    exit(EXIT_FAILURE);
    }
    else if(pid == 0){
        if(argc > 2 && strcmp(argv[argc - 1], "bg") == 0){
            argv[argc - 1] = NULL;
            execvp(argv[1], &argv[1]);
        }
        else{
            if(execvp(argv[1], &argv[1]) != 0){
                perror("[-] ERROR EN EXECVP");
                exit(EXIT_FAILURE);
            }
        }
    }
    else{
        if(argc == 2 ||(argc > 2 && strcmp(argv[argc-1], "bg") != 0))
            wait(NULL);
    }
}