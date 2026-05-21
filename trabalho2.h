/*============================================================================*/
/* ICSF13 - 2026-1 - TRABALHO 2                                               */
/*----------------------------------------------------------------------------*/
/* Bogdan T. Nassu                                                            */
/* Leyza E. B. Dorini                                                         */
/* Daniel F. Pigatto                                                          */
/*============================================================================*/
/** Funções pedidas para o 2o trabalho da disciplina Fundamentos de Programação
 * 1, 1o semestre de 2026, profs. Bogdan T. Nassu, Leyza E. B. Dorini e Daniel
 * F. Pigatto, Universidade Tecnológica Federal do Paraná. */
/*============================================================================*/

#ifndef __TRABALHO2_H
#define __TRABALHO2_H

/*============================================================================*/

void mudaGanho (double* dados, int n_amostras, double ganho);
void misturaDados (double* dados1, double* dados2, double* saida, int n_amostras);
void inverteSinal (double* dados, int n_amostras);
void atrasaSinal (double* dados, int n_amostras, int atraso);
void filtroDaMedia (double* dados, int n_amostras, int largura);
void ecos (double* dados, int n_amostras, int n_repeticoes, int atraso, int abafamento, double decaimento);

/*============================================================================*/
#endif /* __TRABALHO2_H */
