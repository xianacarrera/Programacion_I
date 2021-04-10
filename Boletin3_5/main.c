/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 *
 * Data: 21 de octubre de 2019, 16:53
 * Este programa determina a media dos valores dun arquivo.
 */

#include <stdio.h>
#include <stdlib.h>


/*
 * 
 */
int main(int argc, char** argv) {
    int vec[30], i;
    float suma, media;
    FILE *arquivo; 
    
    arquivo = fopen("Arquivo.txt", "rt");       // Abertura do arquivo.
    
    if (arquivo==NULL){                // Non se pode abrir o arquivo.
        printf("Houbo un erro na abertura do arquivo.\n");
        exit(1);
    }
    else{                                // Pódese abrir o arquivo.
        i = 0;
        do{
            fscanf(arquivo, "%d", &vec[i]);     // Lectura dos datos.
            suma += vec[i];               // Suma acumulada dos datos.
            i++;                        // Contador.
        }while (feof(arquivo)==0);
      
        media = suma/i;           // i é igual ao número de datos do arquivo.
        
        printf("A media dos valores é %f", media);
        
        fclose(arquivo);            // Peche do arquivo.
    }
                
    return (EXIT_SUCCESS);
}

