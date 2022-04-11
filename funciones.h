#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 500

typedef struct list{
    char nom_rbd[max];
    char nom_reg_rbd[max];
    char nom_com_rbd[max];
    float dif_lect2m_rbd;
    int sigdif_lect2m_rbd;
    char com_lect2m_rbd[max];
    struct list *sig;
}Lista;

void Insertar(Lista *l, char *linea){
    Lista *nuevo;
    nuevo = (Lista*)malloc(sizeof(Lista));
    nuevo->sig = NULL;
    char *token;
    token = strtok(linea, "\n");
    token = strtok(NULL, ",");
    strcpy(nuevo->nom_rbd, token);
    token = strtok(NULL, ",");
    strcpy(nuevo->nom_reg_rbd, token);
    token = strtok(NULL, ",");
    strcpy(nuevo->nom_com_rbd, token);
    token = strtok(NULL, ",");
    nuevo->dif_lect2m_rbd = atof(token);
    token = strtok(NULL, ",");
    nuevo->sigdif_lect2m_rbd = atoi(token);
    token = strtok(NULL, ",");
    strcpy(nuevo->com_lect2m_rbd, token);
    if(l == NULL){
        l = nuevo;
        l->sig = NULL;
    }
    else{
        while(l->sig != NULL){
            l = l->sig;
        }
        l->sig = nuevo;
    }
}

void Print(Lista *l){
    printf("\n\tResultados SIMCE");
    if(l == NULL){
        printf("\nLista vacia, nada que mostrar.");
    }
    else{
        while(l != NULL){
            printf("\nNombre: %s\nRegion: %s\nComuna: %s\nDiferencia: %d\nSignificancia: %i\nComentario: %s", l->nom_rbd, l->nom_reg_rbd, l->nom_com_rbd, l->dif_lect2m_rbd, l->sigdif_lect2m_rbd, l->com_lect2m_rbd);
        }
    }
}

/*void llenarLista(Lista *l){
    FILE *f;
    f = fopen("datos.csv", "r");
    char *linea;
    while(!feof(f)){
        fgets(linea, max, f);
        insertar(l, linea);
    }
    fclose(f);
}*/

void limpiarLista(Lista *l){
    while(l != NULL){
        free(l);
        l = l->sig;
    }
}