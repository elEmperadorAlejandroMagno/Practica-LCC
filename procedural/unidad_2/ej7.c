#include <ctype.h>
#include <stdio.h>

#define N 4

typedef struct {
    char name[50];
    char sex; // M or F
    int dni;
    int age;
    int code; // 1 > C < 19
} cand;

void insertData(cand candidates[])
{
    for(int i = 0; i < N; i++)
    {
        printf("Nombre: ");
        scanf("%49s", candidates[i].name);
        printf("Género: ");
        scanf(" %c", &candidates[i].sex);
        printf("DNI: ");
        scanf(" %d", &candidates[i].dni);
        printf("Años: ");
        scanf(" %d", &candidates[i].age);
        do {    
            printf("Localidad: ");
            scanf(" %d", &candidates[i].code);
        }while (candidates[i].code < 1 || candidates[i].code > 19);
    }
    return;
};

void getTotalFByAge(cand candidates[])
{
    int age_filter = 30;
    int c = 0;
    for(int i = 0; i < N; i++)
    {
        if(candidates[i].age <= 30 && toupper(candidates[i].sex) == 'F')
        {
            c++;
        }
    }
    printf("Cantidad de postulates femeninos menor de 30 años: %d\n", c);
    return;
};

int getAvg(int total, int num)
{
    return (total / num);
};

void getAvgAgeM(cand candidates[])
{
    int acum = 0;
    int c = 0;
    for(int i = 0; i < N; i++)
    {
        if(toupper(candidates[i].sex) == 'M')
        {
            acum += candidates[i].age;
            c++;
        }
    }
    printf("Edad promedio de los postulantes masculinos: %d años\n", getAvg(acum, c));
    return;
};

void getNameDNIByCode(cand candidates[])
{
    int localidad = 14, c = 0;
    printf("Postulantes de la localidad %d \n", localidad);
    for(int i = 0; i < N; i++)
    {
        if(candidates[i].code == localidad)
        {
            c++;
            printf("Nombre %s DNI: %d\n", candidates[i].name, candidates[i].dni);
        }
    }
    if(c == 0) printf("No se han encontrado postulantes de la localidad %d", localidad);
    return;
};
void getOldestCand(cand candidates[])
{
    int max = 0, i_max;
    for(int i = 0; i < N; i++)
    {
        if(candidates[i].age > max)
        {
            max = candidates[i].age;
            i_max = i;
        }
    }
    printf("Candidato de mayor edad: %s DNI %d\n", candidates[i_max].name, candidates[i_max].dni);
    return;
};

void sortByAgeASC(cand candidates[])
{
    cand aux;
    int k = 1, limit = N - 1;
    while(k != -1)
    {
        k = -1;
        for(int i = 0; i < limit - 1; i++)
        {
            if(candidates[i].age > candidates[i + 1].age)
            {
                aux = candidates[i];
                candidates[i] = candidates[i + 1];
                candidates[i + 1] = aux;
                k = i;
            }
        }
        limit = k;
    }
    return;
};

void showEveryCand(cand candidates[])
{
    printf("Nombre | Sexo | DNI | Edad | Localidad\n");
    for(int i = 0; i < N; i++)
    {
        printf("%s %c %d %d %d\n", candidates[i].name, candidates[i].sex, candidates[i].dni, candidates[i].age, candidates[i].code);
    }
    return;
};

int main()
{
    cand candidates[N];
    insertData(candidates);
    getTotalFByAge(candidates);
    getAvgAgeM(candidates);
    getNameDNIByCode(candidates);
    getOldestCand(candidates);
    sortByAgeASC(candidates);
    showEveryCand(candidates);
    return 0;
};
