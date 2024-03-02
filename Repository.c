#include "DOMAIN.h"
#include <stdlib.h>
typedef struct
{
	oferta* oferte;
	int dim;
	int cap;
} listaOf;

listaOf creeazaRepo()
{
	/*creeaza o lista de oferte
	date de intrare:
	-
	date de iesire:
	- lista de oferte nou creata (de tip listaOf)
	*/
	listaOf lista;
	lista.oferte = (oferta*)malloc(2 * sizeof(oferta));
	lista.dim = 0;
	lista.cap = 2;
	return lista;
}
int distrugeRepo(listaOf* lista)
{
	/*distruge repository ul lista
	date de intrare:
	lista - lista de oferte care trebuie distrusa
	date de iesire:
	returneaza 0
	*/
	free(lista->oferte);
	return 0;
}

int resize(listaOf* lista)
{
	/*mareste capacitatea listei de oferte lista de 2 ori
	date de intrare:
	lista - lista de oferte a carei capacitate trebuie marita (de tip listaOf*)
	date de iesire:
	returneaza 0
	*/
	lista->cap = 2 * lista->cap;
	if (lista->cap == 0)
		return 1;
	oferta* listaNoua = (oferta*)malloc((lista->cap)*sizeof(oferta));
	if(listaNoua == NULL)
		return 1;
	for (int i = 0; i < lista->dim && i < lista->cap; ++i)
			listaNoua[i] = lista->oferte[i];

	distrugeRepo(lista);
	lista->oferte = listaNoua;
	return 0;
}


int adaugaOfrt(listaOf* lista, oferta ofrt)
{
	/*adauga oferta ofrt in lista de oferte lista
	date de intrare:
	lista - lista de oferte (de tip listaOf*)
	ofrt - oferta de adaugat (de tip oferta)
	date de iesire:
	- returneaza 0 daca oferta a fost adaugata
	*/
	if (lista->dim >= lista->cap)
		resize(lista);
	lista->oferte[lista->dim] = ofrt;
	lista->dim += 1;
	return 0;
}

int modificaOfrt(listaOf* lista, oferta ofrt, oferta ofrtN)
{
	/*modifica prima aparitie a ofertei ofrt la oferta ofrtN
	date de intrare:
	lista - lista de oferte (de tip listaOf)
	ofrt - oferta care se modifica (de tip oferta)
	ofrtN - oferta noua la care se modifica oferta ofrt (de tip oferta)
	date de iesire:
	- returneaza 0 daca oferta ofrt se afla in lista de oferte si a fost modificata si 1 in caz contrar*/
	for (int i = 0; i < lista->dim; i++)
		if (egal(ofrt, lista->oferte[i]))
		{
			lista->oferte[i] = ofrtN;
			return 0;
		}
	return 1;
}

int stergeOfrt(listaOf* lista, oferta ofrt)
{
	/*sterge prima aparitie a ofertei ofrt din lista de oferte lista
	date de intrare:
	lista - lista de oferte (de tip listaOf)
	ofrt - oferta de sters (de tip oferta)
	date de iesire:
	- returneaza 0 daca oferta a existat in lista si a fost stearsa si 1 in caz contrar
	*/

	for(int i=0; i < lista->dim; i++)
		if (egal(ofrt, lista->oferte[i]))
		{
			for (int j = i; j < lista->dim - 1; j++)
				lista->oferte[j] = lista->oferte[j + 1];
			lista->dim--;
			return 0;
		}
	return 1;
}

int lungimeLista(listaOf lista)
{
	/*returneaza lungimea repository-ului de oferte
	date de intrare:
	lista - lista de oferte pentru care se cere lungimea (de tip listaOf)
	date de iesire:
	- lungimea repository-ului de oferte lista*/
	return lista.dim;
}

oferta* getAll(listaOf lista)
{
	/*returneaza lista de oferte a repository-ului de oferte
	date de intrare:
	lista - lista de oferte pentru care se cer elementele (de tip listaOf)
	date de iesire:
	lista de oferte a repository-ului de oferte*/

	return lista.oferte;
}