#pragma once;
#include "corazaDura.h"
#include <cstring>
using namespace std;
corazaDura::corazaDura(string nombre, string ciudad, int edad, int lanzas, int armadura):Soldado(nombre, ciudad, edad),lanzas(lanzas), armadura(armadura){}
double corazaDura::eficienciaAtaque()const{
	return this->lanzas;
}
double corazaDura::eficienciaDefensa()const{
	return this->armadura;
}
string corazaDura::toString(){
	stringstream ss;
	ss << "Coraza Dura:" << Soldado::toString() << "\n\tLanzas: " << this-> lanzas << "\n\tArmadura: " << this->armadura << endl;
	return ss.str();
}