#include <stdio.h>
#include <string.h>

typedef struct 
{ 
    int id;
    char nom_empl[30];
    char emp[30];
    float sueldo;
    int DNI;
} Empresa;

#define filename_original "empresas.dat"
#define filename_nuevo "empresas_aux.dat"

void identificarEmpresa(FILE *original);
void borrarEmpresa(FILE *original, FILE *nuevo);

int main()
{
    FILE *aux;
	FILE *fp = fopen(filename_original, "rb+");
	if(fp == NULL)
	{
		printf("No se pudo abrir el archivo");
		return 1;
	}
    identificarEmpresa(fp);
    aux = fopen(filename_nuevo, "wb");
    if(aux == NULL)
    {
        printf("No se pudo abrir el archivo");
        return 1;
    }
    borrarEmpresa(fp, aux);

    fclose(fp);
    fclose(aux);
	remove(filename_original);
    rename(filename_nuevo, filename_original);

	return 0;
}

void identificarEmpresa(FILE *original) 
{
    char targ[40];
    Empresa aux;
 
    printf("ingrese empresa a eliminar: ");
    fgets(targ, sizeof(targ), stdin);
    targ[strcspn(targ, "\n")] = '\0';

    while (fread(&aux, sizeof(Empresa), 1, original)) 
    {
 	    if (strcmp (aux.emp, targ) == 0){
 		    aux.DNI = -1;
 		    fseek(original, -sizeof(Empresa), SEEK_CUR);
 		    fwrite(&aux, sizeof(Empresa), 1, original);
 	    }
    }
    rewind(original);
    return;
};

void borrarEmpresa(FILE *original, FILE *nuevo) 
{
    Empresa aux;
    while (fread(&aux, sizeof(Empresa), 1, original)) 
    {
        if (aux.DNI != -1) 
        {
            fwrite(&aux, sizeof(Empresa), 1, nuevo);
        }
    }
    return;
}
