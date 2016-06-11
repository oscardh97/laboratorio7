#include "arquero.h"
#include "soldado.h"
#include <sstream>
using namespace std;
Arquero::Arquero(string nombre, string ciudad, int edad, int flechas, double precision):Soldado(nombre, ciudad, edad),flechas(flechas), precision(precision){}
double Arquero::eficienciaAtaque()const{
	return (this->flechas * this->precision) / 1000;
}
double Arquero::eficienciaDefensa()const{
	return -1.0;
}
string Arquero::toString(){
	stringstream ss;
	ss << "Arquero:" << Soldado::toString() << "\n\tFlechas: " << this-> flechas << "\n\tPrecision: " << this->precision << endl;
	return ss.str();
}