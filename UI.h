#pragma once

#include "SERVICE.h"

typedef struct
{
	servOf serv;
}userInt;
userInt creeazaUI();
int menu();
int adauga(userInt* ui);
int afiseaza(userInt ui);
int modifica(userInt* ui);
int sterge(userInt* ui);
int filtrareTip(userInt* ui);
int filtrareDest(userInt* ui);
int filtrarePret(userInt* ui);
int filtrareData(userInt* ui);
int ordonareCresc(userInt* ui);
int ordonareDesc(userInt* ui);
int getComanda();
int ruleaza(userInt* ui, int cmd);
int distrugeUi(userInt* ui);
