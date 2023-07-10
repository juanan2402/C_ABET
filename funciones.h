
#include "funciones.c"

void Menu();
void Inventario(struct medicamento meds[100], int numMeds);
int IngresoProductos(struct medicamento med[100], int numMed);
void Personas(struct personas per[100], int numPer);
int IngresoPersonas(struct personas per[100], int numPer);
void despacho(struct medicamento med[100], int numMed, struct personas per[100], int numPer);
int comprobarCodigo(struct medicamento med[100], int numMed, int codigo);
int comprobarCedula(struct personas per[100], int numPer, int cedula);
