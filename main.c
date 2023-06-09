#include <stdio.h>
#include <stdlib.h>
#include "archivos.h"


int main()
{
    int opcion=0, anio;
    struct medicamento med[100];
    struct personas per[100];
    
    int numMed=0;
    int numPer=0;
//store in local structs the values of the files, for easier processing
    numMed=cargarMedicamentos(med);
    numPer=cargarPersonas(per);

    printf("Bienvenido al sistema de inventario automatico! por favor ingrese el anio actual:\n"); 
    //We ask for a year so we can determine if the products are still within consuming range 
    scanf("%d", &anio);
    do{
        Menu();
        scanf("%d", &opcion);
       // menu switch, based on functions from funciones.c
        switch(opcion){
        case 1:
            printf("Orden de ingreso\n");
            int nuevo=SumarCantidades(med, numMed);
            if(!nuevo){
                int creado = IngresarProductosNuevos(med, numMed);
                if (creado == 1){
                    numMed++;
                }

            }
            
            break;
        case 2:
            printf("Orden de despacho\n");
            int nuevaP=despacho(med, numMed, per, numPer);
            if(!nuevaP){
                int creado = IngresarPersonasNuevas(per, numPer);
                if (creado == 1){
                    numPer++;
                }

            }
            break;
        case 3:
            printf("INVENTARIO: \n");
            inventario(med, numMed, anio);
            break;

        case 4:
            printf("Listado Personas: \n");
            listadoPersonas(per, numPer);
            break;
        }
    }while(opcion!=5);
    
    //The structs are stored into the files again, saving the changes made
    guardarMedicamentos(med, numMed);
    guardarPersonas(per, numPer);
    printf("GRACIAS POR SU TRANSACCION, QUE LE VAYA MUY BIEN!\n\n");
    return 0;
}