#pragma once
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
using namespace std;
class Persona{
	//atributos
protected: string telefono, nit;
		 //constructor
protected:
	Persona() {
	}

	Persona(string tele, string ni) {
		telefono = tele;
		nit = ni;
	}


};

