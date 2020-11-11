#pragma once
#include "Nodo.h"
#include <string>
#include <iostream>
using namespace std;

class Cabecera :public nodo
{
public:
	Cabecera(int s);
	void setSeccion(int s);
	int getSeccion();

private:
	int Seccion;
};