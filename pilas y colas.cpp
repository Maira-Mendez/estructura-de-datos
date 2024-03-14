#include <iostream>

using namespace std;
struct Pila {
	int dato;
	Pila* sig;
};

struct Cola {
	int dato;
	Cola*sig;
	
};
Pila*cabp=NULL;
Cola*cabf=NULL;
void crearPila (Pila*&cabp,int n){
	
	Pila*nuevo = new Pila;
	nuevo->dato=n;
	nuevo->sig=NULL;
	cabp=nuevo;
}

void crearCola (Cola*&cabc,int x){
	
	Cola*nuevo = new Cola;
	nuevo->dato=x;
	nuevo->sig=NULL;
	cabc=nuevo;
}

void insFinalCola (Cola*cabc,int n){

	Cola*nuevo = new Cola;
	nuevo->dato = n;
	nuevo->sig = NULL;
	Cola*aux = cabc;
	while (aux->sig != NULL)
		aux = aux -> sig;

	aux -> sig = nuevo;

}
void insFinalPila (Pila*cabp,int n){

	Pila*nuevo = new Pila;
	nuevo->dato = n;
	nuevo->sig = NULL;
	Pila*aux = cabp;
	while (aux->sig != NULL)
		aux = aux -> sig;

	aux -> sig = nuevo;

}

void elimFinal (Pila*cabp){

		Pila*aux=cabp;
		Pila*ant;

		while(aux->sig!=NULL){

			ant=aux;
			aux=aux->sig;
		}

	ant->sig=NULL;
	delete aux;
}

void elimInis (Cola*&cabc){
	Cola*aux=cabc;
	cabc=cabc->sig;
	
	delete aux;
}
void imprimirTopePila (Pila*cabp){
	Pila*aux=cabp;
	while (aux->sig!=NULL){
		aux=aux->sig;
	}
	cout<<aux->dato;
}
void imprimirInsFinalCola (Cola*cabc){
	Cola*aux=cabc;
	cout<<aux->dato;
	while (aux->sig!=NULL){
		aux=aux->sig;
	}
	cout<<aux->dato;
}

int main (){
//	Cola*cabc=NULL;
	//Pila*cabf=NULL;
	int opcion,x;
	do{
		cout<<"\teste sera nuestro menu: "<<endl;
		cout<<"1) insertar en pila "<<endl;
		cout<<"2) eliminar en pila "<<endl;
		cout<<"3) insertar en cola"<<endl;
		cout<<"4) eliminar en cola "<<endl;
		cout<<"5) mostrar tope en pila "<<endl;
		cout<<"6) mostrar inicio y fin en cola "<<endl;
		cout<<"7) eliminar en pila y pasar a cola "<<endl;
		cout<<"8) eliminar en cola y pasar a pila "<<endl;
		cout<<"9) eliminar en pila hasta encontrar impar "<<endl;
		cout<<"10) eliminar en cola hasta que encuentre par "<<endl;
		cout<<"11) pedir numero, par elimina dos valores de la cola, de lo contrario inserta el valor "<<endl;
		cout<<"12) pedir numero, par elimina dos valores de la pila, de lo contrario inserta el valor "<<endl;
		cout<<"13) borra dos datos de la pila y mostrar su sumatoria "<<endl;
		cout<<"14) borra dos datos de la cola y mostrar su sumatoria "<<endl;
		cout<<"15) ingresar datoy eliminar de la cola hasta encontrarlo "<<endl;
		cout<<"16) ingresar datoy eliminar de la cola hasta encontrarlo "<<endl;
		cin>>opcion;
		if (opcion==1){
			if (cabp==NULL){
				cin>>x;
				crearPila(cabp, x);
			} else {
				cin>>x;
				insFinalPila(cabp,x);
			}
		}
		if (opcion==2){
			elimFinal (cabp);
		}
		if (opcion==3){
			cin>>x;
			if (cabp==NULL){
				crearCola (cabc, x);
			} else {
				cin>>x;
				insFinalCola(cabc,x);
			}
		}
		if (opcion==4){
			elimInis (cabc)
		}
		if (opcion==5){
			
		}
		if (opcion==6){
			
		}
		if (opcion==7){
		
		}
		if (opcion==8){
			
		}
		if (opcion==9){
			
		}
		if (opcion==10){
			
		}
		if (opcion==11){
			
		}
		if (opcion==12){
			
		}
		if (opcion==13){
			
		}
		if (opcion==14){
			
		}
		if (opcion==15){
			
		}
		if (opcion==16){
			
		}
		if (opcion<0 || opcion>16){
			cout<<"numero invalido"<<endl;
		}
		}
	}while (opcion!=0)
	
}