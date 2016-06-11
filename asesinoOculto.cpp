#pragma once
#include "asesinoOculto.h"
#include "soldado.h"
#include <cstring>
#include <sstream>
using namespace std;
asesinoOculto::asesinoOculto(string nombre, string ciudad, int edad, int asesinatos, int escondidas):Soldado(nombre, ciudad, edad),asesinatos(asesinatos), escondidas(escondidas){}
double asesinoOculto::eficienciaAtaque()const{
	return this->asesinatos;
}
double asesinoOculto::eficienciaDefensa()const{
	return this->escondidas;
}
string asesinoOculto::toString(){
	stringstream ss;
	ss << "Asesino Oculto: "<< Soldado::toString() << "\n\tAsesinatos: " << this->asesinatos << "\n\tEscondidas: " << this->escondidas << endl;
	return ss.str();
}