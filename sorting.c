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
/* Function: InsertSort                            */
/* Date: 26-09-2025                                */
/* Authors: Lucas Manuel Blanco Rodríguez          */
/*                                                 */
/* Routine that sorts an array of integers         */
/* using the Insert Sort algorithm.                */
/*                                                 */
/* Input:                                          */
/* int *array: pointer to array to be sorted       */
/* int ip: index of the first element              */
/* int iu: index of the last element               */
/*                                                 */
/* Output:                                         */
/* int: number of OBs made                         */
/* during the sorting process                      */
/* or ERR in case of problem                       */
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
/* Function: BubbleSort                            */
/* Date: 26-09-2025                                */
/* Authors: Lucas Manuel Blanco Rodríguez          */
/*                                                 */
/* Routine that sorts an array of integers         */
/* using the Bubble Sort algorithm.                */
/*                                                 */
/* Input:                                          */
/* int *array: pointer to  array to be sorted      */
/* int ip: index of the first element              */
/* int iu: index of the last element               */
/*                                                 */
/* Output:                                         */
/* int: number of OBs made                         */
/* during the sorting process                      */
/* or ERR in case of problem                       */
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


/***************************************************/
/* Function: BubbleSort     CAMBIAR                       */
/* Date: 26-09-2025                                */
/* Authors: Lucas Manuel Blanco Rodríguez          */
/*                                                 */
/* Routine that sorts an array of integers         */
/* using the Bubble Sort algorithm.                */
/*                                                 */
/* Input:                                          */
/* int *array: pointer to  array to be sorted      */
/* int ip: index of the first element              */
/* int iu: index of the last element               */
/*                                                 */
/* Output:                                         */
/* int: number of OBs made                         */
/* during the sorting process                      */
/* or ERR in case of problem                       */
/***************************************************/
int mergesort(int* tabla, int ip, int iu) {
  assert(tabla != NULL);
  assert(ip >= 0);
  assert(iu >= 0);
  assert(ip <= iu);

  int imedio, count = 0, OBs;
  int *opc_izq = NULL, *opc_der = NULL, *opc_ord = NULL;


  if (ip >= iu){
    return 0;
  }

  imedio = (ip + iu) / 2;

  OBs = mergesort(tabla, ip, imedio);
  if (OBs == ERR) {
    return ERR;
  }
  count += OBs;

  OBs = mergesort(tabla, imedio + 1, iu);
  if (OBs == ERR) {
    return ERR;
  }
  count += OBs;

  OBs = merge(tabla, ip, iu, imedio);
  if (OBs == ERR) {
    return ERR;
  }
  count += OBs;

  return count;
}


int merge(int* tabla, int ip, int iu, int imedio) {
  assert(tabla != NULL);
  assert(ip >= 0);
  assert(iu >= 0);
  assert(imedio >= 0);

  int tamano = iu - ip + 1;
  int *aux = NULL;
  int i = ip, j = imedio + 1, k = 0, count = 0;

  aux = (int*)malloc(tamano * sizeof(int));
  if (aux == NULL) {
    return ERR;
  }

  while (i <= imedio && j <= iu) {
    if (tabla[i] < tabla[j]) {
      aux[k] = tabla[i];
    } else {
      aux[k] = tabla[j];
    }
    k++;
  }

  while (i <= imedio) {
    aux[k] = tabla[i];
    k++;
    i++;
  }

  while (j <= iu) {
    aux[k] = tabla[j];
    k++;
    j++;
  }

  for (i = ip, k = 0; i <= iu; i++, k++) {
    tabla[i] = aux[k];
  }

  free(aux);
  return count;
}

