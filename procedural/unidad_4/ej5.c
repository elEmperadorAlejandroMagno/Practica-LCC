#include <stdio.h>

#define L 6

void loadVoteArr(int arr[], int i);
void getMaxMin(int arr[], int *min, int *max, int i, int *i_min, int *i_max);
void getEvaluation(int arr[], int *less5k, int *more9k, int i);
void getLanguageAboveAvg(int arr[], int i, int avg);
void getAvg(int a[], int *acum, int i);

const char *LANGUAGES[] = {"Javascript", "HTML", "CSS", "Java", "Python", "C"};

int main()
{
    int arr_votes[L];
    int min = 99999, max = 0, c_less5k = 0, c_more9k = 0, acum = 0;
    int i_min, i_max;
    loadVoteArr(arr_votes, 0);
    getMaxMin(arr_votes, &min, &max, 0, &i_min, &i_max);
    getEvaluation(arr_votes, &c_less5k, &c_more9k, 0);
    getAvg(arr_votes, &acum, 0);
    return 0;
};

void loadVoteArr(int arr[], int i)
{
    if(i < L)
    {
        printf("Ingrese cantidad de votos para el lenguage %d %s: ", i + 1, LANGUAGES[i]);
        scanf("%d", &arr[i]);
        loadVoteArr(arr, i + 1);
        return;
    } else return;
};

void getMaxMin(int arr[], int *min, int *max, int i, int *i_min, int *i_max)
{
    if(i < L)
    {
        if(arr[i] > *max)
        {
            *max = arr[i];
            *i_max = i;
        }
        if(arr[i] < *min)
        {
            *min = arr[i];
            *i_min = i;
        }
        getMaxMin(arr, min, max, i + 1, i_min, i_max);
        return;
    } else {
        printf("El lenguaje con mas votos es: %s\n", LANGUAGES[*i_max]);
        printf("El lenguaje con menos votos es: %s\n", LANGUAGES[*i_min]);
        return;
    }
};

void getEvaluation(int arr[], int *less5k, int *more9k, int i)
{
    if(i < L)
    {
        if(arr[i] < 5000)
        {
            *less5k += 1;
        } else if(arr[i] > 9000)
        {
            *more9k += 1;
        }
        getEvaluation(arr, less5k, more9k, i + 1);
        return;
    } else
    {
        printf("Cantidad de lenguajes con menos de 5000 votos: %d\n", *less5k);
        printf("Cantidad de lenguajes con más de 9000 votos: %d\n", *more9k);
        return;
    };
};    

void getAvg(int arr[], int *acum, int i)
{
    int avg;
    if(i < L)
    {
        *acum += arr[i];
        getAvg(arr, acum, i + 1);
        return;
    }else
    {
        avg = *acum / L;
        printf("Promedio de votos: %d\n",avg);
        getLanguageAboveAvg(arr, 0, avg);
        return;
    }
};

void getLanguageAboveAvg(int arr[], int i, int avg)
{
    if(i < L)
    {
        if(arr[i] > avg)
        {
            printf("%s esta por encima del promedio de votos\n", LANGUAGES[i]);
        }
        getLanguageAboveAvg(arr, i + 1, avg);
        return;
    } else return;
};
