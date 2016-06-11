#pragma once
#include "soldado.h"
#include <sstream>
using std::string;
using std::stringstream;
class corazaDura : public Soldado{
	int armadura, lanzas;
	public:
		corazaDura();
		corazaDura(string, string, int, int, int);
		double eficienciaAtaque()const;
		double eficienciaDefensa()const;
		~corazaDura();
		virtual string toString();
};
