/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Xiana
 *
 * Created on 5 de noviembre de 2019, 19:33
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib.h"

/*
 * 
 */

int main(int argc, char** argv){
    char cadena1[25]="s125", cadena2[25]="s14";
    bignum a, b, c;
    int i=0;
    
    a = str2bignum(cadena1);
    b = str2bignum(cadena2);
    
    if (a.tam<b.tam){
        c = a;
        a = b;
        b = c;
    }
    printf("DFHASJ");
    if (a.tam=b.tam){
        do{
            if (b.val[i]>a.val[i]){
                c = a;
                a = b;
                b = c;
            }
            i++;
        }while((a.val[i-1]==b.val[i-1]) && i<a.tam);          
    }

    for (i=0; i<a.tam; i++){
        printf("%d", a.val[i]);
    }
    
    return (EXIT_SUCCESS);
}

