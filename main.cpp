#include <iostream>
#include <stdio.h>
#include <math.h>
#include <fstream>
#include <vector>

using namespace std;

struct Punto { //creamos un objeto con la siguiente estructura
	string nombre; // tiene nombre
	float x; //tiene x es un decimal
	float y; //tiene y es un decimal
	string estado; // estado del punto puede ser cerrado o abierto
};
//hago una funcion
Punto creoPunto(string nombre,float x , float y , string estado){
	/*
		es una funcion que retorna un tipo de dato PUNTO
		con nombre,x,y,estado
	*/
	Punto punto;
	punto.nombre = nombre;
	punto.x = x;
	punto.y = y;
	punto.estado = estado;
	
	return punto; //nos retorna el punto
}
void agregar(){ //void nos indica que vamos a una funcion y no va retornar nada
	Punto misdatos; //creo un objeto de tipo Punto con
	cout<<"Nombre --> "; //pido un nombre
	cin>>misdatos.nombre; // agarro el nombre y lo guardo en nombre
	cout<<"X --> "; //pido un x
	cin>>misdatos.x;
	cout <<"Y --> ";
	cin>>misdatos.y;
	cout<<"Estado --> ";
	cin>>misdatos.estado;
	
	ofstream miarchivo; //creamos un objeto y lo llamamos miarchivo
	miarchivo.open("data.csv",std::ios::app); //entramos a la ultima linea
	cout<<misdatos.nombre<<" "<<misdatos.x<<" "<<misdatos.y<<" "<<misdatos.estado<<"\n"; //mostramos en pantalla
	miarchivo<<misdatos.nombre<<" "<<misdatos.x<<" "<<misdatos.y<<" "<<misdatos.estado<<"\n";
	miarchivo.close();
}
void listar(){ //opcion 3
	ifstream miarchivo;
	miarchivo.open("data.csv");
	Punto punto; //creamos la variable punto
	while(miarchivo>>punto.nombre>>punto.x>>punto.y>>punto.estado){ //mientras hayan lineas 
		cout<<punto.nombre<<" "<<punto.x<<" "<<punto.y<<" "<<punto.estado<<endl; //mostramos con cout esas lineas
	}
	miarchivo.close();
}
void eliminar(){ //opcion 2
	string nombre;
	Punto punto;
	
	ifstream miarchivo;
	miarchivo.open("data.csv",ios::in);
	
	ofstream nuevoarchivo;
	nuevoarchivo.open("temp.csv",ios::out);
	
	cout<<"Ingresa el nombre del punto : ";
	cin>>nombre;
	
	while(miarchivo>>punto.nombre>>punto.x>>punto.y>>punto.estado){
		if(nombre==punto.nombre){
			cout<<"Se elimino el punto "<<nombre<<endl;
		}else{
			nuevoarchivo<<punto.nombre<<" "<<punto.x<<" "<<punto.y<<" "<<punto.estado<<endl;
		}
	}
	miarchivo.close();
	nuevoarchivo.close();
	
	remove("data.csv");
	rename("temp.csv","data.csv");
}
void amenosde10(){
	ifstream miarchivo;
	miarchivo.open("data.csv");
	Punto punto;
	float x;
	float y;
	
	cout<<"Ingresar coordenadas"<<endl;
	cout<<"x : ";
	cin>>x;
	cout<<"y : ";
	cin>>y;
	cout<<"Buscando los puntos en un radio de 10 metros"<<endl;
	
	while(miarchivo>>punto.nombre>>punto.x>>punto.y>>punto.estado){
		float d = sqrt(pow(punto.x-x,2)+pow(punto.y-y,2));
		if(d <= 10){
			cout<<punto.nombre<<" "<<punto.x<<" "<<punto.y<<" "<<punto.estado<<endl;
		}
	}
	
}
void distanciapromedio(){
	ifstream miarchivo;
	miarchivo.open("data.csv");
	Punto punto;
	vector <Punto> puntos;
	
	while(miarchivo>>punto.nombre>>punto.x>>punto.y>>punto.estado){
		puntos.push_back(creoPunto(punto.nombre,punto.x,punto.y,punto.estado));
	}
	
	int caminostotales = 0;
	float distancia;
	float distanciatotal;
	
	for(int i = 0; i < puntos.size(); i++){
		for(int j = i+1 ; j < puntos.size(); j ++){
			distancia = sqrt(pow(puntos[i].x-puntos[j].x,2)+pow(puntos[i].y-puntos[j].y,2));
			caminostotales++;
			distanciatotal+=distancia;
		}
	}
	
	float promedio = distanciatotal/caminostotales;
	cout<<"La distancia promedio entre cada punto es "<<promedio<<endl;
}
void distanciamaslejana(){
	ifstream miarchivo;
	miarchivo.open("data.csv");
	Punto punto;
	vector <Punto> puntos;
	
	while(miarchivo>>punto.nombre>>punto.x>>punto.y>>punto.estado){
		puntos.push_back(creoPunto(punto.nombre,punto.x,punto.y,punto.estado));
	}
	
	float distancia;
	float maslejana=-1;
	
	for(int i = 0; i < puntos.size(); i++){
		for(int j = i+1 ; j < puntos.size(); j ++){
			distancia = sqrt(pow(puntos[i].x-puntos[j].x,2)+pow(puntos[i].y-puntos[j].y,2));
			if(distancia>=maslejana){
				maslejana = distancia;
			}
		}
	}
	cout<<"La distancia mas lejana entre los puntos es "<<maslejana<<endl;
}
void distanciamascorta(){
	ifstream miarchivo;
	miarchivo.open("data.csv");
	Punto punto;
	vector <Punto> puntos;
	
	while(miarchivo>>punto.nombre>>punto.x>>punto.y>>punto.estado){
		puntos.push_back(creoPunto(punto.nombre,punto.x,punto.y,punto.estado));
	}
	
	float distancia;
	float mascercana=99999999;
	
	for(int i = 0; i < puntos.size(); i++){
		for(int j = i+1 ; j < puntos.size(); j ++){
			distancia = sqrt(pow(puntos[i].x-puntos[j].x,2)+pow(puntos[i].y-puntos[j].y,2));
			if(distancia<=mascercana){
				mascercana = distancia;
			}
		}
	}
	cout<<"La distancia mas cercana entre los puntos es "<<mascercana<<endl;

}
void distanciadedospuntos(){
	float x1,y1,x2,y2;
	cout<<"Ingresar el valor x del punto 1 : ";
	cin>>x1;
	cout<<"Ingresar el valor y del punto 1 : ";
	cin>>y1;
	cout<<"Ingresar el valor x del punto 2 : ";
	cin>>x2;
	cout<<"Ingresar el valor y del punto 2 : ";
	cin>>y2;
	cout<<"PUNTO 1 ("<<x1<<","<<y1<<")"<<endl;
	cout<<"PUNTO 2 ("<<x2<<","<<y2<<")"<<endl;
	float distancia = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
	cout<<"La distancia es "<<distancia<<endl;
}
void pendiente(){
	float x1,y1,x2,y2;
	cout<<"Ingresar el valor x del punto 1 : ";
	cin>>x1;
	cout<<"Ingresar el valor y del punto 1 : ";
	cin>>y1;
	cout<<"Ingresar el valor x del punto 2 : ";
	cin>>x2;
	cout<<"Ingresar el valor y del punto 2 : ";
	cin>>y2;
	
	cout<<"PUNTO 1 ("<<x1<<","<<y1<<")"<<endl;
	cout<<"PUNTO 2 ("<<x2<<","<<y2<<")"<<endl;
	
	if(y1 == y2){
		cout<<"No se puede calcular la pendiente !";
	}else{
		float pendiente = (x2-x1)/(y2-y1);
		cout<<"El valor de la pendiente : "<<pendiente<<endl;
	}
}
int main(){
	char opcion; //variable que va ingresar el usuario
	do{
		cout<< "MENU"<<endl; //mostramos en pantalla el menu
		cout<<"1. Agregar una nueva posicion."<<endl;
		cout<<"2.Eliminar una nueva posicion por nombre."<<endl;
		cout<<"3.Listar 100 primeros puntos."<<endl;
		cout<<"4.Listar los puntos ubicados a menos de 10 metros."<<endl;
		cout<<"5.Calcular la distancia promedio entre cada punto."<<endl;
		cout<<"6.Determinar la distancia entre los puntos mas lejanos."<<endl;
		cout<<"7.Determinar la distancia mas corta entre los puntos."<<endl;
		cout<<"8.Determinar la distancia entre dos puntos"<<endl;
		cout<<"9.Determinar la pendiente con dos puntos"<<endl;
		cout<<"0. SALIR"<<endl;
		cout<<"¿Que opcion quieres? : ";
		cin>>opcion;// capturamos la opcion
		
		switch(opcion){ //luego verificamos el caso
		case '1':
			agregar(); //funcion agregar
			break;
		case '2':
			eliminar(); //funcion eliminar
			break;
		case '3':
			listar();
			break;
		case '4': 
			amenosde10();
			break;
		case '5':
			distanciapromedio();
			break;
		case '6':
			distanciamaslejana();
			break;
		case '7':
			distanciamascorta();
			break;
		case '8':
			distanciadedospuntos();
			break;
		case '9':
			pendiente();
			break;
		case '0':
			cout<<"Hasta luego"<<endl;
			break;
		default:
			cout<<"No es una opcion"<<endl;
		}
	}while (opcion != '0'); //mientras la variable no sea la opcion de salida
	cout<<"FIN"<<endl;
	return 0;
}