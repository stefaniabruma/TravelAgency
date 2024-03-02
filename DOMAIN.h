#pragma once

typedef struct
{
	char tip[30];
	char destinatie[30];
	char dataPlecare[30];
	double pret;
} oferta;

oferta creeazaOferta(char tip[], char destinatie[], char dataPlecare[], double pret);
const char* getTipOfrt(oferta ofrt);
const char* getDestOfrt(oferta ofrt);
const char* getDataOfrt(oferta ofrt);
double getPretOfrt(oferta ofrt);
int egal(oferta ofrt1, oferta ofrt2);
const char* str(oferta ofrt);
int maiMic(oferta ofrt1, oferta ofrt2);
int maiMare(oferta ofrt1, oferta ofrt2);