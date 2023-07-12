#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "estructuras.h"

void Menu () {
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

void inventario(struct medicamento med[100], int numMed, int anio){
    char caducados[100][100], agotados[100][100];
    int contCad=0, contAg=0;
    printf("--Reporte de inventario:--\n");
    for (int i=0; i<numMed; i++){
        printf("Nombre: %s\n", med[i].nombre);
        printf("codigo: %d\n", med[i].codigo);
        printf("Anio de caducidad: %d\n", med[i].anio);
        printf("Unidades disponibles: %d\n",med[i].unidades);
        printf("Cajas disponibles: %d\n",med[i].unidades/med[i].unidadesxCaja);
        printf("\n");
        if(med[i].anio<=anio){
            printf("****ATENCION:Producto caducado o por caducar****\n");
        }
        if((med[i].unidades/med[i].unidadesxCaja)<=1){
            printf("**ATENCION: Producto por acabarse, ordenar mas inmediatamente**\n");

        }
        printf("----------------------------------------\n");
        
        
    }
    
}
void listadoPersonas(struct personas per[100], int numPer){
    for (int i=0; i<numPer; i++){
        printf("Nombre: %s\n", per[i].nombre);
        printf("No. cedula: %d\n", per[i].cedula);
        
        printf("\n");
    }
}

int SumarCantidades(struct medicamento med[100], int numMed){

    int codigo;

    printf("Ingresa el codigo del medicamento que llegó\n");
    scanf("%d",&codigo);

    int existe = comprobarCodigo(med,numMed,codigo);

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
    else{
        printf("El medicamento no se encuentra en bodega, ingresar los datos para crearlo:\n");
        return 0;
    }
}

int despacho(struct medicamento med[100], int numMed, struct personas per[100], int numPer){
    int codigo, cedula;
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
        printf("Cedula no existente, crear el perfil para continuar con la transaccion\n");
        return 0;
    }
    
    return 1;
    

}