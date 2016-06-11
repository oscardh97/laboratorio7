#pragma once;
#include "soldado.h"
#include <sstream>
using std::string;
using std::stringstream;
class Arquero : public Soldado{
	int flechas;
	double precision;
	public:
		Arquero();
		Arquero(string, string, int, int, double);
		double eficienciaAtaque()const;
		double eficienciaDefensa()const;
		~Arquero();
		string toString();
};