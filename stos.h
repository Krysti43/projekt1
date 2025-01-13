#pragma once
#include <stdio.h>



typedef struct element_stosu {
	void* data;
	struct element_stosu* kolejny;
} element_stosu;
extern element_stosu* top;

void pop();
void pop_wszystko();