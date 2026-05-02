/*
Ejercicio 13
El encargado del planetario desea que se diseñe un algoritmo con subprogramas que, al ingresar el
número de día de la semana, indique el nombre del día y el astro que da origen a ese nombre.
La siguiente tabla muestra la relación astro-día.
N°  Día      Nombre del Astro
7 - Domingo  - Sol
6 - Sábado   - Saturno
5 - Viernes  - Venus
4 - Jueves   - Júpiter
3 - Miércoles- Mercurio
2 - Martes   - Marte
1 - Lunes    - Luna
*/

#include <stdio.h>



void mostrar_dia(int num) {
	char* dia;
	switch(num) {
		case 1:
			dia = "Lúnes";
			break;
		case 2:
			dia = "Martes";
			break;
		case 3:
			dia = "Miércoles";
			break;
		case 4:
			dia = "Jueves";
			break;
		case 5:
			dia = "Viernes";
			break;
		case 6:
			dia = "Sábado";
			break;
		case 7:
			dia = "Domingo";
			break;
	}
	printf("Es el día %s \n", dia);
}

void mostrar_astro(int num) {
	char* astro;
	switch(num) {
		case 1:
			astro = "Luna";
			break;
		case 2:
			astro = "Marte";
			break;
		case 3:
			astro = "Mercurio";
			break;
		case 4:
			astro = "Júpiter";
			break;
		case 5:
			astro = "Venus";
			break;
		case 6:
			astro = "Saturno";
			break;
		case 7:
			astro = "Sol";
			break;
	}	 
	printf("Pertenece al Astro: %s \n", astro);
}

int main() {
	int num;
	do
	{
		printf("Ingresa número del día: ");
		scanf("%d", &num);
	} while (num < 0);
	mostrar_dia(num);
	mostrar_astro(num);
	return 0;
}
