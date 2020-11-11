#include "Cabecera.h"

Cabecera::Cabecera(int s)
{
    this->Seccion = s;
}

void Cabecera::setSeccion(int s)
{
    this->Seccion = s;
}

int Cabecera::getSeccion()
{
    return this->Seccion;
}