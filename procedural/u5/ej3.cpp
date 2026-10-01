#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int dni;
	int plan;
	float debt;
} cliente;

void carga(int &arr);
void searchByDNI(cliente *arr, int dni, int &i, int *plan, float *debt, int n);

int main()
{
	cliente *p = NULL;
	int N, dni, plan, i = 0;
	float debt;
	printf("Cantidad de clientes: ");
	scanf("%d", &N);
	p = (cliente*) malloc(sizeof(cliente) * N);
	// carga(p);
	
	printf("DNI a buscar: ");
	scanf("%d", &dni);
	searchByDNI(p, dni, i, &plan, &debt, N);
	if(i < N)
	{
		printf("Cliente con dni %d tiene plan %d y debe $%.2f", dni, plan, debt);
	} else printf("No se encontró un cliente con dni %d", dni);
	return 0;
}

void searchByDNI(cliente *arr, int dni, int &i, int *plan, float *debt, int n)
{
	if(i < n)
	{
		if(arr[i].dni == dni)
		{
			*plan = arr[i].plan;
			*debt = arr[i].debt;
		}
		else 
		{
			i += 1;
			searchByDNI(arr, dni, i, plan, debt, n);
		}
		return;
	}
	return;
};

