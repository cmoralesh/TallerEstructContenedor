/* taller de estrucutra de datos
 Cesar Andres Morales Hincapie
 sabados
*/

#include <iostream>
#include <malloc.h>

using namespace std;

struct prioridad {
    int codigo_contenedor;
	int nivel; 
    prioridad *izq;
    prioridad *der;
};
prioridad *raiz, *aux1, *aux2; 


int posicionar(){
    if(aux1->codigo_contenedor < aux2->codigo_contenedor){
        if(aux2->izq!=NULL){
            aux2 = aux2->izq;
            posicionar();
        }
		else 
		    aux2->izq = aux1;               
    }
   
	else if(aux1->codigo_contenedor > aux2->codigo_contenedor){
        if(aux2->der!=NULL){
        aux2 = aux2->der;
        posicionar();    
        }
		else 
		    aux2->der = aux1;
    }
	    else if(aux1->codigo_contenedor == aux2->codigo_contenedor){
    	if(aux2->izq!=NULL && aux2->der!=NULL){
              aux2 = aux2 ->der--;
			  aux2 = aux2 ->izq++;
              posicionar();
	}
}
       return 0; 
   }

int registrar(){
    aux1 = (struct prioridad *)malloc(sizeof(struct prioridad));
    aux1->izq = aux1->der = NULL;
    cout<<"digite el codigo del contenedor: ";
    cin >> aux1->codigo_contenedor;
    cout<<"nivel de prioridad? ";
    cin >> aux1->nivel;
    if(!raiz) {
        raiz = aux1;
        aux1 = NULL;
        free(aux1);        
    } else {
        posicionar();
    }
    
    return 0;
};
int recorrer(prioridad *item){
    cout<<"prioridad: "<<item->nivel<<endl;
    if(item->izq!=NULL){
        recorrer(item->izq);
    }
    if(item->der!=NULL){
        recorrer(item->der);
    }
    return 0;
};

int main(){
  int opc=0;
  do{
     cout<<"---------Menu-------"<<endl;
     cout<<"1. Registro de contenedor"<<endl;
     cout<<"2. Ver registro"<<endl;
     cout<<"3. Salir"<<endl;
     cin>>opc;
     switch(opc){
         case 1: registrar(); break;
         case 2: recorrer(raiz); break;
      }
   }while(opc!=3);
}
