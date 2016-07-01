#ifndef MESH_H
#define MESH_H

#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <list>
#include <math.h>

using namespace std;

namespace ijengine {
  typedef struct Listas {
    list<float> listaV;
    list<float> listaVT;
    list<double> listaVN;
    list<string> listaF;
    float Xmin, Xmax, Ymin, Ymax, Zmin, Zmax;
    float deltaX, deltaY, deltaZ;
  }Lista;

  class Mesh
  {
    public:

      Mesh();
      ~Mesh();

      void carregarArquivo(string nomeArquivo);
      void jogaParaListaV(float a, float b, float c);
      void jogaParaListaVT(float a, float b);
      void jogaParaListaVN(double a, double b, double c);
      void jogaParaListaF(string a, string b, string c);
      void normalizaVetor(double *a, double *b, double *c);
      void centralizaObj();
      void redimensionaObj();

      Lista lista;
  };
}

#endif
