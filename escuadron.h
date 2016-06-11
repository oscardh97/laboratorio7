#pragma once
#include "soldado.h"
#include <sstream>
#include <iostream>
#include <vector>
// using std::vector;

using namespace std;
class Escuadron{
	string nombre;
	vector <Soldado*> soldados;
	public:
		Escuadron(string);
		double eficienciaAtaque()const;
		double eficienciaDefensa()const;
		void agregarSoldado(Soldado*);
		~Escuadron();
		string toString();
};
