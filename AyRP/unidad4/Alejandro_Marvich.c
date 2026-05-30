# include <stdio.h>
# include <stdbool.h>

struct alumno {
    int legajo;
    int edad;
};

const int N = 6;

void load_data(struct alumno arr[]) {
    for (int i=0; i < N; i++) {
        printf("Ingrese legajo: ");
        scanf("%d", &arr[i].legajo);
        printf("Ingrese edad: ");
        scanf("%d", &arr[i].edad);
        if (arr[i].edad <= 0) {
            printf("La edad no puede ser negativa o 0. Inserte una edad válida\n");
        }
    }
    return;
}

int average_edad(struct alumno arr[])  {
    int avg, acum;
    acum = 0;
    for (int i=0; i < N; i++) {
        acum = acum + arr[i].edad;
    }
    avg = acum / N;
    return avg;
}

void search_legajo(struct alumno arr[], int legajo) {
    bool found;
    int i, edad;
    i = 0;
    found = false;

    while (found == false && i < N) {
        if (arr[i].legajo == legajo) {
            found = true;
            edad = arr[i].edad;
        }
        i++;
    }
    if (found == true) {
    	printf("La edad del alumno con legajo %d es %d\n", legajo, edad);
    } else printf("No se ha encontrado un alumno con legajo %d\n", legajo);
    return;
}

void filtro_edad(struct alumno arr[], int avg) {
    printf("Los alumnos que superan el promedio de edad son: \n");
    for (int i=0; i < N; i++) {
        if (arr[i].edad > avg) {
            printf("✔ El estudiante en posicion %d\n", i);
        }
    }
}

int main() {
    struct alumno alumnos[N];
    int edad_prom, legajo;

    load_data(alumnos);
    printf("------0------\n");
    printf("Ingrese legajo a buscar: ");
    scanf("%d", &legajo);
    search_legajo(alumnos, legajo);
    edad_prom = average_edad(alumnos);
    printf("------0------\n");
    filtro_edad(alumnos, edad_prom);
    printf("------0------\n");
    printf("Alumno: Alejandro Marvich E010-869\nProfesor/a: Silvina Balmaceda\n");

    return 0;
}
