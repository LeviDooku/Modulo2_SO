///////////////////////////
//Pedro Velasco Santana  //
//S1 - Módulo II (SO)    //
///////////////////////////

/*
Ejericio 1: 

¿Qué hace el siguiente programa? Probar tras la ejecución del programa las siguientes órdenes
cat archivo 
od -c archivo

gcc ejer_1.c -o prueba
*/

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>  // Para la función exit
#include<unistd.h> // Para write, lseek, close

char buf1[]="abcdefghij"; // 1 char = 1 byte
char buf2[]="ABCDEFGHIJ";

int main(int argc, char *argv[]){
    int fd; //entero para almacenar el descriptor de fichero

    /*
    OPEN

    El descriptor de fichero siempre tiene que ser un entero no negativo.

    Si el descriptor de fichero es negativo, ha habido un error al abrir el archivo

    La función open devuelve el descriptor de fichero

    Parámetros de open:
    - "archivo" será el directorio del fichero a crear
    - O_CREAT es el flag de creación de archivo
    - O_TRUNC trunca el tamaño a 0
    - S_IRUSR el usuario puede leer
    - O_WRONLY es el flag de solo escritura
    - S_IWUSR el usuario puede escribir
    */

    if( (fd=open("archivo",O_CREAT|O_TRUNC|O_WRONLY,S_IRUSR|S_IWUSR))<0) {
        printf("\nError %d en open",errno);
        perror("\nError en open");
        exit(-1);
    }

    /*
    1er WRITE

    La función write devuelve el tamaño de bytes que se han escrito.

    Si el contenido de bytes escrito es diferente del esperado, salta un error

    Parámetros de write:
    - fd: el descriptor de fichero
    - buf1: la cadena de caracteres a escribir
    - 10: tamaño de los bytes a escribir
    */

    if(write(fd,buf1,10) != 10) {
        perror("\nError en primer write");
        exit(-1);
    }

    /*
    LSEEK

    La función lseek devuelve -1 en caso de error

    Parámetros lseek:
    - fd: descriptor de fichero
    - 40: desplazamiento de bytes. EL puntero se moverá 40 bytes desde punto de referencia
    - SEEK_SET: punto de referencia desde el que se aplicará el desplazamiento
    */

    if(lseek(fd,40,SEEK_SET) < 0) {
        perror("\nError en lseek");
        exit(-1);
    }

    //Se escribe la segunda cadena de caracteres (buf2)

    if(write(fd,buf2,10) != 10) {
        perror("\nError en primer write");
        exit(-1);
    }

    close(fd);

    printf("TODO CORRECTO\n");
    return 0;
}