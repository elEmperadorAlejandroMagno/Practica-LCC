#include <stdio.h>
#include <stdbool.h>

void insertData(int arr[], int len);
int searchByDeg(int arr[], int len, int deg);
void sortByBubbleAsc(int arr[], int len);
void sortByBubbleInteractive(int arr[], int len, char order);
float getAvgDeg(int arr[], int len);
void showHotWarning(int arr[], int len);
void binarySearchEficiency(int arr[], int len, int targ);

int main()
{
    int len, deg, day;
    char order;
    printf("Días de análisis: ");
    scanf("%d", &len);
    int arr[len];
    insertData(arr, len);
    printf("Ingrese temperatura a buscar: ");
    scanf(" %d", &deg);
    day = searchByDeg(arr, len, deg);
    if(day >= 0) printf("El día %d tuvo %d°C\n", (day + 1), deg);
    sortByBubbleAsc(arr, len);
    printf("De que forma desea hacer el ordenamiento?\n'A': ascendente(menor a mayor)\n'D': descendente(mayor a menor)\n");
    while(order != 'A' && order != 'D')
    {
        scanf(" %c", &order);
    };
    sortByBubbleInteractive(arr, len, order);
    printf("La temperatura promedio es de %.1f\n", getAvgDeg(arr, len));
    showHotWarning(arr, len);
    binarySearchEficiency(arr, len, deg);
    return 0;
}

void insertData(int arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("Ingrese temperatura del día: ");
        scanf("%d", &arr[i]);
    }
    return;
};

int searchByDeg(int arr[], int len, int deg)
{
    bool f = false;
    int i = 0;
    while(i < len && f == false)
    {
        if(arr[i] == deg)
        {
            f = true;
        } else i++;
    }
    if(f != false)
    {
        return i;
    } else return -1;
};

void sortByBubbleAsc(int arr[], int len)
{
    int k, cota;
    int aux;
    k = 1;
    cota = len - 1;
    while(k != -1)
    {
        k = -1;
        for(int i = 0; i < len; i++)
        {
            if(arr[i] > arr[i + 1])
            {
                aux = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = aux;
                k = i;
            }
        }
        cota = k;
    }
    return;
}

void sortByBubbleInteractive(int arr[], int len, char order)
{
    int k, cota;
    int aux;
    cota = len - 1;
    k = 1;
    while(k != -1)
    {
        k = -1;
        for(int i = 0; i < len; i++)
        {

            switch (order)
            {
                case 'A':
                    if(arr[i] > arr[i + 1])
                    {
                        aux = arr[i];
                        arr[i] = arr[i + 1];
                        arr[i + 1] = aux;
                        k = i;
                    }
                    break;
                case 'D':
                    if(arr[i] < arr[i + 1])
                    {
                        aux = arr[i];
                        arr[i] = arr[i + 1];
                        arr[i + 1] = aux;
                        k = i;
                    }
                    break;
            }
        }
        cota = k;
    }
    return;
}

float getAvgDeg(int arr[], int len)
{
    int acum = 0;
    for(int i = 0; i < len; i++)
    {
        acum += arr[i];
    }
    return ((float)acum / len);
};

void showHotWarning(int arr[], int len)
{
    int count = 0;
    for(int i = 0; i < len; i++)
    {
        if(arr[i] >= 30)
        {
            count++;
        }
    }
    if(count > 3)
    {
        printf("Alerta Ola de Calor!!!\n");
    }
    return;
};

void binarySearchEficiency(int arr[], int len, int targ)
{
    int left = 0, right = len - 1, mid = (left + right) / 2;
    bool f = false;
    return;
};

        

