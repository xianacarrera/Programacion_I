/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 * Data: 30 de setembro de 2019, 15:52
 * 
 * Este programa indica se un ano é bisesto ou non
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int x;
    
    printf("Introduza un ano:\n");
    scanf("%d", &x);
    
    if ((x%4==0 && x%100!=0) || x%400==0){
        printf("O ano é bisesto");
    }
    else{
        printf("O ano non é bisesto");
    }
    return (EXIT_SUCCESS);
}

