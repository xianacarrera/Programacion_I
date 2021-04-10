/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 *
 * Data: 14 de outubro de 2019, 15:26
 * Este programa imprime unha palabra dada ao revés.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */

void revespal(char pal[])   
{
    int i;
   
    for (i=strlen(pal)-1; i>=0; i--){     
        printf("%c", pal[i]);               
    }              
    
    /* Como strlen é unha unidade maior que a última posición ocupada do vector,
     * o bucle comeza en strlen(pal)-1, e vai recorrendo todas as posicións.
     * Se comezásemos en strlen(pal), o primeiro valor sería o carácter nulo.
     */
}


int main(int argc, char** argv) {
    char palabra[30];
    
    printf("Introduza unha palabra:\n");
    scanf("%s", palabra);
    
    revespal(palabra);          // Chamada á función revespal.
    
    return (EXIT_SUCCESS);
}

