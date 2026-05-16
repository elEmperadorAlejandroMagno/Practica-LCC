#include <stdio.h>
#include <stdbool.h>

int cargar_min(int min, int N, int talleres[45]);
int cargar_max(int max, int N, int talleres[45]);
int get_total(int N, int talleres[45]);
bool validate_limit(int n_limit, int N, int talleres[45]);

int main() {
	int min,max,taller,obleas_totales;
	const int N = 45;
	int talleres[N];
	bool f_limit;
	const int n_limit = 500;
	
	min = 999999;
	max = 0;
	f_limit = false;
	min = cargar_min(min, N, talleres);
	max = cargar_max(N, talleres);
	f_limit = validate_limit(n_limit, N, talleres);

	scanf("%d", &taller);
	if(taller > 45 || taller < 1) {
		printf("No se ha encontrado el taller, debe introducir un número entre 1 y 45\n");
	} else {
		printf("El taller %d tiene %d obleas\n", taller, talleres[taller-1]); 	
	}
	
	if (f_limit) {
		printf("Se ha superado el límite de %d\n", n_limit);
	}
	obleas_totales = get_total(N, talleres);
	printf("Hay %d obleas en toda la pronvicia\n", obleas_totales);
}

int cargar_min(int min, int N, int talleres[45]) {
	for (int i=0; i < N; i++) {
		if (talleres[i] < min) {
			min = talleres[i];
		}
	}
return min;
}

int cargar_max(int max, int N, int talleres[45]) {
	for (int i=0; i < N; i++) {
		if (talleres[i] > max) {
			max = talleres[i];
		}
	}
return max;
}

bool validate_limit(int n_limit, int N, int talleres[45]) {
	for (int i=0; i < N; i++) {
		if (talleres[i] > n_limit) {
			return true;
		}
	}
return false;
}

int get_total(int N, int talleres[45]) {
	int acum = 0;
	for (int i=0; i < N; i++) {
		acum = acum + talleres[i];
	}
return acum;
}

