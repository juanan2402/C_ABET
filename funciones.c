#include<stdio.h>
#include<stdlib.h>


struct medicamento{
    char nombre[100];
    int codigo;
    int lote;
    int unidades;
    int unidadesxCaja;
};
struct personas{

    char nombre[100];
    int cedula;
};
int comprobarCodigo(struct medicamento med[100], int numMed, int codigo);
int comprobarCedula(struct personas per[100], int numPer, int cedula);
void modificarCantidades(struct medicamento med[100], int numMed, int codigo);
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
void Inventario(struct medicamento meds[100], int numMeds){
    for (int i=0; i<numMeds; i++){
        printf("Nombre: %s\n", meds[i].nombre);
        printf("codigo del medicamento: %d\n", meds[i].codigo);
        printf("lote: %d\n", meds[i].lote);
        printf("Unidades disponibles: %d\n",meds[i].unidades);
        printf("cajas disponibles: %d\n",meds[i].unidades/meds[i].unidadesxCaja);
        printf("**********************************\n");

    }

}
void Personas(struct personas per[100], int numPer){
    for (int i=0; i<numPer; i++){
        printf("Nombre: %s\n", per[i].nombre);
        printf("cedula: %d\n", per[i].cedula);
        printf("**********************************\n");
    }

}

int IngresoProductos(struct medicamento med[100], int numMed){

    int creado=0;
    struct medicamento m;
    fflush(stdin);
    printf("introducir codigo del medicamento:\n");
    scanf("%d", &m.codigo);
    int existe=comprobarCodigo(med, numMed, m.codigo);
    if (numMed<100){
        if(existe==0){
            printf("introducir nombre del medicamento:\n");
            scanf("%s", m.nombre);
            printf("introducir lote del medicamento:\n");
            scanf("%d", &m.lote);
            printf("introducir unidades ingresadas del medicamento:\n");
            scanf("%d", &m.unidades);
            printf("Especificar cuantas unidades hay por caja\n");
            scanf("%d", &m.unidadesxCaja);
            med[numMed]=m;
            creado=1;
            }
        else{
            int eliminado=0;
            int codigo, indice;
            codigo=m.codigo;
            int existe = comprobarCodigo(med,numMed,codigo);
            if (existe == 1){
                int entrada;
                printf("Introduce la cantidad en unidades que se aumentan\n");
                scanf("%d",&entrada);
                for(int i=0; i<numMed; i++){
                    if (med[i].codigo == codigo){
                        med[i].unidades = med[i].unidades+entrada;
                        printf("Cantidades actualizadas\n");
                    }
                }

            }
            else{
                printf("No se puede modificar el medicamento, no existe el codigo\n");
            }
        }

    }
    else{
        printf("limite de medicamentos en bodega\n");
    }


    return creado;
}


int IngresoPersonas(struct personas per[100], int numPer){

    int creado=0;
    struct personas p;
    fflush(stdin);
    printf("introducir nombre del cliente:\n");
    scanf("%s", p.nombre);
    printf("introducir la cedula del cliente:\n");
    scanf("%d", &p.cedula);
    int existe=comprobarCedula(per, numPer, p.cedula);
    if (numPer<100){
        if(existe==0){
            per[numPer]=p;
            creado=1;
            }
        else{
            printf("Cedula duplicada\n");
        }

    }
    else{
        printf("limite de personas alcanzado\n");
    }
    return creado;
}

void despacho(struct medicamento med[100], int numMed, struct personas per[100], int numPer){
    int eliminado=0;
    int codigo, indice, cedula;
    printf("Ingresar el numero de cedula que desea comprar\n");
    scanf("%d",&cedula);
        int existePer = comprobarCedula(per,numPer,cedula);
        if (existePer == 1){
                do{
                    printf("Introduce el codigo del medicamento\n");
                    scanf("%d",&codigo);
                    int existe = comprobarCodigo(med,numMed,codigo);
                    if (existe == 1){
                        int salida;
                        printf("Introduce la cantidad en unidades que deseas quitar\n");
                        scanf("%d",&salida);
                        for(int i=0; i<numMed; i++){
                            if (med[i].codigo == codigo){
                                med[i].unidades = med[i].unidades-salida;
                                printf("Cantidades actualizadas\n");
                            }
                        }

                    }
                    else{
                        printf("No se puede modificar el medicamento, no existe el codigo\n");
                    }
        }while(codigo!=0);
        }
        else{
            IngresoPersonas(per, numPer);
            printf("Usuario registrado, ingrese nuevamente para registrar su entrega\n");
            guardarPersonas(per, numPer);
        }


}


int comprobarCodigo(struct medicamento med[100], int numMed, int codigo){

    int resultado = 0;

    for (int i=0; i<numMed; i++){
        if (med[i].codigo== codigo){
            resultado = 1;
        }
    }

    return resultado;

}
int comprobarCedula(struct personas per[100], int numPer, int cedula){

    int resultado = 0;

    for (int i=0; i<numPer; i++){
        if (per[i].cedula== cedula){
            resultado = 1;
        }
    }

    return resultado;

}
