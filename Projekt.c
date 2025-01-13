#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "data.h"
#include "stos.h"
#include "wyszukiwanie.h"

int main()
{
	int wybor;
	MY_STUDENT* student;
	do {
	printf(" 1 - Dodaj element \n 2 - Wyjmij element \n 3 - Usun wszystko \n 4 - Wyszukaj element \n 5 - Zapisz w pliku \n 6 - Wczytaj z pliku \n 7 - Wyjdz\n");
	scanf_s("%d", &wybor);
	
		switch (wybor) {
		case 1:
			student = dodawanie();
			if (!student) {
				printf("B³¹d\n");
			}
			else {
				if (stworz_element(student) == NULL) {
					printf("B³¹d\n");
					return 1;
				}
			};
			break;
		case 2:
			pop();
			break;
		case 3:
			pop_wszystko();
			break;
		case 4:
			wyszukaj_element();
			break;
		case 5:

			break;
		case 6:

			break;
		case 7:
			pop_wszystko();
			break;
		default:
			printf("Prosze wybraæ poprawn¹ opcje");
		}
		
	} while (wybor != 7);
		pop_wszystko();
	return 0;
};