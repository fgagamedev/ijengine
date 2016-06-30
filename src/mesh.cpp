#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "mesh.h"
#include <list>
#include <iostream>

using namespace std;
using namespace ijengine;

Mesh mesh;

 /* Laço principal */
int main(){

  string nomeArgv = "Spider-Man-simples.obj";

  mesh.carregarArquivo(nomeArgv);
  mesh.centralizaObj();

  cout << endl <<endl << "Todos valores de V Centralizados:" << endl;

  int n=0;
  for (auto it : mesh.lista.listaV){
    if(n==0){
      cout << "X: " << it << "  ";
      n++;
    }
    else if(n==1){
      cout << "Y: " << it << "  ";
      n++;
    }
    else if(n==2){
      cout << "Z: " << it << "  ";
      n=0;
    }
  }

  mesh.redimensionaObj();

  n=0;

  for (auto it : mesh.lista.listaV){
    if(n==0){cout << "X: " << it << "  "; n++; }
    else if(n==1){cout << "Y: " << it << "  "; n++; }
    else if(n==2){ cout << "Z: " << it << "  "; n=0; }
  }

  printf("\n\nValores minimos e maximos para uma segunda centralizacao\n");

  mesh.centralizaObj();

  cout << "Todos valores de VT:" << endl;
  for (auto it : mesh.lista.listaVT)
    cout << it << endl;

  cout << "Todos valores de VN:" << endl;
  for (auto it : mesh.lista.listaVN)
    cout << it << endl;

  cout << "Todos valores de F:" << endl;
  for (auto it : mesh.lista.listaF)
    cout << it << endl;

  //normalizaVetor(1,-2,2);
  cout << "Encerrando programa." << endl;

  return 0;
}
