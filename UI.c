#include "SERVICE.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
	servOf serv;
}userInt;

userInt creeazaUI()
{
	/*creeaza o interfata utilizator
	date de intrare:
	-
	date de iesire:
	- interfata utilizator nou creata (de tip userInt)*/

	userInt ui;
	servOf serv = creeazaServ();
	ui.serv = serv;
	return ui;
}

int menu()
{
	/*printeaza meniul utilizatorului
	date de intrare:
	-
	date de iesire:
	- returneaza 0*/

	printf_s("Afiseaza ofertele - 1\n");
	printf_s("Adauga oferta - 2\n");
	printf_s("Modifica oferta - 3\n");
	printf_s("Sterge oferta - 4\n");
	printf_s("Filtreaza dupa tip - 5\n");
	printf_s("Filtreaza dupa destinatie - 6\n");
	printf_s("Filtreaza dupa pret - 7\n");
	printf_s("Ordoneaza crescator dupa pret, destinatie - 8\n");
	printf_s("Ordoneaza descrescator dupa pret, destinatie - 9\n");
	printf_s("Filtreaza dupa data - 10\n");
	return 0;
}

int adauga(userInt* ui)
{
	/*adauga o oferta noua
	date de intrare:
	ui - interfata utilizator (de tip userInt)
	date de iesire
	-returneaza 0 daca oferta s-a adaugat cu succes si 1 in caz contrar*/
	char tip[30] = "", destinatie[30] = "", data[30] = "", errors[100] = "";
	double pret;

	printf_s("Introduceti tipul ofertei de adaugat:\n");
	scanf_s("%s", tip, 30);
	printf_s("Introduceti destinatia ofertei de adaugat:\n");
	scanf_s("%s", destinatie, 30);
	printf_s("Introduceti data de plecare a ofertei de adaugat:\n");
	scanf_s("%s", data, 30);
	printf_s("Introduceti pretul ofertei de adaugat:\n");
	scanf_s("%lf", &pret);
	adaugaOf(&ui->serv, tip, destinatie, data, pret, errors);
	if ( strlen(errors) > 0)
	{
		printf_s("%s\n", errors);
		return 1;
	}
	return 0;
}

int afiseaza(userInt ui)
{
	/*afiseaza toate ofertele disponibile
	date de intrare:
	ui - interfata utilizator (de tip userInt)
	date de iesire:
	- returneaza 0*/

	
	printf_s("Ofertele din lista de oferte sunt:\n");
	for (int i = 0; i < lungimeServ(ui.serv); i++)
		printf_s("%s\n", str(getAllServ(ui.serv)[i]));
	return 0;
}

int modifica(userInt* ui)
{
	/*modifica oferta dorita de utilizator
	date de intrare:
	ui - interfata utilizator (de tip ui)
	date de iesire:
	- returneaza 0 daca oferta a fost modificata cu succes si 1 in caz contrar
	*/

	char tip[30] = "", dest[30] = "", data[30] = "", tipN[30] = "", destN[30] = "", dataN[30] = "";
	double pret, pretN;

	printf_s("Introduceti tipul ofertei pe care doriti sa o modificati:\n");
	scanf_s("%s", tip, 30);
	printf_s("Introduceti destinatia ofertei pe care doriti sa o modificati:\n");
	scanf_s("%s", dest, 30);
	printf_s("Introduceti data ofertei pe care doriti sa o modificati:\n");
	scanf_s("%s", data, 30);
	printf_s("Introduceti pretul ofertei pe care doriti sa o modificati:\n");
	scanf_s("%lf", &pret);
	printf_s("Introduceti noul tip al ofertei:\n");
	scanf_s("%s", tipN, 30);
	printf_s("Introduceti noua destinatie a ofertei:\n");
	scanf_s("%s", destN, 30);
	printf_s("Introduceti noua data de plecare a ofertei:\n");
	scanf_s("%s", dataN, 30);
	printf_s("Introduceti noul pret al ofertei:\n");
	scanf_s("%lf", &pretN);

	char errors[100] = "";

	modificaOf(&ui->serv, tip, dest, data, pret, tipN, destN, dataN, pretN, errors);

	if (strlen(errors) > 0)
	{
		printf_s("%s\n", errors);
		return 1;
	}
	return 0;
}


int sterge(userInt* ui)
{
	/*sterge oferta dorita de utilizator
	date de intrare:
	ui - interfata utilizator (de tip ui)
	date de iesire:
	- returneaza 0 daca oferta a fost stearsa cu succes si 1 in caz contrar
	*/

	char tip[30] = "", dest[30] = "", data[30] = "";
	double pret;

	printf_s("Introduceti tipul ofertei pe care doriti sa o stergeti:\n");
	scanf_s("%s", tip, 30);
	printf_s("Introduceti destinatia ofertei pe care doriti sa o stergeti:\n");
	scanf_s("%s", dest, 30);
	printf_s("Introduceti data ofertei pe care doriti sa o stergeti:\n");
	scanf_s("%s", data, 30);
	printf_s("Introduceti pretul ofertei pe care doriti sa o stergeti:\n");
	scanf_s("%lf", &pret);

	char errors[30] = "";
	stergeOf(&ui->serv, tip, dest, data, pret, errors);

	if (strlen(errors) > 0)
	{
		printf("%s", errors);
		return 1;
	}
	return 0;
	
}

