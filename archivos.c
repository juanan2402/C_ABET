#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "funciones.h"
//cargar functions read information from the respective files and stores it into struct arrays for internal use
int cargarMedicamentos(struct medicamento meds[100]){
    int numMed = 0;
    FILE *f;
    f = fopen("Medicamentos.txt","r");
    char cadena[255];
    char separador[] = ";";

    while (feof(f) == 0){

        struct medicamento m;
        fgets(cadena,255,f);
        char *token = strtok(cadena,separador);

        if(token != NULL){
            int campo = 1;
            while (token != NULL){
                if (campo == 1){
                    strcpy(m.nombre,token);
                }
                else if(campo == 2){
                    m.codigo = atoi(token);
                }
                else if(campo == 3){
                    m.anio = atoi(token);
                }
                else if(campo == 4){
                    m.unidades = atoi(token);
                }
                else if(campo == 5){
                    m.unidadesxCaja = atoi(token);
                }
                campo++;
                token = strtok(NULL, separador);
            }
        }
        meds[numMed] = m;
        numMed++;

    }
    fclose(f);
    //returns how many medicines are stored, for laer use in for loops and other control structures
    return numMed;
}
int cargarPersonas(struct personas pers[100]){
    int numPer = 0;
    FILE *f;
    f = fopen("Personas.txt","r");
    char cadena[255];
    char separador[] = ";";

    while (feof(f) == 0){

        struct personas p;
        fgets(cadena,255,f);
        char *token = strtok(cadena,separador);

        if(token != NULL){
            int campo = 1;
            while (token != NULL){
                if (campo == 1){
                    strcpy(p.nombre,token);
                }
                else if(campo == 2){
                    p.cedula = atoi(token);
                }
                campo++;
                token = strtok(NULL, separador);
            }
        }
        pers[numPer] = p;
        numPer++;

    }
    fclose(f);
    return numPer;
}
//Guardar functions reverse the process of cargar, they take the struct array and store data for each struct into a line, separating the information with ; 
void guardarMedicamentos(struct medicamento med[100], int numMed){
    FILE *f;
    f = fopen("Medicamentos.txt","w");

    for (int i=0; i<numMed-1; i++){
        fprintf(f, "%s;%d;%d;%d;%d\n",med[i].nombre,med[i].codigo,med[i].anio,med[i].unidades, med[i].unidadesxCaja);
    }
    fprintf(f, "%s;%d;%d;%d;%d",med[numMed-1].nombre,med[numMed-1].codigo,med[numMed-1].anio,med[numMed-1].unidades, med[numMed-1].unidadesxCaja);

    fclose(f);
}

void guardarPersonas(struct personas per[100], int num){
    FILE *f;
    f = fopen("Personas.txt","w");

    for (int i=0; i<num-1; i++){
        fprintf(f, "%s;%d\n",per[i].nombre,per[i].cedula);
    }
    fprintf(f, "%s;%d",per[num-1].nombre,per[num-1].cedula);
    fclose(f);
}