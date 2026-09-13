#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float price;
    int quant;
} p_det;

void getMaxPrice(p_det product[], int i, float *max_price, int P);
int loadProducts(p_det arr[], int *P);
void getAvgPrice(p_det arr[], int i, float *avg, int P);
int saveProductBelowAvg(p_det arr[], int i, p_det **arrb, int P, int *j);

int main()
{
    p_det *arr, *arrb;
    int P = 0, j = 0;
    float max_price = 0;
    loadProducts(arr, &P);
    getMaxPrice(arr, 0, &max_price, P);
    saveProductBelowAvg(arr, 0, &arrb, P, &j);
    // calcular minimo y maximo
    return 0;
};

void getMaxPrice(p_det product[], int i, float *max_price, int P)
{
    if(i < P)
    {
        if(product[i].price > *max_price)
        {
            *max_price = product[i].price;
        }
        getMaxPrice(product, i + 1, max_price, P);
        if(product[i].price == *max_price)
        {
            printf("Producto %d coincide con el precio máximo registrado de %.2f", i + 1, *max_price);
        }
        return;
    } else return;
};

void getAvgPrice(p_det arr[], int i, float *avg, int P)
{
    if(i < P)
    {
        *avg += arr[i].price;
        getAvgPrice(arr, i + 1, avg, P);
        return;
    } else return;
};

int saveProductBelowAvg(p_det arr[], int i, p_det **arrb, int P, int *j)
{
    return 1;
};
