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
  int imedio = 0, ob_iz = 0, ob_dc = 0, ob_merge = 0, ob_total = 0;

  assert(tabla != NULL);
  assert(ip >= 0);
  assert(iu >= 0);
  assert(ip <= iu);

  if (ip == iu) return 0;

  imedio = (ip + iu)/2;

  ob_iz = mergesort(tabla, ip, imedio);
  assert(ob_iz != ERR);

  ob_dc = mergesort(tabla, imedio+1, iu);
  assert(ob_dc != ERR);

  ob_merge = merge(tabla, ip, iu, imedio);
  assert(ob_merge != ERR);

  ob_total = ob_iz + ob_dc + ob_merge;

  return ob_total;
}


int merge(int* tabla, int ip, int iu, int imedio) {
  int i = ip, j = imedio+1, k = 0, ob = 0, *aux = NULL;

  assert(tabla != NULL);
  assert(ip >= 0);
  assert(iu >= 0);
  assert(imedio >= 0);

  aux = malloc((iu-ip+1)*sizeof(aux[0]));
  if (aux == NULL) return ERR;

  while (i <= imedio && j <= iu) {
    ob++;
    if (tabla[i] <= tabla[j]) {
      aux[k] = tabla[i];
      i++;
    }
    else {
      aux[k] = tabla[j];
      j++;
    }
    k++;
  }

  while (i <= imedio) {
    aux[k] = tabla[i];
    i++;
    k++;
  }

  while (j <= iu) {
    aux[k] = tabla[j];
    j++;
    k++;
  }

  for (i=0; i<(iu-ip+1); i++) {
    tabla[ip+i] = aux[i];
  }

  free(aux);
  return ob;
}

int quicksort(int* tabla, int ip, int iu){
  int count = 0;
  assert(tabla != NULL);
  assert(ip >= 0);
  assert(iu >= 0);
  assert(ip <= iu);



}

int partition(int* tabla, int ip, int iu,int *pos){
  int count = 0;
  assert(tabla != NULL);
  assert(ip >= 0);
  assert(iu >= 0);
  assert(ip <= iu);
  assert(pos != NULL);

  count++;

  if(ip==iu){
    *pos=ip;
  }

  return count;
}

int median(int *tabla, int ip, int iu,int *pos){
  assert(tabla != NULL);
  assert(ip >= 0);
  assert(iu >= 0);
  assert(ip <= iu);
  assert(pos != NULL);

  *pos = ip;

  return 0;

}

int median_avg(int *tabla, int ip, int iu, int *pos){
  assert(tabla != NULL);
  assert(ip >= 0);
  assert(iu >= 0);
  assert(ip <= iu);
  assert(pos != NULL);

  *pos = (ip + iu) / 2;
  return 0;

}

int median_stat(int *tabla, int ip, int iu, int *pos){

  int imedio = (ip + iu) / 2;
  assert(tabla != NULL);
  assert(ip >= 0);
  assert(iu >= 0);
  assert(ip <= iu);
  assert(pos != NULL);

  if ((tabla[ip] <= tabla[imedio] && tabla[imedio] <= tabla[iu]) ||
    (tabla[iu] <= tabla[imedio] && tabla[imedio] <= tabla[ip])) {
    *pos = imedio;
}
else if ((tabla[imedio] <= tabla[ip] && tabla[ip] <= tabla[iu]) ||
         (tabla[iu] <= tabla[ip] && tabla[ip] <= tabla[imedio])) {
    *pos = ip;
}
else {
    *pos = iu;
}

  return 0;
 }