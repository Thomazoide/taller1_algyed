#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"
#define max 500

int main(){
    Lista *resultados_simce;
    FILE *f;
    f = fopen("datos.csv", "r");
    char *linea;
    while(!feof(f)){
        fgets(linea, max, f);
        Insertar(resultados_simce, linea);
    }
    fclose(f);
    Print(resultados_simce);
    printf("%d", resultados_simce->dif_lect2m_rbd);
    limpiarLista(resultados_simce);
    return 0;
}
