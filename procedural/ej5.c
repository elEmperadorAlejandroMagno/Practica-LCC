#include <stdio.h>

#define C 4
#define T 3

void insertData(int mat[][T])
{
    for(int i = 0; i < C; i++)
    {
        printf("Clase %d", i);
        for(int j = 0; j < T; j++)
        {
            printf("Turno %d | ingrese cantidad de alumnos: ", j+1);
            scanf("%d", &mat[i][j]);
        }
    }
    return;
};

void getTotalStudent(int mat[][T])
{
    int total = 0;
    for(int i = 0; i < C; i++)
    {
        for(int j = 0; j < T; j++)
        {
            total += mat[i][j];
        }
    }
    printf("Total de alumnos inscriptos %d", total);
    return;
};

void getBiggerShiftByClass(int mat[][T])
{
    int max = 0, class, i_shift;
    printf("Ingrese numero de clase: ");
    scanf("%d", &class);
    for(int i = 0; i < T; i++)
    {
       if(mat[class][i] > max)
       {
            max = mat[class][i];
            i_shift = i;
       }
    }
    printf("El turno con más alumnos de la classe %d es %d con %d alumnos", class, i_shift+1, max);
    return;
};

void getBiggerClassByShift(int mat[][T])
{
    int max = 0, shift, i_class;
    printf("Ingrese n° de turno: ");
    scanf("%d", &shift);
    for(int i = 0; i < C; i++)
    {
        if(mat[i][shift] > max)
        {
            max = mat[i][shift];
            i_class = i;
        }
    }
    printf("La clase con más alumnos en el turno %d es la clase %d", shift, i_class+1);
    return;
};

void getBiggerClass(int mat[][T])
{
    int max = 0, i_class, total;
    for(int i = 0; i < C; i++)
    {
        total = 0;
        for(int j = 0; j < T; j++)
        {
            total += mat[i][j];
        }
        if(total > max)
        {
            max = total;
            i_class = i;
        }
    }
    printf("La clase con más alumnos inscriptos es %d con %d alumnos", i_class+1, max);
    return;
};
    ;
void getBiggerShift(int mat[][T])
{
    int max = 0, i_shift, total;
    for(int i = 0; i < T; i++)
    {
        total = 0;
        for(int j = 0; j < C; j++)
        {
            total += mat[i][j];
        }
        if(total > max)
        {
            max = total;
            i_shift = i;
        }
    }
    printf("El turno con más alumnos es %d", i_shift+1);
    return;
};

int main()
{
    int planilla[C][T];
    insertData(planilla);
    getTotalStudent(planilla);
    getBiggerShiftByClass(planilla);
    getBiggerClassByShift(planilla);
    getBiggerClass(planilla);
    getBiggerShift(planilla);
    return 0;
};
