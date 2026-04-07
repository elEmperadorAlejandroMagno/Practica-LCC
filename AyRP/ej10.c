# include <stdio.h>
# include <string.h>

char evaluar_caracter(char input) {
	char tipo;
	char vocales[] = "aAeEiIoOuU";
	int largo = strlen(vocales);

	tipo = 'N';

	if (input >= '0' && input <= '9') {
		tipo = 'D';
		return tipo;
	}

	for (int i = 0; i < largo; i++) {
		if (input == vocalesMay[i]) {
			tipo = 'V';
		}	
	}	
return tipo;
}

int main() {
	char input, tipo;
	printf("Ingresar un caracter: ");
	scanf("%c", &input);

	tipo = evaluar_caracter(input);
	switch (tipo) {
		case 'V':
			printf("Es una vocal\n");
			break;
		case 'D':
			printf("Es un dígito\n");
			break;
		default:
			printf("No es ni vocal ni dígito\n");
	}
}
