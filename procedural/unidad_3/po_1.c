//Una distribuidora comercializa 4 tipos de cervezas (1..4) y realiza ventas a 3 negocios (1..3).  
//Se ingresan las ventas realizadas durante un periodo de tiempo, ordenadas por negocio. Por cada venta 
//realizada a un negocio se ingresa: tipo de cerveza y cantidad de unidades vendidas, finalizando con tipo de 
//cerveza igual a 0 (cero)

#include <stdio.h>

#define B 4
#define S 3

void cerear(int a[][B])
{
    for(int i = 0; i < S; i++)
    {
        for(int j = 0; j < B; j++)
        {
            a[i][j] = 0;
        }
    }
    return;
};

void carga(int a[][B]){
    int tipo, cant;
    
    for(int i = 0; i < S; i++) // procesa -> negocio 1(i=0); negocio 2(i=1); negocio 3(i=2);
    {
        printf("Pedidos para negocio %d\n", i+1);
        printf("Ingrese tipo cerveza: ");
        scanf(" %d", &tipo);
        while (tipo !=0)
        {
            do {
                printf("ingrese cantidad: ");
                scanf(" %d", &cant);
            } while(cant < 0);

            a[i][tipo - 1] += cant;
            printf("ingrese tipo: ");
            scanf(" %d", &tipo);
        }
    }
    return;
};

void getTotalBeerType(int a[][B])
{
    int acum;
    for(int i = 0; i < B; i++)
    {
        acum = 0;
        for(int j = 0; j < S; j++)
        {
            acum += a[j][i];
        }
        printf("Se vendieron %d de cervezas de tipo %d\n", acum, i+1);
    }
    return;
};

int getTotalByType(int a[][B], int t)
{
    int acum = 0;
    for(int i = 0; i < S; i++)
    {
        acum += a[i][t - 1];
    }
    return acum;
};

int main()
{
	int distr[S][B], tipo;
    cerear(distr);
    carga(distr);
    getTotalBeerType(distr);
    printf("ingrese tipo: \n");
    scanf(" %d", &tipo);
    getTotalByType(distr, tipo);
	return 0;
};
