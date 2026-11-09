/*
 * ====================================================================
  PROGRAMACIÓN PROCEDURAL - TURNO TARDE
  TEMA 3 - ENUNCIADO: GESTIÓN DE UN CATÁLOGO DE PELÍCULAS
====================================================================

  Desarrolla un programa en C que gestione un catálogo de películas 
  que se han presentado en un cine que utilizando el archivo "pelicula.dat" 
  genere una lista enlazada. Cada componente del archivo tiene los 
  sigs atributos: código de película (a partir de 100), título, 
  género (1..6) y cantidad de entradas vendidas.

  Hacer un programa que a través de funciones óptimas realice las 
  sigs tareas:

  
Creación de la lista enlazada: Ingresar códigos de películas y 
  por teclado a partir del archivo "pelicula.dat" generar una lista 
  enlazada con la información de las películas del código ingresado.

  
Listado ordenado: Implementa una función que a partir de la lista 
  realice un listado ordenado alfabéticamente por título. Indicar en 
  el main la cantidad total de películas.
i
  
Generación de un arreglo: Crea una función que, a partir de la 
  lista enlazada, genere un arreglo de enteros que contenga la cantidad 
  de entradas vendidas por cada género. Mostrar el arreglo cargado 
  en otra función.

  
Cálculo del valor total del inventario: Ingresa el precio de la 
  entrada (valor único para todas las películas) y calcula el valor 
  total recaudado en entradas vendidas. Muestra el resultado en el main. 
  Implementa esta función de forma recursiva.

  
Búsqueda en archivo: Ingresar un nombre de película y a partir de 
  la información del archivo "pelicula.dat" si se encuentra en el 
  archivo, mostrar su información en el main.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "pelicula.dat"

typedef struct {
    int codigo;
    char titulo[100];
    int genero;
    int entradas_vendidas;
} Pelicula;

typedef struct Nodo {
    Pelicula pelicula;
    struct Nodo* sig;
} Nodo;

void initLista(Nodo *&lista) {
    lista = NULL;
}
void loadLista(FILE *file, Nodo *&lista)
{
    Pelicula pelicula;
    int codigo;
    Nodo *aux = lista;
    printf("Ingrese el código de la película (a partir de 100): ");
    scanf("%d", &codigo);
    while(codigo != -1)
    {
        fseek(file, sizeof(Pelicula) * (codigo - 100), SEEK_SET);
        if(fread(&pelicula, sizeof(Pelicula), 1, file))
        {
            Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo)); 
            nuevo->pelicula = pelicula;
            nuevo->sig = NULL;
        
            if(aux == NULL)
            {
                aux = nuevo;
            }
            else
            {
                aux->sig = nuevo;
                aux = nuevo;
            }   
        }
    }
};

void sortLista(Nodo *cab);

int main()
{
    Nodo *lista;
    FILE *fp = fopen(FILENAME, "rb+");
    if(fp == NULL)
    {
        printf("No se pudo abrir el archivo %s", FILENAME);
        return 1;
    }
    initLista(lista);
    loadLista(fp, lista);
    sortLista(lista);
    fclose(fp);
    return 0;
}

void sortLista(Nodo *cab)
{
    Nodo *k, *cota, *p;
    Pelicula aux_dato;
    cota = NULL;
    k = NULL;
    while (k != cab)
    {
        k = cab;
        p = cab;
        while (p->sig != cota)
        {
            if (strcmp(p->pelicula.titulo, p->sig->pelicula.titulo) > 0)
            { // Comparación para orden ascendente
                aux_dato = p->pelicula; // guardamos en auxiliar
                p->pelicula = p->sig->pelicula; // intercambio
                p->sig->pelicula = aux_dato;
                k = p; // Marca el último intercambio realizado
            }
            p = p->sig;
        }
        cota = k->sig; // La nueva cota es el sig del último intercambio
    }
}
