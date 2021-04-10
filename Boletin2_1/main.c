/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 * Data: 30 de setembro de 2019, 15:35
 * 
 * Este programa executa unha función matemática definida por partes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 
 */
int main(int argc, char** argv) {
    double x, a;
    
    printf("Introduza o valor de x:\n");
    scanf("%lf", &x);
    
    if (x>=-1 && x<1){
        a= pow(x,2);
        printf("O resultado é: %f", a);
    }
    else if (x<2){
        a= 2*x-1;
        printf("O resultado é: %f", a);
    }
    else if (x<=4){
        a= -2*pow(x-2.5,2)+3.5;
        printf("O resultado é: %f", a);
    }
    else{
        printf("A función non está definida para ese valor.");
    }
    
    return (EXIT_SUCCESS);
}

