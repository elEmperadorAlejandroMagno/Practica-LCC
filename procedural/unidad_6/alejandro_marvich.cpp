#include <stdio.h>
#include <stdlib.h>

#define demora_prolongada 60

typedef struct Paciente 
{
    int historia_clinica;
    char codigo_urgencia;
    int tiempo_espera;
    struct Paciente* sig;
} Paciente;

void cargarPacientes(Paciente *&lista);
int obtenerMetricas(Paciente *lista, int *min_espera, int &pacientes_demora);
int buscarPaciente(Paciente *lista, int n_hclinica, int &tiempo_espera);
void mostrarMetricas(int pacientes_L, int min_espera, int pacientes_demora);
void mostrarPaciente(int nivel_urgencia, int tiempo_espera);
void eliminarListaRec(Paciente *&lista);

int main()
{
    Paciente *lista = NULL;
    int pacientes_L, min_espera = 99999, pacientes_demora = 0, n_hclinica, tiempo_espera, nivel_urgencia;
    cargarPacientes(lista);
    pacientes_L = obtenerMetricas(lista, &min_espera, pacientes_demora);
    mostrarMetricas(pacientes_L, min_espera, pacientes_demora);
    printf("Ingrese el Numero de Historia Clinica a buscar: ");
    scanf("%d", &n_hclinica);
    nivel_urgencia = buscarPaciente(lista, n_hclinica, tiempo_espera);
    mostrarPaciente(nivel_urgencia, tiempo_espera);
    eliminarListaRec(lista);
    return 0;
}

void cargarPacientes(Paciente *&lista) 
{
    Paciente *nuevo;
    int historia_clinica;
    char codigo_urgencia;
    int tiempo_espera;
 
    printf("Ingrese Numero de Historia Clinica (0 para finalizar): ");
    scanf("%d", &historia_clinica);
    while(historia_clinica != 0) 
    {
        printf("Ingrese Codigo de Urgencia (C, M, L): ");
        scanf(" %c", &codigo_urgencia);
        printf("Ingrese Tiempo de Espera en Guardia (minutos): ");
        scanf(" %d", &tiempo_espera);

        nuevo = (Paciente*)malloc(sizeof(Paciente));
        nuevo->historia_clinica = historia_clinica;
        nuevo->codigo_urgencia = codigo_urgencia;
        nuevo->tiempo_espera = tiempo_espera;
        nuevo->sig = lista;
        lista = nuevo;

        printf("Ingrese Numero de Historia Clinica (0 para finalizar): ");
        scanf(" %d", &historia_clinica);
    };
    return;
}

int obtenerMetricas(Paciente *lista, int *min_espera, int &pacientes_demora) 
{
    int pacientes_L = 0;

    if (lista != NULL) 
    {
        pacientes_L = obtenerMetricas(lista->sig, min_espera, pacientes_demora);

        if (lista->codigo_urgencia == 'L') 
        {
            pacientes_L++;
        }
        if (lista->tiempo_espera < *min_espera) 
        {
            *min_espera = lista->tiempo_espera;
        }
        if (lista->tiempo_espera > demora_prolongada) 
        {
            pacientes_demora++;
        }
    }

    return pacientes_L;
}

int buscarPaciente(Paciente *lista, int n_hclinica, int &tiempo_espera) 
{
    if (lista == NULL) return -1;
    else 
    {
        if (lista->historia_clinica == n_hclinica) 
        {
            tiempo_espera = lista->tiempo_espera;
            if (lista->codigo_urgencia == 'C') return 1;
            else return 0;
        }
        else return buscarPaciente(lista->sig, n_hclinica, tiempo_espera);
    }
};

void mostrarMetricas(int pacientes_L, int min_espera, int pacientes_demora) 
{   
    if (pacientes_L >= 0 && min_espera >= 0 && pacientes_demora >= 0) 
    {
        printf("Metricas de la guardia:\n");
        printf("Cantidad de pacientes con nivel de urgencia L: %d\n", pacientes_L);
        printf("Tiempo minimo de espera en la guardia: %d minutos\n", min_espera);
        printf("Cantidad de pacientes con demora prolongada: %d\n", pacientes_demora);
    } else 
    {
        printf("Error: No se pudieron calcular las metricas correctamente.\n");
    }
}

void mostrarPaciente(int nivel_urgencia, int tiempo_espera) 
{
    if (nivel_urgencia == -1) 
    {
        printf("El paciente no se encuentra en la lista.\n");
        return;
    }
    printf("El paciente es de nivel de urgencia %d y su tiempo de espera fue de %d minutos.\n", nivel_urgencia, tiempo_espera); 
}

void eliminarListaRec(Paciente *&lista)
{
    if (lista != NULL) 
    {
        eliminarListaRec(lista->sig);
        free(lista);
        lista = NULL; 
    }
}
