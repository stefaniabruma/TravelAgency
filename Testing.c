#include <assert.h>
#include <string.h>

#include "SERVICE.h"
#include <stdio.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int testeDomain()
{
	/*ruleaza testele domeniului de oferte
	date de intrare: 
	-
	date de iesire:
	- returneaza 0 daca testele au fost rulate cu succes*/

	oferta ofrt;
	ofrt = creeazaOferta("City break", "Viena", "28.06.2023", 2572.1);
	assert(strcmp(ofrt.tip, "City break") == 0);
	assert(strcmp(ofrt.destinatie, "Viena") == 0);
	assert(strcmp(ofrt.dataPlecare, "28.06.2023") == 0);
	assert(ofrt.pret == 2572.1);

	assert(strcmp(getTipOfrt(ofrt), "City break") == 0);
	assert(strcmp(getDestOfrt(ofrt), "Viena") == 0 );
	assert(strcmp(getDataOfrt(ofrt), "28.06.2023") == 0);
	assert(getPretOfrt(ofrt) == 2572.1);

	oferta ofrtE = creeazaOferta("City break", "Viena", "28.06.2023", 2572.1);
	assert(egal(ofrt, ofrtE) == 1);
	oferta ofrtD = creeazaOferta("Mare", "Grecia", "12.09.2023", 5637.2);
	assert(egal(ofrt, ofrtD) == 0);

	assert(strcmp(str(ofrt),"City break; Viena; 28.06.2023; 2572.1") == 0);

	assert(maiMic(ofrt, ofrtD) == 1);
	assert(maiMic(ofrtD, ofrt) == 0);

	oferta ofrtPretE = creeazaOferta("Munte", "Romania", "23.07.2023", 2572.1);
	assert(maiMic(ofrt, ofrtPretE) == 0);
	assert(maiMic(ofrtPretE, ofrt) == 1);
	return 0;
}

int testeValidator()
{
	/*ruleaza testele validatorului de oferte
	date de intrare:
	-
	date de iesire:
	- returneaza 0 daca testele au fost rulate cu succes*/

	oferta ofrt;
	ofrt = creeazaOferta("CityBreak", "Viena", "28.06.2023", 2572.1);
	char errors[100] = "";
	assert(validatorOfrt(ofrt, errors) == 0);
	assert(strcmp(errors, "") == 0);
	ofrt = creeazaOferta("Plaja", "", "28/06/2023", 0.0);
	assert(validatorOfrt(ofrt, errors) == 1);
	assert(strcmp(errors, "Tip invalid!\nDestinatie invalida!\nData de plecare invalida!\nPret invalid!\n") == 0);
	_CrtDumpMemoryLeaks();
	return 0;
}

int testeRepository()
{
	/*ruleaza testele repository-ului de oferte
	date de intrare:
	-
	date de iesire:
	- returneaza 0 daca testele au fost rulate cu succes*/

	listaOf lista;
	lista = creeazaRepo();
	assert(lungimeLista(lista) == 0);
	assert(lista.cap == 2);

	oferta ofrt = creeazaOferta("City break", "Viena", "28.06.2023", 2572.1);
	assert(adaugaOfrt(&lista, ofrt) == 0);
	oferta ofrt3 = creeazaOferta("Munte", "Franta", "10.06.2023", 3653.1);
	assert(adaugaOfrt(&lista, ofrt3) == 0);
	assert(lungimeLista(lista) == 2);
	assert(egal(lista.oferte[0], ofrt) == 1);
	assert(egal(lista.oferte[1], ofrt3) == 1);

	oferta ofrt2 = creeazaOferta("Munte", "Viena", "28.06.2023", 2572.1);
	oferta ofrtN = creeazaOferta("Mare", "Grecia", "12.09.2023", 5381.9);

	assert(modificaOfrt(&lista, ofrt2, ofrtN) == 1);
	assert(modificaOfrt(&lista, ofrt, ofrtN) == 0);
	assert(egal(lista.oferte[0], ofrtN) == 1);
	assert(lungimeLista(lista) == 2);
	assert(egal(getAll(lista)[0], ofrtN) == 1);

	assert(stergeOfrt(&lista, ofrtN) == 0);
	assert(lungimeLista(lista) == 1);
	
	assert(stergeOfrt(&lista, ofrtN) == 1);
	assert(lungimeLista(lista) == 1);

	assert(adaugaOfrt(&lista, ofrtN) == 0);
	assert(adaugaOfrt(&lista, ofrtN) == 0);
	assert(lista.dim == 3);
	assert(lista.cap == 4);

	listaOf listaTest;
	listaTest.cap = 0;
	listaTest.dim = 0;
	resize(&listaTest);

	distrugeRepo(&lista);
	_CrtDumpMemoryLeaks();
	return 0;
}

