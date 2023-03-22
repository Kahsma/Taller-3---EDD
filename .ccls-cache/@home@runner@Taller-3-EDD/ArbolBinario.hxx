#include "ArbolBinario.h"
#include<queue>
template<class T > 
ArbolBinario::ArbolBinario()
{
  this->raiz = NULL;
}

template<class T > 
ArbolBinario::~ArbolBinario()
{
  if(this->raiz!=NULL)
  {
    delete this->raiz;
    this->raiz!=NULL
  }
}

template<class T > 
bool ArbolBinario::empty()
{
  return this->raiz==NULL;
}

template<class T > 
T ArbolBinario::datoRaiz()
{
  return (this->raiz)-> obtenerDato();
}

template<class T > 
int ArbolBinario::altura()
{
  if (this->empty())
  {
    return -1;
  }
  else{
    return this->altura(this->raiz);
  }
}

template<class T > 
int ArbolBinario::altura(NodoBinario<T>* nodo)
{
  int val;
  if(nodo->esHoja())
  {
    val=0;
  }
  else
  {
    int valtderecho =-1;
    int valIzquierda=-1;
    if(nodo->obtenerHijoIzquierdo()!=NULL)
      valIzquierda = this->altura(nodo->obtenerHijoIzquierdo());
    
    if(nodo->obtenerHijoDerecho()!=NULL)
      valtderecho = this->altura(nodo->obtenerHijoDerecho());
    
    if(valtderecho >valIzquierda)
      val = valtderecho+1;
    
    else
      val = valIzquierda+1;
  }
  return val;
}

template<class T > 
int ArbolBinario::tamanio();

template<class T > 
bool ArbolBinario::insertar(T value)
{
  bool duplicado = false;
  bool insertado = false;
  NodoBinario<T>* nodo =this->raiz;
  NodoBinario<T>* padre =this->raiz;
  while(nodo!=NULL)
  {
    padre= nodo;
    if(value < nodo->ObtenerDato())
    {
      nodo = nodo->obtenerHijoIzquierdo();
    }
    else if (value > nodo->ObtenerDato())
    {
       nodo = nodo->obtenerHijoDerecho();
    }
    else
    {
      duplicado= true;
      break;
    }
  }
  
  if(!duplicado)
  {
    NodoBinario<T>* nuevo= new NodoBinario<T>(value);
    if(nuevo!=NULL){
      if(value < padre->ObtenerDato()){
        padre->fijarHijoIzquierdo(nuevo);
      }
      else{
        padre->fijarHijoDerecho(nuevo);
      }
      insertado = true;
    }
  }
  return insertado;
}
template<class T > 
bool ArbolBinario::eliminar(T value);
template<class T > 
bool ArbolBinario::buscar(T value){
  bool encontrado = false;
  NodoBinario<T>* nodo = this->raiz;
  while(nodo!=NULL && !encontrado ){
    if(value < nodo->ObtenerDato()){
      nodo = nodo->obtenerHijoIzquierdo();
    }
    else if (value > nodo->ObtenerDato()){
       nodo = nodo->obtenerHijoDerecho();
    }
    else{
      encontrado= true;
    }
  }
  return encontrado;
}
template<class T > 
void ArbolBinario::preOrden(){
  if(!this->empty()){
    (this->raiz)->preOrden();
  }
}
template<class T > 
void ArbolBinario::posOrden(){
  if(!this->empty()){
    (this->raiz)->posOrden();
  }
}
// recurrencia en el arbol :
//template<class T > 
//void ArbolBinario::inOrden(){
//  if(!this->empty()){
//    this->inOrden(this->raiz);
//  }
//}
//template<class T > 
//void ArbolBinario::inOrden(NodoBinario<T>* nodo){
//  if(!nodo->empty()){
//    this->inOrden(nodo->obtenerHijoIzquierdo());
//    std::cout << nodo->ObtenerDato() << " ";
//    this->inOrden(nodo->obtenerHijoDerecho());
//  }
//}
//recurrencia nodo inorden:
template<class T >
void ArbolBinario::inOrden(){
  if(!this->empty()){
    this->raiz->inOrden();
  }
}
template<class T > 
void ArbolBinario::ordenNiveles(){
  if(!this->empty()){
    std::queue< NodoBinario<T>*> cola;
    cola.push(this->raiz);
    NodoBinario<T>* nodo;
    while(!cola.empty()){
      nodo = cola.front();
      nodo= cola.pop();
      std::cout<< nodo->ObtenerDato() << " ";
      if(nodo->obtenerHijoIzquierdo()!=NULL){
        cola.push(nodo->obtenerHijoIzquierdo());
      }
      if(nodo->obtenerHijoDerecho()!=NULL){
        cola.push(nodo->obtenerHijoDerecho());
      }
    
  }
}