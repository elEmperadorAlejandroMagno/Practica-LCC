#include <stdio.h>
#include <stdlib.h>

typedef struct people
{
    char nombre[40];
    int edad;
} people;

void loadPeople(char *filename); // cargar los datos de los asistentes jornada.dat
void getPeopleByAge(char *filename, int &count, int &acum); // leer el archivo y mostrar los asistentes edad > 40
int getAvgAge(int acum, int count); // sacamos el promedio de edad
void showPeopleByAvg(char *filename, int prom); // recorremos el archivo y mostramos los assitentes edad >= prom

int main()
{
    char archivo[] = "jornada.dat";
    people buffer;
    int count = 0, acum = 0, prom;
    loadPeople(archivo);
    getPeopleByAge(archivo, count, acum);
    prom = getAvgAge(count, acum);
    printf("Edad promedio de los asistentes: %d", prom);
    showPeopleByAvg(archivo, prom);
    return 0;
}

void loadPeople(char *filename)
{
    FILE *f = fopen(filename, "wb");
    if(f == NULL)
    {
        printf("Error al intentar abrir %s", filename);
        return;
    }
    int edad;
    printf("Ingrese edad de asistente: ");
    scanf("%d", &edad);
    while(edad != -1)
    {
        people p;
        p.edad = edad;
        printf("Ingrese nombre del asistente: ");
        scanf("%s", p.nombre);
        fwrite(&p, sizeof(people), 1, f);

        printf("Ingrese edad de asistente: ");
        scanf("%d", &edad);
    }
    fclose(f);
    return;
};

void getPeopleByAge(char *filename, int &count, int &acum)
{
    FILE *f = fopen(filename, "rb");
    if(f == NULL)
    {
        printf("Error al abrir %s", filename);
        return;
    }
    people p;
    while(fread(&p, sizeof(people), 1, f) == 1)
    {
        count+=1;
        acum+=p.edad;
        if(p.edad > 40)
        {
            printf("Nombre de asistente: %s", p.nombre);
        }
    }
    fclose(f);
    return;
};

int getAvgAge(int count, int acum)
{
    return acum / count;
};

void showPeopleByAvg(char *filename, int prom)
{
    FILE *f = fopen(filename, "rb");
    if(f == NULL)
    {
        printf("Error al intentar abrir %s", filename);
        return;
    }
    people p;
    printf("Nombre de los asistentes con edad mayor o igual al promedio");
    while(fread(&p, sizeof(people), 1, f) == 1)
    {
        if(p.edad >= prom)
        {
            printf("Nombre: %s", p.nombre);
        }
    }
    return;
};
