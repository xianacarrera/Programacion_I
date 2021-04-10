/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 * Data: 23 de setembro de 2019, 16:27
 * 
 * Este programa calcula as coordenadas do punto medio de dous puntos 
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    float a,b,c,d,mediax,mediay;
    
    printf("Introduza a coordenada x do punto 1: \n");
    scanf("%f", &a);
    printf("Introduza a coordenada y do punto 1: \n");
    scanf("%f", &b);
    printf("Introduza a coordenada x do punto 2: \n");
    scanf("%f", &c);
    printf("Introduza a coordenada y do punto 2: \n");
    scanf("%f", &d);
    
    mediax= (a+c)/2;
    mediay= (b+d)/2;
    
    printf("As coordenadas do punto medio son: (%f, %f)", mediax, mediay);
    return (EXIT_SUCCESS);
}

