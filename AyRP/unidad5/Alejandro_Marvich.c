#include <stdio.h>
#include <stdbool.h>

struct paciente {
	int dni;
	int dias_internacion;
};

const int N = 6;

void load_data(struct paciente a[]) {
	for (int i=0; i < N; i++) {
		printf("Ingrese DNI: ");
		scanf("%d", &a[i].dni);
		printf("Ingrese dias de internacion: ");
		scanf("%d", &a[i].dias_internacion);
	}
	return;
}

void ordenar_asc(struct paciente a[]) {
    int j;
    struct paciente aux;
    for (int i = 0; i < N; i++) {
        aux = a[i];
        j = i-1;
        while ( aux.dni < a[j].dni  && j >= 0) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = aux;
    }
    return;
}

int binary_search(struct paciente a[], int dni) {
    int inf, sup, medio;
    bool found;
    inf = 0;
    sup = N-1;
    medio = (inf+sup)/2;
    found = false;
    while (found == false && inf <= sup) {
        if (a[medio].dni == dni) {
            found = true;
        } else if (a[medio].dni < dni) {
            sup = medio - 1;
        } else {
            inf = medio + 1;
        }
        medio = (inf+sup)/2;
    }
    if (found == true) {
        return a[medio].dias_internacion;
    } else {
        return -1;
        }
}

void filtro_dias(struct paciente a[]) {
	for (int i=0; i < N; i++) {
		if (a[i].dias_internacion > 7) {
			printf("✔ El paciente en posicion %d\n", i);
		}
	}
    return;
}


int main() {
    struct paciente pacientes[N];
    int dni, dias_internacion;
    load_data(pacientes);
    ordenar_asc(pacientes);
    printf("------0------\n");
    printf("Alumno: Alejandro Marvich \nProfesora: Malena Paez\n");
    printf("------0------\n");
    printf("Ingrese DNI a buscar: ");
    scanf("%d", &dni);
    dias_internacion = binary_search(pacientes, dni);
    if (dias_internacion != -1) {
        printf("El paciente con DNI %d tiene %d dias de internacion\n", dni, dias_internacion);
    } else {
        printf("No se ha encontrado un paciente con DNI %d\n", dni);
    }
    printf("------0------\n");
    filtro_dias(pacientes);

    return 0;
}