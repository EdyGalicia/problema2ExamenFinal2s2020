#include "Nodo.h"

nodo::nodo()
{
	this->norte = NULL;
	this->sur = NULL;
	this->este = NULL;
	this->oeste = NULL;
}

void nodo::setNorte(nodo* n)
{
	this->norte = n;
}

void nodo::setEste(nodo* n)
{
	this->este = n;
}

void nodo::setOeste(nodo* n)
{
	this->oeste = n;
}

void nodo::setSur(nodo* n)
{
	this->sur = n;
}

nodo* nodo::getNorte()
{
	return this->norte;
}

nodo* nodo::getSur()
{
	return this->sur;
}

nodo* nodo::getEste()
{
	return this->este;
}

nodo* nodo::getOeste()
{
	return this->oeste;
}