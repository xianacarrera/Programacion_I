/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 *
 * Data: 7 de outubro de 2019, 17:08
 * Este programa realiza sumas e multiplicacións de matrices de tamaños menores
 * ou iguais a 4x4.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int nfilas_A, ncolumnas_A, numero_elementos_A;
    int nfilas_B, ncolumnas_B, numero_elementos_B;
    int nfilas_C, ncolumnas_C, numero_elementos_C;
    int operacion, i, j, k=0, l, c=0;
    int elementos_A[16], elementos_B[16], elementos_C[16];
   
    
    printf("Introduza o número de filas da matriz A:\n");
    scanf("%d", &nfilas_A);
    printf("Introduza o número de columnas da matriz A:\n");
    scanf("%d", &ncolumnas_A);
    
    numero_elementos_A = nfilas_A*ncolumnas_A;
    
    for (i=0; i<=(numero_elementos_A - 1); i++){
        printf("Introduza un elemento da matriz A:\n");
        scanf("%d", &elementos_A[i]);
    }
    
    printf("Introduza o número de filas da matriz B:\n");
    scanf("%d", &nfilas_B);
    printf("Introduza o número de columnas da matriz B:\n");
    scanf("%d", &ncolumnas_B);
    
    numero_elementos_B = nfilas_B*ncolumnas_B;
    
    for (i=0; i<=(numero_elementos_B - 1); i++){
        printf("Introduza un elemento da matriz B:\n");
        scanf("%d", &elementos_B[i]);
    }
    
    printf("Introduza 1 para sumar ou outro número para multiplicar\n");
    scanf("%d", &operacion);
    
    if (operacion == 1){
        if (nfilas_A == nfilas_B && ncolumnas_A == ncolumnas_B){
            printf("As matrices introducidas son válidas para a suma.\n");
            nfilas_C = nfilas_A;
            ncolumnas_C = ncolumnas_A;
            
            for (i=0; i<=numero_elementos_A - 1; i++){
                elementos_C[i] = elementos_A[i] + elementos_B[i];
            }
            
            printf("A matriz resultante C ten %d filas e %d columnas.\n",
                    nfilas_C, ncolumnas_C);
            printf("Os elementos da matriz C son, en orde:\n");
            
            for (i=0; i<=numero_elementos_C - 1; i++){
                printf("%d\n", elementos_C[i]);
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
            numero_elementos_C = nfilas_C*ncolumnas_C;
            
            
            for (j=0; j<=numero_elementos_C - 1; j++){
                if (j<ncolumnas_B){
                    for (k=0; k<ncolumnas_A; k++){
                        c += elementos_A[k]*elementos_B[l];
                        l+=ncolumnas_B;
                    }
                    elementos_C[j]=c;
                    l=j+1;
                    c=0;
                }
                else if(j<2*ncolumnas_B){
                    if (l>=ncolumnas_B){
                        l=0;
                    }
                    for (k=ncolumnas_A; k<2*ncolumnas_A; k++){
                        c += elementos_A[k]*elementos_B[l];
                        l+=ncolumnas_B;
                    }
                    elementos_C[j]=c;
                    l=j+1-ncolumnas_A;
                    c=0;
                }
                else if(j<3*ncolumnas_B){
                    if (l>=ncolumnas_B){
                        l=0;
                    }
                    for (k=2*ncolumnas_A; k<3*ncolumnas_A; k++){
                        c += elementos_A[k]*elementos_B[l];
                        l+=ncolumnas_B;
                    }
                    elementos_C[j]=c;
                    l=j+1-2*ncolumnas_A;
                    c=0;
                }
                else{
                    if (l>=ncolumnas_B){
                        l=0;
                    }
                    for(k=3*ncolumnas_A; k<4*ncolumnas_A; k++){
                        c += elementos_A[k]*elementos_B[l];
                        l+=ncolumnas_B;
                    }
                    elementos_C[j]=c;
                    l=j+1-3*ncolumnas_A;
                    c=0;
                   
                }
            }
            printf("A matriz resultante C ten %d filas e %d columnas.\n",
                    nfilas_C, ncolumnas_C);
            printf("Os elementos da matriz C son, en orde:\n");
            
            for (i=0; i<=numero_elementos_C - 1; i++){
                printf("%d\n", elementos_C[i]);
            }
        }
        else{
            printf("As matrices introducidas non son válidas para a "
                    "multiplicación.\n");
        }
    }
    
    return (EXIT_SUCCESS);
}


