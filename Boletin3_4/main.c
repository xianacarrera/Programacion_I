/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 *
 * Data: 21 de outubro de 2019, 15:43
 * Este programa crea unha estructura para un polinomio, avalía o seu valor nun
 * punto, imprime os seus coeficientes non nulos e calcula o seu polinomio 
 * derivado.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>       // Necesaria para usar a función pow.

/*
 * 
 */

typedef struct{         // Defínese a estructura t_polinomio.
    int pgrao;
    int coeficientes[7];    // Tamaño 7 para gardar 6 coeficientes.
} t_polinomio;

void Inicia(int grao, int coe[], t_polinomio *pol)
{
    int i;
    
    pol->pgrao = grao;        // Gárdase o grao introducido.
    for (i=0; i<=grao; i++){
       pol->coeficientes[i] = coe[i];   // Gárdanse os coeficientes introducidos.
    }
}

double Avaliar(t_polinomio pol, double xpt)
{
    int i;
    double ypt=0;
    
    for (i=pol.pgrao; i>=0; i--){            
        ypt += pol.coeficientes[i]*pow(xpt, i);      
                        // O valor de x do punto introducido elévase ao grao
                        // correspondente e multiplícase polo seu coeficiente.
    }
    
    return ypt;
}

void Mostrar(t_polinomio pol)
{
    int i;
    
    printf("A continuación móstranse os coeficientes non nulos:\n");
    for (i=pol.pgrao; i>=0; i--){
        if (pol.coeficientes[i]!=0){
            printf("\tO valor do coeficiente de grao %d é %d\n", i,
                    pol.coeficientes[i]);
        }
    }
    printf("\n");   // Faise unha separación para que no caso de que se todos os
                    // coeficientes sexan nulos se note que non se mostra nada.
}

void Derivar(t_polinomio pol, t_polinomio *der)
{
    int i;
    
    der->pgrao = pol.pgrao-1;
    for (i=pol.pgrao-1; i>=0; i--){
        der->coeficientes[i] = (i+1)*pol.coeficientes[i+1];
                // Cada coeficiente do polinomio derivado obtense multiplicando
                // o grao inmediatamente superior do polinomio orixinal polo
                // seu coeficiente asociado.
    }
}

int main(int argc, char** argv) {
    int grao, i;
    int coe[7];
    t_polinomio polin, deriv;
    double xpt, ypt;
    
    printf("Introduza o grao do polinomio (sendo 5 o máximo):\n");
    scanf("%d", &grao);
    for (i=grao; i>=0; i--){
        printf("Introduza o coeficiente de grao %d:\n", i);
        scanf("%d", &coe[i]);
    }
    Inicia(grao, coe, &polin);        // Chamada á función Inicia.
    
    printf("Introduza a coordenada x dun punto:\n");
    scanf("%lf", &xpt);
    ypt = Avaliar(polin, xpt);         // Chamada á función Avaliar.
    printf("O valor do polinomio no punto %f é %f\n", xpt, ypt);
    
    Mostrar(polin);                 // Chamada á función Mostrar.
    
    Derivar(polin, &deriv);         // Chamada á función Derivar.
    if (deriv.pgrao>=0){
        printf("O polinomio derivado ten grao %d\n", deriv.pgrao);
    }
    else{   // Se o polinomio é de grao 0, o derivado tería grao negativo.
        printf("O polinomio derivado vale 0\n");
    }
    for (i=deriv.pgrao; i>=0; i--){
        printf("\tO valor do coeficiente de grao %d do polinomio "
                "derivado é %d\n", i, deriv.coeficientes[i]);
    }

    return (EXIT_SUCCESS);
}

