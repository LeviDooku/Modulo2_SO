///////////////////////////
//Pedro Velasco Santana  //
//S2 - Módulo II (SO)    //
///////////////////////////

/*
Ejercicio 2:

Realiza un programa en C utilizando las llamadas al sistema necesarias que acepte
como entrada:

• Un argumento que representa el 'pathname' de un directorio.
• Otro argumento que es un número octal de 4 dígitos (similar al que se puede utilizar
para cambiar los permisos en la llamada al sistema chmod). Para convertir este argumento
tipo cadena a un tipo numérico puedes utilizar la función strtol. Consulta el manual en
línea para conocer sus argumentos.

El programa tiene que usar el número octal indicado en el segundo argumento para cambiar los
permisos de todos los archivos que se encuentren en el directorio indicado en el primer
argumento.

El programa debe proporcionar en la salida estándar una línea para cada archivo del directorio
que esté formada por:
<nombre_de_archivo> : <permisos_antiguos> <permisos_nuevos>

Si no se pueden cambiar los permisos de un determinado archivo se debe especificar la siguiente
información en la línea de salida:
<nombre_de_archivo> : <errno> <permisos_antiguos>
*/


#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>

int main(int argc, char *argv[]){

    //Filtro para el número de argumentos 
    if(argc != 3){
        printf("[-] Número de argumentos incorrecto\n");
        printf("USO: <nombre_directorio> <máscara_octal_4D>");
        exit(EXIT_FAILURE);
    }

    //Se pasa el segundo argumento a octal usando strtol
    long int mask;
    mask = strtol(argv[2], NULL, 8);

    if(mask == 0 && argv[2] != 0){
        printf("[-] Error en strtol\n");
        perror("ERROR EN STRTOL");
        exit(EXIT_FAILURE);
    }

    //Variable DIR que almacena el stream del directorio
    DIR *directorio;

    directorio = opendir(argv[1]);

    //Se comprueba si el argumento es correcto y la función opendir ha funcionado
    if(directorio == NULL){
        printf("[-] Error en opendir\n NO se puede acceder a (%s) o no hay memoria suficiente\n", argv[1]);
        perror("ERROR EN OPENDIR");
        exit(EXIT_FAILURE);
    }

    struct dirent *dir_struct; //Para almacenar la estructura dirent
    struct stat atributos;  //Para almacenar los atributos del archivo (directorio)
    unsigned int permisos_antiguos;

    const unsigned long TAM_NOMBRE = strlen(argv[0]) - 2; //IMPORTANTE: se le resta 2 para no contar "./"
    char nombre[TAM_NOMBRE]; 
    char *nombre_programa = &argv[0][2]; //Empieza en el 3er caracter. (./ejecutable)
    sprintf(nombre, "%.*s", (int)TAM_NOMBRE, nombre_programa); //Se copia el nombre en la cadena nombre

    int i = 0;
    for(errno = 0; (dir_struct = readdir(directorio)) != NULL; errno = 0, i++){
        if(errno != 0){
            printf("[-] Error en la lectura de directorio");
            printf("ERROR EN READDIR");
            exit(EXIT_FAILURE);
        }

        if(strcmp(dir_struct->d_name, ".") != 0 && strcmp(dir_struct->d_name, "..") != 0 && strcmp(dir_struct->d_name, nombre)){
            if(lstat(dir_struct->d_name, &atributos) < 0){ //Se comprueba si la obtención de metadatos es correcta
                printf("[-] Error en la obtención de metadatos de %s", dir_struct->d_name);
                printf("ERROR EN LSTAT");
            }
        }
    }









}