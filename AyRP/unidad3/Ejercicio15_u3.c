#include <stdio.h>

int get_num_factura() {
	int num;
	do
	{
		printf("Ingrese el número de la factura: ");
		scanf("%d", &num);
	} while(num <= 0);
	return num;
}

float get_importe_total() {
	float importe;
	do
	{
		printf("Ingrese costo total de la factura: $");
		scanf("%f", &importe);
	} while(importe <= 0);
	return importe;
}

int get_cantidad_productos() {
	int cantidad;
	do
	{
		printf("Ingrese cantidad de productos de la factura: ");
		scanf("%d", &cantidad);
	} while(cantidad <= 0);
	return cantidad;
}

float precio_promedio_producto(float importe, int cantidad) {
	float promedio;
	promedio = importe / cantidad;
	return promedio;
}	

int main() {
	float importe_total, promedio;
	int num_factura, cantidad_productos;

	num_factura = get_num_factura();
	importe_total = get_importe_total();
	cantidad_productos = get_cantidad_productos();

	if(importe_total >= 10000 || (cantidad_productos >= 100 && cantidad_productos <= 200)) {
		printf("Número de factura %d\n", num_factura);
	}
	printf("Precio promedio por producto: $%.2f\n", precio_promedio_producto(importe_total, cantidad_productos));

	return 0;
}
