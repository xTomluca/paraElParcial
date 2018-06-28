#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Empleado.h"

int parser_parseEmpleados(char* fileName, ArrayList* listaEmpleados)
{
    Empleado* aux;
    char id[50];
    char nombre[50];
    char horasTrabajadas[50];
    int testId;
    int testHoras;
    char testNombre[50];
    FILE* fp;
    fp = fopen("data.csv","r");
    fscanf(fp,"%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas);
    do{
        fscanf(fp,"%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas);
        aux = Empleado_newParametros(id,nombre,horasTrabajadas);
        al_add(listaEmpleados,aux);
        Empleado_getId(aux,&testId);
        Empleado_getHorasTrabajadas(aux,&testHoras);
        Empleado_getNombre(aux,testNombre);
        printf("\n%d - %s - %d",testId,testNombre,testHoras);
    }while(!feof(fp));

    return 1; // OK
}

