/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 * Data: 23 de setembro de 2019, 17:01
 * 
 * Este programa mide a lonxitude dunha palabra dada
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
int main(int argc, char** argv) {
    char a[200];
    int b;
    
    printf("Introduza unha palabra: \n");
    scanf("%s", &a);
    b= strlen(a);
    printf("A lonxitude da palabra dada é: %d", b);
    
    return (EXIT_SUCCESS);
}

