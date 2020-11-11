#pragma once
#include <iostream>
using namespace std;

class nodo
{
public:
	nodo();
	void setNorte(nodo* n);
	void setEste(nodo* n);
	void setOeste(nodo* n);
	void setSur(nodo* n);
	nodo* getNorte();
	nodo* getSur();
	nodo* getEste();
	nodo* getOeste();
private:
	nodo* sur;
	nodo* norte;
	nodo* este;
	nodo* oeste;

};