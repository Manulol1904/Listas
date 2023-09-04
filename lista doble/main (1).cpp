#include <iostream>
using namespace std;


struct Nodo{
    int dato;
    Nodo* sig;
    Nodo* ant;
}*first , *last;

void insertar(){
    Nodo*nuevo = new Nodo();
    cin>>nuevo->dato;
    if(first==NULL){
        first=nuevo;
        first->sig=NULL;
        first->ant=NULL;
        last=first;
    }
    else{
        last->sig=nuevo;
        nuevo->sig=NULL;
        nuevo->ant=last;
        last=nuevo;
    }
}

void imprimir(){
    Nodo*actual=new Nodo();
    actual=first;
    if(first!=NULL){
        while(actual != NULL){
            cout<<actual->dato <<"->";
            actual=actual->sig;
        }
    }
}
void buscar(){
    Nodo*actual=new Nodo();
    actual=first;
     bool band=false;
    int nodob;
    cout<<"\ningrese dato a buscar: ";
    cin>>nodob;
    int i=0;
    if(first!=NULL){
        while((actual != NULL && band!=true)){
            if(actual->dato==nodob){
                band=true;
                
            }
            actual=actual->sig;
            i++;
            
        }
        if(band==true){
            cout<<"Dato enocntrado en posicion: "<<i;
        }
        else{
            cout<<"Dato no existe en la lista";
        }
    }
}
void actualizar(){
    Nodo*actual=new Nodo();
    actual=first;
    bool band=false;
    int nodob;
    int newdato;
    cout<<"\ningrese dato a reemplazar: ";
    cin>>nodob;
    cout<<"ingrese dato nuevo ";
    cin>>newdato;
    if(first!=NULL){
        while((actual != NULL && band!=true)){
            if(actual->dato==nodob){
                band=true;
                break;
                
            }
            actual=actual->sig;
            
        }
        if(band==true){
            cout<<"Dato actualizado ";
            actual->dato=newdato;
        }
        else{
            cout<<"Dato no existe en la lista";
            cout<<"Dato no puede ser reemplazado";
        }
    }
}
void insertarF(){
    Nodo*nuevo = new Nodo();
    cout<<"\ninserte un nuevo dato: ";
    cin>>nuevo->dato;
    first->ant=nuevo;
    nuevo->sig=first;
    nuevo->ant=NULL;
    first=nuevo;
        
  
}
void insertarL(){
    Nodo*nuevo = new Nodo();
    cout<<"\ninserte un nuevo dato: ";
    cin>>nuevo->dato;
    last->sig=nuevo;
    nuevo->sig=NULL;
    nuevo->ant=last;
    last=nuevo;
        
  
}
void insertarA(){
    int posicion;
    Nodo*nuevo = new Nodo();
    cout<<"\ninserte posicion a agregar: ";
    cin>>posicion;
    posicion=(posicion-1);
    nuevo=first;
    
        for(int i=1;i<posicion;i++){
            nuevo=nuevo->sig;
        }
        Nodo*Vnuevo = new Nodo();
        cout<<"\ninserte un nuevo dato: ";
        cin>>Vnuevo->dato;
        Vnuevo->sig=nuevo->sig;
        nuevo->sig=Vnuevo;
        Vnuevo->ant=nuevo;

        
  
}
void Borrar(){
   int posicion;
   int i=1;
    Nodo*nuevo = new Nodo();
    Nodo*anterior=new Nodo();
    cout<<"\ninserte posicion a Borrar: ";
    cin>>posicion;
    posicion=(posicion-1);
    nuevo=first;
    
       while(i<=posicion){
           anterior=nuevo;
           nuevo=nuevo->sig;
           i++;
           
       }
        anterior->sig=nuevo->sig;
        nuevo->sig->ant=anterior;
}

















int main(){
    for(int i=0; i<5; i++){
        cout<<"inserte un dato:";
        insertar();
    }
    
    imprimir();
    cout<<"\nBuscar Dato\n";
    buscar();
    cout<<"\nActualizar Dato\n";
    actualizar();
    imprimir();
    cout<<"\nInsertar en primer nodo un dato\n";
    insertarF();
    imprimir();
    cout<<"\nInsertar en ultimo nodo un dato\n";
    insertarL();
    imprimir();
    cout<<"\nInsertar en nodo a eleccion un dato\n";
    insertarA();
    imprimir();
    cout<<"\nBorrar un nodo\n";
    Borrar();
    imprimir();
    
    

    return 0;
}