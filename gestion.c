#include "gestion.h"
#include <string.h>
#include <stdio.h>

/// Función para comprobar que un nombre no exista en el arreglo de alumnos,
// excluyendo la posición donde se va a escribir el nuevo nombre.
bool ComprobarNombre(char alumnos[][MAX_NOMBRE], char nombre[], int NumAlumno)
{
    // Comprueba si el nombre no fue ingresado antes
    int i;
    for (i = 0; i < MAX_ALUMNOS; i++)
    {
        if (strcasecmp(nombre, alumnos[i]) == 0 && i != NumAlumno)
        {
            return false;
        }
    }
    return true;
}

void CalcularPromedio(int notas[][MAX_MATERIAS], float promedios[], int NumAlumno)
{
    int j;
    promedios[NumAlumno] = 0;
    for (j = 0; j < MAX_MATERIAS; j++)
    {
        promedios[NumAlumno] += notas[NumAlumno][j];
    }
    promedios[NumAlumno] /= MAX_MATERIAS;
}

void IngresarNotas(int notas[][MAX_MATERIAS], char materias[][MAX_NOMBRE], int NumAlumno)
{
    int j;
    for (j = 0; j < MAX_MATERIAS; j++)
    {
        printf("Nota en %s: ", materias[j]);
        scanf("%d", &notas[NumAlumno][j]);
    }
}

int BuscarAlumno(char alumnos[][MAX_NOMBRE])
{
    char nombre[MAX_NOMBRE];
    printf("Ingrese el nombre del alumno a buscar: ");
    scanf("%s", nombre);

    for (int i = 0; i < MAX_ALUMNOS; i++)
    {
        if (strcasecmp(alumnos[i], nombre) == 0)
        {
            return i;
        }
    }
    printf("nombre no encontrado\n");
    return -1;
}

void CopiarNotas(int notas[][MAX_MATERIAS], int PosOutput[], int PosInput[])
{
    // Copiar las notas de un alumno a otro
    int j;
    for (j = 0; j < MAX_MATERIAS; j++)
    {
        PosOutput[j] = PosInput[j];
    }
}

void InicializarNotas(int notas[][MAX_MATERIAS], int posicion)
{
    // Inicializar las notas de un alumno
    int j;
    for (j = 0; j < MAX_MATERIAS; j++)
    {
        notas[posicion][j] = 0;
    }
}

void OrdenarAlumnos(int notas[][MAX_MATERIAS], float promedios[], char alumnos[][MAX_NOMBRE], int NumAlumno)
{
    // ordenar los alumnos alfabeticamente
    bool ordenado = false;
    int i, j;
    char AuxNombre[MAX_NOMBRE];
    int AuxNotas[MAX_MATERIAS];
    float AuxPromedio;
    while (!ordenado)
    {
        ordenado = true;
        for (i = 0; i < NumAlumno - 1; i++)
        {
            if (strcasecmp(alumnos[i], alumnos[i + 1]) > 0)
            {
                // Intercambiar nombres
                strcpy(AuxNombre, alumnos[i]);
                strcpy(alumnos[i], alumnos[i + 1]);
                strcpy(alumnos[i + 1], AuxNombre);

                // Intercambiar notas
                CopiarNotas(notas, AuxNotas, notas[i]);
                CopiarNotas(notas, notas[i], notas[i + 1]);
                CopiarNotas(notas, notas[i + 1], AuxNotas);

                // Intercambiar promedios
                AuxPromedio = promedios[i];
                promedios[i] = promedios[i + 1];
                promedios[i + 1] = AuxPromedio;

                ordenado = false;
            }
        }
        NumAlumno--;
    }
}