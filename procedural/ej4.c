#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define E 2 // real 4
#define S 3 // real 8

void insertGrades(int mat[S][E], char opt);
void getStudentCondition(int mat[S][E]);
void showStudentCondition(int std, float avg);
void getExamsPerformance(int mat[S][E]);
void showExamsPerformance(int mat[S][E]);
void getBestWorstGrade(int mat[S][E]);
void getFreeStudents(int mat[S][E]);
void fixWrongData(int mat[S][E]);
void insertCorrectData(int *grade);
void getInsertionMode(char *opt);
int myRand(int min, int max);

int main()
{
    int std_grades[S][E];
    char option;
    getInsertionMode(&option);
    printf("Opción elegida %c\n", option);
    insertGrades(std_grades, option);
    getStudentCondition(std_grades);
    getExamsPerformance(std_grades);
    getBestWorstGrade(std_grades);
    getFreeStudents(std_grades);
    fixWrongData(std_grades);
    return 0;
};

void getInsertionMode(char *opt)
{
    do
    { 
        printf("Insert 'M' for manual insertion of data or 'A' for automatic insertion: ");
        scanf("%c", opt);
    }
    while(*opt != 'M' && *opt != 'A');
    return;
};

void insertGrades(int mat[S][E], char opt)
{
    for(int i = 0; i < S; i++)
    {
        for(int j = 0; j < E; j++)
        {
            switch(opt)
            {
                case 'M':
                    printf("Studen %d | Exam %d\n Insert grade: ", (i+1), (j+1));
                    scanf("%d", &mat[i][j]);
                    break;
                case 'A':
                    printf("Inserting data automaticlly");
                    mat[i][j] = myRand(0,10);
                    break;
            }
        }
    }
    return;
};

int myRand(int min, int max) 
{
    return (rand() % (max - min + 1)) + min;
};

float getStudentAvg(int mat[])
{
    float avg = 0;
        for(int j = 0; j < E; j++)
        {
            avg += mat[j];
        }
    return (avg / E);
};

void getStudentCondition(int mat[S][E])
{
    float avg;
    for(int i = 0; i < S; i++)
    {
        avg = getStudentAvg(mat[i]);
        showStudentCondition((i+1), avg);
    }
    return;
};

char* checkStudentCondition(float avg)
{
    if(avg >= 7) return "Promocional";
    else if(avg >= 4) return "Regular";
    else return "Libre";
};

void showStudentCondition(int std, float avg)
{
    printf("El estudiante %d esta con condición %s\n", std, checkStudentCondition(avg));
};

void getExamsPerformance(int mat[S][E])
{
    float min = 10, max = 0;
    int i_min, i_max;
    for(int i = 0; i < E; i++)
    {
        float avg = 0;
        for(int j = 0; j < S; j++)
        {
            avg += mat[j][i];
        }
        avg = (avg / S);
        if(avg > max)
        {
            max = avg;
            i_max = i;
        }
        if(avg < min)
        {
            min = avg;
            i_min = i;
        }
        printf("Promedio de la comision en el examen %d es de %.2f\n", (i+1), avg);
    }
    return;
};

void getBestWorstGrade(int mat[S][E])
{
    float min = 10, max = 0;
    int s_min, s_max;
    int e_min, e_max;
    int val;
    for (int i = 0; i < S; i++)
    {
        for(int j = 0; j < E; j++)
        {
            val = mat[i][j];
            if(val > max)
            {
                max = val;
                s_max = i;
                e_max = j;
            }
            if(val < min)
            {
                min = val;
                s_min = i;
                e_min = j;
            }
        }
    }
    printf("El mejor examen fue del alumno %d en el examen %d con nota %.2f\n", s_max+1, e_max+1, max);
    printf("El peor examen fue del alumno %d en el examen %d con nota %.2f\n", s_min+1, e_min+1, min);
    return;
};

void getFreeStudents(int mat[S][E])
{
    int count = 0;
    float avg;
    for (int i = 0; i < S; i++)
    {
        avg = getStudentAvg(mat[i]);
        if (avg < 4) count++;
    }
    printf("Hay %d alumnos con condición Libre\n", count);
    return;
};

void fixWrongData(int mat[S][E])
{
    for(int i = 0; i < S; i++)
    {
        for(int j = 0; j < E; j++)
        {
            while(mat[i][j] <= 0)
            {
                printf("Se ha detectado un error en el exament %d del alumno %d\n Ingrese una nota correcta: ", (j+1), (i+1));
                scanf("%d", &mat[i][j]);
            }
        }
    }
    return;
};
