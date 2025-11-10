/**
 *
 * Descripcion: Implementation of function that generate permutations
 *
 * File: permutations.c
 * Autor: Carlos Aguirre
 * Version: 1.1
 * Fecha: 21-09-2019
 *
 */

#include "permutations.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/***************************************************/
/* Function: swap                                  */
/* Date: 18-09-2025                                */
/* Authors: Lucas Manuel Blanco Rodríguez          */
/*                                                 */
/* Routine that swaps the values of two integers. */
/*                                                 */
/* Input:                                          */
/* int *a: pointer to the first integer            */
/* int *b: pointer to the second integer           */
/*                                                 */
/* Output:                                         */
/* void                                            */
/***************************************************/

void swap(int *a, int *b)
{
  int tmp = *a;
  
  assert(a != NULL);
  assert(b != NULL);

  *a = *b;
  *b = tmp;
}

/***************************************************/
/* Function: random_num                            */
/* Date: 18-09-2025                                */
/* Authors:Alina Datsko Yaskerska                  */
/*         Lucas Manuel Blanco Rodríguez           */
/*                                                 */
/* Routine that generates a random number           */
/* between two given numbers                       */
/*                                                 */
/* Input:                                          */
/* int inf: lower limit                            */
/* int sup: upper limit                            */
/* Output:                                         */
/* int: random number                              */
/***************************************************/

int random_num(int inf, int sup)
{
  assert(inf <= sup);
  return rand() / (RAND_MAX + 1.) * (sup - inf + 1) + inf;
}

/***************************************************/
/* Function: generate_perm                         */
/* Date: 18-09-2025                                */
/* Authors: Alina Datsko Yaskerska                 */
/*          Lucas Manuel Blanco Rodríguez          */
/*                                                 */
/* Routine that generates a random permutation      */
/*                                                 */
/* Input:                                          */
/* int n: number of elements in the permutation    */
/* Output:                                         */
/* int *: pointer to integer array                 */
/* that contains the permutation                   */
/* or NULL in case of error                        */
/***************************************************/
int *generate_perm(int N)
{
  int i = 0;
  int *perm;

  assert(N > 0);

  perm = malloc(N * sizeof(perm[0]));
  if (perm == NULL)
    return NULL;

  for (i=0; i<N; i++)
    perm[i] = i + 1;

  for (i=0; i<N; i++)
  {
    int j = random_num(i, N - 1); 
    swap(&perm[i], &perm[j]);
  }

  return perm;
}

/***************************************************/
/* Function: generate_permutations                 */
/* Date: 18-09-2025                                */
/* Authors: Alina Datsko Yaskerska                 */
/*          Lucas Manuel Blanco Rodríguez          */
/*                                                 */
/* Function that generates n_perms random          */
/* permutations with N elements                    */
/*                                                 */
/* Input:                                          */
/* int n_perms: Number of permutations             */
/* int N: Number of elements in each permutation   */
/* Output:                                         */
/* int**: Array of pointers to integer that point  */
/* to each of the permutations                     */
/* NULL en case of error                           */
/***************************************************/
int **generate_permutations(int n_perms, int N)
{
  int i, j;
  int **perm;

  assert(n_perms > 0);
  assert(N > 0);

  perm = malloc(n_perms * sizeof(int *));
  if (perm == NULL)
    return NULL;

  for (i = 0; i < n_perms; i++)
  {
    perm[i] = generate_perm(N);
    if (perm[i] == NULL)
    {
      for (j = 0; j < i; j++)
      {
        free(perm[j]);
      }
      free(perm);
      return NULL;
    }
  }

  return perm;
}
