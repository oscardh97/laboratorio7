#pragma once
#include <sstream>
using std::string;
using std::stringstream;
class Soldado{
	string nombre, ciudad;
	int edad;
	public:
		Soldado();
		Soldado(string, string, int);
		virtual double eficienciaAtaque()const=0;
		virtual double eficienciaDefensa()const=0;
		~Soldado();
		virtual string toString();
};