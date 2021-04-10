/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 *
 * Data: 11 de novembro de 2019, 15:32
 * Este programa mostra como o tipo de punteiro co que accedemos a unha
 * posición de memoria é determinante á hora de interpretar o dato alí gardado.
 * Así, empréganse distintos tipos de punteiros para acceder a varios datos.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    unsigned int ui;
    unsigned char *puntc, vect[4];
    int *punti, i;
    char *puntc2;
    
    printf("Introduza un unsigned int:\n");
    scanf("%u", &ui);
    printf("Introduza unha cadea de caracteres de lonxitude 4:\n");
    scanf("%s", vect);
    
    puntc = &ui;   
    // Punteiro de tipo char* que apunta a un unsigned int.
    punti = vect;  
    // Punteiro de tipo int* que apunta a un vector unsigned char.
    puntc2 = vect; 
    // Punteiro de tipo char* que apunta a un vector unsigned char.
    
    printf("Os valores gardados en cada byte do enteiro son:\n");
    for (i=0; i<4; i++){ 
        printf("%c\n", *puntc);  // Móstrase o correspondente carácter en ASCII.     
        puntc++;        
        /* Ao ser un punteiro de tipo char, puntc++ incrementa o valor de puntc
         * nun byte, permitíndonos acceder a cada un dos catro bytes do enteiro.
         */
    }
    
    printf("Os valores gardados en cada byte da cadea son, accedendo cun "
            "punteiro de tipo int:\n");
    for (i=0; i<4; i++){
        printf("%c\n", *punti);  
        /* Faise a conversión de int a carácter en ASCII. Como estamos
         * imprimindo en tipo char, cóllese un byte en cada iteración do bucle,
         * de forma que se mostran os caracteres un a un.
         */
        punti = vect+i+1;      
        /* Se fixeramos punti++, ao ser punti de tipo int, incrementaríase en 4.
         * Reasignalo a vect+i+1 é equivalente a escribir punti = &vect[i+1].
         */
    }
    printf("Se o imprimimos como un enteiro, o valor da cadea é:\n");
    punti = vect;
    printf("%d\n", *punti);   
    /* Se imprimimos un enteiro, C terá que ler catro caracteres, é dicir, a
     * lonxitude completa do vector. Convertirá cada byte a un só número.
     */
    
    printf("Os valores gardados en cada byte da cadea son, accedendo cun "
            "punteiro de tipo char:\n");
    for (i=0; i<4; i++){
        printf("%c\n", *puntc2);
        puntc2++;       // Tanto char como unsigned char ocupan 1 byte.
    }
    
    
    return (EXIT_SUCCESS);
}

