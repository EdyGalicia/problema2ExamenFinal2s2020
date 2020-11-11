#pragma once
#include "nodo.h"
#include "cabecera.h"
#include "Estudiante.h"
#include <iostream>
#include <string>
#include <ostream>
#include <sstream>
#include <fstream>
using namespace std;

class Matriz
{
public:
	Matriz();
	~Matriz();
	void add(Estudiante* nuevo);

private:
	Cabecera* horizontal;
	Cabecera* vertical;
	Cabecera* getVertical(int dato);
	Cabecera* getHorizontal(int dato);
	Cabecera* crearVertical(int dato);
	Cabecera* crearHorizontal(int dato);

	nodo* obtenerUltimoV(Cabecera* cabecera, int seccion);
	nodo* obtenerUltimoH(Cabecera* cabecera, int seccion);

};