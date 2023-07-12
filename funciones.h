#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "funciones.c"

void Menu();
void inventario(struct medicamento med[100], int numMed, int anio);
int IngresarProductosNuevos(struct medicamento meds[100],int numMed);
int SumarCantidades(struct medicamento med[100], int numMed);
#endif