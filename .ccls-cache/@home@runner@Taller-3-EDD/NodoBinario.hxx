#include "NodoBinario.h"
template <class T>
NodoBinario::NodoBinario(){
  this->hijoIzquierdo==NULL;
  this->hijoDerecho ==NULL;
}
template <class T>
NodoBinario::NodoBinario(T val){
  this->hijoIzquierdo==NULL;
  this->hijoDerecho ==NULL;
  this->dato = val;
}
template <class T>
NodoBinario::~NodoBinario(){
  if(this->hijoIzquierdo!=NULL){
    delete this->hijoIzquierdo
    hijoIzquierdo = NULL;
  }
  if(this->hijoDerecho!=NULL){
    delete this->hijoDerecho
    hijoDerecho = NULL;
  }
}
template <class T>
T& NodoBinario::ObtenerDato(){
  return this->dato; 
}
template <class T>
void NodoBinario::fijatDato(T val){
  this->dato = val;
}
template <class T>
NodoBinario<T>* NodoBinario::obtenerHijoIzquierdo(){
  return this->hijoIzquierdo;
}
template <class T>
NodoBinario<T>* NodoBinario::obtenerHijoDerecho(){
  return this->hijoDerecho;
}
template <class T>
void NodoBinario::fijarHijoIzquierdo(NodoBinario<T>* izq){
  this->hijoIzquierdo = izq;
}
template <class T>
void NodoBinario::fijarHijoDerecho(NodoBinario<T>* der){
  this->hijoDerecho=der;
}
template <class T>
bool NodoBinario::esHoja(){
  return (this->hijoIzquierdo ==NULL && this->hijoDerecho==NULL );
}
template <class T>
void NodoBinario::inOrden(){
  if(this->hijoIzquierdo != NULL)
    (this->hijoIzquierdo)->inOrden();
  std::cout << this->dato << " ";
  if(this->hijoDerecho != NULL)
    (this->hijoDerecho)->inOrden();  
}
template <class T>
void NodoBinario::posOrden(){
  if(this->hijoIzquierdo != NULL)
    (this->hijoIzquierdo)->posOrden();
  if(this->hijoDerecho != NULL)
    (this->hijoDerecho)->posOrden();
  std::cout << this->dato << " ";
}
template <class T>
void NodoBinario::preOrden(){
  std::cout << this->dato << " ";
  if(this->hijoIzquierdo != NULL)
    (this->hijoIzquierdo)->preOrden();
  if(this->hijoDerecho != NULL)
    (this->hijoDerecho)->preOrden();
}