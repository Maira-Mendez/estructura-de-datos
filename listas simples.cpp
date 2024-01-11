#include <iostream>

using namespace std;
struct Nodo{
	int dato;
	Nodo*sig;
};

void crear (Nodo*&cab, int n ){
	Nodo*nuevo=new Nodo;
	nuevo->dato=n;
	nuevo->sig=nuevo;
	cab=nuevo;	
}

void ponerinicio (Nodo*&cab, int n){
	Nodo*nuevo=new Nodo;
	nuevo->dato=n;
	nuevo->sig=cab;
	Nodo*aux=cab;
	while(aux->sig!=cab){
		aux=aux->sig;
	}
	aux->sig=nuevo;
	cab=nuevo;
}

void imprimir (Nodo*cab){
	Nodo*aux=cab;
	do{
		cout<<aux->dato<<endl;
		aux=aux->sig;
	}while (aux!=cab);	
}

void imprimirmedio (Nodo*cab, int b){
	Nodo*aux=cab;
	//Nodo*aux2=cab;
	while (aux->dato!=b){	
	aux=aux->sig;
	}
	Nodo*aux2=aux;
	do{
		cout<<aux2->dato<<endl<<endl;
		aux2=aux2->sig;
		
	}while (aux2!=aux);
}

void imprimirnum (Nodo*cab, int b){
	Nodo*aux=cab;
	while (aux->sig->sig!=cab){
		aux=aux->sig; 
	}
	for (int i=0; i<b; i++){
		imprimir (aux);	
	}
}
void eliminarPrimer (Nodo*cab){
	Nodo*aux=cab;
	Nodo*aux2=cab;
	while (aux->sig!=cab){
		aux=aux->sig;
	}
	aux=aux->sig->sig;
	cab=cab->sig;
	
	delete aux2;
	
	
}
void eliminarUltimo (Nodo*cab){
	
	
	
}

int main (){
	Nodo*cab=NULL;
	int x, y;
	cout<<"dime cuantos nodos quieres: "; cin>>x;
	cout<<"\ndime el primer numero: "; cin>>y;
	crear (cab, y);
	for (int j=1; j<x; j++){
		cin>>y;
		ponerinicio (cab, y);
	}
	
	 int i;
	cout<<"Bienvenido a nuestro menu, estas son las opciones: \n";
	do{
		cout<<"1) insertar \n";
		cout<<"2) imprimir \n";
		cout<<"3) imprimir desde un numero \n";
		cout<<"4) eliminar primer nodo \n";
		cout<<"5) eliminar ultimo nodo \n";
		cout<<"6) imprimir desde el penultimo un n de veces repetidas \n";
		cout<<"0) para salir \n"; cin>>i;
		if (i==1){
			int num;
			cout<<"dime el numero que quieres añadir "; cin>>num;
			ponerinicio (cab, num);	
		}if (i==2){
			imprimir (cab);
		}if (i==3){
			cout<<"dime desde que numero quieres imprimir: "; int e; cin>>e;
			imprimirmedio (cab, e);
		} if (i==4){
			eliminarPrimer (cab);	
		} if (i==5){
			eliminarUltimo (cab);	
		}if (i==6){
			cout<<"dime cuantas veces quieres imrpimir \n"; int r; cin>>r;
			imprimirnum (cab, r);
		}
	}while (i!=0);	
}