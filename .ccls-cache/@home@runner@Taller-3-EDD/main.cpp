#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
#include <set>
#include <string.h>
#include <stdio.h>
#include "ArbolBinario.h"
#include "NodoBinario.h"


using namespace std;

struct MyResult {
    std::set<std::string> mySet;
    std::vector<double> insertTimes;
    std::vector<double> eraseTimes;
};

std::vector<std::vector<string> > leerProductCodes (string nombre)
{
  cout << "Cargar comandos." << endl;
  std::vector<std::vector<string> > elVector;

  string buffer;
  ifstream lectura;
  
  lectura.open(nombre, ios::in);
  bool isEmpty = lectura.peek() == EOF;
  if (lectura.fail() == true)
  {
    cout << "No se pudo abrir el archivo " + nombre << endl;
  }
  if (isEmpty)
  {
    cout << "El archivo " + nombre + " esta vacio" << endl;
  }

  else
  {
    // Aqui van las intrucciones de lectura :)
    cout << "El archivo: " + nombre + " se abrio exitosamente" << endl;
  }
  

  while (getline(lectura, buffer))
  {
    std::vector<string> partido;
    char *ptr; // declare a ptr pointer

    ptr = strtok(const_cast<char *>(buffer.c_str()), " ");
    int i = 0;
    partido.push_back(ptr);
    while (ptr != NULL)
    {
      // cout << *ptr<<endl;
      i++;
      ptr = strtok(NULL, " ");
      if (ptr != NULL)
      {
        partido.push_back(ptr);
        
      }
      // cout<<partido[i];
    } 
    elVector.push_back(partido);
    
    //cout << endl;


  }

  
  lectura.close();
  
  return elVector;
}

void imprimir(std::vector<std::vector<string> > elVector){

for (auto it = elVector.begin(); it != elVector.end(); ++it) {
  for (auto innerIt = it->begin(); innerIt != it->end(); ++innerIt) {
    cout << *innerIt << " ";
  }
  cout << endl;
  }
  
}
std::set<std::string> benchmark(std::vector<std::vector<string> > elVector){
    std::set<std::string> mySet;

  for (const auto& vec : elVector) {
      //std::cout<< "accion"<< vec[0] << " codigo"<< vec[1]<<std::endl;
      if(vec[0].compare("A") == 0){
        std::clock_t init_time = std::clock();
        mySet.insert(vec[1]);
        std::clock_t end_time = std::clock();
        double calc_time = ( end_time - init_time ) / double( CLOCKS_PER_SEC );
        std::cout << "It took me  "<< calc_time << " seconds."<<std::endl;
      }
      else if (vec[0].compare("E") == 0){
        std::clock_t init_time = std::clock();
        mySet.erase(vec[1]);
        std::clock_t end_time = std::clock();
        double calc_time = ( end_time - init_time ) / double( CLOCKS_PER_SEC );
        //std::cout << "It took me  "<< calc_time << " seconds."<<std::endl;
      }
    }
    return mySet;
}

MyResult  benchmark2(std::vector<std::vector<string> > elVector){
    MyResult result;

  for (const auto& vec : elVector) {
      //std::cout<< "accion"<< vec[0] << " codigo"<< vec[1]<<std::endl;
      if(vec[0].compare("A") == 0){
        std::clock_t init_time = std::clock();
        result.mySet.insert(vec[1]);
        std::clock_t end_time = std::clock();
        double calc_time = ( end_time - init_time ) / double( CLOCKS_PER_SEC );
        //std::cout << "It took me  "<< calc_time << " seconds."<<std::endl;
        result.insertTimes.push_back(calc_time);
      }
      else if (vec[0].compare("E") == 0){
        std::clock_t init_time = std::clock();
        result.mySet.erase(vec[1]);
        std::clock_t end_time = std::clock();
        double calc_time = ( end_time - init_time ) / double( CLOCKS_PER_SEC );
        //std::cout << "It took me  "<< calc_time << " seconds."<<std::endl;
        result.eraseTimes.push_back(calc_time);
      }
    }
    return result;
}

void imprimirset(set<std::string> mySet){
  for (auto it = mySet.begin(); it != mySet.end(); ++it) {
    std::cout << *it << std::endl;
  }
}

int main(int argc, char *argv[]) 
{
  std::cout << "argv "<<argv[1]<<std::endl;
  string arch = argv[1];
  MyResult result;
  std::set<std::string> mySet;
  std::vector<std::vector<string> > vequi;
  std::set<string> arbolrn;
  vequi = leerProductCodes(arch);
  //imprimir(vequi);
  // mySet=benchmark(vequi);
  // std::cout<< "is empty:"<< mySet.empty() <<std::endl;
  // imprimirset(mySet);
  std::cout << "con struct"<<std::endl;
  result = benchmark2(vequi);
  imprimirset(result.mySet);
  double tiempoinsert = 0;
  double tiempoerase= 0;
  for(auto insert : result.insertTimes){
    tiempoinsert += insert;
  }
  std::cout << "EL TIEMPO DE INSERCIONES ES : "<<tiempoinsert<<std::endl;
  for(auto insert : result.eraseTimes){
    tiempoerase += insert;
  }
  std::cout << "EL TIEMPO DE ERASE ES : "<<tiempoerase<<std::endl;
}

