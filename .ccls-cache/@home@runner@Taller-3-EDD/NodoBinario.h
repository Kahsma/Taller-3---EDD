#ifndef _NODOBINARIO_H_
#define _NODOBINARIO_H_

template < class T >
class NodoBinario{
protected:
  T dato;
  NodoBinario<T>* hijoIzquierdo;
  NodoBinario<T>* hijoDerecho;
public:
  NodoBinario();
  NodoBinario(T value);
  ~NodoBinario();
  T ObtenerDato();
  void fijatDato(T value);
  NodoBinario<T>* obtenerHijoIzquierdo();
  NodoBinario<T>* obtenerHijoDerecho();
  void fijarHijoIzquierdo(NodoBinario<T>* izq);
  void fijarHijoDerecho(NodoBinario<T>* der);
  bool esHoja();
  int altura();
  void inOrden();
  void posOrden();
  void preOrden();
};

//#include "NodoBinario.hxx"
#endif