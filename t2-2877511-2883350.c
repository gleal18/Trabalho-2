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
        dados[i] = ganho * dados[i];
    }

}

/*============================================================================*/
/**                               Função 2                                    */

void misturaDados(double* dados1, double* dados2, double* saida, int n_amostras)
{
    int i;

    // Loop que acessa do ínicio ao fim os vetores simultaneamente.
    for (i = 0; i < n_amostras; i++){ 
        // Coloca a soma dos vetores de entrada dentro do vetor de saída.
        saida[i] = dados1[i] + dados2[i]; 
    }

}

/*============================================================================*/
/**                               Função 3                                    */

void inverteSinal (double* dados, int n_amostras) {

    int i;
    double aux; // Serve para ajudar na troca.

    // Invertendo o vetor (trocando cada dado por seu simétrico).
    for (i = 0; i < n_amostras / 2; i++){
        aux = dados[i];
        dados[i] = dados[(n_amostras - 1) - i];
        dados[(n_amostras - 1) - i] = aux;
        // Obs.: (n_amostras - 1) - i = "i máximo" - i.
    }

}

/*============================================================================*/
/**                               Função 4                                    */

void atrasaSinal (double* dados, int n_amostras, int atraso) {

    int i;
    double *clone;

    // Cria um vetor igual ao vetor "dados".
    clone = (double*) malloc(n_amostras * sizeof(double)); 
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

void filtroDaMedia (double* dados, int n_amostras, int largura) {

    int p, i;
    double *original, soma;

    // Se "largura" for um número ímpar entre 3 e n_amostras, segue a função. 
    if (largura % 2 && largura >= 3 && largura <= n_amostras) {

        original = (double*) malloc (n_amostras * sizeof(double));

        // Cópia do vetor "dados".
        for (p = 0; p < n_amostras; p++){
            original[p] = dados[p];
        }

        // Percorre "dados" somente nas posições onde a média pode ser tirada.
        for (p = (largura - 1) / 2; p + (largura - 1) / 2 < n_amostras; p++){
            
            soma = 0;
            // Soma os dados originais no intervalo referente à posição "p".
            for (i = p - (largura - 1) / 2; i <= p + (largura - 1) / 2; i++){
                soma += original[i];
            }
            dados[p] = soma / largura; // Média.
        }

        free (original);
    }
    
}

/*============================================================================*/
/**                             Função Extra                                  */



/*============================================================================*/
