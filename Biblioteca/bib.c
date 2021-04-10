/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   implem.c
 * Autores: Xiana Carrera e Javier Beiro
 *
 * Data: 25 de novembro de 2019, 16:45
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib.h"

/*
 * 
 */

bignum str2bignum (char *str)
{
    bignum num;
    int i;
    /* {P} ≡ {(*str!=NULL) AND (str[0]=='+' OR str[0]=='-' OR 48<=str[0]<=57) 
     * AND (∀i: 0<=i<strlen(str): 48<=str[i]<=57)}
     * S ≡ str2bignum
     * {Q} ≡ {num.tam>=1 AND 0<num.sign<1 AND num.val != NULL AND
     * (∀i: 0<=i<num.tam: 0<=num.val[i]=9)} 
     */
    
    /* Na cadea que se pasa como argumento almacénase un número de forma normal,
     * é dicir, que se este é negativo, na primeira posición haberá un signo
     * '-', e se é positivo, pode haber un signo '+' ou non haber nada. No resto
     * de posicións irán cada unha das cifras. Por tanto, faremos a distinción 
     * de dous casos: un no que a primeira posición ten un signo e outro no que
     * xa hai unha cifra.
     */ 
    
    if (str[0]=='-' || str[0]=='+'){    // O signo indícouse explicitamente.
        if (str[0]=='-'){
            num.sign = 1;       // 1 representa que o signo é negativo.
        }
        else{
            num.sign = 0;       // 0 representa que o signo é positivo.
        }
        num.tam = strlen(str)-1;    // Houbo unha posición adicada ao signo.
        
        num.val = (int*)malloc(num.tam*sizeof(int));        

        for (i=0; i<num.tam; i++){
            num.val[i] = str[strlen(str)-1-i]-48;
            /* Réstase 48 para acceder ao valor do enteiro correspondente pola
             * tabla ASCII.
             */
        }    
    }
    else{     // O signo non se indicou, interprétase como un número positivo.
        num.sign = 0; 
        num.tam = strlen(str);  // Non houbo espazo adicado ao signo.
        
        num.val = (int*)malloc(num.tam*sizeof(int));

        for (i=0; i<num.tam; i++){
            num.val[i] = str[strlen(str)-1-i]-48;
        }
    }
    
    return num;
}

bignum add (bignum a, bignum b)
{
    bignum totsum, c;
    int suma, acarreo=0, comp, i, valorb;
    /* {P} ≡ {a.val != NULL AND  b.val != NULL AND b.tam>0 AND a.tam>0 AND 
     * 0<=a.sign<=1 AND 0<=b.sign<=1 AND (∀i: 0<=i<a.tam: 0<=a.val[i]<=9)
     * AND (∀i: 0<=i<b.tam: 0<=b.val[i]<=9)}
     * S ≡ add
     * {Q} ≡ {totsum.tam>0 AND 0<=totsum.sign<=1 AND totsum.val != NULL AND
     * (∀i: 0<=i<num.tam: 0<=num.val[i]=9) AND totsum==a+b} 
     */
    
    comp = comparar(a, b);    
    // Comparamos os números para que a sexa o maior e b o menor.  
    if (comp==1){       // Se b>a, intercámbianse.
        c = a;
        a = b;
        b = c;
    }
    
    if ((a.sign!=b.sign) && (b.tam!=1 || b.val[0]!=0)){
        /* Se os números teñen signos distintos, o que se debe executar é unha
         * resta. Así, faise unha chamada á función correspondente.
         * Se algún dos operandos é cero, o seu signo será positivo. Porén,
         * se o outro operando é negativo, faríase a chamada á resta, cando non
         * é preciso, pois o resultado tanto da suma como da resta será 
         * este mesmo número. Engadindo a condición de que ningún dos dous
         * sexa 0 (pois, en tal caso, o 0 pasará a ser o bignum b)
         * evitamos unha chamada innecesaria.
         */
        
        b.sign = a.sign;        
        // Cámbiase o signo de b (necesario pola forma de executarse a resta).
        totsum = sub(a,b);
    }
    else{       // Os signos coinciden ou, como mínimo, un operando (b) é 0.
        totsum.sign = a.sign;

        totsum.val = (int*)malloc((a.tam+1)*sizeof(int));
        // Reservamos unha posición de máis por se houbera acarreo.

        for (i=0; i<a.tam; i++){
            if (i>=b.tam){
                // Se xa non quedan cifras de b por sumar, simulamos ceros.
                valorb = 0;
            }
            else{
                valorb = b.val[i];
            }
            suma = a.val[i] + valorb + acarreo;
            // O acarreo inicial é sempre 0.
            acarreo = suma/10;     // División enteira (dará 1 ou 0)..
            totsum.val[i] = suma%10;        // Módulo.
        }

        if (acarreo){           // acarreo!=0
            totsum.tam = a.tam+1;      
            // O tamaño do resultado será o tamaño do bignum maior (a) + 1.
            totsum.val[i] = acarreo;
            // Na última posición gardamos o acarreo final.
        }
        else{
            totsum.tam = a.tam;
            totsum.val = (int*)realloc(totsum.val, a.tam*sizeof(int));
            /* Chamamos a realloc para axustar a reserva de memoria a un
             * tamaño exacto e que non queden posicións reservadas que non se
             * usarán.
             */
            
        }
    }
    
    return totsum;
}

