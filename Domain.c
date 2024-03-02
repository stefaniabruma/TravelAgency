#include <string.h>
typedef struct 
{
	char tip[30];
	char destinatie[30];
	char dataPlecare[30];
	double pret;
} oferta;

#include <stdio.h>

oferta creeazaOferta(char tip[], char destinatie[], char dataPlecare[], double pret)
{
	/*creeaza o oferta
	date de intrare:
	tip - char[] (reprezinta tipul ofertei create)
	destinatie - char [] (reprezinta destinatia ofertei create
	dataPlecare - char[] (reprezinta data de plecare a ofertei create)
	pret - double (reprezinta pretul ofertei create)
	date de iesire:
	- oferta nou creata (de tip oferta)*/
	oferta ofrt;
	strcpy_s(ofrt.tip, 30, tip);
	strcpy_s(ofrt.destinatie, 30, destinatie);
	strcpy_s(ofrt.dataPlecare, 30, dataPlecare);
	ofrt.pret = pret;
	return ofrt;
}

const char* getTipOfrt(oferta ofrt)
{
	/*returneaza tipul unei oferte ofrt
	date de intrare:
	ofrt - oferta
	date de iesire:
	- tipul ofereti ofrt (de tip char*)*/
	return ofrt.tip;
}

const char* getDestOfrt(oferta ofrt)
{
	/*returneaza destinatia unei oferte
	date de intrare:
	ofrt - oferta
	date de iesire:
	- destinatia ofertei ofrt (de tip char*)*/
	return ofrt.destinatie;
}

const char* getDataOfrt(oferta ofrt)
{
	/*returneaza data unei oferte
	date de intrare:
	ofrt - oferta
	date de iesire:
	- data de plecare a ofertei ofrt (de tip char*)*/
	return ofrt.dataPlecare;
}

double getPretOfrt(oferta ofrt)
{
	/*returneaza pretul unei oferte
	date de intrare:
	ofrt - oferta
	date de iesire
	- pretul oferei ofrt (de tip double)*/
	return ofrt.pret;
}

int egal(oferta ofrt1, oferta ofrt2)
{
	/*testeaza daca doua oferte sunt egale
	date de intrare:
	ofrt1 - de tip ofeta
	ofrt2 - de tip oferta
	date de iesire:
	- returneaza 0 daca cele doua oferte nu sunt egale si 1 in caz contrar*/
	if (strcmp(getTipOfrt(ofrt1), getTipOfrt(ofrt2)) == 0 && strcmp(getDestOfrt(ofrt1), getDestOfrt(ofrt2)) == 0 && strcmp(getDataOfrt(ofrt1), getDataOfrt(ofrt2)) == 0 && getPretOfrt(ofrt1) == getPretOfrt(ofrt2))
		return 1;
	return 0;
}

const char* str(oferta ofrt)
{
	/*returneaza modul in care o oferta arata la afisare
	date de intrare:
	ofrt - oferta (de tip oferta)
	date de iesire
	- sir de caractere ce concateneaza tipul, destinatia, data de plecare si pretul ofertei*/

	char sir[150];
	double pret = getPretOfrt(ofrt);

	strcpy_s(sir, 150, getTipOfrt(ofrt));
	strcat_s(sir, 150, "; ");
	strcat_s(sir, 150, getDestOfrt(ofrt));
	strcat_s(sir, 150, "; ");
	strcat_s(sir, 150, getDataOfrt(ofrt));
	strcat_s(sir, 150, "; ");

	char pretstr[30];
	sprintf_s(pretstr, 30, "%4.1lf", pret);
	strcat_s(sir, 150, pretstr);
	return sir;
}

int maiMic(oferta ofrt1, oferta ofrt2)
{
	/*compara doua oferte - ofrt1 este mai mica decat oferta2 daca are pretul mai mic; in caz de egalitate oferta mai mica este cea cu destinatia lexicografic inaintea celeilalte
	date de intrare:
	ofrt1 - oferta de comparat (de tip oferta)
	ofrt2 - oferta de comparat (de tip oferta)
	date de iesire
	- returneaza 1 daca ofrt1 este mai mica decat ofrt2 si 0 in caz contrar*/
	if (getPretOfrt(ofrt1) < getPretOfrt(ofrt2))
		return 1;

	if (getPretOfrt(ofrt1) == getPretOfrt(ofrt2) && strcmp(getDestOfrt(ofrt1), getDestOfrt(ofrt2)) < 0)
		return 1;

	return 0;
}

int maiMare(oferta ofrt1, oferta ofrt2)
{
	/*compara doua oferte - ofrt1 este mai mare decat oferta2 daca are pretul mai mare; in caz de egalitate oferta mai mare este cea cu destinatia lexicografic dupa cealalta
	date de intrare:
	ofrt1 - oferta de comparat (de tip oferta)
	ofrt2 - oferta de comparat (de tip oferta)
	date de iesire
	- returneaza 1 daca ofrt1 este mai mare decat ofrt2 si 0 in caz contrar*/
	if (getPretOfrt(ofrt1) > getPretOfrt(ofrt2))
		return 1;

	if (getPretOfrt(ofrt1) == getPretOfrt(ofrt2) && strcmp(getDestOfrt(ofrt1), getDestOfrt(ofrt2)) > 0)
		return 1;

	return 0;
}