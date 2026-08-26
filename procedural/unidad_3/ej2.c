#include <stdio.h>
#include <string.h>

#define N 4 // original 150

typedef struct
{
    int code;
    char name[40];
    float u_price;
    int stock;
} product;

void initProducts(product arr[]);
float salesProcessor(product arr[]);
void sortProductsByStockASC(product arr[]);
int getProductsNoStock(product arr[], int *last_i);
float getActualStockCosts(product arr[], int i);
void showProductsNoStock(int num);
void showActualStockCosts(float amount);

int main()
{
    product products[N];
    int last_0_stock;
    initProducts(products);
    printf("Se ha recaudado un total de: $%.2f\n", salesProcessor(products));
    sortProductsByStockASC(products);
    showProductsNoStock(getProductsNoStock(products, &last_0_stock));
    showActualStockCosts(getActualStockCosts(products, last_0_stock));
    return 0;
};

void initProducts(product arr[])
{
    printf("Ingresar datos de productos en stock\n");
    for(int i = 0; i < N; i++)
    {
        printf("Product details\n");
        printf("Code: ");
        // asumir que el codigo del producto es único
        scanf(" %d", &arr[i].code);
        getchar();
        printf("name:");
        fgets(arr[i].name, sizeof(arr[i].name), stdin);
        arr[i].name[strcspn(arr[i].name, "\n")] = '\0';
        do 
        {
            printf("Price per unit: $");
            scanf(" %f", &arr[i].u_price); 
        }while(arr[i].u_price <= 0);
        do 
        {
            printf("stock: ");
            scanf(" %d", &arr[i].stock);
        }while (arr[i].stock < 0);
    }
    return;
};

float salesProcessor(product arr[])
{
    int targ, units, i;
    float acum = 0;

    printf("Ventas realizadas\n");
    printf("Product code: ");
    scanf(" %d", &targ);
    while(targ != 0)
    {
        printf("Units sold: ");
        scanf(" %d", &units);
        i = 0;
        while(i < N && arr[i].code != targ)
        {
            i++;
        }
        if(i < N && arr[i].stock >= units)
        {
            arr[i].stock -= units;
            acum += (arr[i].u_price * units);
        } else printf("Producto no encontrado o no hay suficiente stock\n");
        printf("Product code: ");
        scanf(" %d", &targ);
    };
    return acum;
};

void sortProductsByStockASC(product arr[])
{
    int min;
    product aux;
    for(int i = 0; i < N - 2; i++)
    {
        min = i;
        for(int j = 1; j < N; j++)
        {
            if(arr[i].stock < arr[min].stock)
            {
                min = j;
            }
        }
        aux = arr[i];
        arr[i] = arr[min];
        arr[min] = aux;
    }
    return;
};

void showProductsNoStock(int num)
{
    printf("Cantidad de productos sin stock: %d\n", num);
    return;
};

void showActualStockCosts(float amount)
{
    printf("Costo actual del stock acumulado: $%.2f\n", amount);
    return;
};

int getProductsNoStock(product arr[], int *last_i)
{
    int i = 0, targ = 0;
    while(i < N && arr[i].stock == targ)
    {
        i++;
    }
    *last_i = i;
    return i + 1;
};

float getActualStockCosts(product arr[], int i)
{
    float acum = 0;
    while(i < N)
    {
        acum += (arr[i].u_price * arr[i].stock);
        i++;
    }
    return acum;
};

