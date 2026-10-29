/*Ejercicio 8 (Migración y Filtrado de Datos)
Una cadena de cines reconocida de argentina solicita la creación de un programa que usando el archivo CINE.DAT que
cuenta con los siguientes datos por película: (Código, Título, Director, Cantidad de Espectadores) cumpla con los
requerimientos:
Nota: El archivo está ordenado en forma secuencial por código a partir del número 1.
a) Mostrar un listado con los datos de las películas del archivo.
b) Modificar la cantidad de espectadores en un valor ingresado por el usuario de la película número 5.
c) Indicar quien es el Director dado el título de una película ingresado por el usuario.
d) Desarrolle una función que cree un nuevo archivo exitos.dat que contenga solo las películas con más de
100.000 espectadores.
e) Indicar el título de la película con mayor cantidad de espectadores del archivo éxitos.dat, suponer única.
f) Al finalizar, muestre un listado comparativo del tamaño en bytes de ambos archivos.*/

#include <stdio.h>
#include <string.h>

typedef struct {
    int codigo;
    char titulo[50];
    char director[50];
    int espectadores;
} Pelicula; // ordenado por codigo a partir del numero 1

#define FILENAME "CINE.DAT"
#define EXITOS_FILENAME "EXITOS.DAT"

void showFilmsData(FILE *file);
void modifySpectators(FILE *file);
void findDirectorByTitle(FILE *file);
void createExitosFile(FILE *file1, FILE *file2);
void findMaxSpectators(FILE *file);
void compareFileSizes(FILE *file1, FILE *file2);

int main()
{
    FILE *file = fopen(FILENAME, "rb+");
    FILE *exitos_file = fopen(EXITOS_FILENAME, "rb+");
    showFilmsData(file);
    modifySpectators(file);
    findDirectorByTitle(file);
    createExitosFile(file, exitos_file);
    findMaxSpectators(exitos_file);
    fclose(file);
    fclose(exitos_file);
    compareFileSizes(file, exitos_file);   
    return 0;
}

void showFilmsData(FILE *file)
{
    Pelicula pelicula;
    rewind(file);
    printf("Listado de peliculas:\n");
    while (fread(&pelicula, sizeof(Pelicula), 1, file))
    {
        printf("Codigo: %d\n", pelicula.codigo);
        printf("Titulo: %s\n", pelicula.titulo);
        printf("Director: %s\n", pelicula.director);
        printf("Cantidad de espectadores: %d\n", pelicula.espectadores);
        printf("\n");
    }
    return;
};

void modifySpectators(FILE *file)
{
    Pelicula pelicula;
    int newSpectators;
    rewind(file);
    fseek(file, sizeof(Pelicula) * 4, SEEK_SET);    
    fread(&pelicula, sizeof(Pelicula), 1, file);
    printf("Ingrese la nueva cantidad de espectadores para la pelicula %s: ", pelicula.titulo);
    scanf("%d", &newSpectators);
    pelicula.espectadores = newSpectators;
    fseek(file, -sizeof(Pelicula), SEEK_CUR); 
    fwrite(&pelicula, sizeof(Pelicula), 1, file);
    return;
};

void findDirectorByTitle(FILE *file)
{
    Pelicula pelicula;
    char title[50];
    int found = 0;
    rewind(file);
    printf("Ingrese el titulo de la pelicula: ");
    scanf("%s", title);
    while (fread(&pelicula, sizeof(Pelicula), 1, file) && !found)
    {
        if (strcmp(pelicula.titulo, title) == 0)
        {
            printf("El director de la pelicula %s es: %s\n", pelicula.titulo, pelicula.director);
            found = 1;
        }
    }
    if (!found)
    {
        printf("No se encontro la pelicula con el titulo %s\n", title);
    }
    return;
};

void createExitosFile(FILE *file1, FILE *file2)
{
    Pelicula pelicula;
    rewind(file1);
    while (fread(&pelicula, sizeof(Pelicula), 1, file1))
    {
        if (pelicula.espectadores > 100000)
        {
            fwrite(&pelicula, sizeof(Pelicula), 1, file2);
        }
    }
    return;
};

void findMaxSpectators(FILE *file)
{
    Pelicula pelicula;
    Pelicula maxPelicula;
    rewind(file);
    while (fread(&pelicula, sizeof(Pelicula), 1, file))
    {
        if (pelicula.espectadores > maxPelicula.espectadores)
        {
            maxPelicula = pelicula;
        }
    }
    printf("La pelicula con mayor cantidad de espectadores es: %s con %d espectadores\n", maxPelicula.titulo, maxPelicula.espectadores);
    return;
};

void compareFileSizes(FILE *file1, FILE *file2)
{
    fseek(file1, 0, SEEK_END);
    fseek(file2, 0, SEEK_END);
    long size1 = ftell(file1);
    long size2 = ftell(file2);
    printf("Tamaño del archivo %s: %ld bytes\n", FILENAME, size1);
    printf("Tamaño del archivo %s: %ld bytes\n", EXITOS_FILENAME, size2);
    return;
};
