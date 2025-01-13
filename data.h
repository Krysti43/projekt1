#pragma once

typedef struct MY_STUDENT {
	char* nazwisko;
	int rok;
	int kierunek;
}MY_STUDENT;
enum kierunek {
	Matematyka = 1,
	Informatyka,
	Technika
};

MY_STUDENT* dodawanie();
void wyswietl_student(MY_STUDENT* student);
void zwalnianie_studenta(MY_STUDENT* student);
