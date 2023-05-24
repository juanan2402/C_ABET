#include<stdio.h>

int Entrada_de_producto (int cantidad) { 
    int i,confirma; 
    char Nombre [100]; 
    int farmacos; 
    printf ("Ingrese la cantidad de medicinas distintas que hay\n"); 
    scanf ("%d",& farmacos); 
    for (i=1 ; i<=farmacos ; i++){ 
        printf ("Ingrese el nombre de la medicina numero %d\n", i); 
        scanf ("%s",& Nombre); printf ("Ingrese el total de cajas de medicinas que tiene de %s\n", Nombre); 
        scanf ("%d",& cantidad); 
        if (cantidad<1){ 
            printf ("Cantidad de cajas erronea"); 
        } 
        printf ("Su medicina se llama %s y tiene un total de %d cajas\n", Nombre , cantidad); 
        printf ("Si desea repetir presione 2 caso contrario presione cualquier numero\n"); 
        scanf ("%d",& confirma); 
        if (confirma==2){ 
            i=i-1; 
        }
    } 
} 