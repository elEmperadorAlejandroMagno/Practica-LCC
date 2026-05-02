# include <stdio.h>
# include <stdbool.h>
# include <string.h>

int main() {
	const int M = 2;
	int edad, DNI, min_edad;
	float puntaje, max_puntaje;
	bool es_argentino = false;
	char nacionalidad[5];

	min_edad = 100;
	max_puntaje = 0;

	for(int competidor = 1; competidor <= M; competidor++) {
		printf("Ingrese los datos del competidor(edad,DNI,nacionalidad,puntaje)\n");
		printf("Edad: ");
		scanf("%d", &edad);
		printf("DNI: ");
		scanf("%d", &DNI);
		printf("Nacionalidad: ");
		scanf("%s", nacionalidad);
		printf("Puntaje: ");
		scanf("%f", &puntaje);

		if((edad <= min_edad) && (puntaje > max_puntaje)) {
			min_edad = edad;
			max_puntaje = puntaje;
			if((strcmp(nacionalidad,"ARG") == 0) && (es_argentino == false)) {
				es_argentino = true;
			}
		}
	}
	if (es_argentino) printf("El competidor más joven con mejor puntaje es argetino\n");
	else printf("El competidor más joven con mejor puntaje no es argentino\n");
}
			
			
		
	
