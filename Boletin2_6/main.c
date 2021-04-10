/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Xiana
 *
 * Created on 11 de octubre de 2019, 13:28
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    float matriz_A[4][4], matriz_B[4][4], matriz_C[4][4];
    int nfilas_A, ncolumnas_A;
    int nfilas_B, ncolumnas_B;
    int nfilas_C, ncolumnas_C;
    int i, j, b; 
    float operacion, a=0;
    
    printf("Introduza o número de filas da matriz A:\n");
    scanf("%d", &nfilas_A);
    printf("Introduza o número de columnas da matriz A:\n");
    scanf("%d", &ncolumnas_A);
    
    for (i=0; i<nfilas_A; i++){
        for (j=0; j<ncolumnas_A; j++){
            printf("Introduza o elemento da matriz A que se corresponde coa "
                    "fila %d e a columna %d:\n", i+1, j+1);
            scanf("%f", &matriz_A[i][j]);
        }
    }
    
    printf("Introduza o número de filas da matriz B:\n");
    scanf("%d", &nfilas_B);
    printf("Introduza o número de columnas da matriz B:\n");
    scanf("%d", &ncolumnas_B);
    
    for (i=0; i<nfilas_B; i++){
        for (j=0; j<ncolumnas_B; j++){
            printf("Introduza o elemento da matriz B que se corresponde coa "
                    "fila %d e a columna %d:\n", i+1, j+1);
            scanf("%f", &matriz_B[i][j]);
        }
    }
    
    printf("Introduza 1 para sumar ou outro número para multiplicar:\n");
    scanf("%f", &operacion);
    
    if (operacion == 1){
        if (nfilas_A == nfilas_B && ncolumnas_A == ncolumnas_B){
            printf("As matrices introducidas son válidas para a suma.\n");
            nfilas_C = nfilas_A;
            ncolumnas_C = ncolumnas_A;
            
            for (i=0; i<nfilas_A; i++){
                for (j=0; j<ncolumnas_A; j++){
                    matriz_C[i][j] = matriz_A[i][j] + matriz_B[i][j];
                }
            }
            
            printf("A matriz resultante C ten %d filas e %d columnas.\n",
                    nfilas_C, ncolumnas_C);
            
            for (i=0; i<nfilas_C; i++){
                for (j=0; j<ncolumnas_C; j++){
                    printf("O elemento de C da fila %d e da columna %d "
                            "é %f.\n", i+1, j+1, matriz_C[i][j]);
                }
            }
        }
        else{
            printf("As matrices introducidas non son válidas para a suma.\n");
        }
        
    }
    else{
        if (ncolumnas_A == nfilas_B){
            printf("As matrices introducidas son válidas para a "
                    "multiplicación.\n");
            nfilas_C = nfilas_A;
            ncolumnas_C = ncolumnas_B;
            
            for (i=0; i<nfilas_C; i++){
                for (j=0; j<ncolumnas_C; j++){
                    for (b=0; b<ncolumnas_A; b++){
                        a += matriz_A[i][b]*matriz_B[b][j];
                    }
                    matriz_C[i][j] = a;
                    a = 0;
                }
            }
            
            printf("A matriz resultante C ten %d filas e %d columnas.\n",
                    nfilas_C, ncolumnas_C);
            
            for (i=0; i<nfilas_C; i++){
                for (j=0; j<ncolumnas_C; j++){
                    printf("O elemento de C da fila %d e da columna %d "
                            "é %f.\n", i+1, j+1, matriz_C[i][j]);
                }
            }
        }
        else{
            printf("As matrices introducidas non son válidas para a "
                    "multiplicación.\n");
        } 
    }
    return (EXIT_SUCCESS);
}

