#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "estructuras.h"

void Menu () {
    //main menu display
        printf("\n*********************************\n");
        printf("* Menu principal *\n");
        printf("* ---------------- *\n");
        printf("* 1. Entrada de producto *\n");
        printf("* 2. Despacho de producto *\n");
        printf("* 3. Reporte del inventario *\n");
        printf("* 4. Listado de personas *\n");
        printf("* 5. Salir *\n");
        printf("*********************************\n\n");

}
//ComprobarCodigo and comprobarCadula, take the value of a product or person ID and try to find it in one of the structures saved, to determine if it exists 
int comprobarCodigo(struct medicamento med[100], int numMed, int codigo){

    int resultado = 0;

    for (int i=0; i<numMed; i++){
        if (med[i].codigo == codigo){
            resultado = 1;
        }
    }

    return resultado;

}
int comprobarCedula(struct personas per[100], int numPer, int cedula){

    int resultado = 0;

    for (int i=0; i<numPer; i++){
        if (per[i].cedula == cedula){
            resultado = 1;
        }
    }

    return resultado;

}
// funcion allows to create new clients, asking for name and ID number, this then gets saved int a struct array
int IngresarPersonasNuevas(struct personas pers[100],int numPer){
    int creado = 0;
    struct personas per;
    fflush(stdin);
    printf("Introduce nombre del cliente:\n");
    scanf("%s", per.nombre);

    printf("Introduce cedula del cliente:\n");
    scanf("%d",&per.cedula);


    int existe=comprobarCedula(pers, numPer, per.cedula);
    if(numPer<=100){
        if(existe == 0){
            pers[numPer] = per;
            creado = 1;
        }
        else{
            printf("No se puede crear cliente, cedula duplicada\n");
        }
    }
    else{
        printf("No se puede ingresar cliente, cantidad maxima de clientes alcanzada\n");
    }

    return creado;

}
//Same as IngresarPersonasNuevas, this functions takes all parameters of a new product and stores them into a struct array slot
int IngresarProductosNuevos(struct medicamento meds[100],int numMed){
    int creado = 0;
    struct medicamento med;
    fflush(stdin);
    printf("Introduce nombre del medicamento:\n");
    scanf("%s", med.nombre);

    printf("Introduce codigo del medicamento:\n");
    scanf("%d",&med.codigo);

    printf("Introduce el anio de caducidad:\n");
    scanf("%d",&med.anio);

    printf("Introduce unidades disponibles:\n");
    scanf("%d",&med.unidades);

    printf("Introduce unidades por caja:\n");
    scanf("%d",&med.unidadesxCaja);
//If the code is already in use, yopu cannot create another item with it
    int existe=comprobarCodigo(meds, numMed, med.codigo);
    if(numMed<=100){
        if(existe == 0){
            meds[numMed] = med;
            creado = 1;
        }
        else{
            printf("No se puede crear producto, codigo duplicado\n");
        }
    }
    else{
        printf("No se puede ingresar medicamento. Cupo alcanzado en bodega\n");
    }

    return creado;

}
//Prints the reports on each product, using the struct array that stores the data
void inventario(struct medicamento med[100], int numMed, int anio){
    char caducados[100][100], agotados[100][100];
    int contCad=0, contAg=0;
    printf("--Reporte de inventario:--\n");
    for (int i=0; i<numMed; i++){
        //prints each report for all the products stored
        printf("Nombre: %s\n", med[i].nombre);
        printf("codigo: %d\n", med[i].codigo);
        printf("Anio de caducidad: %d\n", med[i].anio);
        printf("Unidades disponibles: %d\n",med[i].unidades);
        printf("Cajas disponibles: %d\n",med[i].unidades/med[i].unidadesxCaja);
        printf("\n");
        //validates if a product is still within a consuming range of one year, if not, it warns the user to bring more
        if(med[i].anio<=anio){
            printf("****ATENCION:Producto caducado o por caducar****\n");
        }
        //Does a similar validation but for stocked items, if ther is not enough for one box, the program asks for more
        if((med[i].unidades/med[i].unidadesxCaja)<=1){
            printf("**ATENCION: Producto por acabarse, ordenar mas inmediatamente**\n");

        }
        printf("----------------------------------------\n");
        
        
    }
    
}
//Prints the list of regitered people with their ID number
void listadoPersonas(struct personas per[100], int numPer){
    for (int i=0; i<numPer; i++){
        printf("Nombre: %s\n", per[i].nombre);
        printf("No. cedula: %d\n", per[i].cedula);
        
        printf("\n");
    }
}
//This function takes care fo adding more items to an existing product code
int SumarCantidades(struct medicamento med[100], int numMed){

    int codigo;

    printf("Ingresa el codigo del medicamento que llegó\n");
    scanf("%d",&codigo);

    int existe = comprobarCodigo(med,numMed,codigo);
//If the code exists, it changes the value of unidades, so the user can add more
    if (existe == 1){
        int nuevoIngreso;
        printf("Introduce la cantidad que ha llegado\n");
        scanf("%d",&nuevoIngreso);
        for(int i=0; i<numMed; i++){
            if (med[i].codigo == codigo){
                med[i].unidades += nuevoIngreso;
                printf("Inventario Actualizado\n");
                return 1;
            }
        }

    }
    //If it doesn´t, it asks the user to create a new code, this is handled in the main.c file
    else{
        printf("El medicamento no se encuentra en bodega, ingresar los datos para crearlo:\n");
        return 0;
    }
}
//Same as the Sumar Cantidades function, this one allows the user to subtract from the existing stock
int despacho(struct medicamento med[100], int numMed, struct personas per[100], int numPer){
    int codigo, cedula;
    //it asks for an ID to know who is making the transaction
    printf("Ingresa el numero de cedula del paciente:\n");
    scanf("%d",&cedula);
    int existe1 = comprobarCedula(per,numPer,cedula);
    if (existe1 == 1){
        do{
            printf("Ingresa el codigo del medicamento solicitado, si deseas terminar la orden, presiona 0\n");
            scanf("%d",&codigo);

            int existe = comprobarCodigo(med,numMed,codigo);

            if (existe == 1){
                int nuevaSalida;
                printf("Introduce la cantidad necesitada\n");
                scanf("%d",&nuevaSalida);
                for(int i=0; i<numMed; i++){
                    if (med[i].codigo == codigo){
                        //If the stocked item is lower than the recipe, the program throws a warning
                        if(med[i].unidades<nuevaSalida){
                            printf("No hay suficientes unidades para la receta, intentar nuevamente\n");
                        }
                        else{
                            med[i].unidades -= nuevaSalida;
                            printf("Inventario Actualizado\n");
                        }
                        
                        
                    }
                }

            }
            else{
                //if the person enters 0, the loop ends, allowing the order to be finished
                if(codigo==0){
                    printf("Finalización del pedido...\n");
                }
                else{
                    printf("El medicamento no se encuentra en bodega, intente un codigo valido.\n");
                }
                
            }

            }while(codigo!=0);
    }
    else{
        //if the ID number is not registered, it asks the user to create it, in the main.c file
        printf("Cedula no existente, crear el perfil para continuar con la transaccion\n");
        return 0;
    }
    
    return 1;
    

}