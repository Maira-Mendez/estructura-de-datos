#include <iostream>
using namespace std; 

struct Nodo{
	int dato;
	Nodo *sig; 
	Nodo *ant;
};
void crear (Nodo*&cab, int d){
Nodo *nuevo=new Nodo;
nuevo->dato=d;
nuevo->sig=NULL;
nuevo->ant=NULL;
cab=nuevo;
}
void insInicio(Nodo*&cab,int d ){
	Nodo*nuevo =new Nodo; 
	nuevo->dato=d;
	nuevo->sig=cab;
	cab->ant=nuevo; 
	nuevo->ant=NULL;
	cab=nuevo;
}
void imprimir2 (Nodo*cab){
	Nodo*aux=cab;
	while (aux->sig!=NULL){
		aux=aux->sig;
	}
	while (aux!=NULL){
		cout<<aux->dato<<endl;
		aux=aux->ant;
	}
}
void imprimir (Nodo*cab){
	Nodo*aux=cab;
	while (aux!=NULL){
	cout<<aux->dato;
	aux=aux->sig;
	}
}
void insFinal (Nodo*cab, int d){
	Nodo*nuevo=new Nodo;
	Nodo*aux=cab;
	nuevo->dato=d;
	
	while (aux->sig!=NULL){
		aux=aux->sig;
	}
	aux->sig=nuevo;
	nuevo->ant=aux;
	nuevo->sig=NULL;
	
}
void insertarMed (Nodo*cab, int d, int b){
	Nodo*nuevo=new Nodo;
	Nodo*aux=cab;
	nuevo->dato=d;
	while (aux->dato!=b){
		aux=aux->sig;
	}
	
	nuevo->sig=aux->sig;
	aux->sig->ant=nuevo;
	aux->sig=nuevo;
	nuevo->ant=aux;
	
}
void eliminarInicio (Nodo*&cab){
	Nodo*aux=cab;
	cab=cab->sig;
	cab->ant=NULL;
	
	delete aux;
}
void eliminarMedio (Nodo*cab, int b){
	Nodo*aux=cab;
	while (aux->dato!=b){
		aux=aux->sig;
	}
	aux->sig->ant=aux->ant;
	aux->ant->sig=aux->sig;
	delete aux;
}
void menu (){
int i;
Nodo*cab=NULL;
	int numnodos, cantnodos;
	cout<<"dime cuantos nodos quieres: "<<endl; cin>>cantnodos;
	cout<<"dime los valores de los nodos uno por uno: "<<endl; cin>>numnodos;
	crear (cab, numnodos);
	
	for (int j=1; j<cantnodos; j++){
		cin>>numnodos; 
		insInicio (cab,numnodos);
		
	}
	
	cout<<"bienvenido al menu: "<<endl ;
	do{
		cout<<"1) insertar al inicio \n";
		cout<<"2) insertar en el medio \n";
		cout<<"3) insertar al final \n";
		cout<<"4) imprimir desde el inicio \n";
		cout<<"5) imprimir desde el final \n";
		cout<<"6) borrar el primero \n";
		cout<<"7) borrar en el medio \n";
		cout<<"0) para salir \n";
		int y; cin>>i;
		if (i==1){
			cout<<"dime el numero del nuevo nodo: "<<endl; cin>>numnodos;
			insInicio (cab, numnodos);
		}if (i==2){
			cout<<"dime el numero del nuevo nodo y el numero del nodo en el que lo vamos a colocar: "<<endl; cin>>numnodos; cin>>y;;
			insertarMed (cab, numnodos, y);
		}if (i==3){
			cout<<"dime el numero del nuevo nodo: "<<endl; cin>>numnodos;
			insFinal (cab, numnodos);
		}if (i==4){
			imprimir (cab);
		}if (i==5){
			imprimir2 (cab);
		}if (i==6){
			eliminarInicio (cab);
		}if (i==7){
			
			//eliminarMedio (cab, )
		}
	}while (i!=0);	
}
int main (){
	
	menu ();
}