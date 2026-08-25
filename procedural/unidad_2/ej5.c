#include <stdio.h>

#define C 4
#define T 3

const char *classes[] = {
    "IA Generativa", 
    "Administración de Base de Datos", 
    "Cableado de Datos", 
    "Gestión Inteligente de APs"
};

const char *shifts[] = {
    "Mañana",
    "Tarde",
    "Vespertino"
};

void insertData(int mat[][T])
{
    for(int i = 0; i < C; i++)
    {
        printf("Clase %d %s\n", i+1, classes[i]);
        for(int j = 0; j < T; j++)
        {
            printf("Turno %d %s | ingrese cantidad de alumnos: ", j+1, shifts[j]);
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
    printf("Total de alumnos inscriptos %d\n", total);    
    return;
};

void getBiggerShiftByClass(int mat[][T])
{
    int max = 0, class, i_shift;
    printf("Ingrese numero de clase: ");
    scanf("%d", &class);
    class--;
    for(int i = 0; i < T; i++)
    {
       if(mat[class][i] > max)
       {
            max = mat[class][i];
            i_shift = i;
       }
    }
    printf("El turno con más alumnos de la classe %d %s es %s con %d alumnos\n", class+1, classes[class], shifts[i_shift], max);
    return;
};

void getBiggerClassByShift(int mat[][T])
{
    int max = 0, shift, i_class;
    printf("Ingrese n° de turno: ");
    scanf("%d", &shift);
    shift--;
    for(int i = 0; i < C; i++)
    {
        if(mat[i][shift] > max)
        {
            max = mat[i][shift];
            i_class = i;
        }
    }
    printf("La clase con más alumnos en el turno %s es la clase %d %s\n", shifts[shift], i_class+1, classes[i_class]);
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
    printf("La clase con más alumnos inscriptos: %s con %d alumnos\n", classes[i_class], max);
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
    printf("El turno con más alumnos: %s\n", shifts[i_shift]);
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
