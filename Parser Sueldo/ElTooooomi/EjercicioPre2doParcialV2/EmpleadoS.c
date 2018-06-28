#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



Empleado* Empleado_newParametros(char* strId,char* nombre, char* strHorasTrabajadas)
{
    int id;
    int horasTrabajadas;
    Empleado* this;

    id = atoi(strId); //FALTA VALIDAR
    horasTrabajadas = atoi(strHorasTrabajadas); //FALTA VALIDAR
    this = Empleado_new();
    if( !Empleado_setId(this,id) &&
        !Empleado_setNombre(this,nombre) &&
        !Empleado_setHorasTrabajadas(this,horasTrabajadas)
       )
    {
        return this;
    }
    Empleado_delete(this);
    return NULL;
}



Empleado* Empleado_new()
{
    Empleado* this;
    this=malloc(sizeof(Empleado));
    return this;
}

void Empleado_delete(Empleado* this)
{
    free(this);
}

int Empleado_setId(Empleado* this,int id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int Empleado_getId(Empleado* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Empleado_setNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_getNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_setSueldo(Empleado* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int Empleado_getSueldo(Empleado* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}
    /**Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350 */

void em_calcularSueldo(void* p)
{
    int horasTrabajadas,horasPromedio;
    if(p!=NULL)
    {
        Empleado_getHorasTrabajadas(p,&horasTrabajadas);
        if(horasTrabajadas>=120)
        {
            horasPromedio  = 120 * 180;
            if(horasTrabajadas>=160)
            {
                horasPromedio = horasPromedio + 40*240 +(horasTrabajadas-160)*350;
            }
            else
            {
                horasPromedio = horasPromedio + (horasTrabajadas-120)*240;
            }
        }
        else
        {
            horasPromedio = horasTrabajadas*180;
        }
        Empleado_setSueldo(p,horasPromedio);
    }
}

