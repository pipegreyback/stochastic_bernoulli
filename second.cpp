#include <iostream>
using namespace std;
struct Node{
  int estado_anterior, estado_actual, nivel, probabilidad, recompensa;
  Node *left;
  Node * right;
};

Node * GetNewNode(int estado_anterior, int estado_actual, int nivel, float probabilidad, int recompensa){
  Node * newNode = new Node();
  newNode->estado_anterior = estado_anterior;
  newNode->estado_actual = estado_actual;
  newNode->nivel = nivel;
  newNode->probabilidad = probabilidad;
  newNode->recompensa = recompensa;
  newNode-> left = newNode -> right = NULL;
  return newNode;
}

float calc_prob(int estado_anterior, int estado_actual){
  if (estado_anterior == 0) {
    if (estado_actual == 0){
      return 0.3;
    }else if(estado_actual == 1){
      return 0.7;
    }
  } else if(estado_anterior == 1){
    if(estado_actual == 0){
      return 0.3;
    } else if(estado_actual == 1){
      return 0.7;
    }
  }
}

int calc_recompensa(int estado_anterior, int estado_actual){
  if (estado_anterior == 0) {
    if (estado_actual == 0){
      return 0;
    }else if(estado_actual == 1){
      return 1;
    }
  } else if(estado_anterior == 1){
    if(estado_actual == 0){
      return 0;
    } else if(estado_actual == 1){
      return 1;
    }
  }
}

Node* Insert(Node* main_node, int estado_anterior, int estado_actual, int nivel, float probabilidad, int recompensa){
  float probabilidad_acumulada = calc_prob(estado_anterior, estado_actual);
  int recompensa_acumulada = calc_recompensa(estado_anterior,estado_actual);
  std::cout << "probabilidad_acumulada"<< probabilidad_acumulada << '\n';
  std::cout << "recompoensa_acu"<< recompensa_acumulada << '\n';
  if (main_node == NULL){
    main_node = GetNewNode(estado_anterior, estado_actual, nivel, probabilidad_acumulada, recompensa_acumulada);
    std::cout << "entre" << '\n';
  }else{
    main_node-> left = Insert(main_node->left, main_node->estado_actual, estado_actual, main_node->nivel +1, main_node-> probabilidad * probabilidad_acumulada, main_node->recompensa+ recompensa_acumulada);
    main_node-> right = Insert(main_node->right, main_node->estado_actual, estado_actual, main_node->nivel +1, main_node-> probabilidad * probabilidad_acumulada, main_node->recompensa+ recompensa_acumulada);
  }
  return main_node;
}

int main(int argc, char const *argv[]) {
  Node * main_node = NULL;
  main_node = Insert(main_node, 0, 0, 0, 1, 0);
  main_node = Insert(main_node, main_node->estado_actual, 1, main_node->nivel +1, main_node->probabilidad, main_node->recompensa);
  cout << "probabilidad_acumulada " << main_node->left->probabilidad<< '\n';
  return 0;
}
