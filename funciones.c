#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void ticket_de_recibo(){

}
int existe_producto(){
    
}
void creacion_de_producto(char productos []){
    FILE *medicamentos;
    medicamentos = fopen("medicamentos.txt", "r+");
    int numMed, lote, cantidadIndividual, cantidadCajas, pos;
    char nombre[50];
    do {
    printf("Ingrese el nombre del medicamento:\n");
    scanf("%s",nombre);
    if(existe_producto()!=0){

    }
    printf("Ingrese el lote:\n");
    scanf("%d",&lote);
    printf("Ingrese la cantidad individual recibida:\n");
    scanf("%d",&cantidadIndividual);
    printf("Ingrese la cantidad de medicamentos por caja:\n");
    scanf("%d",&cantidadCajas);
        numMed++;
        fprintf(medicamentos, "%d %s \n", numMed nombre);
    }
    printf("el torneo sera de %d equipos\n", numequipo);
    fclose(equipo);
    return numequipo;


}

void creacion_de_cliente(){

}
void transaccion_entrada(){

}
void transaccion_salida(){

}

void vectorMeds(char meds[][100], int numMed){
    FILE *medicamentos;
    medicamentos= fopen("medicamentos.txt", "r+");
    
    if (medicamentos == NULL)
    {
        printf("No se puede leer el archivo\n");
    }else
    {
        for(int i=0; i<numMed; i++){
            fscanf(medicamentos, "%s",meds[i]);
        }
        fclose(medicamentos);
    }  
    
}
int Menu (int opcion) { 
    do { 
        printf("\n*********************************\n"); 
        printf("* Menu principal *\n"); 
        printf("* ---------------- *\n"); 
        printf("* 1. Entrada de producto *\n"); 
        printf("* 2. Despacho de producto *\n"); 
        printf("* 3. Reporte del inventario *\n"); 
        printf("* 4. Salir *\n")
        printf("*********************************\n\n"); 
        scanf ("%d",& opcion); 
        if (opcion<1 || opcion>4){ 
            printf("Opcion invalida por favor elija las opciones presentadas"); 
        } 
    } while (opcion!=4); 
} 
