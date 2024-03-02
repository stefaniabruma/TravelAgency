#pragma once

#include "REPOSITORY.h"
#include "VALIDATOR.h"


typedef struct
{
	listaOf repo;
} servOf;

servOf creeazaServ();
int adaugaOf(servOf* serv, char* tip, char* dest, char* data, double pret, char* errors);
oferta* getAllServ(servOf serv);
int lungimeServ(servOf serv);
int modificaOf(servOf* serv, char* tip, char* dest, char* data, double pret, char* tipN, char* destN, char* dataN, double pretN, char* errors);
int stergeOf(servOf* serv, char* tip, char* dest, char* data, double pret, char* errors);
oferta* filtreazaTip(servOf* serv, oferta* filtrate, char* tip, int* numar);
oferta* filtreazaDest(servOf* serv, oferta* filtrate, char* dest, int* numar);
oferta* filtreazaPret(servOf* serv, oferta* filtrate, double pret, int* numar);
oferta* filtreazaData(servOf* serv, oferta* filtrate, char* data, int* numar);
oferta* ordonateCresc(servOf* serv, oferta* ordonate);
oferta* ordonateDesc(servOf* serv, oferta* ordonate);
int distrugeServ(servOf* serv);
oferta* ordonateFunc(servOf* serv, oferta* ordonate, int (*funcPtr)(oferta, oferta));