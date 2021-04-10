/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 * Data: 23 de setembro de 2019, 16:51
 * 
 * Este programa redondea unha cantidade real aos enteiros máis próximos
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 
 */
int main(int argc, char** argv) {
    float a;
    int b,c,d;
    
    printf("Introduza un número real: \n");
    scanf("%f", &a);
    b= floor(a);
    c= ceil(a);
    d= round(a);
    
    printf("O número truncado é: %d\n", b);
    printf("O número redondeado ao enteiro superior é: %d\n", c);
    printf("O número redondeado é: %d\n", d);
    return (EXIT_SUCCESS);
}

