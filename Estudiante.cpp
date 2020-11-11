#include "Estudiante.h"

Estudiante::Estudiante(int carnet, int seccion)
{
	this->carnet = carnet;
	this->seccion = seccion;
}

void Estudiante::setCarnet(int Carnet)
{
	this->carnet = Carnet;
}

void Estudiante::setSeccion(int s)
{
	this->seccion = s;
}

int Estudiante::getSeccion()
{
	return this->seccion;
}

int Estudiante::getCarnet()
{
	return this->carnet;
}