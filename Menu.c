#include<stdio.h> 

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

