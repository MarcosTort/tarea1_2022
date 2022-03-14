/* 52865802 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/colCadenas.h"
#include "../include/cadena.h"

struct _nodoCol_
{
  TCadena cad;
  nat pos;
};

struct _rep_colCadenas
{

  _nodoCol_ nodo;
  _rep_colCadenas *sig;
};

TColCadenas irAPosCol(nat pos, TColCadenas col){

  while (col->nodo.pos != pos)
  {
    col = col->sig;
  }
  return col;
}

TColCadenas crearColCadenas()
{
  TColCadenas colCad = new _rep_colCadenas;
  for (nat i = 0; i < CANT_CADS; i++)
  {
    _nodoCol_ *nodo = new _nodoCol_;
    nodo->cad = crearCadena();
    nodo->pos = i;
    colCad->nodo = *nodo;
    colCad = colCad->sig;
  }
  return colCad;
}

/* en siguientes tareas
void liberarColCadenas(TColCadenas col) {
}
*/
nat cantidadColCadenas(nat pos, TColCadenas col)
{
  col = irAPosCol(pos, col);
  return cantidadEnCadena(col->nodo.cad);
}

bool estaEnColCadenas(nat natural, nat pos, TColCadenas col)
{
  
  col = irAPosCol(pos, col);

  return estaEnCadena(natural, col->nodo.cad);
  
}

TColCadenas insertarEnColCadenas(nat natural, double real, nat pos, TColCadenas col)
{
  col = irAPosCol(pos, col);
  TCadena cad = col->nodo.cad;
  cad = insertarAlInicio(natural, real, cad);
  col->nodo.cad = cad;
  
}

TInfo infoEnColCadenas(nat natural, nat pos, TColCadenas col)
{
  col = irAPosCol(pos, col);
  return infoCadena(natural, col->nodo.cad);

}

TColCadenas removerDeColCadenas(nat natural, nat pos, TColCadenas col)
{
  col = irAPosCol(pos, col);
  col->nodo.cad = removerDeCadena(natural, col->nodo.cad);
}
