#include "funciones.c"
struct med{
  char nombre[100];
  int codigo;
  int lote;
  int cantidadIndividual;
  int cantidadPorCajas;

}
void ticket_de_recibo();
void creacion_de_producto();
void creacion_de_cliente();
void transaccion_entrada();
void transaccion_salida();
int existe_producto();
