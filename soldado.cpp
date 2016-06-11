#pragma once
#include "soldado.h"
#include <sstream>
// using std::string;
// using std::stringstream;
using namespace std;
Soldado::Soldado(string nombre, string ciudad, int edad){
	this->nombre = nombre;
	this->ciudad = ciudad;
	this->edad = edad;
}
string Soldado::toString(){
	stringstream ss;
	ss << "\n\tNombre: " << this-> nombre << "\n\tCiudad: " << this->ciudad << "\n\tEdad: " << this->edad << endl;
	return ss.str();
}
// double Soldado::eficienciaAtaque()const{
// }
// double Soldado::eficienciaDefensa()const{
// }
