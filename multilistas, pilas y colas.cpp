#include <iostream>
#include <conio.h>
using namespace std;

struct cajas{
	int id;
	cajas* sig;
};

struct bodegas{
	string nom;
	bodegas* sig=NULL;
	cajas* sec=NULL;
};

struct cola {
	int id;
	cola* sig;
};

void crearprin (bodegas*& cab, string n){
	bodegas* nuevo = new bodegas;
	bodegas* aux;
	nuevo->nom=n;
	nuevo->sec=NULL;
	if (cab==NULL){
		cab=nuevo;
	}else{
		aux=cab;
		while(aux->sig!=NULL){
			aux=aux->sig;
		}
		aux->sig=nuevo;
	}
	
	nuevo->sig=NULL;
}


void imprimirmulti (bodegas* cab){
	bodegas*aux=cab;
	cajas*aux2;
	while (aux!=NULL){
		cout<<aux->nom<<"->";
		aux2=aux->sec;
		while (aux2!=NULL){
			cout<<aux2->id<<"->";
			aux2=aux2->sig;
		}
		cout<<endl;
		aux=aux->sig;
	}
}

cajas* desapilar (cajas*& cab){
	cajas*aux=cab;
	if(cab->sig==NULL){
		cab=NULL;
	}else{
		
	 cab=cab->sig;
	}
	
	return aux;
	delete aux;
	
}
void encolar(cola *&cab2, int d){
	cola*aux=cab2;
	cola* nuevo= new cola;
	nuevo->id=d;

	if (cab2==NULL){
		cab2=nuevo;
	}else{
		while (aux->sig!=NULL){
			aux=aux->sig;
		}
		aux->sig=nuevo;
	}
	nuevo->sig=NULL;
	
}
void insertarcaja (cajas*& cab, int n){
	cajas*nuevo = new cajas;
	nuevo->id=n;
	if (cab==NULL)
	{
		nuevo->sig=NULL;
	} 
	else 
	{
			nuevo->sig=cab;
	}
	cab=nuevo;
}

void imprimircola (cola*cab){
	cola* aux=cab;
	if(cab==NULL){
		cout<<"cola vacia \n";
	}else{
		while (aux!=NULL){
			cout<<"id: "<<aux->id<<endl;
			aux=aux->sig;
		}
	}
	
}	
	

cola* desencolar (cola*& cab){
	cola*aux=cab;
	if (cab->sig==NULL){
		cab=NULL;
	}else{
		cab=cab->sig;
	}
	return aux;
	delete aux;
}
bodegas* buscarbodega(bodegas* cab , string i){
	bodegas* aux=cab;
	while(aux->nom!=i){
		aux=aux->sig;
	}
	
	return aux;	
} 	


int main(){
	cola * cab2=NULL;
	bodegas*cab=NULL;
	bodegas* auxbo;
	cajas* auxca;
	cola* auxco;
	string n;
	int b, op;
	
	do{
	cout<<"\t Este sera nuestro menu: ";
	cout<<"\n1) ingresar una nueva bodega ";
	cout<<"\n 2) ingresar cajas en una bodega ";
	cout<<"\n 3) imprimir bodegas con las cajas ";
	cout<<"\n 4) pasar a cola";
	cout<<"\n 5) mostrar cola";
	cout<<"\n 6) desencolar ";
	cout<<"\n 0) salir\n";
	cin>>op;
	
		if (op==1){
			cout<<"dime el nombre de la bodega :"; cin>>n;
			crearprin(cab, n);
		}
		if (op==2){
			bodegas* aux=cab;
			cout<<"dime el nombre de la biodega en el que vas a ingresar :"; cin>>n;
			cout<<"dime el id de la caja: "; cin>>b;
				while(aux->nom!=n){
					aux=aux->sig;
				}
			insertarcaja(aux->sec, b);
		}
		if (op==3){
			imprimirmulti (cab);
			getch ();
		}
		if (op==4){
			cout<<"Dime la bodega de la que vamos a sacar cajas: \n";
			cin>>n;
			auxbo=buscarbodega(cab, n);
			cout<<"dime cuantas cajas quieres llevar a la cola: "; cin>>b;
			for (int i=0; i<b; i++){
				if (auxbo->sec==NULL){
					cout<<"bodega vacia";
					getch();
					//break;
				}else{
					auxca=desapilar(auxbo->sec);
					encolar (cab2, auxca->id);	
				}
			}
			
		}
		if (op==5){
			imprimircola (cab2);
			getch ();
		}
		if (op==6){
			if (cab2==NULL){
				cout<<"cola vacia\n";
			}else {
				auxco=desencolar(cab2);
				cout<<"desencolaste la caja: "<<auxco->id<<endl;
				getch();	
			}
		}
		system ("cls");
	}while (op!=0);
}