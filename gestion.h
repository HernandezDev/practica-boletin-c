#ifndef GESTION_H
#define GESTION_H

#include <stdbool.h>

#define MAX_ALUMNOS 5
#define MAX_MATERIAS 4
#define MAX_NOMBRE 50

// Funciones de la lógica
bool ComprobarNombre(char alumnos[][MAX_NOMBRE], char nombre[], int NumAlumno);
void CalcularPromedio(int notas[][MAX_MATERIAS], float promedios[], int NumAlumno);
void IngresarNotas(int notas[][MAX_MATERIAS], char materias[][MAX_NOMBRE], int NumAlumno);
int BuscarAlumno(char alumnos[][MAX_NOMBRE]);
void CopiarNotas(int notas[][MAX_MATERIAS], int PosOutput[], int PosInput[]);
void InicializarNotas(int notas[][MAX_MATERIAS], int posicion);
void OrdenarAlumnos(int notas[][MAX_MATERIAS], float promedios[], char alumnos[][MAX_NOMBRE], int NumAlumno);

#endif // GESTION_H