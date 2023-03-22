#ifndef _ARBOLBINARIO_H_
#define _ARBOLBINARIO_H_
#include "NodoBinario.h"
template< class T > 
class ArbolBinario{
protected:
  NodoBinario<T>* raiz;
public:
  ArbolBinario();
  ~ArbolBinario();
  bool empty();
  T datoRaiz();
  int altura();
  int tamanio();
  bool insertar(T value);
  bool eliminar(T value);
  bool buscar(T value);
  void preOrden();
  void posOrden();
  void inOrden();
  void ordenNiveles();
};
//#include "ArbolBinario.hxx"
#endif