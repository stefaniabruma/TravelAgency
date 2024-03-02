#include "REPOSITORY.h"
#include "VALIDATOR.h"
#include <string.h>

typedef struct
{
	listaOf repo;
} servOf;

servOf creeazaServ()
{
	/*creeaza un service de oferte
	date de intrare:
	-
	date de iesire:
	- service-ul de oferte nou creat (de tip servOf)
	*/
	listaOf repository;
	repository = creeazaRepo();
	servOf serv;
	serv.repo = repository;
	return serv;
}

int adaugaOf(servOf* serv, char* tip, char* dest, char* data, double pret, char* errors)
{
	/*adauga oferta cu tipul tip, destinatia dest, data de plecare data si pretul pret in lista de oferte
	date de intrare:
	tip - tipul ofertei ce urmeaza sa fie adugata (de tip char*)
	dest - destinatia ofertei ce urmeaza sa fie adugata (de tip char*)
	data - data de plecare a ofertei ce urmeaza sa fie adaugata (de tip char*)
	pretul - pretul ofertei ce urmeaza sa fie adaugata (de tipul double)
	errors - parametru in care se stocheaza eventualele erori (de tip char*)
	date de iesire:
	- returneaza 0 daca oferta a fost adaugata cu succes si 1 in caz contrar
	*/

	oferta ofrt = creeazaOferta(tip, dest, data, pret);
	
	if (validatorOfrt(ofrt, errors) == 1)
		return 1;

	adaugaOfrt(&(serv->repo), ofrt);
	return 0;
}

oferta* getAllServ(servOf serv)
{
	/*returneaza toate ofertele disponibile in service-ul de oferte
	date de intrare:
	serv - service-ul de oferte (de tip servOf)
	date de iesire
	- lista de oferte disponibile in acest moment (de tip oferta*)*/

	return getAll(serv.repo);
}

int lungimeServ(servOf serv)
{
	/*returneaza numarul ofertelor disponibile in service-ul de oferte
	date de intrare:
	serv - service-ul de oferte (de tip servOf)
	date de iesire:
	- lungimea listei de oferte din service-ul de oferte (de tip int)*/
	return lungimeLista(serv.repo);
}

int modificaOf(servOf* serv, char* tip, char* dest, char* data, double pret, char* tipN, char* destN, char* dataN, double pretN, char* errors)
{
	/*modifica oferta cu tipul tip, destinatia dest, data de plecare data si pretul pret la oferta cu tipul tipN, destinatia destN, data de plecare dataN si pretul pretN
	date de intrare:
	serv - service de oferte (de tipul servOf)
	tip - tipul ofertei de modificat (de tip char*)
	dest - destinatia ofertei de modificat (de tip char*)
	data - data de plecare a ofertei de modificat (de tip char*)
	pret - pretul ofertei de modificat (de tip int)
	tipN - noul tip al ofertei de modificat (de tip char*)
	destN - noua destiantie a ofertei de modificat (de tip char*)
	dataN - noua data de plecare a ofertei de modificat (de tip char*)
	pretN - noul pret al ofertei de modificat (de tip int)
	errors - locul unde vor fi stocate eventualele erori
	date de iesire:
	- returneaza 0 daca noile date ale ofertei sunt valide si 1 in caz contrar
	*/
	oferta ofrt = creeazaOferta(tip, dest, data, pret);
	oferta ofrtN = creeazaOferta(tipN, destN, dataN, pretN);
	if (validatorOfrt(ofrtN, errors) == 1)
		return 1;
	if (modificaOfrt(&serv->repo, ofrt, ofrtN) == 1)
	{
		strcpy_s(errors, 100, "Oferta nu exista!\n");
		return 1;
	}
	return 0;
}

int stergeOf(servOf* serv, char* tip, char* dest, char* data, double pret, char* errors)
{
	/*sterge oferta cu tipul tip, destinatia dest, data de plecare data si pretul pret
	date de intrare:
	serv - service de oferte (de tipul servOf)
	tip - tipul ofertei de sters (de tip char*)
	dest - destinatia ofertei de sters (de tip char*)
	data - data de plecare a ofertei de sters (de tip char*)
	pret - pretul ofertei de sters (de tip int)
	errors - locul unde vor fi stocate eventualele erori

	date de iesire:
	- returneaza 0 in cazul in care oferta a existat si a fost stersa si 1 in caz contrar
	*/
	oferta ofrt = creeazaOferta(tip, dest, data, pret);

	if (stergeOfrt(&serv->repo, ofrt) == 1)
	{
		strcpy(errors, "Oferta nu exista!\n");
		return 1;
	}
	return 0;
}

