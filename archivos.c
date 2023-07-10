#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "funciones.h"
int cargarMedicamentos(struct medicamento meds[100]){
    int numMeds=0;
    FILE *inv;
    inv=fopen("Medicamentos.txt", "r");
    char cadena[255];
    char separador[]=";";

    while(feof(inv)==0){
        struct medicamento m;
        fgets(cadena, 255, inv);
        char *token = strtok(cadena, separador);

        if (token!=NULL){
            int espacio=1;
            while(token!=NULL){
                if(espacio==1){
                    strcpy(m.nombre, token);

                }
                else if(espacio==2){
                    m.codigo=atoi(token);

                }
                else if(espacio==3){
                    m.lote=atoi(token);

                }
                else if(espacio==4){
                    m.unidades=atoi(token);

                }
                else if(espacio==5){
                    m.unidadesxCaja=atoi(token);

                }
                espacio++;
                token=strtok(NULL, separador);

            }
        }
        meds[numMeds]=m;
        numMeds++;

    }
    fclose(inv);
    return(numMeds);
}
int cargarPersonas(struct personas pers[100]){
    int numPer=0;
    FILE *per;
    per=fopen("Personas.txt", "r");
    char cadena[255];
    char separador[]=";";

    while(feof(per)==0){
        struct personas p;
        fgets(cadena, 255, per);
        char *token = strtok(cadena, separador);

        if (token!=NULL){
            int espacio=1;
            while(token!=NULL){
                if(espacio==1){
                    strcpy(p.nombre, token);

                }
                else if(espacio==2){
                    p.cedula=atoi(token);

                }

                espacio++;
                token=strtok(NULL, separador);

            }
        }
        pers[numPer]=p;
        numPer++;

    }
    fclose(per);
    return(numPer);
}
void guardarMedicamentos(struct medicamento meds[100], int numMed){
    FILE *f;
    f = fopen("medicamentos.txt","w+");

    for (int i=0; i<numMed-1; i++){
        fprintf(f, "%s;%d;%d;%d;%d\n",meds[i].nombre,meds[i].codigo,meds[i].lote,meds[i].unidades, meds[i].unidadesxCaja);
    }
    fprintf(f, "%s;%d;%d;%d;%d\n",meds[numMed-1].nombre,meds[numMed-1].codigo,meds[numMed-1].lote,meds[numMed-1].unidades, meds[numMed-1].unidadesxCaja);

    fclose(f);
}
void guardarPersonas(struct personas per[100], int numPer){
    FILE *f;
    f = fopen("Personas.txt","w+");

    for (int i=0; i<numPer-1; i++){
        fprintf(f, "%s;%d\n",per[i].nombre,per[i].cedula);
    }
    fprintf(f, "%s;%d\n",per[numPer-1].nombre,per[numPer-1].cedula);

    fclose(f);
}
