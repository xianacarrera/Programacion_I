/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.c
 * Autora: xiana.carrera
 *
 * Data: 7 de outubro de 2019, 15:33
 * Este programa le unha palabra e di cantas vogais ten de cada tipo.
 */

#include <stdio.h>
#include <stdlib.h>
#include <c++/bits/std_abs.h>

/*
 *
 */
int main(int argc, char** argv) {
    char palabra[15];
    int a, e, i, o, u, n;

    printf("Introduza unha palabra en minúsculas:\n");
    scanf("%s", palabra);
    
    a = 0;
    e = 0;
    i = 0;
    o = 0;
    u = 0;

    n = 0;
    while (palabra[n] != '\0') {
        switch (palabra[n]) {
            case 'a': a++; // IMPORTANTE: non poden ser "", só '
                break;
            case 'e': e++;
                break;
            case 'i': i++;
                break;
            case 'o': o++;
                break;
            case 'u': u++;
                break;
        }
        n++;
    }

    printf("Hai %d 'a'\n", a);
    printf("Hai %d 'e'\n", e);
    printf("Hai %d 'i'\n", i);
    printf("Hai %d 'o'\n", o);
    printf("Hai %d 'u'\n", u);

    return (EXIT_SUCCESS);
}

