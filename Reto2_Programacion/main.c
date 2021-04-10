/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 *
 * Data: 8 de outubro de 2019, 22:06
 * Este programa imprime nomes dados ata que o usuario escribe FIN.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
int main(int argc, char** argv) {
    char fin[4], texto[50];
    int y;
    
    strcpy(fin, "FIN");     // Copio FIN no array fin.
    do{
        printf("Introduza un nome (escriba FIN para rematar):\n");
        scanf("%s", texto);
        
        y = strcmp(fin, texto);     // A función strcmp compara dous vectores de
            // caracteres e devolve 0 se son iguais. Se a cadea do primeiro 
            // vector é maior ca a do segundo, devolve un número positivo; se é
            // menor, devolve un número negativo. Téñense en conta as
            // minúsculas e as maiúsculas.
        
        if (y==0){         // Se as cadeas son iguais, imprímese "Rematei".
            printf("Rematei");
        }
        else{              // Se as cadeas non son iguais, imprímese o nome.
            printf("%s\n", texto);
        }          
    }while(y!=0);          // O bucle acaba cando se introduce FIN.

    return (EXIT_SUCCESS);
}

