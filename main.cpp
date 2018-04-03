#include <iostream>
using namespace std;

class Nodo{
  int estado, recompensa_acumulada, eslavon, iteraciones;
  float probabilidad_acumulada;
  float matriz_probabilidades[4] = {0.3,0.7,0.1,0.9};
  int matriz_recompensa[4] = {0,1,2,3};
  Nodo *nodo_derecho, *nodo_izquierdo;
public:
  Nodo(int, int, int, float, int, int);
};
Nodo::Nodo(int estado_anterior, int estado_actual, int recompensa_acumulada, float probabilidad_acumulada, int eslavon, int iteraciones){
  estado = estado_actual;
  cout << "Nivel numero  " << eslavon<< '\t';
  cout << "Probabilidad acumulada " << probabilidad_acumulada << '\t';
  cout << "Recompensa acumulada " << recompensa_acumulada << '\n';
  eslavon = eslavon+1;
  iteraciones = iteraciones;
  if (eslavon< iteraciones){
    if(estado == 0){
      if(estado_anterior == 0){
        recompensa_acumulada += matriz_recompensa[1];
        probabilidad_acumulada = probabilidad_acumulada * matriz_probabilidades[1];
        cout << "si1" << '\n';
      } else if(estado_anterior == 1){
        recompensa_acumulada += matriz_recompensa[3];
        probabilidad_acumulada = probabilidad_acumulada * matriz_probabilidades[3];
        cout << "si2" << '\n';
      }
    }else if(estado == 1){
      if(estado_anterior == 0){
        recompensa_acumulada += matriz_recompensa[2];
        probabilidad_acumulada = probabilidad_acumulada * matriz_probabilidades[2];
        cout << "si3" << '\n';
      } else if(estado_anterior == 1){
        recompensa_acumulada += matriz_recompensa[4];
        probabilidad_acumulada = probabilidad_acumulada * matriz_probabilidades[4];
        cout << "si4" << '\n';
      }
    }
    Nodo *nodo_derecho = new Nodo(estado, 1, recompensa_acumulada, probabilidad_acumulada, eslavon, iteraciones);
    Nodo *nodo_izquierdo = new Nodo(estado, 0, recompensa_acumulada, probabilidad_acumulada, eslavon, iteraciones);
  }else{}
};


int main(int argc, char const *argv[]) {
  int estado_inicial = 0;
  int iteraciones = 3;
  Nodo nodo_inicial(0, estado_inicial, 0, 1, 0, iteraciones);
  return 0;
}
