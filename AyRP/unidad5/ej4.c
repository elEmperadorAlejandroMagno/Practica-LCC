# include <stdio.h>
# include <stdlib.h>
# include <string.h>

const int N = 19;

void init_arr(int a[]) {
for (int i = 0; i < N; i++) {
	a[i] = 0;
}
return;
}

void load_arr(int a[], int E) {
int codL, cantE;
for (int i = 0; i < E; i++) {
	do {
		printf("Código de localidad: ");
		scanf("%d", &codL);
		printf("Cantidad de empleados: ");
		scanf("%d", &cantE);
	} while(codL < 0 || codL > 19 || cantE < 0);
	a[codL - 1] = a[codL - 1] + cantE;
}
return;
}

void sort_arr_desc(int a[]) {
int i, j, aux;
for (int i = 0; i < N; i++) {
	aux = a[i];
	j = i-1;
	while ( aux > a[j]  && j >= 0) {
		a[j + 1] = a[j];
		j = j - 1;
	}
	a[j + 1] = aux;
}
return;
}

int load_max(int a[]) {
int max;
max = 0;
for (int i = 0; i < N; i++) {
	if(a[i] > max) max = a[i];
}
return max;
}

int load_new_arr(int a[], int b[]) {
int j, max;
j = 0;
max = load_max(a);
for (int i = 0; i < N; i++) {
	if(a[i] == max) {	
		b[j] = i + 1;
		j++;
	}
}
return j;
}

void show_loc_max(int a[], int n) {
for (int i = 0; i < n; i++) {
		printf("La localidad %d alcanzó el límite de empleados\n", a[i]);
	}
return;
}

int main(int argc, char *argv[]) {
int max, lenL, E;
int localidades[N], localidadesMax[N];

if (argc > 2) {
	if (strcmp(argv[1], "-E") == 0 && atoi(argv[2]) > 0) {
		E = atoi(argv[2]);
	}
} else {
	E = 600;
}

init_arr(localidades);
load_arr(localidades, E);
lenL = load_new_arr(localidades, localidadesMax);
sort_arr_desc(localidades);
for (int i = 0; i < N; i++) {
	printf("Empleados: %d\n", localidades[i]);
}
show_loc_max(localidadesMax, lenL);
return 0;
} 
