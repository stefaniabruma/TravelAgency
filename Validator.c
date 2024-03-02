#include "DOMAIN.h"
#include <string.h>
int validatorOfrt(oferta ofrt, char errors[])
{
	/*verifica daca o oferta este valida
	date de intrare:
	ofrt - oferta de validat (de tip oferta)
	errors - variabila de tip sir de caractere unde se vor stoca eventualele erori
	date de iesire:
	errors - eventualele erori ce ar putea aparea
	returneaza 0 in cazul in care nu sunt erori si 1 in caz contrar*/

	strcpy_s(errors, 1, "");
	char tip[30], dest[30], data[30];
	double pret;
	strcpy_s(tip, 30, getTipOfrt(ofrt));
	strcpy_s(dest, 30, getDestOfrt(ofrt));
	strcpy_s(data, 30, getDataOfrt(ofrt));
	pret = getPretOfrt(ofrt);
	if (strcmp(tip, "Munte") != 0 && strcmp(tip, "Mare") != 0 && strcmp(tip, "CityBreak") != 0)
		strcat_s(errors, 100, "Tip invalid!\n");
	if (strcmp(dest, "") == 0)
		strcat_s(errors, 100, "Destinatie invalida!\n");
	if (strchr("1234567890", data[0]) == NULL || strchr("1234567890", data[1]) == NULL || data[2] != '.' || strchr("1234567890", data[3]) == NULL || strchr("1234567890", data[4]) == NULL || data[5] != '.' || strchr("1234567890", data[6]) == NULL || strchr("1234567890", data[7]) == NULL || strchr("1234567890", data[8]) == NULL || strchr("1234567890", data[9]) == NULL)
		strcat_s(errors, 100, "Data de plecare invalida!\n");
	if (pret <= 0.0)
		strcat_s(errors, 100, "Pret invalid!\n");
	if (strlen(errors) != 0)
		return 1;
	return 0;
}