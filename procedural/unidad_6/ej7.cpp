/*Ejercicio 7 (Archivos con Estructuras Internas Complejas)
La asociación argentina de futbol solicita la creación de un programa que haciendo uso del archivo Categorias.Dat que
almacena los datos de las 5 categorías existentes: Código, nombre, cantidad de clubes disponibles y un arreglo de
enteros con la cantidad de inscriptos de los últimos 20 años. Responda a los siguientes requerimientos:
a) Dado un código de categoría determinado, localizar el año (índice del arreglo) con mayor cantidad de
inscriptos e informarlo.
b) Implemente una función que permita modificar la cantidad de clubes disponibles de un año ingresado por
el usuario dentro del arreglo de inscriptos para una categoría determinada, actualizando el archivo físico.
c) Mostrar un listado con los nombres de las categorías que superen el promedio total de inscriptos.
d) Dado el nombre de la categoría “NACIONAL B” realizar la actualización en el archivo de la cantidad de
clubes disponibles a un número ingresado por el usuario.*/

#include <stdio.h>
#include <string.h>

#define FILENAME "Categorias.Dat"
#define CATEGORIAS 5
#define AÑOS 20

typedef struct
{
    int codigo;
    char nombre[30];
    int cantidad_clubes;
    int inscriptos[AÑOS];
} Categoria;

void getMaxInscriptos();
void modificarCantidadClubes();
void mostrarCategoriasSuperanPromedio(int prom);
void actualizarCantidadClubes(char *nom_categoria);
void getPromedioInscriptos(int &prom);

int main()
{
    int prom;
    char nom_categoria[] = "NACIONAL B";
    // carga de datos de ejemplo en el archivo Categorias.Dat
    getMaxInscriptos();
    modificarCantidadClubes();
    getPromedioInscriptos(prom);
    mostrarCategoriasSuperanPromedio(prom); 
    actualizarCantidadClubes(nom_categoria); 
    return 0;
}

void getMaxInscriptos()
{
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }

    int codigo;
    printf("Ingrese el codigo de la categoria: ");
    scanf("%d", &codigo);

    Categoria cat;
    int found = 0;
    while (fread(&cat, sizeof(Categoria), 1, file) && !found)
    {
        if (cat.codigo == codigo)
        {
            found = 1;
            int maxInscriptos = 0;
            int maxYearIndex;
            for (int i = 0; i < AÑOS; i++)
            {
                if (cat.inscriptos[i] > maxInscriptos)
                {
                    maxInscriptos = cat.inscriptos[i];
                    maxYearIndex = i;
                }
            }
            printf("El año con mayor cantidad de inscriptos es: %d con %d inscriptos.\n", maxYearIndex + 1, maxInscriptos);
        }
    }

    if (!found)
    {
        printf("Categoria con codigo %d no encontrada.\n", codigo);
    }

    fclose(file);
    return;
};

void modificarCantidadClubes()
{
    FILE *fp = fopen(FILENAME, "rb+");
    if (fp == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }
    int cod_cat;
    Categoria cat;
    printf("Ingrese el codigo de la categoria a modificar: ");
    scanf("%d", &cod_cat);
    while(fread(&cat, sizeof(Categoria), 1, fp))
    {
        if(cat.codigo == cod_cat)
        {
            int año;
            printf("Ingrese el año (1-20) para modificar la cantidad de clubes: ");
            scanf("%d", &año);
            printf("Ingrese la nueva cantidad de clubes: ");
            scanf("%d", &cat.cantidad_clubes);

            fseek(fp, -sizeof(Categoria), SEEK_CUR);
            fwrite(&cat, sizeof(Categoria), 1, fp);

            printf("Cantidad de clubes actualizada correctamente.\n");
            fclose(fp);
            return;
        }
    }
    return;
};

void getPromedioInscriptos(int &prom)
{
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }
    Categoria cat;
    int totalInscriptos = 0;
    int totalCategorias = 0;
    while(fread(&cat, sizeof(Categoria), 1, fp))
    {
        for(int i = 0; i < AÑOS; i++)
        {
            totalInscriptos += cat.inscriptos[i];
        }
        totalCategorias++;
    }
    prom = totalInscriptos / (totalCategorias * AÑOS);
    fclose(fp);
    return;
};

void mostrarCategoriasSuperanPromedio(int prom)
{
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }
    Categoria cat;
    printf("Categorias que superan el promedio de inscriptos (%d):\n", prom);
    while(fread(&cat, sizeof(Categoria), 1, fp))
    {
        int totalInscriptos = 0;
        for(int i = 0; i < AÑOS; i++)
        {
            totalInscriptos += cat.inscriptos[i];
        }
        if(totalInscriptos > prom)
        {
            printf("%s\n", cat.nombre);
        }
    }
    fclose(fp);
    return;
};

void actualizarCantidadClubes(char *nom_categoria)
{
    FILE *fp = fopen(FILENAME, "rb+");
    if (fp == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }
    Categoria cat;
    int found = 0;
    while(fread(&cat, sizeof(Categoria), 1, fp) && !found)
    {
        if(strcmp(cat.nombre, nom_categoria) == 0)
        {
            printf("Ingrese la nueva cantidad de clubes para %s: ", nom_categoria);
            scanf("%d", &cat.cantidad_clubes);

            fseek(fp, -sizeof(Categoria), SEEK_CUR);
            fwrite(&cat, sizeof(Categoria), 1, fp);

            printf("Cantidad de clubes actualizada correctamente para %s.\n", nom_categoria);
            fclose(fp);
            found = 1;
        }
    }
    if(!found) printf("Categoria %s no encontrada.\n", nom_categoria);
    fclose(fp);
    return;
};
