/*
Ejercicio 14
Se procesa la información de N apuestas realizadas en una agencia de quiniela. Por cada apuesta se
ingresa: el número y el importe.
Se pide realizar un algoritmo usando subprogramas que permita:
1. Indicar el número de las apuestas con importes entre dos valores ingresados por teclado.
2. Escribir el número y el importe de las apuestas mayores a $5000.
*/
#include <stdio.h>

int obtener_num_apuesta() {
	int num;
	do
	{
	printf("Insertar N° de apuesta: ");
	scanf("%i", &num);
	}
	while(num < 0);
	return num;
}

float obtener_dinero_apuesta() {
	float dinero;
	do
	{
	printf("Insertar importe de apuesta: $");
	scanf("%f", &dinero);
	}
	while(dinero < 0);
	return dinero;	
}

int main() {
	/* N lo definimos nosotros */
	const int N = 5;

	for(int i = 0; i < N; i++) {
		int num;
		float dinero;
		num = obtener_num_apuesta();
		dinero = obtener_dinero_apuesta();
		if (dinero >= 5000) {
			printf("Apuesta N° %i con importe $%.2f \n", num, dinero);
		}
	}
	return 0;
}
