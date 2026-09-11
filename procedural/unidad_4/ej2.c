#include <stdio.h>

#define C 5 // 30

void loadAges(int *ptr, int i);
void showArrInverted(int *ptr, int i);

int main()
{
    int comp_ages[C];
    int i = 0;
    loadAges(comp_ages, i);
    printf("Edad de los competidores\n");
    showArrInverted(comp_ages, i);
    return 0;
}

void loadAges(int *ptr, int i)
{
    if(i >= C) return; // caso base i >= 30
    //caso general i < 30
    printf("Ingrese la edad del competidor %d: ", i + 1);
    scanf("%d", (ptr + i));
    loadAges(ptr, i + 1);
    return;
};

void showArrInverted(int *ptr, int i)
{
    if(i >= C) return; // caso base i >= 30
    // caso general i < 30
    showArrInverted(ptr, i + 1);
    printf("Competidor %d: %d\n", i, *(ptr + i));
    return;
};

