#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Definiciones de preprocesador para el número máximo de alumnos y materias
#define MAX_ALUMNOS 5
#define MAX_MATERIAS 4
#define MAX_NOMBRE 50

// Funciones de la lógica
bool ComprobarNombre(char alumnos[][MAX_NOMBRE], const char nombre[], int NumAlumno);
void CalcularPromedio(int notas[][MAX_MATERIAS], float promedios[], int NumAlumno);
void IngresarNotas(int notas[][MAX_MATERIAS], char materias[][MAX_NOMBRE], int NumAlumno);
int BuscarAlumno(char alumnos[][MAX_NOMBRE]);
void CopiarNotas(int notas[][MAX_MATERIAS], int PosOutput, int PosInput);
void InicializarNotas(int notas[][MAX_MATERIAS], int posicion);
void OrdenarAlumnos(int notas[][MAX_MATERIAS], float promedios[], char alumnos[][MAX_NOMBRE], int NumAlumno);

// Funciones del menú
void RegistrarNotas(int notas[][MAX_MATERIAS], float promedios[], char alumnos[][MAX_NOMBRE], char materias[][MAX_NOMBRE], int *NumAlumno);
void MostrarNota(int notas[][MAX_MATERIAS], float promedios[], char alumnos[][MAX_NOMBRE], char materias[][MAX_NOMBRE]);
void MejorPeorPromedio(float promedios[], char alumnos[][MAX_NOMBRE], int NumAlumno);
void EditarNotas(int notas[][MAX_MATERIAS], float promedios[], char alumnos[][MAX_NOMBRE], char materias[][MAX_NOMBRE]);
void EditarNombre(char alumnos[][MAX_NOMBRE]);
void EliminarAlumno(int notas[][MAX_MATERIAS], float promedios[], char alumnos[][MAX_NOMBRE], int *NumAlumno);
void Guardar(int notas[][MAX_MATERIAS], float promedios[], char alumnos[][MAX_NOMBRE], char materias[][MAX_NOMBRE], int NumAlumno);

int main()
{
    bool salir = false;
    int NumAlumno = 0;
    int opcion;
    int notas[MAX_ALUMNOS][MAX_MATERIAS] = {0};
    float promedios[MAX_ALUMNOS] = {0.0};
    char alumnos[MAX_ALUMNOS][MAX_NOMBRE] = {0};
    char materias[MAX_MATERIAS][MAX_NOMBRE] = {"matematicas", "lengua", "sc.naturales", "sc.sociales"};

    while (!salir)
    {
        printf("1. Registrar notas de un alumno\n");
        printf("2. Mostrar notas y promedio de alumno\n");
        printf("3. Mejor y Peor promedio\n");
        printf("4. Editar notas de un alumno\n");
        printf("5. Editar nombre de un alumno\n");
        printf("6. Eliminar Alumno\n");
        printf("7. Guardar en archivo .CSV\n");
        printf("8. Salir del programa\n");
        printf("Elije opcion: ");

        // Leer la opción sin el inconveniente al ingresar un carácter
        if (scanf("%d", &opcion) != 1)
        {
            printf("Entrada no válida. Por favor, ingrese un número.\n");
            // Limpiar el buffer de entrada
            while (getchar() != '\n');
            // Volver al comienzo del bucle while para mostrar el menú
            continue;
        }

        switch (opcion)
        {
            case 1:
                RegistrarNotas(notas, promedios, alumnos, materias, &NumAlumno);
                break;
            case 2:
                MostrarNota(notas, promedios, alumnos, materias);
                break;
            case 3:
                MejorPeorPromedio(promedios, alumnos, NumAlumno);
                break;
            case 4:
                EditarNotas(notas, promedios, alumnos, materias);
                break;
            case 5:
                EditarNombre(alumnos);
                break;
            case 6:
                EliminarAlumno(notas, promedios, alumnos, &NumAlumno);
                break;
            case 7:
                Guardar(notas, promedios, alumnos, materias, NumAlumno);
                break;
            case 8:
                salir = true;
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }
    }

    return 0;
}

// Función para comprobar que un nombre no exista en el arreglo de alumnos,
// excluyendo la posición donde se va a escribir el nuevo nombre.
bool ComprobarNombre(char alumnos[][MAX_NOMBRE], const char nombre[], int NumAlumno)
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

void CopiarNotas(int notas[][MAX_MATERIAS], int PosOutput, int PosInput)
{
    // Copiar las notas de un alumno a otro
    int j;
    for (j = 0; j < MAX_MATERIAS; j++)
    {
        notas[PosOutput][j] = notas[PosInput][j];
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

                // Copiar notas auxiliares
                for (j = 0; j < MAX_MATERIAS; j++)
                {
                    AuxNotas[j] = notas[i][j];
                }
                CopiarNotas(notas, i, i + 1);
                for (j = 0; j < MAX_MATERIAS; j++)
                {
                    notas[i + 1][j] = AuxNotas[j];
                }

                // Recalcular promedios
                CalcularPromedio(notas, promedios, i);
                CalcularPromedio(notas, promedios, i + 1);

                ordenado = false;
            }
        }
        NumAlumno--;
    }
}

// Funciones del menu

