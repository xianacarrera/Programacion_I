/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 *
 * Data: 14 de outubro de 2019, 15:09
 * Este programa calcula o promedio e o máximo de dous valores.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

float encontprom(int num1, int num2)
{
    float promedio;

    promedio = (num1 + num2) / 2.0;
    return(promedio);
}

int encontmax(int num1, int num2)
{
    if (num1 >= num2){   // Se o primeiro número é maior, devólvese como máximo.
        return(num1);    // Se son iguais, podemos coller calquera dos dous.
    }
    else{
        return(num2);    // Se o segundo número é maior, devólvese como máximo.
    }   
}

int main(int argc, char** argv) {
    int a,b, resultado2;
    float resultado;
    
    printf("Dame dous valores enteiros: ");
    scanf("%d %d",&a,&b);
    
    resultado = encontprom(a, b);
    resultado2 = encontmax(a, b);       // Chamada á función encontmax.
    printf("Promedio=%f\n",resultado);
    printf("Máximo=%d\n", resultado2);
    
    return (EXIT_SUCCESS);
}

