/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   def.h
 * Autores: Xiana Carrera e Javier Beiro
 *
 * Data: 25 de novembro de 2019, 16:12
 * Esta biblioteca permite realizar operacións con números enteiros de gran
 * tamaño.
 */

#ifndef DEF_H
#define DEF_H

typedef struct{
    int sign;
    int tam;
    int *val;
} bignum;

bignum str2bignum (char *str);
bignum add (bignum a, bignum b);
bignum sub (bignum a, bignum b);
bignum mult (bignum a, bignum b);
bignum remainder1 (bignum a, bignum n);
bignum fact (bignum n);
bignum multmod (bignum a, bignum b, bignum n);
int comparar (bignum a, bignum b);
void imprimir(bignum resultado);


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* DEF_H */