int filtrareTip(userInt* ui)
{
	/*afiseaza doar ofertele care au un anumit tip
	date de intrare:
	ui - interfata utilizator (de tip userInt*)
	date de iesire:
	- returneaza 0*/

	oferta filtrate[100];
	int numar;
	char tip[30] = "";

	printf_s("Introduceti tipul dupa care vreti sa fie filtrate rezultatele:\n");
	scanf_s("%s", tip, 30);

	filtreazaTip(&ui->serv, filtrate, tip, &numar);

	for (int i = 0; i < numar; i++)
		printf_s("%s\n", str(filtrate[i]));

	return 0;

}


int filtrareDest(userInt* ui)
{
	/*afiseaza doar ofertele care au o anumita destinatie
	date de intrare:
	ui - interfata utilizator (de tip userInt*)
	date de iesire:
	- returneaza 0*/

	oferta filtrate[100];
	int numar;
	char dest[30] = "";

	printf_s("Introduceti destinatia dupa care vreti sa fie filtrate rezultatele:\n");
	scanf_s("%s", dest, 30);

	filtreazaDest(&ui->serv, filtrate, dest, &numar);

	for (int i = 0; i < numar; i++)
		printf_s("%s\n", str(filtrate[i]));

	return 0;

}

int filtrarePret(userInt* ui)
{
	/*afiseaza doar ofertele care au un anumit pret
	date de intrare:
	ui - interfata utilizator (de tip userInt*)
	date de iesire:
	- returneaza 0*/

	oferta filtrate[100];
	int numar;
	double pret;

	printf_s("Introduceti destinatia dupa care vreti sa fie filtrate rezultatele:\n");
	scanf_s("%lf", &pret);

	filtreazaPret(&ui->serv, filtrate, pret, &numar);

	for (int i = 0; i < numar; i++)
		printf_s("%s\n", str(filtrate[i]));

	return 0;

}

int filtrareData(userInt* ui)
{
	/*afiseaza doar ofertele care au o anumita data
	date de intrare:
	ui - interfata utilizator (de tip userInt*)
	date de iesire:
	- returneaza 0*/

	oferta filtrate[100];
	int numar;
	char data[30] = "";

	printf_s("Introduceti data dupa care vreti sa fie filtrate rezultatele:\n");
	scanf_s("%s", data, 30);

	filtreazaData(&ui->serv, filtrate, data, &numar);

	for (int i = 0; i < numar; i++)
		printf_s("%s\n", str(filtrate[i]));

	return 0;

}

int ordonareCresc(userInt* ui)
{
	/*afiseaza ofertele ordonate crescator dupa pret, destinatie
	date de intrare:
	ui - interfata utilizator (de tio userInt*)
	date de iesire:
	returneaza 0*/

	oferta ordonate[100];

	ordonateFunc(&ui->serv, ordonate, maiMic);
	for (int i = 0; i < lungimeServ(ui->serv); i++)
		printf_s("%s\n", str(ordonate[i]));
	return 0;
}

int ordonareDesc(userInt* ui)
{
	/*afiseaza ofertele ordonate descrescator dupa pret, destinatie
	date de intrare:
	ui - interfata utilizator (de tio userInt*)
	date de iesire:
	returneaza 0*/

	oferta ordonate[100];

	ordonateFunc(& ui->serv, ordonate, maiMare);
	for (int i = 0; i < lungimeServ(ui->serv); i++)
		printf_s("%s\n", str(ordonate[i]));
	return 0;
}

int getComanda()
{
	/*preia comanda utilizatorului
	date de intrare:
	-
	date de iesire:
	- returneaza comanda utilizatorlui (de tip int)*/
	printf_s("Introduceti comanda:\n");
	int cmd;
	scanf_s("%d", &cmd);
	return cmd;
}

int ruleaza(userInt* ui, int cmd)
{
	/*ruleaza comanda data de utilizator
	date de intrare:
	ui - interfata utilizator (de tip userInt)
	cmd - comanda data de utilizator
	date de iesire:
	- returneaza 0*/

	if (cmd == 1)
		afiseaza(*ui);
	if (cmd == 2)
		adauga(ui);
	if (cmd == 3)
		modifica(ui);
	if (cmd == 4)
		sterge(ui);
	if (cmd == 5)
		filtrareTip(ui);
	if (cmd == 6)
		filtrareDest(ui);
	if (cmd == 7)
		filtrarePret(ui);
	if (cmd == 8)
		ordonareCresc(ui);
	if (cmd == 9)
		ordonareDesc(ui);
	if (cmd == 10)
		filtrareData(ui);
	return 0;
}

int distrugeUi(userInt* ui)
{
	/*distruge interfata utilizator ui
	date de intrare:
	ui - interfata utilizator
	date de iesire:
	returneaza 0*/

	distrugeServ(&ui->serv);
	return 0;
}