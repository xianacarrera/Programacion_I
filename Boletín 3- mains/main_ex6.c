/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 *
 * Data: 28 de outubro de 2019, 16:03
 * Este programa le un arquivo e garda os seus datos noutro, encriptándoos de
 * forma que o primeiro carácter non é modificado e o resto son o carácter ASCII
 * que corresponde ao módulo 128 da suma de cada carácter lido co anterior.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    FILE *arquivo, *narquivo;
    int i, c;
    char a, b; 
    
    arquivo = fopen("Arquivo2.txt", "rt");   // Abertura do arquivo a ler.
    narquivo = fopen("NArquivo.txt", "wt");  // Abertura do arquivo a escribir.
                                        // Se narquivo non existise, crearíase.
    
    if (arquivo==NULL || narquivo==NULL){
        printf("Houbo un erro na abertura dos arquivos.\n");
        exit(1);
    }
    else{
        i = 0;
        a = fgetc(arquivo);             // Lectura do primeiro carácter.
        fprintf(narquivo, "%c", a);     // Escríbese sen cambios.
        while (feof(arquivo)==0){
            b = fgetc(arquivo);           // Lectura do segundo carácter.
            if (b!=EOF){    // Sen o bucle if gardaríase un carácter de máis.
                c = (a+b)%128;   // Cálculo do novo carácter en ASCII.
                // A conversión de char a int para o cálculo é automática.
                a = b;              // O segundo carácter pasa a ser o primeiro.
                fprintf(narquivo, "%c", c);
            }
        }
        
        fclose(arquivo);        // Peche dos arquivos.
        fclose(narquivo);
    }
   
    return (EXIT_SUCCESS);
}

