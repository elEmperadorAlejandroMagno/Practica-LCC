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
	int N;
	do
	{
		printf("Cantidad de apuestas a ingresar: ");
		scanf("%i",&N);
	}
	while(N > 10 || N <= 0);

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
