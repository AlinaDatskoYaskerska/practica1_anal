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

short average_sorting_time(pfunc_sort metodo,
                           int n_perms,
                           int N,
                           PTIME_AA ptime)
{
  int i = 0, start = 0, end = 0, temp = 0, max, min, ob = 0;
  int **tabla;

  assert(metodo != NULL);
  assert(n_perms > 0);
  assert(N > 0);
  assert(ptime != NULL);

  tabla = generate_permutations(n_perms, N);
  if (tabla == NULL) return ERR;

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
  ptime->time = ((double)(end - start)) / (CLOCKS_PER_SEC * n_perms);
  ptime->average_ob = ((double)ob) / n_perms;
  ptime->min_ob = min;
  ptime->max_ob = max;

  for (i = 0; i < n_perms; i++) free(tabla[i]);
  free(tabla);

  return OK;
}

/***************************************************/
/* Function: generate_sorting_times Date:          */
/*                                                 */
/* Your documentation                              */
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
/* Function: save_time_table Date:                 */
/*                                                 */
/* Your documentation                              */
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

  fprintf(fp, "N\t     Time(s)\t   OB_avg\t      OB_max\t  OB_min\n");

  for (i = 0; i < n_times; i++)
  {
    fprintf(fp, "%d\t   %10.6f      %-12.2f   %-7d     %-7d\n",
            ptime[i].N,
            ptime[i].time,
            ptime[i].average_ob,
            ptime[i].max_ob,
            ptime[i].min_ob);
  }

  fclose(fp);

  return OK;
}
