# Practica Struct C (calificador)
Este proyecto es una aplicación en C para gestionar información de alumnos, incluyendo sus datos personales y calificaciones.

## Características

- Cargar información de alumnos
- Mostrar alumnos ordenados por promedio
- Mostrar alumnos ordenados alfabéticamente por apellido

## Requisitos

- Compilador de C como [GCC](https://gcc.gnu.org/) ([MinGW-w64](https://www.mingw-w64.org/) para Windows)

## Uso

### En Windows

#### Forma Rápida

1. Clona el repositorio:
    ```bash
    git clone https://github.com/HernandezDev/practica-struct-c.git
    cd practica-struct-c
    ```

2. Compila el programa (usando MinGW-w64):
    ```bash
    gcc main.c -o calificador.exe
    ```

3. Ejecuta el programa:
    ```bash
    ./calificador.exe
    ```

#### Para Mejor Compatibilidad

1. Clona el repositorio:
    ```bash
    git clone https://github.com/HernandezDev/practica-struct-c.git
    cd practica-struct-c
    ```

2. Consulta el charset de la consola:
    ```bash
    chcp
    ```
    Esto mostrará algo como `Active code page: 850`. Toma nota del número de la página de códigos.

3. Compila el programa (usando MinGW-w64) con compatibilidad con el charset:
    ```bash
    gcc -finput-charset=UTF-8 -fexec-charset=CP850 main.c -o calificador.exe
    ```
    Asegúrate de reemplazar `CP850` con el número de la página de códigos obtenida en el paso anterior si es diferente.

4. Ejecuta el programa:
    ```bash
    ./calificador.exe
    ```
