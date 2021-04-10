/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   def.h
 * Author: Xiana
 *
 * Created on 25 de noviembre de 2019, 16:12
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


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* DEF_H */

