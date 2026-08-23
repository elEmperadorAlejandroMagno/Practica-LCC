#include <stdio.h>

#define F 1 // 2
#define R 2 // 3
#define C 2 // 3


void insertData(int cube[][R][C])
{
    for(int i = 0; i < F; i++)
    {
        for(int j = 0; j < R; j++)
        {
            for(int k = 0; k < C; k++)
            {
                printf("Ingrese cantidad de paquetes del compartimiento: ");
                scanf("%d", &cube[i][j][k]);
            }
        }
    }
    return;
};

void showPackagesByFace(int cube[][R][C])
{
    int face;
    do {
        printf("Que sección del deposito desea analisar?(0-1): ");
        scanf("%d", &face);
    }while (face < 0 || face > F - 1);
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            printf("%d ", cube[face][i][j]);
        }
        printf("\n");
    }
    return;
};

int getTotalPackages(int cube[][R][C])
{
    int c = 0;
    for(int i = 0; i < F; i++)
    {
        for (int j = 0; j < R; j++)
        {
            for(int k = 0; k < C; k++)
            {
                c += cube[i][j][k];
            }
        }
    }
    return c;
};

int getTotalEmptyDeposits(int cube[][R][C])
{
    int c = 0;
    for(int i = 0; i < F; i++)
    {
        for(int j = 0; j < R; j++)
        {
            for(int k = 0; k < C; k++)
            {
                if(cube[i][j][k] == 0)
                {
                    c++;
                }
            }
        }
    }
    return c;
};

void showDepositDetails(int cube[][R][C])
{
    printf("Cantidad total de paquetes del deposito: %d\n", getTotalPackages(cube));
    printf("Cantidad de compartimientos vacíos: %d\n", getTotalEmptyDeposits(cube));
    return;
};

int main()
{
    int deposit[F][R][C];
    insertData(deposit);
    showPackagesByFace(deposit);
    showDepositDetails(deposit);
    return 0;
};
    

