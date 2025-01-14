#include "pliki.h"
#include "stos.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


void zapisz_plik()
{
	FILE* plik;
	errno_t err;
	err = fopen_s(&plik, "dane.txt", "w");
	if (err != 0) {
		printf("Nie udalo sie otworzyc pliku\n");
		return;
	}
	element_stosu* temp = top;
	while (temp != NULL) {
		MY_STUDENT* student = (MY_STUDENT*)temp->data;
		fprintf(plik, "%s %d %d\n", student->nazwisko, student->rok, student->kierunek);
		temp = temp->kolejny;
	}
	fclose(plik);
}

void wczytaj_plik()
{
	FILE* plik;
	errno_t err;
	err = fopen_s(&plik, "dane.txt", "r");
	if (err != 0) {
		printf("Nie udalo sie otworzyc pliku\n");
		return;
	};
	
	while (!feof(plik)) {
		MY_STUDENT* student = (MY_STUDENT*)malloc(sizeof(MY_STUDENT));
		if (student == NULL) {
			printf("Blad alokacji pamieci\n");
			return;
		}
		else
		{
			fread(student, sizeof(MY_STUDENT), 1, plik);
			if (stworz_element(student) == NULL) {
				printf("Blad zapisu\n");
				return 1;
			}
		}


	}
	fclose(plik);
}