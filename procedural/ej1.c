#include <stdio.h>
#include <stdbool.h>

const int N = 10;

float getAvgWeight(float arr[]);
void getNullValue(float arr[]);
void showEvenIndex(float arr[]);
void showArrDetails(float arr[]);
void initArr(float arr[]);
void getMaxMinValue(float arr[]);
void showvalRL(float arr[]);
void checkFirstArrValue(float arr[]);

int main()
{
    float arr_g[N];
    initArr(arr_g);
    getNullValue(arr_g);
    printf("Peso promedio de las piezas: %.2fg\n", getAvgWeight(arr_g));
    showEvenIndex(arr_g);
    getMaxMinValue(arr_g);
    showvalRL(arr_g);
    checkFirstArrValue(arr_g);
    printf("Tamaño del arreglo %zu bytes\n", sizeof(arr_g));
    return 0;
};

void initArr(float arr[])
{
    float piece_g;
    for(int i = 0; i < N; i++)
    {
        scanf("%f", &piece_g);
        arr[i] = piece_g;
    }
    return;
};

void getMaxMinValue(float arr[])
{
    float min = 99999, max = 0;
    int i_min, i_max;
    for(int i = 0; i < N; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
            i_min = i;
        }
        if(arr[i] > max)
        {
            max = arr[i];
            i_max = i;
        }
    }
    printf("Peso mínimo: %2.fg | posición %d\n", min, i_min);
    printf("Peso máximo: %2.fg | posición %d\n", max, i_max);
    return;
};

float getAvgWeight(float arr[])
{
    float avg = 0;
    for(int i = 0; i < N; i++)
    {
        avg += arr[i];
    }
    return (avg/N);
};

void getNullValue(float arr[])
{
    bool f = false;
    int i = 0;
    while(f == false && i < N)
    {
        if(arr[i] == 0)
        {
            f = true;
        }
        i++;
    }
    if(f)
    {
        printf("Se ha encontrado un pesaje con valor 0, posición %d\n", i);
    }
    return;
};

void showEvenIndex(float arr[])
{
    int i = 0;
    while(i < N)
    {
        printf("Pieza con peso de %.2f g\n | índice %d", *(arr + i), i);
        i += 2;
    }
    return;
};

void showvalRL(float arr[])
{
    int count = 0;
    for(int i = 0; i < N; i++)
    {
        if(((int)arr[i] % 2) == 0)
        {
            count++;
            printf("Valor-L(identificador representa una ubicacion en memoria) %p | Valor-R(dato almacenado en memoria): %.2f\n", &arr[i], arr[i]);
        }
    }
    if(count > 0)
    {
        printf("Hay %d piezas con peso par\n", count);
    }
    return;
};

void checkFirstArrValue(float arr[])
{
    if(arr[0] == *arr)
    {
       printf("El identificador del arreglo efectivamente cumple con el array decay \n arr[0] hace referencia a la misma direccion de memoria que *arr y por lo tanto se obtiene el mismo valor.\n");
       printf("arr[0] %p \n *arr %p\n", &arr[0], arr);
    } else
    {
        printf("El identificador del arreglo no esta cumpliendo con el array decay");
    }
};

