///////////////////////////
//Pedro Velasco Santana  //
//S1 - Módulo II (SO)    //
///////////////////////////

/*
Ejercicio 4:

Define una macro en lenguaje C que tenga la misma funcionalidad que la macro
S_ISREG(mode) usando para ello los flags definidos en <sys/stat.h> para el campo st_mode de
la struct stat, y comprueba que funciona en un programa simple. Consulta en un libro de C o
en internet cómo se especifica una macro con argumento en C.
#define S_ISREG2(mode) ...
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define S_ISREG2(mode) (((mode) & S_IFMT) == S_IFREG)

int main(int argc, char *argv[])
{
    // test de la macro
    struct stat attr;
    lstat(argv[1], &attr);
    printf("Fichero regular? %s\n", (S_ISREG2(attr.st_mode) ? "Sí" : "No"));
    
    return 0;
}