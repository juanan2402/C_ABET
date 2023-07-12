#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

struct medicamento{
    char nombre[50];
    int codigo;
    int lote;
    int unidades;
    int unidadesxCaja;
};

struct personas{
    char nombre[50];
    int cedula;
};



#endif