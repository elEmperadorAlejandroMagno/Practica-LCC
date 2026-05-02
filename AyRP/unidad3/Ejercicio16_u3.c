# include <stdio.h>

float calculo_costo(float litros, float costo_litro) {
	float total;
	total = litros * costo_litro;
	return total;
}

float gasto_usuario(float litros) {
	float costo_total;
	if(litros <= 50) {
		costo_total = calculo_costo(litros, 1.5);
	} else if((litros > 50) && (litros < 100)) {
		costo_total = calculo_costo(litros, 2.5);
	} else if(litros > 100) {
		costo_total = calculo_costo(litros, 4);
	}
	return costo_total;
}

int main() {
	float litros;

	printf("Cantidad de litros consumidos por el usuario: ");
	scanf("%f", &litros);

	do
	{
		printf("El usuario deberá pagar: $%.2f\n", gasto_usuario(litros));
		printf("Cantidad de litros consumidos por el usuario: ");
		scanf("%f", &litros);
	} while (litros >= 0);
}

