#include "stos.h"
#include "data.h"
#include <stdlib.h>
#include <stdio.h>
#include "wyszukiwanie.h"

void po_nazwisku(MY_STUDENT* student) {
	char szukane_nazwisko[64];
	printf("Prosze podac nazwisko:\n");
	scanf_s("%63s", szukane_nazwisko, 63);

	while(top != NULL){
		if (strcmp(student->nazwisko, szukane_nazwisko) == 0) {
			wyswietl_student(student);
		}
		top = top->kolejny;

	};


}