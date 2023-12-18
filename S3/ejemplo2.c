///////////////////////////
//Pedro Velasco Santana  //
//S2 - Módulo II (SO)    //
///////////////////////////

//Progra que obtiene el uid real y efectivo (euid) y el gid real y efectivo (gid) 

#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main(void){

    printf("Identificador del proceso de usuario real (UID): %d\n", getuid());
    printf("Identificador del proceso de usuario efectivo (EUID): %d\n", geteuid());
    printf("Identificador del proceso de grupo real (GID): %d\n", getgid());
    printf("Identificador del proceso de grupo efectivo (EGID): %d\n", getegid());
}