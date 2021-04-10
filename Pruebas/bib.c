/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   implem.c
 * Author: Xiana
 *
 * Created on 25 de noviembre de 2019, 16:45
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib.h"

/*
 * 
 */

// Preguntas:
        // Se puede llamar a malloc en medio del programa o es mejor hacerlo en
        // la declaración de variables?
        // Cifra más significativa - se puede tener en cuenta al guardar o es mejor ir
        // viéndolo operación a operación?
        // Guardar al revés los números? Más fácil para las operaciones.
// Considerar +
// https://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/
// En el archivo aparte meter pantallazos y comentarios.
bignum str2bignum (char *str)
{
    bignum num;
    int i;
    
    /* A miña intención é que no primeira posición da str poida haber un signo
     * (positivo ou negativo) ou non. Neste caso interpretarase como un número
     * positivo. Para saber cal é a cifra máis significativa na segunda (ou primeira)
     * posición haberá un s (a primeira cifra) ou un n (a última).
     */
    
    
    if (str[0]=='-' || str[0]=='+'){
        if (str[0]=='-'){
            num.sign = 1;       // 1 representa que o signo é negativo.
        }
        else{
            num.sign = 0;
        }
        num.tam = strlen(str)-2;
        
        num.val = (int*)malloc(num.tam*sizeof(int));        
        if (str[1]=='l'){           // last - la última es la más significativa
            for (i=0; i<num.tam; i++){
                num.val[i] = str[i+2]-48;
            }       
            // --48 por la tabla ascii. Se puede almacenar los enteros, no?
        }
        else{
            for (i=0; i<num.tam; i++){
                num.val[i] = str[strlen(str)-1-i]-48;
            }
        }     
    }
    else{
        num.sign = 0;       // 0 representa que o signo é positivo.
        num.tam = strlen(str)-1;
        
        num.val = (int*)malloc(num.tam*sizeof(int));
        if (str[0]=='l'){           // n - la última es la más significativa
            for (i=0; i<num.tam; i++){
                num.val[i] = str[i+1]-48;
            }      
        }
        else{
            for (i=0; i<num.tam; i++){
                num.val[i] = str[strlen(str)-1-i]-48;
            }
        } 
    }
    
    return num;
}

bignum add (bignum a, bignum b)
{
    // Inicializar totsum - positivo, negativo...
    // Caso - +, llamar a sub
    bignum totsum, c;
    int suma, acarreo=0, i, valorb;
    
    if ((a.sign==0 && b.sign==0) || (a.sign==1 && b.sign==1)){
        if (a.tam<b.tam){
            c = a;
            a = b;
            b = c;
        }
        
        totsum.sign = a.sign;

        totsum.val = (int*)malloc((a.tam+1)*sizeof(int));
        // Reservamos un espacio más por si hay acarreo.
        // realloc más tarde para optimizar?

        for (i=0; i<a.tam; i++){
            if (i>=b.tam){
                valorb = 0;
            }
            else{
                valorb = b.val[i];
            }
            suma = a.val[i] + valorb + acarreo;
            acarreo = suma/10;
            totsum.val[i] = suma%10;
        }
        
        if (acarreo){           // Acarreo!=0
            totsum.tam = a.tam+1;
            totsum.val[i] = acarreo;    
        }
        else{
            totsum.tam = a.tam;
            totsum.val = (int*)realloc(totsum.val, a.tam*sizeof(int));
        }
        // Es necesario realloc?
        
    }
    return totsum;
}

bignum sub (bignum a, bignum b)
{
    bignum totrest, c;
    int i=0, valorb, acarreo=0, resta;
    
    if (a.tam<b.tam){
        c = a;
        a = b;
        b = c;
    }
    else if (a.tam=b.tam){
        do{
            if (b.val[i]>a.val[i]){
                c = a;
                a = b;
                b = c;
                i++;
            }
        }while ((a.val[i-1]==b.val[i-1]) && i<a.tam);          
    }
    
    totrest.sign = a.sign;
            
    totrest.val = (int*)malloc(a.tam*sizeof(int));
    
    for (i=0; i<a.tam; i++){
        if (i>=b.tam){
            valorb = 0;
        }
        else{
            valorb = b.val[i];
        }
        resta = a.val[i]-acarreo-valorb;
        if (resta<0){
            resta += 10;
            acarreo = 1;
        }
        else{
            acarreo = 0;
        }
        totrest.val[i] = resta;
    }
    printf("HHHHHHH");
    do{
        i--;
        if (totrest.val[i]!=0){         // Hace falta !=0?
            totrest.tam = i;
        }
    }while (totrest.val[i]==0 && i>0);
    
    if (i==0){
        totrest.tam = 1;
        totrest.val = (int*)realloc(totrest.val, sizeof(int));
    }
    else{
        totrest.val = (int*)realloc(totrest.val, totrest.tam*sizeof(int));
    }
    
    return totrest;
}
