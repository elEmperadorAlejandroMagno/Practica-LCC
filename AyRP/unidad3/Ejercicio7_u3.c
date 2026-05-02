/*
Ejercicio 7
Una distribuidora de gaseosas posee 5 sucursales codificadas: 1: Zona Centro; 2: Zona Sur; 3: Zona
Este; 4: Zona Oeste; 5: Zona Norte.
Se leen los datos de una factura:
• Número de sucursal en la que se realizó la venta
• Importe
• Día de vencimiento
• Día de pago
Realizar un algoritmo que usando subprogramas permita:
• Si la factura es de la sucursal 2 o 5 escriba el importe a cobrar sabiendo que, si la fecha de pago es
posterior a la de vencimiento se tendrá un recargo del 1,5%.
• Si la sucursal es 1, 3 o 4 escriba el importe a cobrar sabiendo que, si la fecha de pago es igual o menor a
la de vencimiento tendrá un descuento del 2,5%.
*/

#include <stdio.h>

float calculo_porcentaje(float importe, float porcentaje) {
	float resultado;
	resultado = (importe * porcentaje) / 100;
	return resultado;
}

float calculo_factura(float importe, int sucursal, int d_pago, int d_vencimiento) {
	float total_pagar = importe;
	if(sucursal == 2 || sucursal == 5) {
		if (d_pago > d_vencimiento) {
			total_pagar = total_pagar + calculo_porcentaje(importe, 1.5);
		} 
	} else if(sucursal == 1 || sucursal == 3 || sucursal == 4) {
		if (d_pago <= d_vencimiento) {
			total_pagar = total_pagar - calculo_porcentaje(importe, 2.5);
		}
	} else return total_pagar;			
	return total_pagar;
}

float get_importe() {
	float importe;
        do
        {
                 printf("Ingrese monto de factura: $");
                 scanf("%f", &importe);
        } while(importe <= 0);
        return importe;
}

int get_dia_pago() {
	int d_pago;
	do
        {
                 printf("Ingrese día de pago de la factura: ");
                 scanf("%d", &d_pago);
        } while(d_pago <= 0);
	return d_pago;
}

int get_dia_vencimiento() {
	int d_vencimiento;        
 	do
        {
        	printf("Ingrese día de vencimiento de facutra: ");
                scanf("%d", &d_vencimiento);
   	} while(d_vencimiento <= 0);
	return d_vencimiento;
}

int get_sucursal() {
	int sucursal;
	do
	{
		printf("Ingrese el número de sucursal: ");
		scanf("%d", &sucursal);
	} while(sucursal <= 0);
	return sucursal;
}

int main() {
	float costo_factura, importe;
	int sucursal, d_pago, d_vencimiento;
	importe = get_importe();
	sucursal = get_sucursal();
	d_pago = get_dia_pago();
	d_vencimiento = get_dia_vencimiento();
	costo_factura = calculo_factura(importe, sucursal, d_pago, d_vencimiento);
	printf("El cliente deberá pagar $%.2f del costo de la factura\n", costo_factura);
	return 0;
}
