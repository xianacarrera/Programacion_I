/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 * Data: 30 de setembro de 2019, 16:00
 * 
 * Este programa calcula o seno dun valor dado.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 
 */
int main(int argc, char** argv) {
    double x, precision, sen_x, termo, ntermo;
    int i, d;
    
    printf("Introduza o valor de x:\n");
    scanf("%lf", &x);
    printf("Introduza un valor entre 0 e 1 que indique a precisión:\n");
    scanf("%lf", &precision);
    
    termo=x;
    sen_x=termo;
    i=3;
    do{
        ntermo=(-x*x/(i*(i-1)))*termo;
        termo=ntermo;
        sen_x+=termo;
        i+=2;
    }while (fabs(termo)<precision);
    
    printf("O valor do seno é: %f", sen_x);
    
    return (EXIT_SUCCESS);
}

