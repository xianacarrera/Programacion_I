/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 * Data: 23 de setembro de 2019, 15:08
 * Versión: 2
 * 
 * Este programa imprime a media de dous valores reais dados polo usuario
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    float val1,val2,media;

    printf ("Introduza o valor 1: ");
    scanf("%f", &val1);
    printf ("Introduza o valor 2: ");
    scanf("%f", &val2);
    
    media= (val1 + val2)/2.0;
    printf("Valor medio: %f\n", media);

    return (EXIT_SUCCESS);
}
