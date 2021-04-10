/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 *
 * Data: 11 de novembro de 2019, 16:59
 * Este programa le dúas cadeas de caracteres e detecta se teñen caracteres
 * comúns. En tal caso, crea unha cadea nova con estes e despois, imprímea.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */

char *CarCompartidos(char *cad1, char *cad2)
{
    int i=0, j=0, k, N=0, rep=0, lonx;
    
    if (strlen(cad1)<=strlen(cad2)){
        lonx = strlen(cad1);
    }
    else{
        lonx = strlen(cad2);
    }
    /* lonx é a lonxitude máxima que podería chegar a ter a cadea de caracteres
     * compartidos. É necesario coñecer este dato para executar malloc
     * correctamente.
     */
    
    char *carcomp = (char*)malloc(lonx*sizeof(char));
    /* Asígnase memoria no montón para o punteiro *carcomp. A reserva de
     * memoria dinámica neste caso é necesaria porque a función devolverá
     * un vector (unha cadea de caracteres).
     */ 
    
    while (cad1[i]!='\0'){     //Ao ser cadeas de caracteres, rematan en '\0'.
        while (cad2[j]!='\0'){    
            if (cad1[i]==cad2[j]){
                /* Para cada carácter da primeira cadea recórrese a segunda
                 * e búscase algunha coincidencia (os caracteres comúns poden
                 * estar en posicións distintas).
                 */
                for (k=0; k<N; k++){
                    // N aumenta cando se engaden elementos a carcomp.
                    if (cad1[i]==carcomp[k]){
                        /* Compróbase que o carácter coincidente non estivese
                         * xa en carcomp.
                         */
                        rep++;      // Contador de repeticións.
                    }
                }
                if (rep==0){   // Se non hai repeticións, engádese o carácter.
                    carcomp[N] = cad1[i];
                    N++;        // Pásase á seguinte posición de carcomp.
                }
                rep=0;          // rep reiníciase.
            }
            j++;                // Seguinte posición da segunda cadea.
        }
        j=0;           // Reiníciase o contador das posicións da segunda cadea.
        i++;           // Seguinte posición da primeira cadea. 
    }
    
    if (N==0){         
        // Se N segue sendo 0, non se engadiu ningún carácter a carcomp.
        carcomp = NULL;
    }
    else{
        carcomp[N]='\0';            // Engádese o carácter nulo a carcomp.
    }
    
    return carcomp;
}

int main(int argc, char** argv) {
    char cad1[30], cad2[30], *carc;
    
    printf("Introduza a primeira cadea de caracteres:\n");
    scanf("%s", cad1);
    printf("Introduza a segunda cadea de caracteres:\n");
    scanf("%s", cad2);
    
    carc = CarCompartidos(cad1, cad2);
    // carc é un punteiro que apunta ao primeiro elemento de carcomp.
    
    if (carc==NULL){        // carc non apunta a nada.
        printf("As cadeas non tenen caracteres en común");
    }
    else{
        printf("A cadea común é %s\n", carc);
    }
    
    free(carc);
    
    return (EXIT_SUCCESS);
}

