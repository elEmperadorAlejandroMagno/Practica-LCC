#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float price;
    int quant;
} p_det;

void getMaxPrice(p_det product[], int i, float *max_price, int P);
int loadProducts(p_det arr[], int *P);
float getAvgPrice(p_det arr[], int i, float *avg, int P);
void saveProductBelowAvg(p_det arr[], int i, p_det **arrb, int P, int *j, float avg);
void getMinMaxArrB(p_det **arr, int i, int j, float *min, float *max);

int main()
{
    p_det arr[3] = {{5.90, 1}, {2, 3}, {1.50, 1}};
    p_det *arrb = malloc(sizeof(p_det));
    int P = 0, j = 0;
    float max_price = 0, avg, max = 0, min = 99999;
    //loadProducts(arr, &P);
    P = 3;
    getMaxPrice(arr, 0, &max_price, P);
    avg = getAvgPrice(arr, 0, &avg, P); 
    saveProductBelowAvg(arr, 0, &arrb, P, &j, avg);
    // calcular minimo y maximo
    getMinMaxArrB(&arrb, 0, j, &min, &max);
    printf("Precio máximo por debajo del precio promedio: %.2f\n", max);
    printf("Precio mínimo por debajo del precio promedio: %.2f\n", min);
    //free(arr);
    free(arrb);
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
            printf("Producto %d coincide con el precio máximo registrado de %.2f\n", i + 1, *max_price);
        }
        return;
    } else return;
};

float getAvgPrice(p_det arr[], int i, float *avg, int P)
{
    if(i < P)
    {
        *avg += arr[i].price;
        return getAvgPrice(arr, i + 1, avg, P);
    } else return (*avg / P);
};

void saveProductBelowAvg(p_det arr[], int i, p_det **arrb, int P, int *j, float avg)
{
    if(i < P)
    {
        saveProductBelowAvg(arr, i + 1, arrb, P, j, avg);
        if(arr[i].price < avg)
        {
            if(*j > 0)
            {
                p_det *tmp = malloc((*j + 1) * sizeof(p_det));
                for(int k = 0; k < *j; k++)
                {
                    tmp[k] = (*arrb)[k];
                }
                tmp[*j] = arr[i];
                free(*arrb);
                *arrb = tmp;
            } else *arrb[*j] = arr[i];
            *j += 1;
        }
        return;
    }
    return;
};

void getMinMaxArrB(p_det **arr, int i, int j, float *min, float *max)
{
    if(i < j)
    {
        if((*arr)[i].price < *min) *min = (*arr)[i].price;
        if((*arr)[i].price > *max) *max = (*arr)[i].price;
        getMinMaxArrB(arr, i + 1, j, min, max);
        return;
    } return;
};
