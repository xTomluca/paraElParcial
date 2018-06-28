#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"



int main()
{
    ArrayList* destinatarios = al_newArrayList();
    ArrayList* blackList = al_newArrayList();


    parserEmployee("destinatarios.csv", destinatarios);


    return 0;
}





int comparoDest(void* el0, void* el1)
{
    char mail0[128];
    char mail1[128];

    // el0->nombre NO
    Dest* el0Dest = (Dest*)el0;
    Dest* el1Dest = (Dest*)el1;

    //el0Dest->name NO
    dest_getEmail(el0Dest,mail0);
    dest_getEmail(el1Dest,mail1);

    return strcmp(mail0,mail1);

}

















int i;
for(i=0; i<al_len(blackList); i++)
{
    Dest* dListaNegra = al_get(blackList,i);

    int index= al_indexOfElement(destinatarios,dListaNegra,comparoDest);

    al_remove(destinatarios,index);
}
















int al_indexOfElement(
                      ArrayList* this,
                      void* item,
                      int(*fnComparar)(void*,void*)
                     )
{

    int i;
    int ret=-1;
    for(i=0; i<this->size; i++)
    {
        //if(this->pElements[i]==item)
        if(fnComparar(this->pElements[i],item)==0)
            ret =i;
    }
    return ret;
}














