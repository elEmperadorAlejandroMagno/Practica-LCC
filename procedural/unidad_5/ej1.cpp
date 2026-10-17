#include <stdio.h>
#include <stdlib.h>

void crear(int *&p, int &N);
void carga(int *p, int N, int i);

int main()
{
	int *p1 = NULL, *p2 = NULL;
	int N;
	// el cast (tipo*) malloc(...) es requerido en C++, en C estandar malloc devuelve un puntero *void y el cambio
	// de tipo es implicito

	//p1 = (int*) malloc(sizeof(int) * N);
	crear(p1, N);
	carga(p1, N, 0);

	//p2 = (int*) malloc(sizeof(int) * N);
	crear(p2, N);
	carga(p2, N, 0);

	free(p1);
	free(p2);
	return 0;
};

// usamos &* o ** si modificamos el puntero con malloc desde un subprograma pg 188 libro de procedural
void crear(int *&p, int &N)
{
	printf("Tamañao del arreglo: ");
	scanf("%d", N);
	p = (int *) malloc(sizeof(int) * N);
	return;
};

void carga(int *p, int N, int i)
{
	if(i < N)
	{
		printf("Ingrese numero: ");
		scanf("%d", (p + i));
		carga(p, N, i+1);
		return;
	}
	return;
};

