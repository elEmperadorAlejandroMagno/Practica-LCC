#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct vendedor {
	char first_name[20];
	char last_name[20];
	int dni;
};

struct venta {
	int dni;
	float importe;
};

struct data {
	float total;
	int cant;
};

const int N = 20;

void cargar_vendedor(struct vendedor a[]) {
char nombre[20], apellido[20];
int dni;
for(int i = 0; i < N - 1; i++) {
	printf("Ingrese nombre del vendedor: ");
	do {
		scanf("%s", nombre);
	} while(strlen(nombre) <= 0);	
	printf("Ingrese apellido del vendedor: ");
	do {
		scanf("%s", apellido);		
	} while(strlen(apellido) <= 0);	
	printf("Ingrese DNI del vendedor: ");
	do {
		scanf("%d", &dni);	
	} while(dni <= 0);
	strcpy(a[i].first_name, nombre);
	strcpy(a[i].last_name, apellido);
	a[i].dni = dni;
}
return;
}

int cargar_venta(struct venta a[]) {
int dni;
float importe;
int i;
i = 0;
printf("Ingrese DNI del vendedor: ");
scanf("%d", &dni);
while(dni != -1) {
	printf("Ingresar el importe de la venta: $");
	scanf("%f", &importe);
	a[i].dni = dni;
	a[i].importe = importe;
	i = i + 1;
	printf("Ingrese DNI del vendedor: ");
	scanf("%d", &dni);
}
return i;
}

struct data calculo_ventas(struct venta a[], int dni, int n) {
float total_ventas;
int cant_ventas;
struct data info;
total_ventas = 0;
for(int i = 0; i < n; i++) {
	if(a[i].dni == dni) {
		cant_ventas++;
		total_ventas = total_ventas + a[i].importe;
	}
}
info.total = total_ventas,
info.cant = cant_ventas;
return info;
} 

int main() {
	struct vendedor vendedores[N];
	struct venta ventas[20];
	struct data vendedor_info;
	int len, dni;
	cargar_vendedor(vendedores);
	len = cargar_venta(ventas);
	scanf("%d", &dni);
	vendedor_info = calculo_ventas(ventas, dni, len);
	printf("Vendedor %d \n Cantidad ventas: %d\n Monto total en ventas: $%f", dni, vendedor_info.cant, vendedor_info.total);
	return 0;
}
