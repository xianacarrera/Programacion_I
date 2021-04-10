/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 *
 * Data: 28 de outubro de 2019, 16:50
 * Este programa le un texto encriptado dun arquivo, descífrao e móstrao
 * descifrado.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

char Desencriptar(int a, int b)
{
    int c;
    
    c = ((b-a)+128)%128;              // Cálculo do carácter orixinal.
    /* A conversión de int a char é automática. Non dará problemas ao estar
     * en módulo 128 (non pode ser maior que 127).
     */
    return c;            
}

int main(int argc, char** argv) {
    FILE *arquivo;
    int a, b;
    char orixinal;
    
    arquivo = fopen("Arquivo3.txt", "rt");      // Abertura do arquivo.
    
    if (arquivo==NULL){
        printf("Houbo un erro na abertura do arquivo.\n");
        exit(1);
    }
    else{
        a = fgetc(arquivo);
        printf("%c", a);            // O primeiro carácter non sufriu cambios.
        while (feof(arquivo)==0){
            b = fgetc(arquivo);
            if (b!=EOF){   // Sen o bucle if escribiríase un carácter de máis.
                orixinal = Desencriptar(a, b);        // Chamada á función.
                a = orixinal;     // Para o cálculo precísase o valor orixinal.
                printf("%c", orixinal);
            }
        }
        
        fclose(arquivo);        // Peche do arquivo.
    }
    return (EXIT_SUCCESS);
}

