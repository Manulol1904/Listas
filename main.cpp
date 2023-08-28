#include <iostream>

using namespace std;


class Nodo {
  public:
    int dato;
    Nodo* siguiente;

    Nodo(int dato) {
      this->dato = dato;
      this->siguiente = NULL;
    }
};

class ListaSimple {
  public:
    Nodo* primero;

    ListaSimple() {
      this->primero = NULL;
    }
    void agregarAlFinal(int dato) {
      Nodo* nuevo = new Nodo(dato);

      if (this->primero == NULL) {
        this->primero = nuevo;
      } else {
        Nodo* actual = this->primero;

        while (actual->siguiente != NULL) {
          actual = actual->siguiente;
        }

        actual->siguiente = nuevo;
      }
    }

    void imprimir() {
      Nodo* actual = this->primero;

      while (actual != NULL) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
      }

      cout << endl;
    }
};

int main() {
  ListaSimple lista;
  
  int dato;
  
  for(int i=0; i < 5;i++){
  cout<<"Ingresa un valor:  ";
  cin >>dato;

  lista.agregarAlFinal(dato);
}
  

  lista.imprimir();

  return 0;
}