int testeService()
{
	/*ruleaza testele service-ului de oferte
	date de intrare:
	-
	date de iesire:
	- returneaza 0 daca testele au fost rulate cu succes*/

	servOf serv = creeazaServ();
	assert(lungimeLista(serv.repo) == 0);

	char* errors = (char*)malloc(100*sizeof(char));
	assert(adaugaOf(&serv, "CityBreak", "Viena", "28.06.2023", 2572.1, errors) == 0);
	assert(lungimeLista(serv.repo) == 1);
	assert(adaugaOf(&serv, "City brea", "", "28/06/2023", -2, errors) == 1);
	assert(lungimeLista(serv.repo) == 1);
	assert(strcmp(errors, "Tip invalid!\nDestinatie invalida!\nData de plecare invalida!\nPret invalid!\n") == 0);
	assert(lungimeServ(serv) == 1);
	assert(egal(getAllServ(serv)[0], creeazaOferta("CityBreak", "Viena", "28.06.2023", 2572.1)) == 1);

	strcpy_s(errors, 100, "");
	assert(modificaOf(&serv, "CityBreak", "Viena", "28.06.2023", 2572.1, "Mare", "Grecia", "23.03.2023", 3664.1, errors) == 0);
	assert(egal(getAllServ(serv)[0], creeazaOferta("Mare", "Grecia", "23.03.2023", 3664.1)) == 1);
	assert(modificaOf(&serv, "CityBreak", "Viena", "28.06.2023", 2572.1, "Ma", "", "23.03/2023", -9.1, errors) == 1);
	assert(strcmp(errors, "Tip invalid!\nDestinatie invalida!\nData de plecare invalida!\nPret invalid!\n") == 0);
	assert(egal(getAllServ(serv)[0], creeazaOferta("Mare", "Grecia", "23.03.2023", 3664.1)) == 1);
	assert(modificaOf(&serv, "CityBreak", "Viena", "28.06.2023", 2572.1, "Mare", "Grecia", "23.03.2023", 3664.1, errors) == 1);
	assert(strcmp(errors, "Oferta nu exista!\n") == 0);

	strcpy_s(errors, 100, "");
	assert(stergeOf(&serv, "Mare", "Grecia", "23.03.2023", 3664.1, errors) == 0);
	assert(lungimeServ(serv) == 0);
	assert(stergeOf(&serv, "Mare", "Grecia", "23.03.2023", 3664.1, errors) == 1);
	assert(strcmp(errors, "Oferta nu exista!\n") == 0);


	strcpy_s(errors, 100, "");
	adaugaOf(&serv, "CityBreak", "Viena", "28.06.2023", 2572.1, errors); //-
	adaugaOf(&serv, "Mare", "Grecia", "05.06.2023", 3366.1, errors); //-
	adaugaOf(&serv, "Mare", "Italia", "19.03.2023", 2356.1, errors); //-

	oferta* filtrate = (oferta*)malloc(100*sizeof(oferta));
	int numar;
	filtreazaTip(&serv, filtrate, "Mare", &numar);
	assert(numar == 2);
	assert(egal(filtrate[0], creeazaOferta("Mare", "Grecia", "05.06.2023", 3366.1)) == 1);
	assert(egal(filtrate[1], creeazaOferta("Mare", "Italia", "19.03.2023", 2356.1)) == 1);

	filtreazaTip(&serv, filtrate, "Munte", &numar);
	assert(numar == 0);

	adaugaOf(&serv, "Munte", "Italia", "20.04.2023", 2146.1, errors); //-

	filtreazaDest(&serv, filtrate, "Italia", &numar);
	assert(numar == 2);
	assert(egal(filtrate[0], creeazaOferta("Mare", "Italia", "19.03.2023", 2356.1)) == 1);
	assert(egal(filtrate[1], creeazaOferta("Munte", "Italia", "20.04.2023", 2146.1)) == 1);

	filtreazaDest(&serv, filtrate, "Uganda", &numar);
	assert(numar == 0);

	adaugaOf(&serv, "Mare", "Florida", "21.08.2023", 3366.1, errors); //-
	filtreazaPret(&serv, filtrate, 3366.1, &numar);
	assert(numar == 2);
	assert(egal(filtrate[0], creeazaOferta("Mare", "Grecia", "05.06.2023", 3366.1)) == 1);
	assert(egal(filtrate[1], creeazaOferta("Mare", "Florida", "21.08.2023", 3366.1)) == 1);

	filtreazaPret(&serv, filtrate, 3000.1, &numar);
	assert(numar == 0);

	oferta ordonate[100];

	ordonateFunc(&serv, ordonate, maiMic);
	assert(egal(ordonate[0], creeazaOferta("Munte", "Italia", "20.04.2023", 2146.1)) == 1);
	assert(egal(ordonate[1], creeazaOferta("Mare", "Italia", "19.03.2023", 2356.1)) == 1);
	assert(egal(ordonate[2], creeazaOferta("CityBreak", "Viena", "28.06.2023", 2572.1)) == 1);
	assert(egal(ordonate[3], creeazaOferta("Mare", "Florida", "21.08.2023", 3366.1)) == 1);
	assert(egal(ordonate[4], creeazaOferta("Mare", "Grecia", "05.06.2023", 3366.1)) == 1);

	ordonateFunc(&serv, ordonate, maiMare);
	assert(egal(ordonate[4], creeazaOferta("Munte", "Italia", "20.04.2023", 2146.1)) == 1);
	assert(egal(ordonate[3], creeazaOferta("Mare", "Italia", "19.03.2023", 2356.1)) == 1);
	assert(egal(ordonate[2], creeazaOferta("CityBreak", "Viena", "28.06.2023", 2572.1)) == 1);
	assert(egal(ordonate[1], creeazaOferta("Mare", "Florida", "21.08.2023", 3366.1)) == 1);
	assert(egal(ordonate[0], creeazaOferta("Mare", "Grecia", "05.06.2023", 3366.1)) == 1);

	filtreazaData(&serv, filtrate, "20.04.2023", &numar);
	assert(egal(filtrate[0], creeazaOferta("Munte", "Italia", "20.04.2023", 2146.1)) == 1);
	free(errors);
	free(filtrate);
	distrugeServ(&serv);
	_CrtDumpMemoryLeaks();
	return 0;
}