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

    while (cad->sig != NULL && natInfo(cad->dato) != natural )
    {
      cad = cad->sig;
    }

    return cad->sig != NULL && natInfo(cad->dato) == natural;
  }
}

TCadena insertarAlInicio(nat natural, double real, TCadena cad)
{
  if (cad == NULL)
  {
    TCadena q = new _rep_cadena;
    TInfo dato = crearInfo(natural, real);
    q->dato = dato;
    q->sig = NULL;
    cad = q;
    return cad;
  }
  else
  {
    TCadena q = new _rep_cadena;
    TInfo dato = crearInfo(natural, real);
    q->dato = dato;
    q->sig = cad;
    cad = q;
    return cad;
  }
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

TCadena removerDeCadena(nat natural, TCadena cad)
{
  ////////printf( "remover de cadena");
  while (natInfo(cad->sig->dato) != natural)
  {
    cad = cad->sig;
  }
  TCadena q = cad->sig;
  cad->sig = q->sig;
  delete q;
  return cad;
}

void imprimirCadena(TCadena cad)
{
  // //////printf( "imprimir cadena");
  // while (cad != NULL)
  // {
  //   imprimirInfo(cad->dato);
  // }
}
