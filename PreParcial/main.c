#include <stdio.h>
#include <stdlib.h>
#include "valid.h"
#include "persona.h"
#include "ArrayList.h"

int main()
{
    ArrayList* pArray= al_newArrayList();
    char seguir = 's';
    char cuit[13];
    int opcion;
    while(seguir=='s')
    {
            printf("OPCIONES DE CARGA:\n1)ORDENAR POR NOMBRE\n2)PARSEAR ARCHIVO\n3)MOSTRAR ORDENADO\n4)SALIR!\n");
            getNumeroInt(7,1,&opcion,0,3,"","");
            switch(opcion){
                case 1:
                    ordenar(pArray,2,2);
                    break;
                case 2:
                    parser(pArray,"lista.txt");
                    break;
                case 3:
                    imprimirTodo(pArray,al_len(pArray));
                    break;
                case 4:
                    eliminarDuplicados(pArray);
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    seguir = 'n';
                    break;
            }
    }

    return 0;
}
