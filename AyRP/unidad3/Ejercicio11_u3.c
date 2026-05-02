/*
Ejercicio 11
Para realizar una recarga virtual de una determinada empresa de telefonía celular, se ingresan por
teclado los datos correspondientes al número de celular y el importe de la recarga. Considerar que si el
importe de la recarga es:
• mayor o igual a $2000 y menor que $7000, el importe acreditado se incrementará en un 20%
• igual o superior a $7000 y menor que $9000, el incremento es del 50%
• si la recarga supera los $9000 el incremento será del 100%
Realizar un algoritmo que utilizando subprogramas muestre el número de celular y el importe total
acreditado de la recarga.
*/

#include <stdio.h>

void mostrar_recarga(float recarga, long telefono) {
	printf("Se ha acreditado una recarga de $%.2f para el número de telefono %ld \n", recarga, telefono);
}

float calculo_bonificacion(float importe, float porcentaje) {
	float bonificacion;
	bonificacion = (importe * porcentaje) / 100;
	return bonificacion;
}

int cantidad_digitos(long telefono) {
	int count = 0;
	long num_tel = telefono;
	while(num_tel > 0) {
		num_tel = num_tel / 10;
		count ++;
	}
	return count;
}

float get_importe_recarga() {
	float importe;
	do
	{
		printf("Ingrese importe de recarga: $");
		scanf("%f", &importe);
	} while(importe <= 0);
	return importe;
}

long get_telefono() {
	long telefono;
	int digitos;
	do
	{
		printf("Ingrese número de teléfono para la recarga: ");
		scanf("%ld", &telefono);
		digitos = cantidad_digitos(telefono);
	} while(digitos < 10);
	return telefono;
}

 float calculo_recarga(float importe) {
         float total = importe;
         if(importe >= 2000 && importe < 7000) {
                 total = total + calculo_bonificacion(importe, (float)20);
         } else if(importe >= 7000 && importe < 9000) {
                 total = total + calculo_bonificacion(importe, (float)50);
         } else if(importe > 9000) {
                 total = total + calculo_bonificacion(importe, (float)100);
         } else return total;
         return total;
}

int main() {
	float importe, recarga_total;
	long telefono;
	int digitos;

	importe = get_importe_recarga();
	telefono = get_telefono();
	recarga_total = calculo_recarga(importe);

	mostrar_recarga(recarga_total, telefono);
	return 0;
}
