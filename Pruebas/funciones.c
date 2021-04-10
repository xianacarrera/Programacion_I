
#include <stdlib.h>
#include <string.h>
#include "prueba.h"

bignum str2bignum (char *str)
{
    bignum num;
    int i=0;

    /* A miña intención é que no primeira posición da str poida haber un signo
     * (positivo ou negativo) ou non. Neste caso interpretarase como un número
     * positivo. Para saber cal é a cifra máis significativa na segunda (ou primeira)
     * posición haberá un s (a primeira cifra) ou un n (a última).
     */


    if (str[0]=='-' || str[0]=='+'){
        i=0;
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
    else {
        num.sign = 0; // 0 representa que o signo é positivo.
        num.tam = strlen(str) - 1;

        num.val = (int*)malloc(num.tam*sizeof(int));
        if (str[0]=='n'){           // n - la última es la más significativa
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

    if (a.tam<b.tam){
        c = a;
        a = b;
        b = c;
    }
    else if (a.tam==b.tam){
        do{
            if (b.val[i]>a.val[i]){
                c = a;
                a = b;
                b = c;
            }
            i++;
        }while((a.val[i-1]==b.val[i-1]) && i<a.tam);
    }

    if (a.sign!=b.sign){
        b.sign = a.sign;
        totsum = sub(a,b);
        return totsum;
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

    return totsum;
}

bignum sub (bignum a, bignum b)
{
    // Si tienen distinto signo, llamar a add porque se acaban sumando
    // +-(-)=++ o --(+)=--
    bignum totrest, c;
    int i=0, valorb, acarreo=0, resta, stop=0;

    if (b.sign==1){
        b.sign = 0;
    }
    else{
        b.sign = 1;
    }           // Se podría optimizar esto?

    if (a.tam<b.tam){
        c = a;
        a = b;
        b = c;
    }
    else if (a.tam==b.tam){
        do{
            if (b.val[b.tam-1-i]>a.val[a.tam-1-i]){
                c = a;
                a = b;
                b = c;
                stop = 1;
            }
            i++;
        }while(stop=0 && b.tam-1-i>=0);
    }

    if (a.sign==b.sign){
        totrest = add(a, b);
        return totrest;
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
            resta = a.val[i]+10-acarreo-valorb;
            acarreo = 1;
        }
        else{
            acarreo = 0;
        }
        totrest.val[i] = resta;
    }

    do{
        i--;
        if (totrest.val[i]!=0){         // Hace falta !=0?
            totrest.tam = i+1;
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

bignum mult (bignum a, bignum b)
{
    bignum totmult, c, lin;
    int i, j, cont, multi, acarreo=0;

    if (a.tam<b.tam){
        // Aunque este if no es necesario, se hace para una optimización en el
        // tiempo de ejecución de las operaciones posteriores.
        c = a;
        a = b;
        b = c;
    }

    lin.sign = 0;
    totmult.tam = 1;              // Temporal
    totmult.val = (int*)malloc(sizeof(int));
    totmult.val[0] = 0;

    for (i=0; i<(a.tam+b.tam); i++){
        totmult.val[i] = 0;          // Inicialización
    }

    for (i=0; i<b.tam; i++){
        lin.val = (int*)malloc((a.tam+1+i)*sizeof(int));
        // Por ejemplo, el tamaño de la primera línea puede ser el tamaño de
        // b o una unidad mayor, por lo que reservamos una unidad más para
        // asegurar que haya espacio. La segunda línea mide una unidad más
        // al haber un 0 a la derecha, y así sucesivamente.
        cont = i;
        for (j=i-1; j>=0; j--){
            lin.val[j] = 0;
        }

        for (j=0; j<a.tam; j++){
            multi = b.val[i]*a.val[j] + acarreo;
            acarreo = multi/10;
            lin.val[cont] = multi%10;
            cont++;
        }

        if (acarreo){
            lin.tam = a.tam+i+1;
            lin.val[cont] = acarreo;
        }
        else{
            lin.tam = a.tam+i;
            lin.val = (int*)realloc(lin.val, (a.tam+i)*sizeof(int));
        }

        totmult = add(totmult, lin);
        // Problema: repetición malloc???
        free(lin.val);
    }

    totmult.sign = (a.sign+b.sign)%2;
    return totmult;
}

bignum fact(bignum a){
    int i;
    bignum resta1;
        resta1.tam=1;
        resta1.sign=0;
        resta1.val=malloc(1* sizeof(int));
        *resta1.val=1;

    bignum factorial;
        factorial.tam=a.tam;
        factorial.val=malloc(a.tam* sizeof(int));
            for(i=0; i<a.tam; i++){
                factorial.val[i]=a.val[i];
            }
        factorial.sign=a.sign;


     while(a.tam>1 || (a.tam== 1 && a.val[0]!=1)){
         a = sub(a,resta1);
         factorial=mult(factorial,a);
     }

    return factorial;
}

bignum reminder(bignum a, bignum b){
    int i;
    //-----------------------------------RESULTADO-DE-LA-DIVISIÓN-REAL--------------------------------------------------
    bignum cociente;
    cociente.sign=0;
    cociente.val = malloc(1* sizeof(int));
    cociente.val[0]=0;
    cociente.tam=1;

    //-----------------------------------SUMA-UNA-UNIDAD-A-UN-BIGNUM----------------------------------------------------
    bignum suma1;
    suma1.val = malloc(1* sizeof(int));
    suma1.val[0]=1;
    suma1.tam=1;
    suma1.sign=0;

    //----------------------------------ALMACENA-EL-VALOR-DE-LA-VARIABLE-"a"--------------------------------------------
    bignum valora;
    valora.val = malloc(1* sizeof(int));

    //----------------------------------CALCULO-DEL-RESTO-PARA-FINALIZAR-BUCLE------------------------------------------
    bignum comparacion;

    //----------------------------------CÁLCULO-DEL-LOS-DISTINTOS-VALORES-QUE-FORMAN-EL-COCIENTE------------------------
    bignum multiplicando;
    multiplicando.sign=0;
    multiplicando.tam=a.tam-b.tam+1;
    multiplicando.val= malloc(multiplicando.tam* sizeof(int));
    multiplicando.val[multiplicando.tam-1]=1;
    for(i=0; i<multiplicando.tam-1; i++){
        multiplicando.val[i]=0;
    }

    //--------------------------------CASO-EN-EL-QUE-AMBOS-NUMEROS-SON-POSITIVOS/NEGATIVOS------------------------------
    if(a.sign==b.sign) {
        comparacion=sub(a,b);
        if (a.tam >= b.tam) {

            while (a.tam >= b.tam && comparacion.sign != 1) {

                valora.tam = a.tam;
                valora.sign = a.sign;
                valora.val = realloc(valora.val, valora.tam * sizeof(int));
                for (i = 0; i < a.tam; i++) {
                    valora.val[i] = a.val[i];
                }

                a = sub(a, mult(b, multiplicando));
                if (a.sign == 1) {
                    multiplicando.tam = multiplicando.tam - 1;
                    multiplicando.val[multiplicando.tam - 1] = 1;
                    multiplicando.val = realloc(multiplicando.val, multiplicando.tam * sizeof(int));

                    //devuelvo "a" a su valor original
                    a.sign = valora.sign;
                    a.tam = valora.tam;
                    for (i = 0; i < valora.tam; i++) {
                        a.val[i] = valora.val[i];
                    }

                } else {
                    cociente = add(cociente, multiplicando);
                }

                comparacion = sub(a, b);
            }
        }
        else{
            cociente.val=malloc(1* sizeof(int));
            cociente.val[0]=0;
            cociente.tam=1;
            cociente.sign=0;
        }
    }
    //-----------------------------------------CASO-CON-DIFERENTES-SIGNOS-----------------------------------------------
    else{
        a.sign=0;
        b.sign=0;
        if(a.tam>=b.tam){
            while (a.tam >= b.tam && comparacion.sign != 1) {

                valora.tam = a.tam;
                valora.sign = a.sign;
                valora.val = realloc(valora.val, valora.tam * sizeof(int));
                for (i = 0; i < a.tam; i++) {
                    valora.val[i] = a.val[i];
                }

                a = sub(a, mult(b, multiplicando));
                if (a.sign == 1) {

                    multiplicando.tam = multiplicando.tam - 1;
                    multiplicando.val[multiplicando.tam - 1] = 1;
                    multiplicando.val = realloc(multiplicando.val, multiplicando.tam * sizeof(int));
                    //devuelvo "a" a su valor original
                    a.sign = valora.sign;
                    a.tam = valora.tam;
                    for (i = 0; i < valora.tam; i++) {
                        a.val[i] = valora.val[i];
                    }

                } else {
                    cociente = add(cociente, multiplicando);
                }
                comparacion = sub(a, b);
            }
            cociente.sign=1;
            comparacion.sign=0;
            b.sign=1;
            if(add(b, comparacion).sign==1){
                cociente=add(cociente, suma1);
            }
        }
        else{
            cociente.val=malloc(1* sizeof(int));
            cociente.val[0]=1;
            cociente.tam=1;
            cociente.sign=1;
        }
    }

    return cociente;
}

//------------------------------------división con restas indefinidas---------------------------------------------------
bignum reminder1(bignum a, bignum b){
    //---------------------------------------------variables-auxiliares-----------------------------
    bignum suma1;
    suma1.val = malloc(1* sizeof(int));
    suma1.val[0]=1;
    suma1.tam=1;
    suma1.sign=0;
    int i;
    //---------------------------------------------variables-principales-----------------------------
    bignum cociente;
    bignum resto;
    bignum resta_de_comparacion;

    if(a.sign==b.sign) {
        resta_de_comparacion=sub(a,b);

        if (resta_de_comparacion.sign == 1) {
            cociente.val[0] = 0;
            cociente.val[1] = '\0';
            cociente.tam = 1;
            cociente.sign = 0;

        }
        else if (resta_de_comparacion.sign == 0) {
            while (resta_de_comparacion.sign == 0) {
                resta_de_comparacion = sub(resta_de_comparacion, b);
                cociente = add(cociente, suma1);
            }
        }
    }
    else if(a.sign!=b.sign){
        int sig_a = a.sign;
        int sig_b = b.sign;
        a.sign=0;
        b.sign=0;
        resta_de_comparacion = sub(a,b);

        if(resta_de_comparacion.sign==0){
            while (resta_de_comparacion.sign == 0) {
                resta_de_comparacion = sub(resta_de_comparacion, b);
                cociente = add(cociente, suma1);
            }
            resto=add(b, resta_de_comparacion);
            if(resto.val[0]==0 && resto.tam==1){
                cociente.val = cociente.val;
            }
            else{
                cociente = add(cociente, suma1);
            }
            cociente.sign=1;
        }
        else{
            cociente.val[0] = 1;
            cociente.val[1] = '\0';
            cociente.tam = 1;
            cociente.sign = 1;
        }
    }
    return cociente;
}