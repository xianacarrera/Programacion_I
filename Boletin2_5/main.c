/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 *
 * Data: 7 de outubro de 2019, 16:26
 * Este programa determina o máximo e mínimo dun vector e cantas veces se 
 * repiten.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int x[10];
    int a, b, c, d, i;
    
    for (i=0; i<=9; i++){
        printf("Introduza un número:\n");
        scanf("%d", &x[i]);
    }
    
    a=0;
    for (i=0; i<=9; i++){
        if (x[i]>a){
            a=x[i];
        }    
    }
    
    b=a;
    for (i=0; i<=9; i++){
        if (x[i]<b){
            b=x[i];
        }  
    }
    
    c=0;
    d=0;
    for (i=0; i<=9; i++){
        if (x[i]==a){
            c++;
        }
        if (x[i]==b){
            d++;
        }
    }
    
    
    printf("O valor máximo é %d, e aparece %d veces\n", a, c);
    printf("O valor mínimo é %d, e aparece %d veces", b, d);
   
    return (EXIT_SUCCESS);
}

