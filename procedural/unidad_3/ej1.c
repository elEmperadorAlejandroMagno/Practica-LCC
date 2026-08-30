#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 35

void initNums(int nums[]);
int getEvenOddDetails(int nums[]);
int getAvg(int nums[]);
int getNumsBiggerThanAvg(int nums[], int avg);
void showNumsSmallerThanTarget(int nums[], int tar);
int getRandomNum();

int main()
{
    srand(time(NULL));
    int nums[N];
    int avg, target;
    initNums(nums);
    if(getEvenOddDetails(nums))
    {
        printf("La cantidad de num pares e impares es el mismo");
    } else printf("La cantidad de num pares e impares es distinta");
    avg = getAvg(nums);
    printf("Cantidad de num que superan el promedio: %d\n", getNumsBiggerThanAvg(nums, avg));
    printf("Ingrese número objetivo: ");
    scanf("%d", &target);
    showNumsSmallerThanTarget(nums, target);
    return 0;
}

int getRandomNum()
{
    // de 0 - 50
    int num = rand() % (50 - 0 + 1) - 0;
    return num;
};

void initNums(int nums[])
{
    for(int i = 0; i < N; i++)
    {
        nums[i] = getRandomNum();
    }
    return;
};

int getEvenOddDetails(int nums[])
{
    int ce = 0, co = 0;
    for(int i = 0; i < N; i++)
    {
        if(nums[i] % 2 == 0)
        {
            ce++;
        } else {
            co++;
        }   
    }
    return (ce == co);
};
    
int getAvg(int nums[])
{
    int avg = 0;
    for(int i = 0; i < N; i++)
    {
        avg += nums[i];
    }
    return (avg / N);
};

int getNumsBiggerThanAvg(int nums[], int avg)
{
    int c = 0;
    for(int i = 0; i < N; i++)
    {
        if(nums[i] > avg)
        {
            c++;
        }
    }
    return c;
};

void showNumsSmallerThanTarget(int nums[], int tar)
{
    int c = 0;
    printf("Posición de los números inferior a %d\n", tar);
    for(int i = 0; i < N; i++)
    {
        if(nums[i] < tar)
        {
            c++;
            printf("Valor-L %p\n", &nums[i]);
        }
    }
    if(c == 0) printf("No se han encontrado números que cumplan la condición\n");
    return;
};
