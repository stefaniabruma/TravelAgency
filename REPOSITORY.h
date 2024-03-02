#pragma once

#include "DOMAIN.h"

typedef struct
{
	oferta* oferte;
	int dim;
	int cap;
} listaOf;

listaOf creeazaRepo();
int adaugaOfrt(listaOf* lista, oferta ofrt);
int modificaOfrt(listaOf* lista, oferta ofrt, oferta ofrtN);
int stergeOfrt(listaOf* lista, oferta ofrt);
int lungimeLista(listaOf lista);
oferta* getAll(listaOf lista);
int resize(listaOf* lista);
int distrugeRepo(listaOf* lista);