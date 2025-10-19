/**
 *
 * Descripcion: Implementation of sorting functions
 *
 * Fichero: sorting.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2019
 *
 */

#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/***************************************************/
/* Function: InsertSort    Date:                   */
/* Your comment                                    */
/***************************************************/
int InsertSort(int *array, int ip, int iu)
{
  int count = 0;
  int i = 0, j = 0, aux = 0;

  assert(array != NULL);
  assert(ip >= 0);
  assert(iu >= 0);
  assert(ip <= iu);

  for (i = ip + 1; i <= iu; i++)
  {
    aux = array[i];
    j = i - 1;
    while (j >= ip)
    {
      count++;
      if (array[j] > aux)
      {
        array[j + 1] = array[j];
        j = j - 1;
      }
      else
      {
        break;
      }
    }
    array[j + 1] = aux;
  }

  return count;
}

/***************************************************/
/* Function: SelectSort ¿?    Date:                */
/* Your comment                                    */
/***************************************************/
int BubbleSort(int *array, int ip, int iu)
{
  int i = 0, j = 0;
  int count = 0;
  int flag = 0;

  assert(array != NULL);
  assert(ip >= 0);
  assert(iu >= 0);
  assert(ip <= iu);

  for (i = ip; i < iu; i++)
  {
    flag = 0;
    for (j = ip; j < iu - (i - ip); j++)
    {
      count++;
      if (array[j] > array[j + 1])
      {
        swap(&array[j], &array[j + 1]);
        flag = 1;
      }
    }
    if (flag == 0)
      break;
  }

  return count;
}

