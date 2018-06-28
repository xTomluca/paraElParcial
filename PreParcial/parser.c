#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
int parser(void* pArray, char* path)
{
    FILE* fp;
    fp = fopen(path,"r");
    int retorno = -1;
    int cantidad = 0;
    int test;
    if(fp!=NULL)
    {
        while(!feof(fp))
        {
           // char bId[10];
            char bName[50];
            char bHoras[10];
            char bSueldo[10];
            /**Empleado* aux;*/
            cantidad = fscanf(fp,"%[^,],%[^,],%[^\n]\n"/*,bId*/,bName,bHoras,bSueldo);
            if(cantidad==3)
            {
                printf("\n\nTEST PARA PERSONA %s %s %s\n"/*,bId*/,bName,bHoras,bSueldo);
                aux = persona_newConParametrosStr(/*bId,*/bName,bHoras,bSueldo);
                if(aux==NULL)
                    exit(1);
                test=al_add(pArray,aux);
                printf("\n\nTEST ADD %d\n",test);
                retorno = 0;
            }
        }
        fclose(fp);
    }
    return retorno;
}


