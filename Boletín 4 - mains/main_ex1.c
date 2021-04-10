/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 *
 * Data: 11 de novembro de 2019, 15:07
 * Este programa imprime o enderezo e o valor dun double, un enteiro e unha
 * cadea dados.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    // Declaramos as variables e os punteiros cos que imos acceder a elas.     
    double doub, *d;
    int integ, *i;
    char cadea[30], *c;
    
    printf("Introduza un double:\n");
    scanf("%lf", &doub);
    printf("Introduza un enteiro:\n");
    scanf("%d", &integ);
    getchar();          // O retorno de carro queda no buffer de teclado.
    printf("Introduza unha cadea de caracteres:\n");
    scanf("%[^\n]", cadea);
    
    // Os punteiros deben apuntar aos enderezos de memoria das variables.
    d = &doub;          
    i = &integ;
    c = cadea;      
    
    /* Empregando os punteiros podemos acceder ao valor das variables e ao
     * enderezo no que están gardadas.
     */
    printf("O valor do double é %f e o seu enderezo é %p\n", *d, d);
    printf("O valor do int é %d e o seu enderezo é %p\n", *i, i);
    printf("O valor almacenado na cadea é ");
    while(*c!='\0'){         // A cadea remata no carácter nulo.           
        printf("%c", *c);    // Temos que acceder á cadea carácter a carácter.
        c++;
        /* c++ aumenta o valor do punteiro segundo o tamaño do dato ao que
         * apunta, de forma que, neste caso, pasa a referenciar o seguinte
         * elemento da cadea.
         */
    }
    printf(" e o seu enderezo é %p", c);
    
    return (EXIT_SUCCESS);
}

