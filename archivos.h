#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED
#include "archivos.c"
int cargarMedicamentos(struct medicamento meds[100]);
int cargarPersonas(struct personas pers[100]);
void guardarPersonas(struct personas per[100], int numPer);
void guardarMedicamentos(struct medicamento meds[100], int numMed);
#endif // ARCHIVOS_H_INCLUDED
