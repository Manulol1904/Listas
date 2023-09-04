#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo*sig;
}*first, *last;

void insertar(){
    Nodo*nuevo=new Nodo();
    cout<<"ingrese un dato: ";
    cin>>nuevo->dato;
    if(first==NULL){
        first=nuevo;
        first->sig=first;
        last=nuevo;
    }
    last->sig=nuevo;
    nuevo->sig=first;
    last=nuevo;
    
    
}
void imprimir(){
    Nodo*actual=new Nodo();
    actual=first;
    if(first!=NULL){
        do{
            cout<<actual->dato<<"->";
            actual=actual->sig;
            
        }while(actual!=first);
    }
    else{
        cout<<"la lista no existe";
    }
    
}
void buscar(){
    bool band=false;
    int i=1;
    Nodo*pivot=new Nodo();
    pivot=first;
    int value;
    cout<<"\ninserta dato a buscar: ";
    cin>>value;
    
    do{
        if(pivot->dato==value){
            band=true;
            break;
        }
        pivot=pivot->sig;
        i++;
        
        
    }while(pivot!=first);
    
    if(band==true){
        cout<<"el dato se encuentra en la posicion "<<i;
    }
    else{
        cout<<"sapo";
    }
}
void insertarF(){
    Nodo*nuevo = new Nodo();
    cout<<"\ninserta un dato: ";
    cin>>nuevo->dato;
    nuevo->sig=first;
    first=nuevo;
    last->sig=first;
    
}
void insertarL(){
    Nodo*nuevo = new Nodo();
    cout<<"\ninserta un dato: ";
    cin>>nuevo->dato;
    last->sig=nuevo;
    last=nuevo;
    last->sig=first;
    
}
void insertarA(){
    Nodo*actual = new Nodo();
    int posicion;
    cout<<"\ninserta posicion: ";
    cin>>posicion;
    actual=first;
    int i=1;
 
    do{
        i++;
        actual=actual->sig;
        

    }while((actual!=first)&&(i<posicion));
    Nodo*nuevo = new Nodo();
    cout<<"inserte dato a agregar: ";
    cin>>nuevo->dato;
    nuevo->sig=actual->sig;
    actual->sig=nuevo;
}
void actualizar(){
    Nodo*actual = new Nodo();
    int posicion;
    cout<<"\ninserta posicion: ";
    cin>>posicion;
    actual=first;
    int i=1;
    
    if(posicion==1){
        cout<<"inserte dato: ";
        cin>>first->dato;
    }
    else{
 
    do{
        
        i++;
        actual=actual->sig;
        

    }while((actual!=first)&&(i<posicion));
    cout<<"inserte dato: ";
    cin>>actual->dato;
    }
}
void borrar(){
    Nodo*actual = first;
    int i=1;
    int posicion;
    cout<<"ingrese posicio a borrar: ";
    cin>>posicion;
    Nodo*anterior=NULL;
    do{
        anterior=actual;
        actual=actual->sig;
        i++;
    }while(i<posicion);
    anterior->sig=actual->sig;
    delete actual;
}









int main(){
    for(int i=0; i<5; i++){
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
    borrar();
    imprimir();
    
    

    return 0;
}
