#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILENAME "becas.dat"

typedef struct
{
    int reg;
    char name[20];
} Alu;

typedef struct
{
    char name[20];
} Fac;

typedef struct nodoAlu
{
    Alu alumno;
    nodoAlu *sig;
} nodoAlu;

typedef struct nodoFac
{
    Fac facultad;
    nodoFac *sig;
    nodoAlu *cab_alu;
} nodoFac;

typedef struct
{
    Fac facultad;
    Alu alumno;
} RegBecas;

void inverseLoad(nodoFac *&list, FILE *file);
void freeList(nodoFac *&list);

int main()
{
    nodoFac *lista = NULL;

    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL)
    {
        printf("No se pudo abrir %s\n", FILENAME);
        return 1;
    }

    inverseLoad(lista, fp);
    fclose(fp);

    freeList(lista);
    return 0;
}

void inverseLoad(nodoFac *&list, FILE *file)
{
    RegBecas nuevo;               // variable normal, no puntero
    nodoFac *ultFac = NULL;       // última facultad cargada
    nodoAlu *ultAlu = NULL;       // último alumno de esa facultad

    while (fread(&nuevo, sizeof(RegBecas), 1, file))
    {
        // ¿Cambió la facultad (o es el primer registro)?
        if (ultFac == NULL || strcmp(ultFac->facultad.name, nuevo.facultad.name) != 0)
        {
            nodoFac *auxFac = (nodoFac *)malloc(sizeof(nodoFac));
            auxFac->facultad = nuevo.facultad;
            auxFac->sig = NULL;
            auxFac->cab_alu = NULL;

            if (list == NULL) list = auxFac;  // primera facultad: es la cabeza
            else ultFac->sig = auxFac;  // enlazar al final

            ultFac = auxFac;
            ultAlu = NULL;  // sublista nueva
        }

        // Agregar alumno al final de la sublista de la facultad actual
        nodoAlu *auxAlu = (nodoAlu *)malloc(sizeof(nodoAlu));
        auxAlu->alumno = nuevo.alumno;
        auxAlu->sig = NULL;

        if (ultAlu == NULL) ultFac->cab_alu = auxAlu;
        else ultAlu->sig = auxAlu;

        ultAlu = auxAlu;
    }
}

void freeList(nodoFac *&list)
{
    if(list != NULL)
    {
        freeList(list->sig);
        while(list->cab_alu != NULL)
        {
            nodoAlu *aux = list->cab_alu;
            list->cab_alu = list->cab_alu->sig;
            free(aux);
        }
        free(list);
        list = NULL;
    }
} 
