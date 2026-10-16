#include <stdio.h>
#include <stdlib.h>

#define N 4

struct nodo
{
	int cod_dron;
	int cod_tarea;
	char gestion[40];
	struct nodo *sig;
};

typedef struct nodo *ptr;

typedef struct
{
	char supervisor[40];
	ptr cab;
}tarea;

void cargaArr(tarea arr[], int i);
void cargaListas(tarea arr[]);

int main()
{
	tarea tareas[N];
	cargaArr(tareas, 0);
	cargaListas(tareas);
	return 0;
}

void cargaArr(tarea tareas[], int i)
{
	if(i < N)
	{
		printf("Ingrese nombre de supervisor: ");
		scanf("%s", tareas[i].supervisor);
		tareas[i].cab = NULL;
		cargaArr(tareas, i + 1);
	}
	return;
};

void cargaListas(tarea tareas[])
{
	int cod;
	printf("Ingrese codigo de prioridad(1-4): ");
	scanf("%d", &cod);
	if(cod != -1)
	{
		ptr nuevo = (ptr) malloc(sizeof(struct nodo));
		printf("Ingrsre codigo de dron: ");
		scanf("%d", &nuevo->cod_dron);

		printf("Ingrse codigo de tarea: ");
		scanf("%d", &nuevo->cod_tarea);

		printf("Ingrese gestion de tarea: ");
		scanf("%s", nuevo->gestion);

		nuevo->sig = NULL;
		if(tareas[cod - 1].cab != NULL)
		{
			ptr aux = tareas[cod - 1].cab;
			while(aux->sig != NULL)
			{
				aux = aux->sig;
			}
			aux->sig = nuevo;
		} else 	tareas[cod - 1].cab = nuevo;
		
		cargaListas(tareas);
	}
	return;
};
