#include "soldado.h"
#include "escuadron.h"
#include <sstream>	
#include <vector>
using namespace std;
Escuadron::Escuadron(string nombre){
	this->nombre = nombre;
}
double Escuadron::eficienciaAtaque()const{
	double retVal;
	for(int i = 0; i < this->soldados.size(); i++)
		retVal += soldados[i]->eficienciaAtaque();
	return retVal;

}
double Escuadron::eficienciaDefensa()const{
	double retVal;
	for(int i = 0; i < this->soldados.size(); i++)
		retVal += soldados[i]->eficienciaDefensa();
	return retVal;
}
void Escuadron::agregarSoldado(Soldado* nuevo){
	this->soldados.push_back(nuevo);
}
// Escuadron::~Escuadron(){}
string Escuadron::toString(){
	stringstream ss;
	ss << "Escuadron: " << this->nombre << endl;
	for(int i = 0; i < this->soldados.size(); i++)
		ss << "Soldado #" << i + 1 << " " << this->soldados[i]->toString();
	ss << "\tAtaque: " << this->eficienciaAtaque() << endl;
	ss << "\tDefensa: " << this->eficienciaDefensa() << endl;
	return ss.str();
}
