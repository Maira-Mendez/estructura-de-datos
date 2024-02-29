#include <iostream>
#include <conio.h>
using namespace std;
//creadora Maira Mendez
struct Nodo{
	char n;
	Nodo *sig;
	Nodo *ant;

};
struct pal{
	char b;
	pal *sig;
	pal *ant;
};
void crear (Nodo*&cab, char d){
	Nodo *nuevo=new Nodo;
	nuevo->n=d;
	nuevo->sig=NULL;
	nuevo->ant=NULL;
	cab=nuevo;
}
void crearpal (pal*&cab, char d){
	pal *nuevo=new pal;
	nuevo->b=d;
	nuevo->sig=NULL;
	nuevo->ant=NULL;
	cab=nuevo;
}
void insInicio(Nodo*&cab, char d ){
	Nodo*nuevo=new Nodo;
	Nodo*aux=cab;
	nuevo->n=d;
	
	while (aux->sig!=NULL){
		aux=aux->sig;
	}
	aux->sig=nuevo;
	nuevo->ant=aux;
	nuevo->sig=NULL;
	
}
void insIniciopal(pal*&cab, char d ){
	pal*nuevo=new pal;
	pal*aux=cab;
	nuevo->b=d;
	
	while (aux->sig!=NULL){
		aux=aux->sig;
	}
	aux->sig=nuevo;
	nuevo->ant=aux;
	nuevo->sig=NULL;
	
}
void imprimir (Nodo*cab){
	Nodo*aux=cab;
	while (aux!=NULL){
	cout<<aux->n;
	aux=aux->sig;
	}
}
void imprimirpal (pal*cab){
	pal*aux=cab;
	while (aux!=NULL){
	cout<<aux->b;
	aux=aux->sig;
	}
}
int buscar (char f, Nodo*cab){
	Nodo*aux=cab;
	int a=2;
	
	while (aux!=NULL){
			if (f==aux->n){
			a=1;
			return a;
			break;
		}
	aux=aux->sig;
	}
		return a;
}

void menu(){
	int i;
	int bus=0;
	Nodo*cab=NULL;
	pal*cab2=NULL;
 	int cantnodos;
 	char letra;
	cout<<"dime cuantas letras quieres en tu alfabeto: "<<endl; cin>>cantnodos;
	cout<<"dime los caracteres uno por uno: "<<endl; cin>>letra;
	crear (cab, letra);
	for (int j=1; j<cantnodos; j++){
		cin>>letra; 
		insInicio (cab,letra);
		
	}
	system("cls");
	
	char palabra;
	int cantpal;
	cout<<"dime la cantidad de letras de tu palabra que quieres: "<<endl; cin>>cantpal;
	cout<<"dime los caracteres separados por espacio: "<<endl; cin>>palabra;
	crearpal (cab2, palabra);
	for (int j=1; j<cantpal; j++){
		cin>>palabra; 
		insIniciopal (cab2,palabra);
		
	}
	
	
	int h=0;
	pal*aux2=cab2;
	 while (aux2!=NULL){
	 	h=buscar (aux2->b, cab);
	 	if (h==2){
	 		cout<<"esta palabra no se puede"<<endl;
	 		getch();
	 		system ("cls");
	 		menu();
		 }
	 	aux2=aux2->sig;
	 }
		system("cls");

	cout<<"bienvenido al menu: "<<endl ;
	do{
		cout<<"1) prefijo \n";
		cout<<"2) sufijo \n";
		cout<<"3) imprimir la palabra \n";
		cout<<"4) imrpimir el alfabeto \n";
		cout<<"0) salir "<<endl;
		cin>>i;
		if (i==1){
		
			for (int i=0; i<cantpal; i++){
				int n=i;
				pal*aux=cab2;
				do  {
					cout<<aux->b;
					aux=aux->sig;
					n--;
				}while(n>-1);
				cout<<endl;
			}
			getch();
	 		system ("cls");
		}
		if (i==2){
			for (int i=0; i<cantpal; i++){
				int n=i;
				pal*aux3=cab2;
				while (aux3->sig!=NULL){
					aux3=aux3->sig;
				}	
				do  {
					cout<<aux3->b;
					aux3=aux3->ant;
					n--;
				}while(n>-1);
				cout<<endl;
			}
			getch();
	 		system ("cls");
		}if (i==3){
			imprimirpal(cab2);
			getch();
	 		system ("cls");
		}if (i==4){
			imprimir(cab);
			getch();
	 		system ("cls");
		}if (i<0 or i>4){
			cout<<"numero invalido"<<endl;
			getch();
	 		system ("cls");
		}
	}while (i!=0);	
	
}
	
	int main (){
	menu();
	cout<<"creado por: Maira Mnedez <3";
}