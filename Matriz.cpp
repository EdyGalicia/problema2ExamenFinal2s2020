#include "Matriz.h"
#include <string>
#include"Estudiante.h"



Matriz::Matriz()
{
	this->horizontal = NULL;
	this->vertical = NULL;
}

Matriz::~Matriz()
{
}

void Matriz::add(Estudiante* nuevo)
{
	Cabecera* vertical = this->getVertical(nuevo->getSeccion());
	Cabecera* horizontal = this->getHorizontal(nuevo->getSeccion());
	if (vertical == NULL) {
		vertical = crearVertical(nuevo->getSeccion());
	}
	if (horizontal == NULL) {
		horizontal = crearHorizontal(nuevo->getSeccion());
	}
	nodo* izquierda = obtenerUltimoH(vertical, nuevo->getSeccion());
	nodo* superior = obtenerUltimoV(horizontal, nuevo->getSeccion());
	if (izquierda->getEste() == NULL) {
		izquierda->setEste(nuevo);
		nuevo->setOeste(izquierda);
	}
	else {
		nodo* temp = izquierda->getEste();
		izquierda->setEste(nuevo);
		nuevo->setOeste(izquierda);
		temp->setOeste(nuevo);
		nuevo->setEste(temp);
	}
	if (superior->getSur() == NULL) {
		superior->setSur(nuevo);
		nuevo->setNorte(superior);
	}
	else {
		nodo* temp = superior->getSur();
		superior->setSur(nuevo);
		nuevo->setNorte(superior);
		temp->setNorte(nuevo);
		nuevo->setSur(temp);
	}
}
Cabecera* Matriz::getVertical(int dato)
{
	if (this->vertical == NULL) {
		return NULL;
	}
	Cabecera* aux = this->vertical;
	while (aux != NULL) {
		if (aux->getSeccion() == dato) {
			return aux;
		}
		aux = (Cabecera*)aux->getSur();
	}
	return NULL;
}

Cabecera* Matriz::getHorizontal(int dato)
{
	if (this->horizontal == NULL) {
		return NULL;
	}
	Cabecera* aux = this->horizontal;
	while (aux != NULL) {
		if ((aux->getSeccion() == dato)) {
			return aux;
		}
		aux = (Cabecera*)aux->getEste();
	}
	return NULL;
}

Cabecera* Matriz::crearVertical(int dato)
{
	if (this->vertical == NULL) {
		Cabecera* nueva = new Cabecera(dato);
		this->vertical = nueva;
		return nueva;
	}
	Cabecera* aux = this->vertical;
	if (dato <= aux->getSeccion()) {
		Cabecera* nueva = new Cabecera(dato);
		nueva->setSur(aux);
		this->vertical->setNorte(nueva);
		this->vertical = nueva;
		return nueva;
	}
	while (aux->getSur() != NULL) {
		if (dato > aux->getSeccion() && dato <= ((Cabecera*)aux->getSur())->getSeccion()) {
			Cabecera* nueva = new Cabecera(dato);
			Cabecera* temp = (Cabecera*)aux->getSur();
			temp->setNorte(nueva);
			nueva->setSur(temp);
			aux->setSur(nueva);
			nueva->setNorte(aux);
			return nueva;
		}
		aux = (Cabecera*)aux->getSur();
	}
	Cabecera* nuevo = new Cabecera(dato);
	aux->setSur(nuevo);
	nuevo->setNorte(aux);
	return nuevo;
}

Cabecera* Matriz::crearHorizontal(int dato)
{
	if (this->horizontal == NULL) {
		Cabecera* nueva = new Cabecera(dato);
		this->horizontal = nueva;
		return nueva;
	}
	Cabecera* aux = this->horizontal;
	if (dato <= aux->getSeccion()) {
		Cabecera* nueva = new Cabecera(dato);
		nueva->setEste(aux);
		this->horizontal->setOeste(nueva);
		this->horizontal = nueva;
		return nueva;
	}
	while (aux->getEste() != NULL) {
		if (dato > aux->getSeccion() && dato <= ((Cabecera*)aux->getEste())->getSeccion()) {
			Cabecera* nueva = new Cabecera(dato);
			Cabecera* temp = (Cabecera*)aux->getEste();
			temp->setOeste(nueva);
			nueva->setEste(temp);
			aux->setEste(nueva);
			nueva->setOeste(aux);
			return nueva;
		}
		aux = (Cabecera*)aux->getEste();
	}
	Cabecera* nuevo = new Cabecera(dato);
	aux->setEste(nuevo);
	nuevo->setOeste(aux);
	return nuevo;
}

nodo* Matriz::obtenerUltimoV(Cabecera* cabecera, int seccion)
{
	if (cabecera->getSur() == NULL) {
		return cabecera;
	}
	nodo* aux = cabecera->getSur();
	while (aux->getSur() != NULL)
	{
		if (seccion <= ((Estudiante*)aux)->getSeccion()) {
			return aux->getNorte();
		}
		aux = aux->getSur();
	}
	if (seccion <= ((Estudiante*)aux)->getSeccion()) {
		return aux->getNorte();
	}
	return aux;
}

nodo* Matriz::obtenerUltimoH(Cabecera* cabecera, int seccion)
{
	if (cabecera->getEste() == NULL) {
		return cabecera;
	}
	nodo* aux = cabecera->getEste();
	while (aux->getEste() != NULL)
	{
		if (seccion <= ((Estudiante*)aux)->getSeccion()) {
			return aux->getOeste();
		}
		aux = aux->getEste();
	}
	if (seccion <= ((Estudiante*)aux)->getSeccion()) {
		return aux->getOeste();
	}
	return aux;
}