#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "data.h"

MY_STUDENT* dodawanie() {
	

	MY_STUDENT* student = (MY_STUDENT*)malloc(sizeof(MY_STUDENT));
	if (student == NULL) {
		printf("Blad alokacji pamieci\n");
		return NULL;
	}


	printf("Podaj nazwisko\n");
	char nazwisko[64] = {0};
	
	scanf_s("%63s", nazwisko, 63);
	

	student->nazwisko = (char*)malloc((strlen(nazwisko) + 1) * sizeof(char));
	if (student->nazwisko == NULL) {
		printf("Blad alokacji pamieci dla nazwiska\n");
		free(student);
		return NULL;
	}
	strcpy_s(student->nazwisko,strlen(nazwisko) + 1, nazwisko);

	int dlugosc_nazwiska = sizeof(student->nazwisko);

	printf("Podaj rok urodzenia\n");
	
	
	do {
		
		if (scanf_s("%d", &student->rok) != 1 || student->rok <= 1900 || student->rok >= 2025) {
			printf("Nieprawidlowy rok\n");
			while (getchar() != '\n');
		}
	} while (student->rok <= 1900 || student->rok >= 2025);

	printf("Podaj kierunek\n Matematyka - 1\n Informatyka - 2\n Technika - 3\n");
	

	do {

		if (scanf_s("%d", &student->kierunek) != 1 || student->kierunek <1 || student->kierunek > 3) {
			printf("Nieprawidlowy kierunek\n");
			while (getchar() != '\n');
		}
	} while (student->kierunek < 1 || student->kierunek > 3);


	wyswietl_student(student);
	
	 
	return student;
};

void wyswietl_student(MY_STUDENT* student) {
	printf("Nazwisko: %s, Rok: %d, Kierunek: ", student->nazwisko, student->rok);

	switch (student->kierunek) {
	case Matematyka:
		printf("Matematyka\n");
		break;
	case Informatyka:
		printf("Informatyka\n");
		break;
	case Technika:
		printf("Technika\n");
		break;
	}
};

void zwalnianie_studenta(MY_STUDENT* student)
{
	wyswietl_student(student);
	free(student->nazwisko);
	free(student);
}