bignum sub (bignum a, bignum b)
{
    bignum totrest, c;
    int i, valorb, acarreo=0, resta, stop=0, comp;
    /* {P} ≡ {a.val != NULL AND  b.val != NULL AND b.tam>0 AND a.tam>0 AND 
     * 0<=a.sign<=1 AND 0<=b.sign<=1 AND (∀i: 0<=i<a.tam: 0<=a.val[i]<=9)
     * AND (∀i: 0<=i<b.tam: 0<=b.val[i]<=9)}
     * S ≡ sub
     * {Q} ≡ {totrest.tam>0 AND 0<=totrest.sign<=1 AND totrest.val != NULL AND
     * (∀i: 0<=i<totrest.tam: 0<=totrest.val[i]=9) AND totrest==a-b} 
     */

    
    // Primeiro cambiamos o signo do segundo operando, por ser unha resta.
    if (b.sign==1){
        b.sign = 0;
    }
    else{
        b.sign = 1;
    }
    
    comp = comparar(a, b);
    if (comp==1){
        c = a;
        a = b;
        b = c;
    }       // b será o menor bignum.
    
    if ((a.sign==b.sign) && (b.tam!=1 || b.val[0]!=0)){
        totrest = add(a, b);
        /* Se tras facer o cambio de signo previo os signos de a e b coinciden,
         * o que se ten que executar é unha suma.
         * Como na función add, poñemos a condición de que ningún dos bignum
         * sexa 0 para evitar chamadas innecesarias.
         */ 
        
    }        
    else{   // Os signos de a e b non coinciden ou, como mínimo, b é 0.
        totrest.val = (int*)malloc(a.tam*sizeof(int));

        for (i=0; i<a.tam; i++){
            if (i>=b.tam){
                // Se xa se restaron todas as cifras de b, simulamos ceros.
                valorb = 0;
            }
            else{
                valorb = b.val[i];
            }
            resta = a.val[i]-acarreo-valorb;
            if (resta<0){
                resta += 10;
                // Sumamos 10 para que quede positivo e poñemos o acarreo a 1.
                acarreo = 1;
            }
            else{
                acarreo = 0;
            }
            totrest.val[i] = resta;     
            // Gardamos o valor do resultado na posición correspondente.
        }

        do{
            i--;
            if (totrest.val[i]){  
                // Buscamos o último valor non nulo para determinar o tamaño.
                totrest.tam = i+1;
                stop = 1;
            }
        }while (totrest.val[i]==0 && i>0);

        if (stop==0){       // Todas as posicións teñen gardado un 0.
            totrest.tam = 1;
            totrest.val = (int*)realloc(totrest.val, sizeof(int));
            totrest.sign = 0;   // O signo do 0 é positivo. 
        }
        else{
            totrest.val = (int*)realloc(totrest.val, totrest.tam*sizeof(int));
            totrest.sign = a.sign;
            // O signo será o do maior bignum (a).
        }
        
    }
    
    return totrest;
}

