/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 * 
 * Fecha: 6 de octubre de 2019, 12:49
 * Este programa muestra la tabla de multiplicar de un número entero dado.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int x, y, i;
    
    printf("Introduzca un número entero:\n");
    scanf("%d", &x);
    
    for(i=0; i<=10; i++){
        y= x*i;
        printf("%d * % d = %d\n", x, i, y);
    }
    return (EXIT_SUCCESS);
}

