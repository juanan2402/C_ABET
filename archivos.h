#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "archivos.c"
 int cargarMedicamentos(struct medicamento meds[100]);
 int cargarPersonas(struct personas pers[100]);
 void guardarPersonas(struct personas per[100], int num);
 void guardarMedicamentos(struct medicamento med[100], int numMed);
#endif