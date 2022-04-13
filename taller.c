#include <stdio.h>
#include "funciones.h"


int main(int argc, char **argv){
	Lista *head = NULL, *nuevo = NULL;
	FILE *f;
	f = fopen("datos.csv", "r");
	char *linea;
	linea = malloc(sizeof(char)*max);
	while(fgets(linea, max, f)){
		nuevo = (Lista*)malloc(sizeof(Lista));
		nuevo = nuevoNodo(linea);
		if(head == NULL){
			head = (Lista*)malloc(sizeof(Lista));
			head = nuevo;
		}
		else{
			insertar(head, nuevo);
		}
		nuevo = NULL;
		linea = malloc(sizeof(char)*max);
	}
	imprimir(head);
	return 0;
}