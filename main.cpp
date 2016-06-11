#include "soldado.h"
#include "corazaDura.h"
#include "escuadron.h"
#include "arquero.h"
#include "asesinoOculto.h"
#include <iostream>
#include <vector>
#include <sstream>
// using std::cout;
// using std::endl;
using std::vector;
using namespace std;
int menu();
void imprimirEscuadrones(vector <Escuadron*>);

int main(int argc, char* argv[]){
	vector <Escuadron*> escuadrones;
	
	// int opcion = menu();
	// if(opcion == 1){
	int usuarios = 0;
	int cantEscuadrones = 0;
	bool otroSoldado;
	while(usuarios < 2){
		cout << "--------------------------------------------USUARIO NUMERO" << usuarios + 1 << "--------------------------------------------"<< endl;
		cout << "----------------------Para cada escuadron se pedira automaticamente un soldado---------------------------" << endl;
		while(cantEscuadrones < 4){
			string nombre;
			cout << "Ingrese el nombre del escuadron " << cantEscuadrones + 1 << endl;
			cin >> nombre;
			escuadrones.push_back(new Escuadron(nombre));
			do{
				string nombreSoldado, ciudad;
				int edad;
				cout << "Ingrese el nombre del soldado" << endl;
				cin >> nombreSoldado;
				cout << "Ingrese la ciudad" << endl;
				cin >> ciudad;
				cout << "Ingrese la edad" << endl;
				cin >> edad;
				int tipo;
				cout << "Ingrese el tipo de soldado" << endl;
				cout << "1. Arquero" << endl;
				cout << "2. Coraza Dura" << endl;
				cout << "3. Asesino" << endl;
				cin >> tipo;
				if(tipo == 1){
					int flechas;
					double precision;
					cout << "Ingrese las flechas" << endl;
					cin >> flechas;
					cout << "Ingrese la precision" << endl;
					cin >> precision;
					escuadrones[escuadrones.size() - 1]->agregarSoldado(new Arquero(nombreSoldado, ciudad, edad, flechas, precision));
				}else if(tipo == 2){
					int armadura;
					double lanzas;
					cout << "Ingrese las armadura" << endl;
					cin >> armadura;
					cout << "Ingrese la lanzas" << endl;
					cin >> lanzas;
					escuadrones[escuadrones.size() - 1]->agregarSoldado(new corazaDura(nombreSoldado, ciudad, edad, lanzas, armadura));
				}else{
					int asesinatos;
					double escondidas;
					cout << "Ingrese los asesinatos" << endl;
					cin >> asesinatos;
					cout << "Ingrese la escondidas" << endl;
					cin >> escondidas;
					escuadrones[escuadrones.size() - 1]->agregarSoldado(new asesinoOculto(nombreSoldado, ciudad, edad, asesinatos, escondidas));
					
				}
				// cout << escuadrones[escuadrones.size() - 1]->toString();
				imprimirEscuadrones(escuadrones);
				cout << "Desea agregar otro Soldado al escuadron? 1/0" << endl;
				cin >> otroSoldado;
			}while(otroSoldado);
			cantEscuadrones++;
		}
		usuarios++;
		cantEscuadrones = 0;
	}
	int hayGanador = 0;
	int usuarioActual = 1;
	bool* muertos = new bool[8];
	imprimirEscuadrones(escuadrones);
	cout << "--------------------------------------------SIMULACION--------------------------------------------" << endl;
	for(int i = 0; i <8;i++)
		muertos[i] = false;
	while(!hayGanador){
		int escuadronAtaque, escuadronDefensa;
		do{
			cout << "Usuario " << usuarioActual << " ingrese el numero del escuadron a atacar" << endl;
			cin >> escuadronAtaque;
			if(muertos[escuadronAtaque - 1]){
				cerr << "Escuadron Muerto!!" << endl;
			}else{
				break;
			}
		}while(1);
		do{
			cout << "Otro usuario ingrese el numero del escuadron a defender" << endl;
			cin >> escuadronDefensa;
			if(muertos[escuadronDefensa - 1]){
				cerr << "Escuadron Muerto!!" << endl;
			}else{
				break;
			}
		}while(1);
		if (escuadrones[escuadronAtaque - 1]->eficienciaAtaque() >= escuadrones[escuadronDefensa - 1]->eficienciaDefensa()){
			muertos[escuadronDefensa - 1] = true;
			int totalMuertos = 0;
			for(int i = 0; i < 4; i++){
				if (muertos[i]){
					totalMuertos++;
				}
			}
			if(totalMuertos == 4){
				hayGanador = usuarioActual;
			}
			totalMuertos = 0;
			for(int i = 4; i < 8; i++){
				if (muertos[i]){
					totalMuertos++;
				}
			}
			if(totalMuertos == 4){
				hayGanador = usuarioActual;
			}
		}
	}
	cout << "Gano el usuario " << usuarioActual << endl;
	return 0;
}
void imprimirEscuadrones(vector <Escuadron*> escuadrones){
	for(int i = 0; i < escuadrones.size(); i++){
		if(i == 0)
			cout << "--------------------------------------------Escuadrones de usuario: 1--------------------------------------------" << endl;
		if(i == 4)
			cout << "--------------------------------------------Escuadrones de usuario: 2--------------------------------------------" << endl;
		cout << i + 1<< ".- " << escuadrones[i]->toString();
	}
}