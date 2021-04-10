/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 * Fecha: 3 de octubre de 2019, 17:38
 * 
 * Este programa muestra los 10 primeros números naturales impares y su suma.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int i, x, c;
    
    x=1;
    c=0;
    for(i=1; i<=10; i++){       
        printf("%d\n", x);      // Mostrar el número impar.
        c+=x;              // Guardar el valor de dicho número.
        x+=2;              // Sumar 2 al número para obtener el siguiente impar.
    }
    printf("La suma total es: %d", c);       // Mostrar la suma total.
    return (EXIT_SUCCESS);
}

