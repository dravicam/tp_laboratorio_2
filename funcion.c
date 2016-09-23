#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcion.h"

#define R 20



int menu()
{
    int opcion=0;
    system("cls");
    printf("***Menu de opciones***\n\n");
    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Imprimir lista ordenada por  nombre\n");
    printf("4- Imprimir grafico de edades\n");
    printf("5- Salir\n");
    printf("\nElija la opcion: ");
    scanf("%d",&opcion);
    return opcion;
}


void mostrarPersona(ePersona unaPersona)
{
    printf("%10ld  %10s     %4d   \n",unaPersona.dni, unaPersona.nombre, unaPersona.edad);
}


void mostrarPersonas(ePersona personas[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(personas[i].estado == 1)
        {
            mostrarPersona(personas[i]);
        }
    }
    printf("\n\n");
}


void inicializarPersonas(ePersona personas[], int tam)
{
     int i;
     for(i=0; i<tam; i++)
     {
       personas[i].estado = 0;
     }

}


int buscarLibre(ePersona personas[], int tam)
{
    int indice =-1;
    int i;

    for(i=0; i< tam; i++)
    {
        if(personas[i].estado ==0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int buscarPersona(ePersona personas[], int tam, int dni)
{
    int indice =-1;
    int i;

    for(i=0; i< tam; i++)
    {
        if(personas[i].dni == dni)
        {
            indice = i;
            break;
        }
    }
    return indice;

}


void altaPersona(ePersona personas[], int tam)
{
    int indice;
    int dni;
    int esta;

    indice = buscarLibre(personas, tam);

    if(indice == -1)
    {
        printf("\nNo hay lugar disponible\n");
    }
    else
    {
        printf("\nIngrese DNI: ");
        scanf("%d", &dni);

        esta = buscarPersona(personas, tam, dni);

        if(esta != -1)
        {
            printf("\nLa persona ya esta en el sistema\n");
        }
        else
        {
            personas[indice].dni = dni;

            printf("\nIngrese el nombre completo: ");
            fflush(stdin);
            gets(personas[indice].nombre);

            printf("\nIngrese edad: ");
            scanf("%d", &personas[indice].edad);

            personas[indice].estado = 1;

            printf("\nPersona agregada con exito!!!\n\n");
        }
    }
}


void bajaPersona(ePersona persona[], int tam)
{



    int indice;
    int dni;
    char baja;

    printf("\nIngrese DNI: ");
    scanf("%ld", &dni);

    indice = buscarPersona(persona, tam, dni);

    if(indice == -1)
    {
        printf("\nLa persona de indice %ld no se encuentra en el sistema\n\n", dni);
    }
    else
    {
        printf("\nDatos de la persona\n\n");
        printf(" Documento  Nombre y Apellido   Edad \n\n");
        mostrarPersona(persona[indice]);

        printf("\n\nConfirma la baja de la persona? Si(s) / No(n): ");
        fflush(stdin);
        scanf("%c", &baja);

        if(baja == 's')
        {
            persona[indice].estado = 2;
        }
        else
        {
            printf("\n\nLa baja ha sido cancelada por el usuario\n\n");
        }
    }
}
