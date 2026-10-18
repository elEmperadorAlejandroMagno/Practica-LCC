#include <complex>
#include <stdio.h>
#include <stdlib.h>


typedef struct nodo_sub
{
    int cod_dron;
    int cod_tarea;
    char gestion[40];
    struct nodo_sub *sig;
}nodo_sub;

typedef struct nodo
{
    int cod_prio;
    char sup[40];
    struct nodo *sig;
    nodo_sub *cab;
}nodo;

//typedef struct nodo *puntero; alias o tipo personalizado

void iniciarLista(nodo *&lista); // puntero &lista
void cargarTareas(nodo_sub *&sublista, nodo *&lista, int cod);

int main()
{
    //puntero nuevo = (puntero) malloc(sizeof nodo));
    nodo *lista = (nodo*) malloc(sizeof(nodo));
    lista = NULL;
    nodo *ptr = lista;
    iniciarLista(ptr);
    return 0;
}
// ingreso por cola
void iniciarLista(nodo *&lista)
{
    int cod;
    printf("Ingrese codigo de prioridad(1-4): ");
    scanf("%d", &cod);
    if(cod != -1)
    {
        if(lista == NULL)
        {
            nodo *nuevo = (nodo*) malloc(sizeof(nodo));
            lista->cod_prio = cod;
            printf("Ingrese nombre de supervisor: ");
            scanf("%s", nuevo->sup);

            nuevo->sig = NULL;
            nodo_sub *sublista = (nodo_sub*) malloc(sizeof(nodo_sub));
            sublista = NULL;
            lista = nuevo;
        } else 
        {
            iniciarLista(lista->sig);
        }
    }
    return;
};

void cargarTareas(nodo_sub *&sublista, nodo *&lista, int cod)
{
   if(cod != -1)
   {
        if((lista != NULL) && (cod != lista->cod_prio))
        {
            cargarTareas(sublista, lista->sig, cod);
        }
        if(lista != NULL)
        {
            if(sublista == NULL)
            {
                nodo_sub *nuevo = (nodo_sub*) malloc(sizeof(nodo_sub));
                printf("Ingrese codigo de dron: ");
                scanf("%d", &nuevo->cod_dron);
                printf("Ingrese codigo de tarea: ");
                scanf("%d", &nuevo->cod_tarea);
                printf("Ingrese gestion: ");
                scanf("%s", nuevo->gestion);
                nuevo->sig = sublista;
                sublista = nuevo;
                
                printf("Ingrese codigo de prioridad: ");
                scanf("%d", &cod);
                cargarTareas(sublista, lista, cod);
            } else 
            {
                cargarTareas(sublista->sig, lista, cod);
            }
        }
   }
    return;
};

void cambioPrio(nodo_sub *&lista_crit, nodo_sub *&lista_alta, int cod)
{
    if(lista_alta == NULL) return;
    if(lista_alta->cod_dron != cod)
    {
        cambioPrio(lista_crit, lista_alta->sig, cod);
        
    }else
    {
        nodo_sub *aux = lista_alta;
        lista_alta = lista_alta->sig;
        aux->sig = NULL;
        // corta enlace de lista alta

        if(lista_crit != NULL)
        {
            lista_crit->sig = aux;
            lista_crit = aux;
            // arma el enlace en lista critica
        } else lista_crit = aux;
        cambioPrio(lista_crit, lista_alta, cod);
    } 
    return;
};
        




        
