/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autores: Xiana Carrera e Javier Beiro
 *
 * Data: 25 de novembro de 2019, 16:06
 * Este é un programa para a proba de operacións con enteiros de gran tamaño
 * empregando unha biblioteca.
 */

#include <stdio.h>
#include <stdlib.h>
#include "bib.h"

/*
 * 
 */

int main(int argc, char** argv) {
    int selector, sel2, d, y, z;
    char x;
    char *numero1, *numero2, *factorial, *modulo;
    bignum numero_1, numero_2, factor, mod, resultado;

    /* En primeiro lugar, pedimos os datos dos dous números cos que se van
     * realizar as operacións.
     */
    
    printf("--- Número 1 ---\n");
    numero1 = (char*)malloc(sizeof(char));
    z=0;
    printf("Introduza o número:\n");
    scanf("%c", &x);        
    while(x != '\n'){       // Paramos ao atopar un salto de liña.
        numero1[z] = x;      // Gardamos o primeiro carácter.
        /* Temos que ir carácter a carácter en lugar de almacenalos todos
         * xuntos porque non sabemos canta cantidade de memoria se precisará,
         * o que nos obriga a ir facendo reallocs para axustala.
         */ 
        numero1 = (char*)realloc(numero1, (z+2)*sizeof(char));
        /* Aumentamos o tamaño, axustándoo iterativamente (non sabemos
         * a lonxitude de antemán).
         */
        z++;
        scanf("%c", &x);    // Seguinte carácter.
    }
    numero1[z] = '\0';       // Pechamos a cadea.
    numero_1 = str2bignum(numero1);     // Creamos o bignum correspondente.

    printf("--- Número 2 ---\n");
    numero2 = (char*)malloc(sizeof(char));
    z=0;
    printf("Introduza o número:\n");
    scanf("%c", &x);        
    while(x != '\n'){    
        numero2[z] = x;    
        numero2 = (char*)realloc(numero2, (z+2)*sizeof(char));
        z++;
        scanf("%c", &x);   
    }
    numero2[z] = '\0';     
    numero_2 = str2bignum(numero2);

    free(numero1);
    free(numero2);
    // As cadeas de caracteres iniciais xa non nos fan falta.
    
    system("clear");            // Limpamos a pantalla.
    do{
        // Mostramos un menú.
        printf("----Indique a operación a realizar---- \n\n");
        printf("Suma --------------------------------> 1\n");
        printf("Resta -------------------------------> 2\n");
        printf("Multiplicación ----------------------> 3\n");
        printf("Factorial ---------------------------> 4\n");
        printf("Resto da división -------------------> 5\n");
        printf("Multiplicación módulo n -------------> 6\n");
        printf("Cambiar números ---------------------> 7\n");
        printf("Saír --------------------------------> 8\n");
        printf("Realizar a operación: ");
        scanf("%d", &selector);
        printf("\n");
        getchar();    
        // Con getchar recollemos o salto de liña que queda no buffer.

        switch(selector){
            case 1:         
                resultado = add(numero_1, numero_2);
                printf("Resultado da suma:\n");
                imprimir(resultado);    // Mostramos o resultado.
                free(resultado.val);
                /* Debemos liberar a memoria reservada para resultado.val
                 * porque se realizamos outra operación, resultado.val quedaría
                 * asignado a un novo enderezo. Entón, o anterior sería
                 * inaccesible e non habería posibilidade de reempregalo.
                 */
                break;

            case 2:         
                resultado = sub(numero_1, numero_2);
                printf("Resultado da resta:\n");
                imprimir(resultado);
                free(resultado.val);
                break;

            case 3:
                resultado = mult(numero_1, numero_2);
                printf("Resultado da multiplicación:\n");
                imprimir(resultado);
                free(resultado.val);
                break;

            case 4:
                printf("Realizar o factorial de...\n");
                printf("Número 1 --------> 1\n");
                printf("Número 2 --------> 2\n");
                printf("Outro número -----> 3\n");
                /* Damos a posibilidade de usar un número diferente aos dous
                 * iniciais.
                 */                
                scanf("%d", &sel2);
                getchar();

                switch(sel2){
                    case 1:
                        resultado = fact(numero_1);
                        break;

                    case 2:
                        resultado = fact(numero_2);
                        break;

                    case 3:     
                        factorial = (char*)malloc(sizeof(char));
                        z=0;
                        printf("Introduza o número:\n");
                        scanf("%c", &x);        
                        while(x != '\n'){    
                            factorial[z] = x;    
                            factorial = (char*)realloc(factorial, 
                                    (z+2)*sizeof(char));
                            z++;
                            scanf("%c", &x);   
                        }
                        factorial[z] = '\0';     
                        factor = str2bignum(factorial);
                        free(factorial);
                        
                        resultado = fact(factor);
                        free(factor.val);
                        break;
                        
                    default:
                        printf("A opción seleccionada non é ningunha das "
                        "dispoñibles.\n\n");
                }        
                
                if (sel2==1 || sel2==2 || sel2==3){
                    if (resultado.tam==-5){     // Condición de erro.
                        printf("Non é posible realizar o factorial de números "
                                "negativos.\n\n");
                    }
                    else{
                        printf("Resultado do factorial:\n");
                        imprimir(resultado);
                        free(resultado.val);
                    }
                }
                break;

            case 5:
                printf("Introduza 1 para dividir o primeiro número entre o "
                        "segundo ou outro número para dividir o segundo entre o"
                        " primeiro:\n");
                scanf("%d", &d);
                if (d==1){
                    resultado = remainder1(numero_1, numero_2);
                }
                else{
                    resultado = remainder1(numero_2, numero_1);
                }
                
                if (resultado.tam==-5){
                    printf("Non é posible a división entre 0.\n\n");
                }
                else{
                    printf("Resto da divisón:\n");
                    imprimir(resultado);
                    free(resultado.val);
                }
                break;

            case 6:
                printf("Indique o módulo da operación.\n");
                modulo = (char*)malloc(sizeof(char));
                z=0;
                printf("Introduza o número:\n");
                scanf("%c", &x);        
                while(x != '\n'){    
                    modulo[z] = x;    
                    modulo = (char*)realloc(modulo, (z+2)*sizeof(char));
                    z++;
                    scanf("%c", &x);   
                }
                modulo[z] = '\0';     
                mod = str2bignum(modulo);
                free(modulo);

                resultado = multmod(numero_1, numero_2, mod);

                if (resultado.tam==-5){
                    printf("O módulo non pode ser negativo nin cero.\n\n");
                }
                else{
                    printf("Resultado da operación en módulo ");                    
                    for (y = mod.tam - 1; y >= 0; y--) {
                        printf("%d", mod.val[y]);
                    }
                    printf(":\n");
                    imprimir(resultado);
                    free(mod.val);
                    free(resultado.val);
                }
                break;

            case 7:
                printf("Introduza 1 para cambiar o primeiro número ou 2 para "
                        "cambiar o segundo:\n");
                scanf("%d", &sel2);     // Reempregamos sel2.
                getchar();
                if (sel2==1){
                    free(numero_1.val);     // Liberamos a memoria antiga.
                    
                    numero1 = (char*)malloc(sizeof(char));
                    z=0;
                    printf("Introduza o número:\n");
                    scanf("%c", &x);        
                    while(x != '\n'){    
                        numero1[z] = x;    
                        numero1 = (char*)realloc(numero1, (z+2)*sizeof(char));
                        z++;
                        scanf("%c", &x);   
                    }
                    numero1[z] = '\0';     
                    numero_1 = str2bignum(numero1);
                    free(numero1);
                }
                else if (sel2==2){
                    free(numero_2.val);
                    
                    numero2 = (char*)malloc(sizeof(char));
                    z=0;
                    printf("Introduza o número:\n");
                    scanf("%c", &x);        
                    while(x != '\n'){    
                        numero2[z] = x;    
                        numero2 = (char*)realloc(numero2, (y+2)*sizeof(char));
                        z++;
                        scanf("%c", &x);   
                    }
                    numero2[z] = '\0';     
                    numero_2 = str2bignum(numero2);
                    free(numero2);
                }
                else{           // Mensaxe de aviso.
                    printf("O valor elixido non ten sentido para esta "
                            "operación.\n\n");
                }
                printf("\n");
                break;
                
            case 8:
                printf("Pechando programa...");
                break;

            default:            // Mensaxe de aviso.
                printf("A opción seleccionada non é ningunha das "
                        "dispoñibles.\n\n");
        }

    }while(selector!=8);

    return (EXIT_SUCCESS);
}