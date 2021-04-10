/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 *
 * Fecha: 6 de octubre de 2019, 12:56
 * Este programa crea un patrón triángulo con una altura dada.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int altura, i, x; 
    
    printf("Introduzca la altura deseada del triángulo:\n");
    scanf("%d", &altura);
    printf("\n");
    
    x=1;
    for(i=1; i<=altura; i++){
        for (x=1; x<=i; x++){
            printf("%d", x);
        }
        printf("\n");
    }
    return (EXIT_SUCCESS);
}

