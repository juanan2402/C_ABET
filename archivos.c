#include<stdio.h>
#include<stdlib.h>
int cargarMedicamentos(struct empleado empleados[100]){
    int n_emp = 0;
    FILE *meds;
    f = fopen("medicamentos.txt","r");
    char cadena[255];
    char delimitador[] = ";";

    while (feof(f) == 0){

        struct empleado e;
        fgets(cadena,255,f);
        char *token = strtok(cadena,delimitador);

        if(token != NULL){
            int campo = 1;
            while (token != NULL){
                if (campo == 1){
                    strcpy(e.nombre,token);
                }
                else if(campo == 2){
                    e.id = atoi(token);
                }
                else if(campo == 3){
                    e.sueldo = atof(token);
                }
                else if(campo == 4){
                    e.horas = atoi(token);
                }
                campo++;
                token = strtok(NULL, delimitador);
            }
        }
        empleados[n_emp] = e;
        n_emp++;

    }
    fclose(f);
    return n_emp;
}
