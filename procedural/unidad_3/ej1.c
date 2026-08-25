#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#include <time.h>

#define N 35

void initNums(int nums[]);
void getEvenOddNum(int nums[], int *ce, int *co);
int getAvg(int nums[]);
int getNumsBiggerThanAvg(int nums[], int avg);
void showNumsSmallerThanTarget(int nums[], int tar);
int getRandomNum();

int main()
{
    srand(time(NULL));
    int nums[N];
    int c_even, c_odd, avg, target;
    initNums(nums);
    getEvenOddNum(nums, &c_even, &c_odd);
    printf("%d\n", (c_even == c_odd));
    avg = getAvg(nums);
    printf("Cantidad de num que superan el promedio: %d\n", getNumsBiggerThanAvg(nums, avg));
    printf("Ingrese número objetivo: ");
    scanf("%d", &target);
    showNumsSmallerThanTarget(nums, target);
    return 0;
}

int getRandomNum()
{
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

void getEvenOddNum(int nums[], int *ce, int *co)
{
    ce = 0;
    co = 0;
    for(int i = 0; i < N; i++)
    {
        if(nums[i] % 2 == 0)
        {
            ce++;
        } else {
            co++;
        }   
    }
    return;
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
