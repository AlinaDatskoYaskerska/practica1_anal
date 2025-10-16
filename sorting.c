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

/***************************************************/
/* Function: InsertSort    Date:                   */
/* Your comment                                    */
/***************************************************/
int InsertSort(int *array, int ip, int iu)
{
  /*Comprobacion errores*/
  if (array == NULL || ip < 0 || iu < 0 || ip > iu)
  {
    return ERR;
  }

  /*Declaracion de variables*/
  int count = 0;
  int i = 0, j = 0, aux = 0;

  /*Main codigo*/
  for (i = ip + 1; i <= iu; i++)
  {
    aux = array[i];
    j = i - 1;
    while (j >= ip && array[j] > aux)
    {
      array[j + 1] = array[j];
      j = j - 1;
          count++;
    }
    array[j + 1] = aux;
    count++;
  }

  return count;
}

/***************************************************/
/* Function: SelectSort ¿?    Date:                */
/* Your comment                                    */
/***************************************************/
int BubbleSort(int *array, int ip, int iu)
{
  /*Comprobacion errores*/
  if (array == NULL || ip < 0 || iu < ip)
  {
    return ERR;
  }

  /*Declaracion de variables*/
  int i = 0, j = 0, temp = 0;
  int count = 0;
  int flag = 0;

  /*Main codigo*/
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

/* No sé qué considerar OB, si las comparaciones o los intercambios de números => REPASAR*/
