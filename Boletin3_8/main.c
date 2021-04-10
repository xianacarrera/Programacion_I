/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 *
 * Data: 4 de novembro de 2019, 15:03
 * 
 * Este programa compara unha chave de paso dada polo usuario coas almacenadas
 * nun arquivo, informando se coincide con algunha delas.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>         // Precísase a función strlen.

/*
 * 
 */

int Hamming(char u[], char v[])     
{
    int a=0, i;
    
    if (strlen(u)!=strlen(v)){
        return -1; 
        // Hamming devolve -1 se a lonxitude das cadeas non coincide.
    }
    else{
        for (i=0; i<strlen(u); i++){
            if (u[i]!=v[i]){     // Faise unha comparación carácter a carácter.
                a++;             // Cando non coinciden, auméntase un contador.
            }
        }
        return a;
    }
}

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
    char u[30], v[30];
    int i, a, b=0, c=0;
    char k, l, orixinal;
    FILE *chaves;
    
    chaves=fopen("chaves.dat", "rt");       // Abertura do arquivo.
    if (chaves==NULL){          
        printf("Houbo un erro na abertura do arquivo.\n");
        exit(1);
    }
    else{
        printf("Introduza a súa chave de paso:\n");
        scanf("%s", u);         // Almacénase nun vector de caracteres.
        
        do{
            i = 1;                // Contador para as posicións do vector.
            k = fgetc(chaves);    // Cóllese o primeiro carácter.
            if (k!='\n' && k!=EOF){
                /* Se se atopa o final da liña, non se executa o if e 
                 * vólvese a coller outro carácter. Se se chega ao final do 
                 * arquivo, o bucle do-while principal terminará.
                 */
                                        
                v[0] = k;         // O primeiro carácter non sufriu cambios.
                do{
                    l = fgetc(chaves);    // Cóllese o segundo carácter.
                    if (l!='\n' && l!=EOF){ 
                        // Sen o bucle if teríase un carácter de máis.
                        orixinal = Desencriptar(k, l);    // Chamada á función.
                        k = orixinal;
                        // Para o cálculo precísase o valor orixinal.
                        v[i] = orixinal;      // Gárdase o valor desencriptado.
                        i++;                // Seguinte posición do vector.
                    }
                }while (l!='\n' && l!=EOF);
                v[i] = '\0'; 
                    
                a = Hamming(u,v);       // Chamada a Hamming.
                if (a==-1){
                    b++;        
                    // Contador dos casos de que as lonxitudes non coincidan.
                }
                else if (a==0){
                    c++;    // Contador das coincidencias.
                }
            }
        }while(k!=EOF);         // Continúase ata chegar ao final do arquivo.

        if (b!=0){
            printf("A lonxitude da cadea non coincide con algunha das do "
                    "arquivo\n");
        }  
        
        if (c==0){
            printf("A cadea non coincide con ningunha das do arquivo\n");
        }
        else{
            printf("A cadea coincide con algunha das do arquivo\n");
        }
        
        fclose(chaves);
    }
        
    return (EXIT_SUCCESS);
}