bignum mult (bignum a, bignum b)
{
    bignum totmult, c, lin;
    int i, j, cont, multi, acarreo;
    /* {P} ≡ {a.val != NULL AND  b.val != NULL AND b.tam>0 AND a.tam>0 AND 
     * 0<=a.sign<=1 AND 0<=b.sign<=1 AND (∀i: 0<=i<a.tam: 0<=a.val[i]<=9)
     * AND (∀i: 0<=i<b.tam: 0<=b.val[i]<=9)}
     * S ≡ mult
     * {Q} ≡ {totmult.tam>0 AND 0<=totmult.sign<=1 AND totmult.val!=NULL AND
     * (∀i: 0<=i<totmult.tam: 0<=totmult.val[i]=9) AND totmult==a*b}
     */
    
    if (a.tam<b.tam){
        /* Aínda que este paso non é totalmente necesario, faise para unha 
         * optimización no tempo de execución das operacións posteriores. 
         */
        c = a;
        a = b;
        b = c;
    }
    
    /* En lin iremos gardando o resultado de multiplicar a por cada unha 
     * das cifras de b.
     */
    
    lin.sign = 0;
    // Temporalmente, gardamos en totmult o valor 0.
    totmult.sign = 0;
    totmult.tam = 1;
    totmult.val = (int*)malloc(sizeof(int)); 
    totmult.val[0] = 0;
    
    for (i=0; i<b.tam; i++){ 
        // Repetimos a operación para todas as cifras de b.
        lin.val = (int*)malloc((a.tam+1+i)*sizeof(int));     
        /* Na primeira línea, o tamaño de lin pode ser igual que o tamaño de a
         * ou unha unidade maior (se hai acarreo). Na segunda línea, como
         * engadimos un 0 á dereita, aumentamos en 1 o tamaño máximo, e así
         * sucesivamente.
         */
        cont = i;      
        /* Con este contador iremos desplazando cada línea unha posición á 
         * esquerda nas sucesivas iteracións.
         */
        for (j=i-1; j>=0; j--){
            /* Ao facer estes desprazamentos, temos que simular ceros para as
             * posicións que quedan á dereita.
             */
            lin.val[j] = 0;
        }
        
        acarreo = 0;        // Reinicio do acarreo.
        for (j=0; j<a.tam; j++){
            multi = b.val[i]*a.val[j] + acarreo;
            // Multiplicamos e engadimos o acarreo do cálculo anterior.
            acarreo = multi/10;
            lin.val[cont] = multi%10;   
            // O contador non coincide nin con i nin con j. 
            cont++;
        }
        
        if (acarreo){       // acarreo!=0
            lin.tam = a.tam+i+1;
            lin.val[cont] = acarreo;
        }
        else{
            lin.tam = a.tam+i;
            /* Non facemos un realloc porque a memoria reservada liberarase
             * igualmente.
             */            
        }
        
        totmult = add(totmult, lin);
        free(lin.val);                
    }
    
    if (totmult.tam==1 && totmult.val[0]==0){
        totmult.sign = 0;       // O signo do é positivo.
    }
    else{
        totmult.sign = (a.sign+b.sign)%2;
        // (0+0)%2 = (1%1)%2 = 0 e (1+0)%2 = (0+1)%2 = 1
    }
    
    return totmult;
}

