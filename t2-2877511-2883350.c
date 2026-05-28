/*============================================================================*/
/** ICSF13 - 2026-1 - TRABALHO 2                                              */
/*============================================================================*/
/*  20 de maio de 2026                                                        */
/*----------------------------------------------------------------------------*/
/**                               Autores                                     */
/*  Guilherme Cardoso Leal                                                    */
/*      Número de matrícula: 2883350                                          */
/*  Daniel Cury Teodoro de Oliveira                                           */
/*      Número de matrícula: 2877511                                          */
/*============================================================================*/

#include <string.h>
#include <stdlib.h>
#include "trabalho2.h"
#include "wavfile.h"

/*============================================================================*/
/**                               Função 1                                    */

void mudaGanho (double* dados, int n_amostras, double ganho) {

    int i;

    // Multiplica cada dado pelo ganho.
    for (i = 0; i < n_amostras; i++){
        dados [i] = ganho * dados [i];
    }

}

/*============================================================================*/
/**                               Função 2                                    */

void misturaDados (double* dados1, double* dados2, double* saida, int n_amostras) {

    int i;

    for (i = 0; i < n_amostras; i++){ // Loop que acessa do ínicio ao fim dos vetores simultaneamente.
        saida[i] = dados1[i] + dados2[i]; // Coloca a soma dos vetores deentrada dentro do vetor de saída.
    }
}

/*============================================================================*/
/**                               Função 3                                    */

void inverteSinal (double* dados, int n_amostras) {

    int i;
    double aux; // Serve para ajudar na troca.

    // Invertendo o vetor (trocando cada dado por seu simétrico).
    for (i = 0; i < n_amostras / 2; i++){
        aux = dados [i];
        dados [i] = dados [(n_amostras - 1) - i];
        dados [(n_amostras - 1) - i] = aux;
        // Obs.: (n_amostras - 1) - i = "i máximo" - i.
    }

}

/*============================================================================*/
/**                               Função 4                                    */

void atrasaSinal (double* dados, int n_amostras, int atraso){

    int i;
    double *clone;

    clone = (double*) malloc(n_amostras * sizeof(double)); // Cria um vetor igual ao vetor "dados".
    for (i = 0; i < n_amostras; i++) // Loop para "clonar" o vetor "dados".
        clone[i] = dados[i];
    for (i = 0; i < n_amostras; i++){
        if (i < atraso)
            dados[i] = 0;
        else
            dados[i] = clone[i - atraso];
    }
    free(clone);
}

/*============================================================================*/
/**                               Função 5                                    */

//largura deve ser um número ímpar entre 3 e o número de amostras

//[p-(largura-1)/2, p+(largura-1)/2].

void filtroDaMedia (double* dados, int n_amostras, int largura) {

    int p;
    double *original;

    original = (*double) malloc (n_amostras * sizeof(double));

    // Cópia do vetor "dados".
    for (p = 0; p < n_amostras; p++){
        original [p] = dados [p];
    }

    p = 0;
    while (p - (largura - 1) / 2 < 0){
        p++;
    }

    

    free (original);

}

/*============================================================================*/
/**                             Função Extra                                  */



/*============================================================================*/
