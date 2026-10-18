#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	char sup[40];
	ptr cab;
}tarea;

void loadArr(tarea arr[], int i);
void loadListas(tarea arr[]);
void moveDronTask(ptr cab_to, ptr cab_from, int dron);
void deleteTask(tarea arr[], int dron, int task, int i);
void showTasksByPrio(ptr cab);
void showTasksByDron(tarea arr[], int dron, int i);
void showTasksBySup(tarea arr[], char sup[], int i);

int main()
{
	tarea tareas[N];
	ptr p1, p2;
	int dron, task, prio;
	char sup[40];
	loadArr(tareas, 0);
	loadListas(tareas);
	p1 = tareas[0].cab; // critico
	p2 = tareas[1].cab; // alto
	printf("Ingrese codigo de dron: ");
	scanf("%d", &dron);
	moveDronTask(p1, p2, dron);
	printf("Ingrese codigo de dron: ");
	scanf("%d", &dron);
	printf("Ingrese codigo de tarea: ");
	scanf("%d", &task); 
	deleteTask(tareas, dron, task, 0);
	printf("Ingrese prioridad de tarea(1-4): ");
	scanf("%d", &prio);
	printf("Supervisor: %s", tareas[prio].sup);
	showTasksByPrio(tareas[prio].cab);
	printf("Ingrese codigo de dron: ");
	scanf("%d", &dron);
	showTasksByDron(tareas, dron, 0);
	printf("Ingrese nombre de supervisor: ");
	scanf("%s", sup);
	showTasksBySup(tareas, sup, 0);
	return 0;
}

void loadArr(tarea tareas[], int i)
{
	if(i < N)
	{
		printf("Ingrese nombre de sup: ");
		scanf("%s", tareas[i].sup);
		tareas[i].cab = NULL;
		loadArr(tareas, i + 1);
	}
	return;
};

void loadListas(tarea tareas[])
{
	int cod;
	ptr nuevo, aux;
	printf("Ingrese codigo de prioridad(1-4): ");
	scanf("%d", &cod);
	if(cod != -1)
	{
		nuevo = (ptr) malloc(sizeof(struct nodo));
		printf("Ingrsre codigo de dron: ");
		scanf("%d", &nuevo->cod_dron);

		printf("Ingrse codigo de tarea: ");
		scanf("%d", &nuevo->cod_tarea);

		printf("Ingrese gestion de tarea: ");
		scanf("%s", nuevo->gestion);

		nuevo->sig = NULL;
		if(tareas[cod - 1].cab == NULL)
		{
			tareas[cod - 1].cab = nuevo;
		}
		else
		{
			aux = tareas[cod - 1].cab;
			while(aux->sig != NULL)
			{
				aux = aux->sig;
			}
			aux->sig = nuevo;
		}	
		
		loadListas(tareas);
	}
	return;
};

void moveDronTask(ptr cab_to, ptr cab_from, int dron)
{
	if(cab_from != NULL && cab_from->cod_dron != dron)
		{
			cab_from = cab_from->sig;
			moveDronTask(cab_to, cab_from, dron);
		}	
	else if(cab_from != NULL)
		{
			cab_to->sig = cab_from;
			cab_to = cab_to->sig;
			moveDronTask(cab_to, cab_from, dron);
		}
	return;
};

void deleteTask(tarea arr[], int dron, int task, int i)
{
    if (i < N)
    {
        ptr *cab = &arr[i].cab;

        if (*cab != NULL && (*cab)->cod_dron == dron && (*cab)->cod_tarea == task)
        {   // Caso 1: es la cabeza -> se elimina y se termina
            ptr p = *cab;
            *cab = p->sig;
            free(p);
        }
        else
        {
            ptr anterior = NULL;
            ptr p = *cab;

            while (p != NULL && (p->cod_dron != dron || p->cod_tarea != task))
            {
                anterior = p;
                p = p->sig;
            }

            if (p != NULL)
            {   // Caso 2: intermedio o final -> se elimina y se termina
                anterior->sig = p->sig;
                free(p);
            }
            else
            {   // No estaba en esta lista -> seguir con la siguiente posición
                deleteTask(arr, dron, task, i + 1);
            }
        }
    }
}

void showTasksByPrio(ptr cab)
{
	if(cab != NULL)
	{
		printf("Cod dron: %d\n Cod tarea: %d\n Gestion Tarea: %s\n", cab->cod_dron, cab->cod_tarea, cab->gestion);
		cab = cab->sig;
		showTasksByPrio(cab);
	}
	return;
};	

void showTasksByDron(tarea arr[], int dron, int i)
{
	if(i < N)
	{
		ptr cab = arr[i].cab;
		if(cab != NULL)
		{
			while(cab != NULL)
			{
				if(cab->cod_dron == dron)
				{
					printf("Cod tarea: %d\n Gestion tarea: %s\n", cab->cod_tarea, cab->gestion);
				}
				cab = cab->sig;
			}
		}
		showTasksByDron(arr, dron, i + 1);
	}
	return;
};


void showTasksBySup(tarea arr[], char sup[], int i)
{
	if(i < N)
	{
		if(strcmp(arr[i].sup, sup) == 0)
		{

			ptr cab = arr[i].cab;
			if(cab != NULL)
			{
				while(cab != NULL)
				{
					printf("Cod tarea: %d\n Gestion tarea: %s\n", cab->cod_tarea, cab->gestion);
					cab = cab->sig;
				}
			}
		}
		showTasksBySup(arr, sup, i + 1);
	}
	return;
};