bignum remainder1 (bignum a, bignum n)
{
    bignum remainder;
    int mayor, i, cont=0, comp, m, j;
    /* {P} ≡ {a.val != NULL AND n.val != NULL AND n.tam>0 AND a.tam>0 AND 
     * 0<=a.sign<=1 AND 0<=n.sign<=1 AND (∀i: 0<=i<a.tam: 0<=a.val[i]<=9)
     * AND (∀i: 0<=i<n.tam: 0<=b.val[i]<=9) AND (n.tam != 1 OR n.val[0] != 0)}
     * S ≡ remainder1
     * {Q} ≡ {remainder.tam>0 AND 0<=remainder.sign<=1 AND remainder.val!=NULL 
     * AND (∀i: 0<=i<remainder.tam: 0<=remainder.val[i]=9) AND remainder==a%n}
     */
    
    if (n.tam==1 && n.val[0]==0){
        remainder.tam = -5;
        // Empregaremos isto para avisar de que non se pode dividir por 0.
    }
    else{
        mayor = comparar(a, n);

        if (mayor==0){      // Os dous números son iguais, polo tanto, resto 0.
            remainder.tam = 1;
            remainder.sign = 0;
            remainder.val = (int*)malloc(sizeof(int));
            remainder.val[0] = 0;
        }
        else if (mayor==1){
            /* O resultado será igual ao dividendo. Copiamos os datos de a en
             * remainder (non podemos igualalos porque posteriormente faremos
             * un free de remainder.val e, entón, tamén liberaríamos a.val, que
             * fai falta no resto de operacións.
             * É necesario separar este caso porque o algoritmo empregado non
             * funcionaría correctamente.
             */
            remainder.tam = a.tam;
            remainder.sign = a.sign;
            remainder.val = (int*)malloc(a.tam*sizeof(int));
            for (i=0; i<a.tam; i++){
               remainder.val[i] = a.val[i]; 
            }
        }
        else{
            remainder.sign = 0;     // Temporal.
            remainder.tam = n.tam;  // Este é o tamaño inicial.
            remainder.val = (int*)malloc(n.tam*sizeof(int));
            for (i=a.tam-1; i>a.tam-1-n.tam; i--){
                remainder.val[remainder.tam-1-cont] = a.val[i];
                // Copiamos as n.tam primeiras cifras do dividendo en remainder.
                cont++;
                // Cont é o número de díxitos do dividendo xa "usados".
            }

            n.sign = 0;     // Para chamar correctamente á resta.
            do{
                comp = comparar(remainder, n);
                /* Queremos que os restos intermedios (e o final) sexan menores 
                 * que o divisor.
                 */
                while (comp<=0){
                    remainder = sub(remainder, n);
                    /* Se o resto intermedio non é menor que o divisor,
                     * restámoslle este último e volvemos facer a comparación.
                     */
                    comp = comparar(remainder, n);
                }
                if (a.tam-1-cont>=0){     // Aínda quedan cifras do dividendo.
                    remainder.val = (int*)realloc(remainder.val, 
                            (remainder.tam+1)*sizeof(int));
                    /* A chamada á resta vai reaxustando a memoria reservada.
                     * Agora engadímoslle unha posición máis para poder colocar
                     * o seguinte díxito do dividendo.
                     */
                    
                    for (i=remainder.tam; i>0; i--){
                        remainder.val[i] = remainder.val[i-1];
                        // Facemos un oco ápara poñer o seguinte número.
                    }
                    remainder.tam = remainder.tam+1;
                    remainder.val[0] = a.val[a.tam-1-cont];
                }
                cont++;
            }while (a.tam-cont>=0);
            /* A condición é >=0 para que tamén se volva evaluar tras colocar
             * a última cifra.
             */

            if (remainder.tam!=1 || remainder.val[0]!=0){
                remainder.sign = a.sign;
            }
            // Se o if non se cumpre, o signo queda como 0.
        }    
    }
    
    return remainder;
}

bignum fact (bignum n)
{
    int i;
    bignum resta1, factorial;
    /* {P} ≡ {n.val != NULL AND n.tam>0 AND n.sign==0 AND 
     * (∀i: 0<=i<n.tam: 0<=n.val[i]<=9)}
     * S ≡ fact
     * {Q} ≡ {factorial.tam>0 AND factorial.sign==0 AND factorial.val!=NULL AND
     * (∀i: 0<=i<factorial.tam: 0<=factorial.val[i]=9) AND factorial==n!}
     */
    
    if (n.sign==1){
        factorial.tam = -5;
        /* Empregaremos isto para avisar de que non se pode facer o factorial
         * de números negativos.
         */
        
    }
    else if (n.tam==1 && n.val[0]==0){     
        // O factorial de 0 é un caso especial, e daría 1.
        factorial.sign = 0;
        factorial.tam = 1;
        factorial.val = (int*)malloc(sizeof(int));
        factorial.val[0] = 1;
    }
    else{
        resta1.tam = 1;
        resta1.sign = 0;
        resta1.val = (int*)malloc(sizeof(int));
        resta1.val[0] = 1;
        
        // Copiamos n en factorial.
        factorial.sign = 0;
        factorial.tam = n.tam;
        factorial.val = (int*)malloc(n.tam*sizeof(int));
        for(i=0; i<n.tam; i++){
            factorial.val[i] = n.val[i];
        }

        while (n.tam>1 || n.val[0]!=1){
            n = sub(n,resta1);
            factorial = mult(factorial,n);
            /* A n imos restándolle 1 en cada iteración e multiplicámolo
             * por factorial, que garda o acumulado nas multiplicacións 
             * anteriores.
             */
        }
    }

    return factorial;
}

