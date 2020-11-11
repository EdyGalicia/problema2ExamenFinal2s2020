
#pragma once
#include "Nodo.h"
#include <string>
#include <iostream>
using namespace std;


class Estudiante : public nodo
{
public:
	Estudiante(int carnet, int seccion);
	void setCarnet(int carnet);
	void setSeccion(int s);
	int getSeccion();
	int getCarnet();
private:
	int seccion;
	int carnet;
};