#include <iostream>
using namespace std;

class Nodo{
  int estado, recompensa_acumulada, eslavon, iteraciones;
  float probabilidad_acumulada;
  float matriz_probabilidades[4] = {0.3,0.7,0.3,0.7};
  int matriz_recompensa[4] = {0,1,0,1};
  Nodo *nodo_derecho, *nodo_izquierdo;
public:
  Nodo(int, int, int, float, int, int);
  ~Nodo();
};
Nodo::Nodo(int estado_anterior, int estado_actual, int recompensa_acumulada, float probabilidad_acumulada, int eslavon, int iteraciones){
  estado = estado_actual;
  eslavon = eslavon+1;
  iteraciones = iteraciones;
  if (eslavon< iteraciones){
    if(estado == 0){
      Nodo *nodo_derecho = new Nodo(estado, 1, recompensa_acumulada + matriz_recompensa[1], probabilidad_acumulada * matriz_probabilidades[1], eslavon, iteraciones);
      Nodo *nodo_izquierdo = new Nodo(estado, 0, recompensa_acumulada + matriz_recompensa[0], probabilidad_acumulada * matriz_probabilidades[0], eslavon, iteraciones);
    }else if(estado == 1){
      Nodo *nodo_derecho = new Nodo(estado, 1, recompensa_acumulada + matriz_recompensa[3], probabilidad_acumulada * matriz_probabilidades[3], eslavon, iteraciones);
      Nodo *nodo_izquierdo = new Nodo(estado, 0, recompensa_acumulada + matriz_recompensa[2], probabilidad_acumulada * matriz_probabilidades[2], eslavon, iteraciones);
      this->~Nodo();
    }
    cout << "Nivel numero  " << eslavon<< '\t';
    cout << "Probabilidad acumulada " << probabilidad_acumulada << '\t';
    cout << "Recompensa acumulada " << recompensa_acumulada << '\n';
  }else{}
};
Nodo::~Nodo(void){
};


int main(int argc, char const *argv[]) {
  int estado_inicial = 0;
  int iteraciones = 20;
  Nodo nodo_inicial(0, estado_inicial, 0, 1, -1, iteraciones);
  return 0;
}
