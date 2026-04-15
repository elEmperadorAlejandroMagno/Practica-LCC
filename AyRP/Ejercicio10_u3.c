/*
Ejercicio 10
Realizar un algoritmo que determine si un carácter ingresado por el usuario es vocal, dígito o ninguno de
los anteriores.
*/
# include <stdio.h>

char evaluar_caracter(char input) {
	char tipo;

	if ((input >= '0') && (input <= '9')) {
		tipo = 'D';
	} else if(((input >= 'A') && (input <= 'Z')) || ((input >= 'a') && (input <= 'z'))) {
		tipo = 'V';
	} else tipo = 'N';

return tipo;
}
void mostrar_tipo(char tipo, char caracter) {
	switch (tipo) {
		case 'V':
			printf("El caracter '%c' es una vocal\n", caracter);
			break;
		case 'D':
			printf("El caracter '%c' es un dígito\n", caracter);
			break;
		default:
			printf("El caracter '%c' no es ni vocal ni dígito\n", caracter);
	}
}
int main() {
	char input, tipo;
	printf("Ingresar un caracter: ");
	scanf("%c", &input);
	tipo = evaluar_caracter(input);
	mostrar_tipo(tipo, input);
	return 0;
}
