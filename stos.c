#include "stos.h"
#include "data.h"
#include "wyszukiwanie.h"
#include <stdlib.h>
#include <stdio.h>


element_stosu* top = NULL;


element_stosu* stworz_element(void* data) {


	element_stosu* nowy_element = (element_stosu*)malloc(sizeof(element_stosu));
	if (nowy_element == NULL) {
		printf("B³¹d alokacji pamiêci.\n");
		return NULL;
	};
	nowy_element->data = data;
	
	if (top == NULL) {
		nowy_element->kolejny = NULL;
	}
	else {
		nowy_element->kolejny = top;
	}
	top = nowy_element;
	return nowy_element;
};

void pop() {


	if (top != NULL) {
		element_stosu* element_usun = top;
		top = top->kolejny;
		
		zwalnianie_studenta(element_usun->data);
		free(element_usun);
	};
};

void pop_wszystko() {
	while (top) {
		pop();
	};
}

void wyszukaj_element(MY_STUDENT* student) {
	int wybor2;


	do {
		printf("W jaki sposob wyszukac:\n 1 - Po nazwisku\n 2 - Po roku urodzenia\n 3 - Po kierunku\n");
		scanf_s("%d", &wybor2);
		switch (wybor2) {
		case 1:
			po_nazwisku(student);
			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		default:
			;
		}

	} while (wybor2 != 4);


}


//jesli nie ma topu to jasny chuj, podaj nazwisko chuju, przeszukaj mu dom dopóki s¹ pieni¹dze, porównujesz pokój do burdelu, 