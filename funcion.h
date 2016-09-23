#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[50];
    int edad;
    long int dni;
    int estado;
}ePersona;

int menu();
void mostrarPersona(ePersona);
void mostrarPersonas(ePersona[], int);
void inicializarPersonas(ePersona[], int);
int buscarLibre(ePersona[], int);
int buscarPersona(ePersona[], int, int);
void altaPersona(ePersona[], int);
void bajaPersona(ePersona[], int);

