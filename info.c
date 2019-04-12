#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINEAS 5
#define MAX_LONG 100

void lecturaMatriz(char matrizL[MAX_LINEAS][MAX_LONG], FILE *fileL);
void busquedaPorInicial(char matrizB[MAX_LINEAS][MAX_LONG], char letraB);

int main(int argc, char const *argv[]){
	FILE *file;
	char matriz[MAX_LINEAS][MAX_LONG], letra = *argv[1];
	file = fopen("info.txt", "r");
	//Antes de hacer nada compruebo que se ha pasado bien la letra y se puede leer el archivo
	if (file == NULL){
		printf("Error: No se pudo encontrar o abrir el archivo info.txt\n");
		return(-1);
	}
	if (argc != 2){
		printf("Error: Se debe añadir una letra de busqueda al ejecutar.\n");
		return(-1);
	}

	lecturaMatriz(matriz, file);
	fclose(file);
	busquedaPorInicial(matriz, letra);
	return 0;
}

void lecturaMatriz(char matrizL[MAX_LINEAS][MAX_LONG], FILE *fileL){
	int i = 0;
	size_t bytes, tam;
	char *line;
	do{
		bytes=getline(&line, &tam, fileL);
		if (bytes!=(-1)){
			strncpy(matrizL[i], line, bytes-1);
			matrizL[i][bytes-1]='\0';
			i++;
		}
	} while (bytes!=(-1));
	free(line);
}

void busquedaPorInicial(char matrizB[MAX_LINEAS][MAX_LONG], char letraB){
	int k, contador = 0, l=0;
	for (k = 0; k < MAX_LINEAS; k++)
	{
		if (matrizB[k][0] == letraB){
				contador++;
				printf("Se encontro el nombre : '");
				while(matrizB[k][l] != '\0'){
					printf("%c",matrizB[k][l]);
					l++;
				}
				printf("' con la letra %c.\n", letraB);

		}
	}
	if (contador == 0){
		printf("No se encontro ningun nombre que comenzase por la letra %c.\n", letraB);
	}
}


