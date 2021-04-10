/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 * Data: 23 de setembro de 2019, 16:45
 * 
 * Este programa imprime o código ASCII dunha letra dada
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    char a;
    
    printf("Introduza unha letra: \n");
    scanf("%c", &a);
    printf("O código ASCII da letra %c é %i", a, a);
    
    return (EXIT_SUCCESS);
}

