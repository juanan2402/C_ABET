#include<stdio.h>
#include "Menu.h"
#include "Entrada.h"

int main(){ 
    char clientes[100][100];
    //File Creation
    FILE *clientes;
    FILE *mediamentos;
    FILE *entradas;
    FILE *salidas;

    clientes = fopen("clientes.txt", "w+");
    if (clientes == NULL)
    {
        printf("No se puede crear el archivo\n");
    }else
    {
        printf("Se ha creado el archivo clientes.txt\n");
        fclose(clientes);
    } 

    entradas = fopen("entradas.txt", "w+");
    if (entradas == NULL)
    {
        printf("No se puede crear el archivo\n");
    }else
    {
        printf("Se ha creado el archivo salidas.txt\n");
        fclose(entradas);
    } 

    salidas = fopen("salidas.txt", "w+");
    if (salidas == NULL)
    {
        printf("No se puede crear el archivo\n");
    }else
    {
        printf("Se ha creado el archivo salidas.txt\n");
        fclose(salidas);
    } 

    medicamentos = fopen("medicamentos.txt", "w+");
        if (medicamentos == NULL)
        {
            printf("No se puede crear el archivo\n");
        }else
        {
            printf("Se ha creado el archivo medicamentos.txt\n");
            fclose(medicamentos);
        } 

    int opcion, entrada; 
    switch (Menu (opcion)){ 
        case 1: Entrada_de_producto (entrada); 
        break; 
        case 2: 
        break; 
        case 3: 
        break; 
    } 
}
