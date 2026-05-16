/*
Ejercicio 14: Operativo Verano (Control de Tránsito)
Dividimos la provincia en 12 zonas y 10 tipos de infracciones. Se han clasificado las infracciones en 10 tipos (1:
exceso de velocidad, 2: falta de iluminación, ..., 10: alcoholemia).
Vamos a procesa cada infracción realizada, sabiendo que se conocen los siguientes datos: patente del
vehículo, zona y tipo de infracción.
Para evaluar los resultados del Operativo necesitamos un algoritmo que con subprogramas permita lo
siguiente:
1. Realizar un listado ordenado ascendentemente por cantidad, de los 10 tipos de infracciones.(arreglo de contadorespara infracciones).
2. Mostrar el o los tipos de infracción/es que más se cometen.
3. Decir si algún tipo de infracción no se cometió.
4. Indicar para cada zona la cantidad de infracciones realizadas.(arreglo decontadores para las zonas).
5. Mostrar todas las zonas que tuvieron una cantidad de infracciones inferior al promedio de las
infracciones realizadas en las 12 zonas de la provincia.
*/
/*
	infraccion: patente de vehiculo, zona y tipo de infracción
	si patente = 0 salimos del programa
*/

#include <stdio.h>
#include <stdbool.h>

const int N1 = 10;
const int N2 = 12;
struct infraccion {
	int zona;
	int tipo;
	char patente[];
};

void iniciar_arr_contadores(int arr[], int n) {
// iniciar cada valor del arreglo en 0
return;
}

int calc_prom_inf(int arr[N2]) {
int prom;
// calcular promedio de infracciones de las 12 zonas de la provincia
return prom;
}

int crear_nueva_lista(int arr[N1], int new_arr[N1]) {
int c;
c = 0;
// crear una copia del arreglo de infracciones
for(int i=0; i < N1; i++) {
	new_arr[i] = arr[i];
	c = c+1;
}
return c;
}

void ordenar_infr_asc(int arr[N1], int arr_len) {
// ordenar el arreglo en forma ascendente
return;
}

int main(){
int infracciones[N1], zonas[N2], infracciones_asc[N1];
int arr_len, infr_prom;
bool empty_infr = false;
int max_infr = 0;
int min_infr = 99999;
struct infraccion infr;

iniciar_arr_contadores(infracciones, N1);
iniciar_arr_contadores(zonas, N2);
printf("Ingrese patente: ");
scanf("%s", infr.patente);
while(infr.patente != 0) {
	do {
		printf("Ingrese código de infracción: ");
        	scanf("%d", &infr.tipo);
	} while(infr.tipo < 0 || infr.tipo > 10);
	do {
		printf("Ingrese código de zona: ");
                scanf("%d", &infr.zona);
	} while(infr.zona < 0 || infr.zona > 12);

	infracciones[infr.tipo] = infracciones[infr.tipo] + 1;
	zonas[infr.zona] = zonas[infr.zona] + 1;
	printf("--0--\n");
	printf("Ingrese patente: ");
	scanf("%s", infr.patente);
}
//prom_infr = calc_prom_infr(zonas, N2)
//arr_len = crear_nuevo_arr(infracciones, infracciones_asc);
//ordenar_infr_asc(infracciones_asc, arr_len);
// mostrar la o las infracciones que mas se cometen
// mostrar si alguna infraccion no fue cometida
// mostrar por zona la cantidad de infracciones cometidas
// mostrar las zonas que tuvieron infracciones inferior al promedio
return 0;
}
