#pragma once
#include "soldado.h"
#include <sstream>
using std::string;
using std::stringstream;
class asesinoOculto : public Soldado{
	int asesinatos, escondidas;
	public:
		asesinoOculto();
		asesinoOculto(string, string, int, int, int);
		double eficienciaAtaque()const;
		double eficienciaDefensa()const;
		~asesinoOculto();
		virtual string toString();
};
