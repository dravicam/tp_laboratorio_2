#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcion.h"

#define R 20


//void mostrarGrafico(ePersona[]);
void ordenarPersona(ePersona[], int);

int main()
{
    ePersona Persona[R];

    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        switch(menu())
        {
            case 1:
                altaPersona(Persona, R);
                system("pause");
                break;

            case 2:
                bajaPersona(Persona, R);
                system("pause");
                break;

            case 3:
                ordenarPersona(Persona, R);
                system("pause");
                break;

            case 4:
                //mostrarGrafico(Persona);
                system("pause");
                break;

            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

void ordenarPersona(ePersona persona[], int tam)
{
    int i;
    int j;
    for(i=0; i<R-1; i++)
    {
        char auxC[50];
        long int auxD;
        int auxE;
        for(j=i+1; j<R; j++)
        {
            if(strcmp(persona[i].nombre, persona[j].nombre)<0)
            {
            strcpy(auxC, persona[i].nombre);
            strcpy(persona[i].nombre, persona[j].nombre);
            strcpy(persona[j].nombre, auxC);

            auxD = persona[i].dni;
            persona[i].dni = persona[j].dni;
            persona[j].dni = auxD;

            auxE = persona[i].edad;
            persona[i].edad = persona[j].edad;
            persona[j].edad = auxE;
            }
        }
    }
    for(i=0; i<R*0.1; i++)
    {
        printf(" Documento  Nombre y Apellido   Edad \n\n");
        mostrarPersonas(persona, tam);
    }
}



/*
void mostrarGrafico(ePersona personas[])
{
    int i;
    int flag=0;
    int ninios;
    int jovenes;
    int adultos;
    int may;

    ninios = (edad <= 18 && edad >=1);
    jovenes = (edad <= 35 && edad >=19);
    adultos = (edad <= 100 && edad >=36);

    if(ninios >= jovenes && ninios >= adultos)
    {
        personas = ninios;
    }
    else
    {
        if(jovenes >= ninios && jovenes >= adultos)
        {
            personas = jovenes;
        }
        else
        {
            personas = adultos;
        }
    }

    for(i=personas; i>0; i--)
    {
        if(i<10)
        {
            printf("%02d|",i);
        }
        else
            printf("%02d|",i);

        if(i<= ninios)
        {
            printf("*");
        }
        if(i<= jovenes)
        {
            flag=1;
            printf("\t*");
        }
        if(i<= adultos)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }

        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d", ninios, jovenes, adultos);
}*/
