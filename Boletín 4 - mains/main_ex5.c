/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 *
 * Data: 18 de novembro de 2019, 15:04
 * Este programa realiza a suma, a multiplicación escalar e a multiplicación 
 * tensorial de dous vectores gardados nun arquivo. O nome do arquivo é pasado
 * a través da liña de comandos.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

float *sum(float *u, float *v, int N1, int N2)
{
    float *su = (float*)malloc(N1*sizeof(float));
    /* Asígnase memoria dinámica para un vector de floats. O seu tamaño será
     * igual ao dos vectores pasados como operandos (se teñen distinto tamaño,
     * non se pode realizar a suma).
     */
    int i;
    
    if (su==NULL){      // Erro na reserva de memoria.
        printf("Memoria insuficiente.\n");
        exit(1);
    }
    
    if (N1==N2){
        for (i=0; i<N1; i++){
            su[i] = u[i]+v[i];
            // Cada valor de su é a suma dos valores de u e i para esa posición.
        }
    }
    else{
        su = NULL;
    }
    
    return su;
}

float *mul(float *u, float *v, int N1, int N2)
{
    float *mult = (float*)malloc(N1*sizeof(float));
    /* Como na función suma, asígnase memoria dinámica para o vector co 
     * resultado da multiplicación. O seu tamaño é igual ao dos vectores
     * pasados (se teñen distinta lonxitude, non se pode realizar a
     * multiplicación escalar).
     */
    int i;
    
    if (mult==NULL){      // Erro na reserva de memoria.
        printf("Memoria insuficiente.\n");
        exit(1);
    }
    
    if (N1==N2){
        for (i=0; i<N1; i++){
            mult[i] = u[i]*v[i];
            /* Cada valor de su é a multiplicación dos valores de u e i para 
             * esa posición.
             */
        }
    }
    else{
        mult = NULL;
    }
    
    return mult;
}

float *ten(float *u, float *v, int N1, int N2)
{
    float *tensor = (float*)malloc(N1*N2*sizeof(float));
    /* tensor será unha matriz, polo que hai que reservar memoria para
     * N1*N2 floats.
     */
    int i, j;
    
    if (tensor==NULL){      // Erro na reserva de memoria.
        printf("Memoria insuficiente.\n");
        exit(1);
    }
    
    /* Non se fai ningunha comprobación sobre o tamaño dos vectores porque 
     * no caso da multiplicación tensorial non é necesario que coincidan.
     */

    for (i=0; i<N1; i++){
        for (j=0; j<N2; j++){
            // u é tomado como un vector columna e v, como un vector fila.
            *(tensor+i*N2+j) = u[i]*v[j];
            /* Os elementos da matriz serán o resultado de multiplicar o
             * elemento da fila correspondente de u polo elemento da columna
             * correspondente de v.
             */
        }
    }
    
    return tensor;
}

int main(int argc, char** argv) {
    FILE *vectores;
    float *suma, *multip, *tens;
    // Punteiros aos que se asignarán os resultados das operacións.
    int i, j, N1, N2;
    char operacion;
    
    if (argc!=2){
        printf("Número de argumentos incorrecto. Precísase indicar cal é o "
                "arquivo que contén os datos dos vectores");
        exit(1);
    }
    else{
        vectores = fopen(argv[1], "rt");
        // O arquivo pásase como argv[1] e ábrese en modo de lectura.
        if (vectores==NULL){
            printf("Houbo un erro na abertura do arquivo");
            exit(1);
        }
        else{
            fscanf(vectores, "%d", &N1);      // Tamaño do primeiro vector.
            float u[N1];
            // Agora que se coñece o tamaño, pódese declarar o vector.
            for (i=0; i<N1; i++){
                fscanf(vectores, "%f", &u[i]);
            }

            fscanf(vectores, "%d", &N2);        // Tamaño do segundo vector.
            float v[N2];
            for (i=0; i<N2; i++){
                fscanf(vectores, "%f", &v[i]);
            }
            
            // A continuación móstranse os vectores que se acaban de ler.
            printf("O vector 1 é:\n");
            for(i=0; i<N1; i++){
                printf("%f\t", u[i]);
            }
            printf("\n");

            printf("O vector 2 é:\n");
            for (i=0; i<N2; i++){
                printf("%f\t", v[i]);
            }
            printf("\n");

            do{
                printf("Elixa a operación:\n"   // Menú para elixir a operación.
                        "Suma = s\n"
                        "Multiplicación = m\n"
                        "Multiplicación tensorial = t\n"
                        "Finalizar = f\n");
                scanf("%c", &operacion);
                getchar();
                /* Precísase usar getchar porque, sen el, o retorno de carro 
                 * quedaría no buffer de teclado e sería lido na seguinte
                 * iteración do bucle.
                 */

                switch (operacion){
                    case 's':
                        suma = sum(u, v, N1, N2);
                        /* Cópiase o vector resultante da función a suma
                         * (comparten memoria).
                         */
                        if (suma==NULL){
                            printf("Os vectores non teñen a mesma dimensión. "
                                    "Non se pode realizar a suma nin a "
                                    "multiplicación\n");
                        }
                        else{
                            printf("Elementos do vector suma:\n");
                            for (i=0; i<N1; i++){
                                printf("%f\t", suma[i]);
                            }
                            printf("\n");
                        }
                        
                        free(suma); 
                        /* A memoria reservada é liberada (non se vai 
                         * empregar máis).
                         */
                        break;      // O case 's' remata aquí.
                        
                    case 'm':
                        multip = mul(u, v, N1, N2);
                        /* Cópiase o vector resultante da función a multip
                         * (comparten memoria).
                         */
                        if (multip==NULL){
                            printf("Os vectores non teñen a mesma dimensión. "
                                    "Non se pode realizar a suma nin a "
                                    "multiplicación\n");
                        }    
                        else{
                            printf("Elementos do vector multiplicación:\n");
                            for (i=0; i<N2; i++){
                                printf("%f\t", multip[i]);
                            }
                            printf("\n");
                        }
                        
                        free(multip); 
                        /* A memoria reservada é liberada (non se vai 
                         * empregar máis).
                         */
                        
                        break;      // O case 'm' remata aquí.
                        
                    case 't':
                        tens = ten(u, v, N1, N2);
                        /* Cópiase o vector resultante da función a tens
                         * (comparten memoria).
                         */
                        printf("Matriz resultante da multiplicación "
                                "tensorial:\n");
                        
                        // Imprímese unha matriz:
                        for (j=0; j<N2; j++){
                            printf("\tColumna %d", j+1);
                        }
                        printf("\n");
                        for (i=0; i<N1; i++){
                            printf("Fila %d\t", i+1);
                            for (j=0; j<N2; j++){
                                printf("%f\t", *(tens+i*N2+j));
                            }
                            printf("\n");
                        }
                        
                        free(tens); 
                        /* A memoria reservada é liberada (non se vai 
                         * empregar máis).
                         */
                        
                        break;        // O case 't' remata aquí.
                }

            }while(operacion != 'f');

            fclose(vectores);         // Peche do arquivo.
        }
    }
    
    return (EXIT_SUCCESS);
}

