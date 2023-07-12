#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
//main structures used for the whole program, the parameters can be changed to suit other needs
struct medicamento{
    char nombre[50];
    int codigo;
    int anio;
    int unidades;
    int unidadesxCaja;
};

struct personas{
    char nombre[50];
    int cedula;
};



#endif