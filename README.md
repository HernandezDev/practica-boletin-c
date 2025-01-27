# Practica Boletin C

Este proyecto es un programa en C para gestionar las notas de los alumnos en varias materias. Permite registrar, mostrar, editar y eliminar notas, así como calcular promedios y guardar los datos en un archivo CSV.

## Funcionalidades

- Registrar notas de los alumnos para diferentes materias.
- Calcular y mostrar el promedio de notas de cada alumno.
- Editar las notas y los nombres de los alumnos.
- Eliminar alumnos del registro.
- Ordenar los alumnos alfabéticamente.
- Guardar los datos en un archivo CSV.

## Requisitos

- Compilador de C (como GCC)

## Uso en Windows

### Forma Rapida
1. Clona el repositorio:
    ```bash
    git clone https://github.com/HernandezDev/practica-boletin-c.git
    cd practica-boletin-c
    ```

2. Compila el programa (usando Mingw-w64):
    ```bash
    gcc main.c gestion.c -o boletin.exe  
    ```

3. Ejecuta el programa:
    ```bash
    ./boletin.exe
    ```
### Para Mejor Compatibilidad
1. Clona el repositorio:
    ```bash
    git clone https://github.com/HernandezDev/practica-boletin-c.git
    cd practica-boletin-c
    ```

2. Consulta el charset de la consola:
    ```bash
    chcp
    ```
    Esto mostrará algo como `Active code page: 850`. Toma nota del número de la página de códigos.

3. Compila el programa (usando Mingw-w64) con compatibilidad con el charset:
    ```bash
    gcc -finput-charset=UTF-8 -fexec-charset=CP850 main.c gestion.c -o boletin.exe
    ```
    Asegúrate de reemplazar `CP850` con el número de la página de códigos obtenida en el paso anterior si es diferente.

4. Ejecuta el programa:
    ```bash
    ./boletin.exe
    ```