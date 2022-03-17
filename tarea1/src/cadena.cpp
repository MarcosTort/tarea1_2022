/* 5286580 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/cadena.h"
#include "../include/info.h"
#include "../include/utils.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// los elementos se mantienen entre 0 y cantidad - 1, incluidos

struct _rep_cadena
{
  TInfo dato;
  _rep_cadena *sig;
};

TCadena crearCadena()
{
  //////printf( "crear cadena");
  return NULL;
}

/* en siguientes tareas
void liberarCadena(TCadena cad) {
}
*/

nat cantidadEnCadena(TCadena cad)
{
  //////printf(" cantidad en cadena");
  nat count = 0;
  if (cad == NULL)
  {
    return count;
  }
  else
  {
    count = 1;
    while (cad->sig != NULL)
    {
      count++;
      cad = cad->sig;
    }
  }
  return count;
}

bool estaEnCadena(nat natural, TCadena cad)
{
  if (cad == NULL)
  {
    return false;
  }
  else
  {
    while ((cad != NULL) && (natInfo(cad->dato) != natural))
    {
      if (cad->sig != NULL)
      {
        cad = cad->sig;
      }
      else
      {
        break;
      }
    }
    if (natInfo(cad->dato) == natural)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
}

TCadena insertarAlInicio(nat natural, double real, TCadena cad)
{
  TCadena q = new _rep_cadena;
  TInfo dato = crearInfo(natural, real);
  q->dato = dato;
  q->sig = cad;
  cad = q;
  return cad;
}

TInfo infoCadena(nat natural, TCadena cad)
{
  ////////printf("info cadena");
  while (natInfo(cad->dato) != natural)
  {
    cad = cad->sig;
  }

  return cad->dato;
}
/*
  Remueve el primer elemento de 'cad' cuyo componente natural es 'natural'.
  Se libera la memoria asignada al mismo.
  Devuelve 'cad'.
  Precondición: estaEnCadena(natural, cad).
 */
TCadena removerDeCadena(nat natural, TCadena cad)
{
  //si tiene solo un elemento, borro info y cad
  if (cad->sig == NULL)
  {
    liberarInfo(cad->dato);
    delete cad;
    return NULL;
  }
  else
  //si tiene mas de un elemento, busco
  {
    TCadena aux; 
    while (natInfo(cad->dato) != natural)
    {
      aux = cad;
      cad = cad->sig;
    }
    TCadena q = cad;
    if (q->sig == NULL)
    {
      aux->sig = NULL;
    }
    else
    {
      aux->sig = q->sig;
    }
    liberarInfo(q->dato);
    delete q;
    return cad;
  }
}

void imprimirCadena(TCadena cad)
{
  while (cad != NULL)
  {
    char *dat = infoATexto(cad->dato);
    printf("%s", dat);
    delete[] dat;
    cad = cad->sig;
  }
  printf("\n");
}
