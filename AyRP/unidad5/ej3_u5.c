/*
Ejercicio 3: Distribuidora de Bebidas
Manejo de un stock de 50 productos vendidos a 20 comercios. Por cada comercio se ingresan los siguientes datos: CUIL
del comercio y la información de las compras realizadas por ese comercio a la distribuidora de bebidas. De cada compra,
los datos ingresados son: Nombre del producto comprado y cantidad de unidades de éste.
1. Almacenar, por cada uno de los 50 productos: el nombre y el precio unitario.
2. Mostrar para los comercios, un listado ordenado descendentemente por importe total que muestre el número de
CUIL y el importe total.
3. Generar una estructura que contenga el CUIL de aquellos comercios que compraron más de 500 unidades, indicar
cuántos son.
4. Dado el CUIL de un comercio indicar si se encuentra entre los comercios que compraron más de 500 unidades
5. Mostrar por cada uno de los 50 productos la cantidad total de unidades que la distribuidora debe tener para
satisfacer los pedidos realizados.
*/

#include <stdio.h>
#include <stdbool.h>

const int C = 3;
const int P = 5;

typedef struct producto {
	char nombre[20];
	float precio_unidad;
} producto;

typedef struct compra
{
	char nombre[20];
	int cantidad;
} compra;

typedef struct comercio
{
	char CUIL[20];
	compra compras[P];
	float importe_total;
} comercio;


void cargarProductos(producto lista_productos[])
{
	char nombre[20];
	float precio_unidad;
	for(int i = 0; i < P; i++)
	{
		scanf("%s\n", nombre);
		scanf("%d\n", precio_unidad);
		lista_productos[i].nombre = nombre;
		lista_productos[i].precio_unidad = precio_unidad;
	}
	return;
}

void sortImporteTotalDesc(comercio c[])
{
	int j;
    	comercio aux;
    	for (int i = 0; i < C; i++) 
	{
        	aux = c[i];
        	j = i-1;
       		while ( aux.importe_total < c[j].importe_total  && j >= 0) 
		{
            		c[j + 1] = c[j];
            		j = j - 1;
        	}
		c[j + 1] = aux;
    	}
   	return;
}

void mostrarCUILImporteComercios(comercio c[])
{
	for(int i = 0; i < C; i++)
	{
		printf("CUIL: %s\n", c[i].CUIL);
		printf("Importe total: $%.2f\n", c[i].importe_total);
	}
	return;
}

int cargarNuevaListaComercios(comercio c[], comercio nc[])
{
	int j = 0;
	int cant;
	for(int i = 0; i < C; i++)
	{
		cant = 0;
		while(c[i].compras[k].cantidad != 0 && k < P)
		{
			cant = cant + c[i].compras[k].cantidad;
		}
		if (cant > 500)
		{
			nc[j] = c[i].CUIL;
			j++;
		}
	}
	return j; // mostar la cantida de comercios > 500 productos en main()
}

bool searchByCUIL(comercio nc[], char CUIL[20], int len)
{
	int i = 0;

	while(nc[i].CUIL != CUIL && i < len)
	{
		i++;
	}
	if (i == len)
	{
		return false;
	} else return true;
	// se debe mostrar un mensaje desde main si se ha encontrado o no un comercio con ese CUIL
}

void mostrarProductosRequeridos(comercio c[], producto p[])
{
	int count;
	for(int i = 0; i < P; i++)
	{
		count = 0;
		for(int j = 0; j < C; j++)
		{
			count += c[j].compras[i].cantidad;
		}
		printf("Se han comprado: %d unidades de %s\n", count, p[i].nombre); 
	}
	return;
}

int main()
{

producto productos[P] = {
    { "Arroz", 150.0 },
    { "Fideos", 120.0 },
    { "Aceite", 800.0 },
    { "Azucar", 200.0 },
    { "Yerba", 950.0 }
};

comercio comerciosA[C] = {
    {
        "20-12345678-9",
        {
            { "Arroz", 10 },
            { "Aceite", 5 },
            { "Fideos", 0 },
            { "Azucar", 0 },
            { "Yerba", 0 }
        },
        10*150.0 + 5*800.0
    },
    {
        "23-98765432-1",
        {
            { "Fideos", 20 },
            { "Azucar", 15 },
            { "Yerba", 8 },
            { "Arroz", 0 },
            { "Aceite", 0 }
        },
        20*120.0 + 15*200.0 + 8*950.0
    },
    {
        "27-45678901-2",
        {
            { "Yerba", 12 },
            { "Arroz", 0 },
            { "Fideos", 0 },
            { "Aceite", 0 },
            { "Azucar", 0 }
        },
        12*950.0
    }
};

	//producto productos[P];
	//comercio comerciosA[C];
	comercio comerciosB[C];
	int lenComerciosB;
	char CUIL[24];
	bool f;

	//cargarProductos(productos);
	sortImporteTotalDesc(comerciosA);
	mostrarCUILImporteComercios(comerciosA);
	lenComerciosB = cargarNuevaListaComercios(comerciosA, comerciosB);
	printf("Ingrese CUIL de comercio:");
	scanf("%19s", CUIL);
	f = searchByCUIL(comerciosB, CUIL, lenComerciosB);
	if (f == true)
	{
		printf("Se ha encontrado el comercio con CUIL: %s", CUIL);
	} else printf("No se ha encontrado un comercio con CUIL: %s", CUIL);
	
	mostrarProductosRequeridos(comerciosA, productos);

	return 0;
}
