/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 *
 * Fecha: 3 de octubre de 2019, 17:57
 * Este programa calcula la raíz cuadrada de la suma de 10 números dados.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int i, x;
    int a[10];
    double b;
    
    for(i=0; i<=9; i++){
        printf("Introduzca un número:\n");
        scanf("%d", &a[i]);                // Lectura de los números.
    }            
    
    x=0;
    for(i=0; i<=9; i++){        // Cálculo de los cuadrados y almacenamiento
        x+=pow(a[i],2);         // en la variable x.
    }
    
    b=sqrt(x);             // Cálculo de la raíz de x.
    printf("La suma total es: %f", b);      // Resultado final.
    return (EXIT_SUCCESS);
}

