/**
 *
 * Descripcion: Implementation of time measurement functions
 *
 * Fichero: times.c
 * Autor: Carlos Aguirre Maeso
 * Version: 1.0
 * Fecha: 16-09-2019
 *
 */

#include "times.h"
#include "sorting.h"
#include "permutations.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

/***************************************************/
/* Function: average_sorting_time                  */
/* Date: 10-10-2025                                */
/* Authors: Alina Datsko Yaskerska                 */
/*                                                 */
/* Routine that takes the average time and OBs     */
/* of a sorting function                           */
/*                                                 */
/* Input:                                          */
/* pfunc_sort metodo: pointer to the sorting       */
/* function to test                                */
/* int n_perms: number of random permutations      */
/* int N: number of elements in each permutation   */
/* PTIME_AA ptime: pointer to struct to store      */
/* time statistics                                 */
/*                                                 */
/* Output:                                         */
/* short: OK if successful, ERR if an error        */
/*                                                 */
/* The ptime struct will have: average time,       */
/* average OBs, minimum and maximum OBs            */
/***************************************************/

short average_sorting_time(pfunc_sort metodo,
                           int n_perms,
                           int N,
                           PTIME_AA ptime)
{
  int i = 0, j = 0, start = 0, end = 0, temp = 0, max, min, ob = 0;
  int **tabla;

  assert(metodo != NULL);
  assert(n_perms > 0);
  assert(N > 0);
  assert(ptime != NULL);

  tabla = generate_permutations(n_perms, N);
  if (tabla == NULL) return ERR;

  /*Crea la tabla usando generate_permutations pero luego
    la ordenamos indice por indice de forma ascendente*/
  for (i = 0; i < n_perms; i++) {
    for (j = 0; j < N; j++) {
      tabla[i][j] = j + 1;
    }
  }

  start = clock();

  temp = metodo(tabla[0], 0, N - 1);

  ob = temp;
  min = temp;
  max = temp;

  for (i = 1; i < n_perms; i++)
  {
    temp = metodo(tabla[i], 0, N - 1);
    ob += temp;

    if (temp > max)
      max = temp;
    if (temp < min)
      min = temp;
  }

  end = clock();

  ptime->N = N;
  ptime->n_elems = n_perms;
  ptime->time = (end - start + 0.) / (CLOCKS_PER_SEC * n_perms + 0.);
  ptime->average_ob = ((double)ob) / n_perms;
  ptime->min_ob = min;
  ptime->max_ob = max;

  for (i = 0; i < n_perms; i++) free(tabla[i]);
  free(tabla);

  return OK;
}

/***************************************************/
/* Function: generate_sorting_times                */
/* Date: 10-10-2025                                */
/* Authors: Alina Datsko Yaskerska                 */
/*                                                 */
/* Routine that generates a table of sorting times */
/* for a given sorting function over a range of    */
/* array sizes and saves the results to a file.    */
/*                                                 */
/* Input:                                          */
/* pfunc_sort method: pointer to the sorting       */
/* function to test                                */
/* char *file: name of the file to write           */
/* int num_min: minimum array size                 */
/* int num_max: maximum array size                 */
/* int incr: increment of array sizes              */
/* int n_perms: number of permutations per size    */
/*                                                 */
/* Output:                                         */
/* short: OK if successful, ERR if an error        */
/*                                                 */
/* Writes a table with average time, OBs, min and  */
/* max OBs for each array size to the file         */
/***************************************************/

short generate_sorting_times(pfunc_sort method, char *file,
                             int num_min, int num_max,
                             int incr, int n_perms)
{
  int i = 0, n_times;
  int N;
  PTIME_AA times;

  assert(method != NULL);
  assert(file != NULL);
  assert(num_min > 0);
  assert(num_max > num_min);
  assert(incr > 0);
  assert(n_perms > 0);

  n_times = ((num_max - num_min) / incr) + 1;
  times = (PTIME_AA)malloc(n_times * sizeof(times[0]));
  if (times == NULL) return ERR;

  for (i = 0, N = num_min; N <= num_max; i++, N += incr)
  {
    if (average_sorting_time(method, n_perms, N, &times[i]) == ERR)
    {
      free(times);
      return ERR;
    }
  }

  if (save_time_table(file, times, n_times) == ERR)
  {
    free(times);
    return ERR;
  }

  free(times);
  return OK;
}

/***************************************************/
/* Function: save_time_table                       */
/* Date: 10-10-2025                                */
/* Authors: Alina Datsko Yaskerska                 */
/*          Lucas Manuel balnco Rodríguez          */
/*                                                 */
/* Routine that saves a table of sorting times     */
/* and OBs to a file.                              */
/*                                                 */
/* Input:                                          */
/* char *file: name of the output file             */
/* PTIME_AA ptime: pointer to array of structs     */
/* of time and OBs                                 */
/* int n_times: number of files of the table       */
/*                                                 */
/* Output:                                         */
/* short: OK if successful, ERR if an error        */
/*                                                 */
/* Writes a table with headers and data for each   */
/* array size, including average time, average OB, */
/* maximum OB, and minimum OB                      */
/***************************************************/

short save_time_table(char *file, PTIME_AA ptime, int n_times)
{
  FILE *fp;
  int i = 0;

  assert(file != NULL);
  assert(ptime != NULL);
  assert(n_times > 0);

  fp = fopen(file, "w");
  if (fp == NULL)
    return ERR;

  fprintf(fp, "N         Time(s)           OB_avg          OB_max       OB_min\n");

  for (i = 0; i < n_times; i++)
  {
    fprintf(fp, "%-10d%-18.8f%-16.2f%-13d%-16d\n",
            ptime[i].N,
            ptime[i].time,
            ptime[i].average_ob,
            ptime[i].max_ob,
            ptime[i].min_ob);
  }

  fclose(fp);

  return OK;
}
