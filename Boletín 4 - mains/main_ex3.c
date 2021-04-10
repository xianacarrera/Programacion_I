/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 *
 * Data: 11 de novembro de 2019, 15:52
 * Este programa detecta se un vector de enteiros ten algún valor negativo e,
 * en caso afirmativo, mostra o valor e a súa posición.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

int *PosNegativo(int *vector, int N)
{
    int i;

    for (i=0; i<N; i++){
        if (vector[i]<0){       // Búscase un valor negativo no vector.
            return &vector[i];   
            // Se hai algún valor negativo, devólvese o seu enderezo de memoria.
        }
    }
    /* Se non hai ningún valor negativo, non se executa o return do if, e a
     * función segue. Entón, devolvemos o valor NULL.
     */
    return NULL;
}

int main(int argc, char** argv) {
    int N, *pos, i, a;
    
    printf("Introduza o número de elementos que vai ter o vector:\n");
    scanf("%d", &N);
    int vector[N];
    
    printf("Introduza os valores do vector:\n");
    for (i=0; i<N; i++){
        scanf("%d", &vector[i]);
    }
    
    pos = PosNegativo(vector, N);
    /* PosNegativo devolve un enderezo de memoria ou NULL e, polo tanto, débese
     * empregar un punteiro para recoller estes valores.
     */
    
    if (pos==NULL){
        printf("O vector non ten valores negativos.");
    }
    else{
        printf("O primeiro valor negativo é %d e está no enderezo de memoria "
                "%p\n", *pos, pos);
        a = pos - &vector[0];
        /* O valor negativo estará na posición resultante de restar o enderezo
         * do valor co primeiro enderezo do vector e dividir entre 4 (por ser
         * enteiros). Porén, C xa divide automaticamente por 4 ao detectar o
         * tipo dos datos.
         */
        printf("O valor atópase na posición %d do vector\n", a);
    }
    
    return (EXIT_SUCCESS);
}

