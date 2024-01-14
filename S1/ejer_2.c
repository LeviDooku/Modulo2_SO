///////////////////////////
//Pedro Velasco Santana  //
//S1 - Módulo II (SO)    //
///////////////////////////

/*
Ejercicio 2: 

Implementa un programa que realice la siguiente funcionalidad. El programa
acepta como argumento el nombre de un archivo (pathname), lo abre y lo lee en bloques de
tamaño 80 Bytes, y crea un nuevo archivo de salida, salida.txt, en el que debe aparecer la
siguiente información
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const int TAM_BLOQUE = 80;

int main(int argc, char *argv[]){
    
    //Filtro argumentos
    
    if (argc != 2) {
        fprintf(stderr, "[-] número de argumentos incorrecto.\n"
                        "uso: %s <input>\n", argv[0]);
        exit(-1);
    }

    char *input_file = argv[1];
    char *output_file = "salida.txt";

    char buf[TAM_BLOQUE];
    int  fd_input, fd_output;

    //APERTURA Y CREACIÓN DE ARCHIVOS (INPUT Y OUTPUT)

    if((fd_input = open(input_file, O_RDONLY)) < 0){
        printf("\n[-] ERROR: apertura fichero argumento", errno);
        perror("\n[-] ERROR EN (1er) OPEN");
        exit(-1);
    }

    if((fd_output = open(output_file, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR)) < 0){
        printf("\n[-] ERROR: apertura fichero salida", errno);
        perror("\n[-] ERROR EN (2o) OPEN");
        exit(-1);
    }

    //LECTURA DE BLOQUES

    int leido;
    int num_bloque = 0;

    //Mientras queden datos por leer (si read devuelve 0, se ha llegado al final, no quedan bytes por leer)
    //Se guardan en el buffer un bloque sacado de fd_input
    while((leido = read(fd_input, buf, TAM_BLOQUE)) > 0){
        printf("\nEscritura del bloque: %d...", num_bloque);

        dprintf(fd_output, "Bloque: %d\n", num_bloque);

        write(fd_output, buf, TAM_BLOQUE);

        dprintf(fd_output, "\n\n");

        num_bloque++;

        printf("\n[+] CORRECTA");
    }

    close(fd_input);
    close(fd_output);

    return 0;
}