#include <stdio.h>
#include <stdlib.h>
#include "archivos.h"

int main()
{
    int opcion=0;
    int numMed=0, numPer=0;
    struct medicamento meds[100];
    struct personas pers[100];
    numMed=cargarMedicamentos(meds);
    numPer=cargarPersonas(pers);

    do{
        Menu();
        scanf("%d", &opcion);
        switch(opcion){
        case 1:
            printf("Orden de ingreso\n");
            int creado=IngresoProductos(meds, numMed);
            if(creado==1){
                numMed++;
            }
            break;
        case 2:
            printf("Orden de despacho\n");
            despacho(meds, numMed, pers, numPer);
            break;
        case 3:
            printf("INVENTARIO: \n");
            Inventario(meds, numMed);
            break;

        case 4:
            printf("Listado Personas: \n");
            Personas(pers, numPer);
            break;
        }
    }while(opcion!=5);
    guardarMedicamentos(meds, numMed);
    guardarPersonas(pers, numPer);
    printf("GRACIAS POR SU TRANSACCION, QUE LE VAYA MUY BIEN!\n\n");
    return 0;
}
