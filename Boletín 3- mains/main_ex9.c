/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 *
 * Data: 4 de novembro de 2019, 16:30
 * Este programa garda datos nun inventario, le dito inventario e permite
 * vender arquivos, actualizando os datos.
 */



#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

typedef struct{
    int codigo;
    char nome[30];
    float prezo;
    int cantidade;
} artigo;           // Defínese a estrutura "artigo".

int gravar_datos()
{
    FILE *invent;
    int nelementos=0, pech;
    artigo art;
    
    invent=fopen("invent.dat", "wb");
    if (invent==NULL){
        printf("Houbo un erro na abertura do arquivo");
        exit(1);
    }
    else{
        do{
            art.codigo=nelementos+1;    // Os códigos comezan en 1.
            printf("Introduza o nome do artigo:\n");
            scanf("%s", art.nome);
            printf("Introduza o prezo do artigo:\n");
            scanf("%f", &art.prezo);
            printf("Introduza a cantidade de unidades do artigo:\n");
            scanf("%d", &art.cantidade);
            printf("Escriba 1 para saír ou 0 para continuar:\n");
            scanf("%d", &pech);
            fwrite(&art, sizeof(art), 1, invent);
            // En cada iteración gárdase o artigo que se acaba de crear.
            nelementos++;       // Contador.
        }while (pech==0);
        
        fclose(invent);
    }
    
    return nelementos;
}

void ler_datos(artigo vect[])
{
    FILE *invent;
    artigo art;
    int ler, i=0;
    
    invent=fopen("invent.dat", "rb");
    if (invent==NULL){
        printf("Houbo un erro na abertura do arquivo");
        exit(1);
    }
    else{
        do{
           ler=fread(&vect[i], sizeof(art), 1, invent);
           // Almacénase un artigo en cada posición do vector.
           i++;
        }while(ler==1); // fread non devolve 1 se hai un erro ou se remata.
        
        vect[i-1].nome[0]='\0';   // Servirá para saber a lonxitude do vector.
        fclose(invent);
    }
}

void venta_item(int codigodes, int nunidades, artigo vect[]) 
{
    float total;
    
    total=vect[codigodes-1].prezo*nunidades;
    printf("O valor total da venda é: %f\n", total);
    if (vect[codigodes-1].cantidade < nunidades){
        printf("Non hai suficientes existencias. Non se puido realizar a "
                "venda\n");
    }
    else{       // Actualización do vector co inventario.
        vect[codigodes-1].cantidade=vect[codigodes-1].cantidade-nunidades;         
    }
}

int main(int argc, char** argv) {
    int nelementos, codigodes, nunidades, merc, eleccion=0, i;
    artigo art, vect[20];    // De partida non sabemos cantos datos hai.       
    FILE *invent;
    
    
    /* En primeiro lugar, faise unha comprobación de que o arquivo existe.
     * Primeiro emprégase o modo de lectura (r) para que en caso de que si 
     * existamos datos non se borren, como ocurriría se empregásemos 
     * directamente o modo de escritura (w).
     */
    invent = fopen("invent.dat", "rb");
    if (invent==NULL){          // O arquivo non existe e fopen falla.
        invent = fopen("invent.dat", "wb");
        // Usando o modo wb créase un arquivo novo.
        if (invent==NULL){
            printf("O programa non ten acceso de escrita ao directorio\n");
            eleccion=4; //Se aínda así hai un erro, non se executa o while.
        }
    }
    fclose(invent); 
    /* En calquera caso, invent péchase para que non haxa problemas máis tarde,
     * pois non todos os procesos empregan o mesmo modo.
     */
    
    while (eleccion!=4){     
        printf("Menú:\n"
            "Pulse 1 para introducir datos do inventario\n"
            "Pulse 2 para mostrar o inventario\n"
            "Pulse 3 para facer unha compra\n"
            "Pulse 4 para saír\n");
        scanf("%d", &eleccion);
        
        switch(eleccion){
            case 1: 
                nelementos = gravar_datos();
                break;
                
            case 2: 
                ler_datos(vect);    
                if (vect[0].nome[0]=='\0'){
                    printf("Non había datos gardados no inventario\n");
                }
                i=0;
                while (vect[i].nome[0]!='\0'){
                    /* Na lectura de datos gardouse na última posición do
                     * vector o carácter nulo '\0' na primeira posición de nome,
                     * polo que podemos empregar esta condición para executar o 
                     * bucle. A razón pola que non se usa nelementos é que este
                     * pode estar desactualizado se se decide mostrar o
                     * inventario (ou facer unha compra) antes de gardar datos.
                     */ 
                    printf("Código do artigo: %d\n", vect[i].codigo);
                    printf("Nome: %s\n", vect[i].nome);
                    printf("Prezo: %f\n", vect[i].prezo);
                    printf("Cantidade de unidades: %d\n", 
                            vect[i].cantidade);
                    i++;
                }
                break;
            
            case 3: 
                ler_datos(vect);
                invent = fopen("invent.dat", "wb");
                if (invent==NULL){
                    printf("Houbo un erro na apertura do inventario. Non se "
                            "puido realizar a venda\n");
                    exit(1);
                }
                else{
                    do{
                        printf("Introduza o código do artigo desexado:\n");
                        scanf("%d", &codigodes);
                        printf("Introduza o número de unidades desexadas do "
                                "artigo:\n");
                        scanf("%d", &nunidades);
                        venta_item(codigodes, nunidades, vect);
                        i=0;
                        while (vect[i].nome[0]!='\0'){
                            fwrite(&vect[i], sizeof(art), 1, invent);
                            i++;
                        }   // Actualización do arquivo ao rematar cada venda.
                        printf("Introduza 1 para mercar outro artigo, 0 para "
                                "saír:\n");
                        scanf("%d", &merc);
                    }while (merc==1);

                    fclose(invent);
                }
                break;
        }        
    }
    
    return (EXIT_SUCCESS);
}                                                                       
                                                                                                                                            
                                                                                    