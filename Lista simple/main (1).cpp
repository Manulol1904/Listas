
#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    int newdato;
    Nodo*siguiente;
};
//insertar valores
void insertarLista(Nodo *&lista, int n){
    Nodo*nuevo_nodo= new Nodo();
    nuevo_nodo -> dato =n;
    
    Nodo*aux1=lista;
    Nodo*aux2;
    
    while((aux1 !=NULL)&&(aux1->dato<n)){
    aux2=aux1;
    aux1=aux1->siguiente;
}
if(lista==aux1){
    lista=nuevo_nodo;
}
else{
    aux2->siguiente=nuevo_nodo;
}
nuevo_nodo->siguiente=aux1;




}
//prueba
void insertarfirst(Nodo*lista,int n,int m){
     bool band=false;
    Nodo*actual=new Nodo();
    actual=lista;
    while((actual!=NULL)&&(actual->dato <=n)){
        if(actual->dato==n){
            band=true;
            break;
            
        }
        actual=actual->siguiente;
        
        
    }
    if(band==true){
        actual->dato=m;
    }
    else{
        cout<<"elemento no encontrado"<<"\n";
    }
    
    
}
//prueba 2
void insertarPrincipio(Nodo **lista, int n) {
  Nodo *nuevo = new Nodo();
  nuevo->siguiente = *lista;
  *lista = nuevo;
  nuevo->dato=n;
}
//prueba 3
void insertarFinal(Nodo **lista, int n) {
  Nodo *nuevo = new Nodo();
  if (*lista == nullptr) {
    *lista = nuevo;
  } 
  else {
    Nodo *actual = *lista;
    while (actual->siguiente != nullptr) {
      actual = actual->siguiente;
    }
    actual->siguiente = nuevo;
    nuevo->dato=n;
}
}
//prueba 4
void insertarPosicion(Nodo **lista, int dato, int posicion) {
  if (posicion == 0) {
    insertarPrincipio(lista, dato);
  } else {
    Nodo *actual = *lista;
    for (int i = 1; i < posicion-1; i++) {
      if (actual == nullptr) {
        return;
      }
      actual = actual->siguiente;
    }
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->siguiente = actual->siguiente;
    actual->siguiente = nuevoNodo;
    nuevoNodo->dato=dato;
  }
}
//prueba 5
void Borrar(Nodo*lista,int n){
     bool band=false;
    Nodo*actual=new Nodo();
    Nodo*anterior=new Nodo();
    actual=lista;
    
    while((actual!=NULL)&&(actual->dato <=n)){
        if(actual->dato==n){
            band=true;
            break;
            
        }
        anterior=actual;
        actual=actual->siguiente;
        
        
    }
    if(band==true){
        if(actual==lista){
            lista=lista->siguiente;
        }
        else{
            anterior->siguiente=actual->siguiente;
        }
        delete actual;
    }
    else{
        cout<<"elemento no encontrado"<<"\n";
    }
    
    
}
    

//imprimir la lista
void mostrarlista(Nodo*lista){
    Nodo*actual=new Nodo();
    actual=lista;
    
    while(actual!= NULL){
        cout<<actual->dato<<"->";
        actual=actual->siguiente;
    }
}
//buscar
void buscarlista(Nodo*lista,int n){
    bool band=false;
    int i=0;
    Nodo*actual =new Nodo();
    actual=lista;
    
    while((actual!=NULL)&&(actual->dato <=n)){
        if(actual->dato==n){
            band=true;
        }
        actual=actual->siguiente;
        i++;
    }
    if(band==true){
        cout<<"elemento encontrado en posicion: "<<i<<"\n";
    }
    else{
        cout<<"elemento no encontrado"<<"\n";
    }
    
}


int main()
{
    Nodo*lista=NULL;
    
    int dato;
    int newdato;
    int posicion;
    for(int i=0;i<6;i++){
    cout<<"inserte un dato: ";
    cin>>dato;
    insertarLista(lista,dato);
    }
mostrarlista(lista);
cout<<"\ndigite numero a buscar\n";
cin>>dato;
buscarlista(lista,dato);
cout<<"\ndigite numero a borrar\n";
cin>>dato;
Borrar(lista,dato);
mostrarlista(lista);
cout<<"\ndigite numero a reemplazar\n";
cin>>dato;
cout<<"\ndigite valor: \n";
cin>>newdato;
insertarfirst(lista,dato,newdato);
mostrarlista(lista);
cout << "\nIntroduce el dato a insertar primer nodo:\n ";
cin >> dato;
insertarPrincipio(&lista, dato);
mostrarlista(lista);
cout << "\nIntroduce el dato a insertar en ultimo nodo:\n ";
cin >> dato;
insertarFinal(&lista,dato);
mostrarlista(lista);
cout << "\nInsertar dato nodo especifico \n";
cout << "Introduce el dato a insertar: ";
cin >> dato;
cout << "Introduce la posición: ";
cin >> posicion;
insertarPosicion(&lista, dato, posicion);
mostrarlista(lista);





    return 0;
}
