/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 *
 * Data: 14 de outubro de 2019, 16:07
 * Este programa substitúe as minúsculas dunha cadea de caracteres por
 * maiúsculas, e devolve o número de cambios realizados.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

int substitu(char cadea[])
{
    int a, i=0, cont=0;
    
    do{
        a = (cadea[i]);    // Como a é un enteiro, almacénase o valor ASCII.
        if (a>=65 & a<=90){
            cadea[i] = a+32;   
            // Como cadea é de tipo char, almacénase o carácter.
            cont++;        // Aumentáse un contador nunha unidade.
        }
        i++;               // Pásase á seguinte posición do vector.
    }while (a!='\0');      // a=='\0' cando se chega ao final da cadea.
    /* Emprégase un while e non un for porque non se sabe cantos caracteres 
     * contén a cadea. Ademais, a elección de do-while débese a que para poder
     * facer unha comparación de cada carácter con '\0', antes debe lerse.
     */
    
    return cont;
}


int main(int argc, char** argv) {
    char cadea[30];
    int cambios;
    
    printf("Introduza unha cadea de caracteres:\n");
    scanf("%s", cadea);
            
    cambios = substitu(cadea);       // Chamada á función substitu.
    printf("A cadea tranformada é: %s.\n", cadea);
    printf("O número de cambios realizados é %d.", cambios);
    
    return (EXIT_SUCCESS);
}

