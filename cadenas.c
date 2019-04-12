#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimirSinSalto(char *cadena);

int main(int argc, char const *argv[]){
	if (argc!=3){
		printf("Error, se debe pasar un numero y una cadena sin espacios.\n");
		return(-1);
	}
	char *cadena=(char*)malloc(sizeof(char)*100);
	char caracter;
	printf("Introduzca una frase (max 100 carácteres): ");
	fgets(cadena, 100, stdin);
	int longitud = strlen(cadena);
	int numParam = atoi(argv[1]);
	printf("La longitud de la cadena introducida ('");
	imprimirSinSalto(cadena);
	printf("') es de %d carácteres.\n", longitud);
	strcat(cadena, "Cadena añadida");
	printf("Al añadirle los cambios necesarios la cadena queda tal que: '");
	imprimirSinSalto(cadena);
	printf("'.\n");
	if (strstr(cadena, argv[2]) == NULL){
		printf("No se encontro la cadena pasada como parametro en la cadena principal.\n");
	}
	else{
		printf("Se encontro la cadena ('%s') en la cadena principal.\n", argv[2]);
	}
	if (longitud >= numParam && numParam>=0){
		caracter = (*(cadena+numParam));
		printf("El caracter de la cadena principal en la posicion %d es %c.\n",numParam, caracter);
	}
	else{
		printf("Error, la cadena es menor que el numero o el numero es negativo\n");
		exit(-1);
	}

	return 0;
}

void imprimirSinSalto(char *cadena){
	int longitud = strlen(cadena);
	for (int i = 0; i < longitud; i++){
		if ((int)(*(cadena+i)) != '\n'){
			printf("%c", *(cadena+i));
		}
	}
}