void RegistrarNotas(int notas[][MAX_MATERIAS], float promedios[], char alumnos[][MAX_NOMBRE], char materias[][MAX_NOMBRE], int *NumAlumno)
{
    char opcion[2];
    if (*NumAlumno >= MAX_ALUMNOS)
    {
        printf("solo se pueden ingresar %d alumnos\n", MAX_ALUMNOS);
        return;
    }
    printf("nombre: ");
    scanf("%s", alumnos[*NumAlumno]);
    while (!ComprobarNombre(alumnos, alumnos[*NumAlumno], *NumAlumno))
    {
        printf("nombre ya ingresado\n");
        printf("nombre: ");
        scanf("%s", alumnos[*NumAlumno]);
    }
    IngresarNotas(notas, materias, *NumAlumno);
    CalcularPromedio(notas, promedios, *NumAlumno);
    // indicar el número del siguiente alumno
    (*NumAlumno)++;
    // preguntar si desea ingresar otro alumno
    printf("desea ingresar otro alumno? (s/n): ");
    scanf("%s",opcion);
    if (strcasecmp(opcion,"s")==0)
    {
        //llamar a la funcion de nuevo
        RegistrarNotas(notas, promedios, alumnos, materias, NumAlumno);
    }

}

void MostrarNota(int notas[][MAX_MATERIAS], float promedios[], char alumnos[][MAX_NOMBRE], char materias[][MAX_NOMBRE])
{
    
    int j;
    int posicion=BuscarAlumno(alumnos);
    if (posicion==-1)
    {
        return;
    }
    for ( j = 0; j < MAX_MATERIAS; j++)
    {
        printf("%s:\t%i\n",materias[j],notas[posicion][j]);  
    }
    printf("Promedio:\t%.2f\n",promedios[posicion]);
}

void MejorPeorPromedio(float promedios[], char alumnos[][MAX_NOMBRE], int NumAlumno)
{
    if (NumAlumno<=0)
    {
        printf("no hay alumnos registrados\n");
        return;
    }
    int i;
    float mejor=promedios[0];
    float peor=promedios[0];
    int posMejor=0;
    int posPeor=0;
    for ( i = 1; i < NumAlumno; i++)
    {
        if (promedios[i]>mejor)
        {
            mejor=promedios[i];
            posMejor=i;
        }
        if (promedios[i]<peor)
        {
            peor=promedios[i];
            posPeor=i;
        }
    }
    printf("Mejor promedio: %s %.2f\n",alumnos[posMejor],mejor);
    printf("Peor promedio: %s %.2f\n",alumnos[posPeor],peor);
    
}

void EditarNotas(int notas[][MAX_MATERIAS], float promedios[], char alumnos[][MAX_NOMBRE], char materias[][MAX_NOMBRE])
{
    int posicion=BuscarAlumno(alumnos);
    if (posicion==-1)
    {
        return;
    }
    IngresarNotas(notas, materias, posicion);
    CalcularPromedio(notas, promedios, posicion);
    printf("poromedio: %.2f\n",promedios[posicion]);
}

void EditarNombre(char alumnos[][MAX_NOMBRE])
{
    
    int posicion=BuscarAlumno(alumnos);
    char NuevoNombre[MAX_NOMBRE];
    if (posicion==-1)
    {
        return;
    }
    printf("nuevo nombre: ");
    scanf("%s",NuevoNombre);
    while (!ComprobarNombre(alumnos,NuevoNombre,posicion))
    {
        printf("nombre ya ingresado\n");
        printf("nuevo nombre: ");
        scanf("%s",NuevoNombre);
    }
    strcpy(alumnos[posicion], NuevoNombre);
    printf("nombre cambiado\n");
}

void EliminarAlumno(int notas[][MAX_MATERIAS], float promedios[], char alumnos[][MAX_NOMBRE], int *NumAlumno)
{
    int i;
    char opcion[2];
    int posicion=BuscarAlumno(alumnos);
    if (posicion==-1)
    {
        return;
    }
    printf("seguro que desea eliminar a %s? (s/n): ",alumnos[posicion]);
    scanf("%s",opcion);
    if (strcasecmp(opcion,"n")==0)
    {
        return;
    }
    
    for ( i = posicion; i < MAX_ALUMNOS; i++)
    {
        CopiarNotas(notas, i, i+1);
        strcpy(alumnos[i], alumnos[i+1]);
        promedios[i]=promedios[i+1];
    }
    //Incializar ultimo elemento del arreglo
        InicializarNotas(notas, MAX_ALUMNOS-1);
        strcpy(alumnos[MAX_ALUMNOS-1], "");
        promedios[MAX_ALUMNOS-1]=0;

    (*NumAlumno)--;
    printf("alumno eliminado\n");

}

void Guardar(int notas[][MAX_MATERIAS], float promedios[], char alumnos[][MAX_NOMBRE], char materias[][MAX_NOMBRE], int NumAlumno)
{
    FILE *archivo;
    int i ,j;
    archivo=fopen("notas.csv","w");
    OrdenarAlumnos(notas, promedios, alumnos, NumAlumno);
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo para escritura.\n");
        return;
    }
    fprintf(archivo,"nombre,");
    for ( i = 0; i < MAX_MATERIAS; i++)
    {
        fprintf(archivo,"%s,",materias[i]);
    }  
    fprintf(archivo,"promedio\n");
    for ( i = 0; i < NumAlumno; i++)
    {
        fprintf(archivo,"%s,",alumnos[i]);
        for ( j = 0; j < MAX_MATERIAS; j++)
        {
            fprintf(archivo,"%i,",notas[i][j]);
        }
        fprintf(archivo,"%.2f\n",promedios[i]);
    }
    fclose(archivo);
    printf("Datos guardados en notas.csv\n");
}