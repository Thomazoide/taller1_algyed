#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1000

typedef struct list{
    char *nom_rbd;
    char *nom_reg_rbd;
    char *nom_com_rbd;
    float dif_lect2m_rbd;
    int sigdif_lect2m_rbd;
    char *com_lect2m_rbd;
    struct list *sig;
}Lista;

Lista *nuevoNodo(char *linea){
	Lista *nuevo = (Lista*)malloc(sizeof(Lista));
	linea = strtok(linea, "\n");
	nuevo->nom_rbd = strtok(linea, ",");
	nuevo->nom_reg_rbd = strtok(NULL, ",");
	nuevo->nom_com_rbd = strtok(NULL, ",");
	nuevo->dif_lect2m_rbd = atof(strtok(NULL, ","));
	nuevo->sigdif_lect2m_rbd = atoi(strtok(NULL, ","));
	nuevo->com_lect2m_rbd = strtok(NULL, ",");
	return nuevo;
}

void insertar(Lista *raiz, Lista *nuevo){
	Lista *aux = (Lista*)malloc(sizeof(Lista));
	aux = raiz;
	while(aux->sig){
		aux = aux->sig;
	}
	aux->sig = nuevo;
}

void imprimir(Lista *lis){
	printf("\tResultados simce");
	Lista* aux = (Lista*)malloc(sizeof(Lista));
	aux = lis;
	if(lis){
		while(aux){
			printf("\nNombre: %s\nRegion: %s\nComuna: %s\nDiferencia: %f\nSignificancia: %i\nComentario: %s", aux->nom_rbd, aux->nom_reg_rbd, aux->nom_com_rbd, aux->dif_lect2m_rbd, aux->sigdif_lect2m_rbd, aux->com_lect2m_rbd);
			aux = aux->sig;
		}
	}
	else{
		printf("\nLista vacia....");
	}
}