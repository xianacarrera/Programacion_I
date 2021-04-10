/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 * Data: 23 de setembro de 2019, 16:38
 * 
 * Este programa devolve a maiúscula dunha letra dada
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
 * 
 */
int main(int argc, char** argv) {
    char c,d;
    
    printf("Introduza unha letra: \n");
    scanf("%c", &c);
    d= toupper(c);
    printf("A maiúscula da letra é: %c", d);
    
    return (EXIT_SUCCESS);
}

