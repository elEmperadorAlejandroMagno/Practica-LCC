#include <stdio.h>

#define O 3 // 25

typedef struct
{
    float height;
    float weight;
} Op;

void loadOperators(Op arr[], int i);
int countOp60kg(Op arr[], int i);
void getHeightAvgOp(Op arr[], float *acum, int *count, int i);

int main()
{
    Op operators[O];
    float total_height = 0;
    int count = 0;
    loadOperators(operators, 0);
    printf("Operarios con más de 60k: %d\n", countOp60kg(operators, 0));
    getHeightAvgOp(operators, &total_height, &count, 0);
    printf("Peso promedio de los operarios que miden más de  1.5m: %.2fkg\n", total_height / count);
    return 0;
}

void loadOperators(Op arr[], int i)
{
    if(i == O) return;
    printf("Operador %d\n", i + 1);
    printf("Altura: ");
    scanf("%f", &arr[i].height);
    printf("Peso: ");
    scanf("%f", &arr[i].weight);
    loadOperators(arr, i + 1);
    return;
};

int countOp60kg(Op arr[], int i)
{
    static int count = 0;
    if(i == O) return count;
    if(arr[i].weight > 60)
    {
        count++;
    }
    return countOp60kg(arr, i + 1);
};

void getHeightAvgOp(Op arr[], float *acum, int *count, int i)
{
    if(i == O) return;
    if(arr[i].height > 1.5)
    {
        *acum += arr[i].weight;
        *count += 1; // tambien funciona (*count)++
        // *count++ se interpeta como *(count++) la direccion incrementada
    }
    getHeightAvgOp(arr, acum, count, i + 1);
    return;
};
