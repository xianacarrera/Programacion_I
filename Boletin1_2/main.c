/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Autora: Xiana Carrera
 * Data: 23 de setembro de 2019, 16:14
 * Versión: 1
 * 
 * Este programa permite sumar dous números enteiros
 */

#include <stdio.h>      //Directivas preprocesador
#include <stdlib.h>
#define PI 3.1416

/*
 * 
 */
int main(int argc, char** argv) {    //COMEZO PARTE EXECUTIVA
    float r,a,p; //Declaración de variables locais
    // Lectura de datos
    printf ("Introduza o radio do círculo:");
    scanf("%f",&r);
    // Cálculo dos resultados
    p=2*PI*r;
    a=PI*r*r;
    //-------- Saída da información ----------*)
    printf ("Área do círculo = %f \n",a);
    printf ("Perímetro do círculo = %f \n",p);
    
    return (EXIT_SUCCESS);
}                           // FIN PARTE EXECUTIVA