oferta* filtreazaTip(servOf* serv, oferta* filtrate, char* tip, int* numar)
{
	/* ofera lista de oferte ce au tipul tip
	date de intrare:
	serv - service-ul de oferte (De tip servOf*)
	filtrate - locul unde se vor stoca ofertele cu tipul tip (de tip oferta*)
	tip - tipul dupa care se realizeaza filtrarea (de tip char*)
	numar - numarul de elemente din lista filtrate (de tip int*)
	date de iesire:
	- lista de oferte ce au tipul tip (de tip oferte*)
	*/

	* numar = 0;
	for(int i = 0; i < lungimeServ(*serv); i++)
		if (strcmp(getTipOfrt(getAllServ(*serv)[i]), tip) == 0)
		{
			filtrate[*numar] = getAllServ(*serv)[i];
			*numar = *numar + 1;
		}

	return filtrate;
}

oferta* filtreazaDest(servOf* serv, oferta* filtrate, char* dest, int* numar)
{
	/* ofera lista de oferte ce au destinatia dest
	date de intrare:
	serv - service-ul de oferte (De tip servOf*)
	filtrate - locul unde se vor stoca ofertele cu destinatia dest (de tip oferta*)
	dest - destinatia dupa care se realizeaza filtrarea (de tip char*)
	numar - numarul de elemente din lista filtrate (de tip int*)
	date de iesire:
	- lista de oferte ce au destinatia dest (de tip oferte*)
	*/

	* numar = 0;
	for (int i = 0; i < lungimeServ(*serv); i++)
		if (strcmp(getDestOfrt(getAllServ(*serv)[i]), dest) == 0)
		{
			filtrate[*numar] = getAllServ(*serv)[i];
			*numar = *numar + 1;
		}

	return filtrate;
}

oferta* filtreazaPret(servOf* serv, oferta* filtrate, double pret, int* numar)
{
	/* ofera lista de oferte ce au pretul pret
	date de intrare:
	serv - service-ul de oferte (De tip servOf*)
	filtrate - locul unde se vor stoca ofertele cu pretul pret (de tip oferta*)
	pret - pretul dupa care se realizeaza filtrarea (de tip int)
	numar - numarul de elemente din lista filtrate (de tip int*)
	date de iesire:
	- lista de oferte ce au pretul pret (de tip oferte*)
	*/

	* numar = 0;
	for (int i = 0; i < lungimeServ(*serv); i++)
		if (getPretOfrt(getAllServ(*serv)[i]) == pret)
		{
			filtrate[*numar] = getAllServ(*serv)[i];
			*numar = *numar + 1;
		}

	return filtrate;
}

oferta* filtreazaData(servOf* serv, oferta* filtrate, char* data, int* numar)
{
	/*ofera lista de oferte ce au data data
	date de intrare:
	serv - service-ul de oferte(de tip servOf*)
	filtrate - locul unde se vor stica ofertele cu data data (de tip oferta*)
	data - data dupa care se realizeaza filtrarea (de tip int)
	numar - numarul de elemente din lista filtrate (de tip int*)
	date de iesire:
	- lista de oferte ce au pretul pret (de tip oferte*)
	*/
	*numar = 0;
	for (int i = 0; i < lungimeServ(*serv); i++)
		if (strcmp(getDataOfrt(getAllServ(*serv)[i]), data) == 0)
		{
			filtrate[*numar] = getAllServ(*serv)[i];
			*numar = *numar + 1;
		}

	return filtrate;
}

oferta* ordonateFunc(servOf* serv, oferta* ordonate, int (*funcPtr)(oferta, oferta))
{
	/*ordoneaza ofertele dupa functia funcPtr
	date de intrare:
	serv - service-ul de oferte
	ordonate - locatia unde se vor regasi ofertele ordonate dupa functia funcPtr
	date de iesire
	- locatia unde se regasesc ofertele ordonate dupa functia funcPtr*/


	int i, j;
	for (i = 0; i < lungimeServ(*serv); i++)
		ordonate[i] = getAllServ(*serv)[i];
	for (i = 0; i < lungimeServ(*serv) - 1; i++)
		for (j = 0; j < lungimeServ(*serv) - i - 1; j++)
			if (funcPtr(ordonate[j], ordonate[j + 1]) == 0)
			{
				oferta aux = ordonate[j];
				ordonate[j] = ordonate[j + 1];
				ordonate[j + 1] = aux;
			}
	return ordonate;
}


int distrugeServ(servOf* serv)
{
	/*distruge service-ul de oferte serv
	date de intrare:
	serv -  service de oferte
	date de iesire:
	returneaza 0*/
	distrugeRepo(&serv->repo);
	return 0;
}