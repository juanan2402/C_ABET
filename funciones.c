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
    int numMed, lote, cantidadIndividual, cantidadCajas;
    char nombre[50];
    do {
    printf("Ingrese el nombre del medicamento:\n");
    scanf("%s",nombre);
    if(existe_producto()!=0){

    }
    printf("Ingrese el lote:\n");
    scanf("%d",&nombre);
    printf("Ingrese la cantidad individual recibida:\n");
    scanf("%d",&nombre);
    printf("Ingrese la cantidad de medicamentos por caja:\n");
    scanf("%d",&nombre);
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