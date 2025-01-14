#include "stos.h"
#include "data.h"
#include <stdlib.h>
#include <stdio.h>
#include "wyszukiwanie.h"

void po_nazwisku(MY_STUDENT* student, element_stosu* top) {
    char szukane_nazwisko[64];
    printf("Prosze podac nazwisko:\n");
    scanf_s("%63s", szukane_nazwisko, 63);

    element_stosu* obecny1 = top;
    while (obecny1 != NULL) {
        MY_STUDENT* obecny1_student = (MY_STUDENT*)obecny1->data;
        if (strcmp(obecny1_student->nazwisko, szukane_nazwisko) == 0) {
            wyswietl_student(obecny1_student);
        }
        obecny1 = obecny1->kolejny;
    }


};

void po_roku(MY_STUDENT* student, element_stosu* top) {

    int szukany_rok;
    printf("Prosze podac roku urodzenia:\n");
   
    do {

        if (scanf_s("%d", &szukany_rok) != 1 || szukany_rok <= 1900 || szukany_rok >= 2025) {
            printf("Nieprawidlowy rok\n");
            while (getchar() != '\n');
        }
    } while (szukany_rok <= 1900 || szukany_rok >= 2025);


    element_stosu* obecny2 = top;
    while (obecny2 != NULL) {
        MY_STUDENT* obecny2_student = (MY_STUDENT*)obecny2->data;
        if (obecny2_student->rok == szukany_rok) {
            wyswietl_student(obecny2_student);
        };
        obecny2 = obecny2->kolejny;
    };

};

void po_kierunku(MY_STUDENT* student, element_stosu* top) {
	int szukany_kierunek;
	printf("Prosze podac kierunek:\n Matematyka - 1\n Informatyka - 2\n Technika - 3\n");
    do {

        if (scanf_s("%d", &szukany_kierunek) != 1 || szukany_kierunek < 1 || szukany_kierunek > 3) {
            printf("Nieprawidlowy kierunek\n");
            while (getchar() != '\n');
        }
    } while (szukany_kierunek < 1 || szukany_kierunek > 3);

    element_stosu* obecny3 = top;
    while (obecny3 != NULL) {
        MY_STUDENT* obecny3_student = (MY_STUDENT*)obecny3->data;
        if (obecny3_student->kierunek == szukany_kierunek) {
            wyswietl_student(obecny3_student);
        };
        obecny3 = obecny3->kolejny;
    };

};  