bignum multmod (bignum a, bignum b, bignum n)
{
    bignum result;
    /* {P} ≡ {a.val != NULL AND b.val != NULL AND n.val!=NULL AND 
     * a.tam>0 AND b.tam>0 AND n.tam>0 AND 0<=a.sign<=1 AND 0<=b.sign<=1 AND 
     * n.sign==0 AND (∀i: 0<=i<a.tam: 0<=a.val[i]<=9) AND
     * (∀i: 0<=i<b.tam: 0<=b.val[i]<=9) AND (∀i: 0<=i<n.tam: 0<=n.val[i]<=9) 
     * AND (n.tam != 1 OR n.val[0] != 0)}
     * S ≡ multmod
     * {Q} ≡ {result.tam>0 AND 0<=result.sign<=1 AND result.val!=NULL 
     * AND (∀i: 0<=i<result.tam: 0<=result.val[i]=9) AND
     * result==(a*b)%n}
     */
        
    if (n.sign==1 || (n.tam==1 && n.val[0]==0)){
        result.tam = -5;
        // O módulo non pode ser negativo nin 0.
    }
    else{
        result = remainder1(mult(a,b), n);
        // Primeiro multiplicamos e logo calculamos o resto.
    }
    
    return result;
}

int comparar (bignum a, bignum b)
{
    int mayor=0, i=0;
    /* {P} ≡ {a.val != NULL AND  b.val != NULL AND b.tam>0 AND a.tam>0 AND 
     * 0<=a.sign<=1 AND 0<=b.sign<=1 AND (∀i: 0<=i<a.tam: 0<=a.val[i]<=9)
     * AND (∀i: 0<=i<b.tam: 0<=b.val[i]<=9)}
     * S ≡ comparar
     * {Q} ≡ {mayor==-1 OR mayor==0 OR mayor==1 AND (a<b => mayor==-1) AND
     * (a==b => mayor==0) AND (a>b => mayor==1)}
     */
    
    // Comparamos os valores absolutos de dous bignums.
    if (a.tam<b.tam){  // Se os tamaños son distintos, xa sabemos cal é maior.
        mayor = 1;
    }
    else if (a.tam==b.tam){
        // Comparamos cifra a cifra ata atopar dúas que non sexan iguais.
        do{
            if (b.val[b.tam-1-i]>a.val[a.tam-1-i]){
                mayor = 1;
            }
            else if (b.val[b.tam-1-i]<a.val[a.tam-1-i]){
                mayor = -1;
            }
            i++;
        }while(mayor==0 && b.tam-1-i>=0);          
        /* Se en ningún momento se atopan dúas cifras distintas, os bignums son
         * iguais e mayor permanece como 0.
         */
    }
    else{
        mayor = -1;
    }
    
    return mayor;
}

void imprimir(bignum resultado)
{
    int y;
    /* {P} ≡ {resultado.val != NULL AND resultado.tam>0 AND 
     * 0<=resultado.sign<=1 AND 
     * (∀i: 0<=i<resultado.tam: 0<=resultado.val[i]<=9)}
     * S ≡ imprimir
     * {Q} ≡ {TRUE}
     */    
    
    // Esta función afórranos ter que repetir o mesmo código moitas veces.
    printf("Tamaño: %d\n", resultado.tam);
    if (resultado.sign == 1) {
        printf("-");
    } else {
        printf("+");
    }
    for (y = resultado.tam - 1; y >= 0; y--) {
        printf("%d", resultado.val[y]);
    }
    printf("\n\n");
}