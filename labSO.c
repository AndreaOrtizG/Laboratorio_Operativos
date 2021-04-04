#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void remove_spaces(char* restrict str_trimmed, const char* restrict str_untrimmed){
	while(*str_untrimmed!='\0'){
		if(!isspace(*str_untrimmed)){
			*str_trimmed = *str_untrimmed;
			str_trimmed++;
		}
		str_untrimmed++;
	}
	*str_trimmed='\0';
}

void intercambiar(int *x1, int *x2){
	int aux = *x1;
	*x1 = *x2;
	*x2 = aux;
}

/* void imprimir_arreglo(int arreglo[], int tam){
	
	for(int k=0; k<tam; k++){
		printf(" %d ", arreglo[k]);
	}
	printf("\n");
 */
//}



void permutacion(int *arreglo, int inicio, int fin){
	if(inicio == fin){
		imprimir_arreglo(arreglo, fin+1);
	}
	
	for(int i = inicio; i<= fin;i++){
		intercambiar((arreglo+i), (arreglo+inicio));
		permutacion(arreglo, inicio+1, fin);
		intercambiar((arreglo+i), (arreglo+inicio));
	}
}

int main(int argc, char*argv[]){
	/*Validar que el archivo a leer fue ingresado como parametro*/
	if(argc < 2){
		printf("You must specify a filepath\n");
		return EXIT_FAILURE;
	}

	FILE* fp = fopen(argv[1], "r");

	/*Validar si hubo un error al ingresar a leer el archivo*/
	if(!fp){
		printf("Error while opening the file %s\n", argv[1]);
	}

	char line[1024];
	int line_count = 0;
	int total_plates = 0;
	int total_ingredientes = 0;
	int quantities[4];
	int num_ingredientes = 0;
	int x2, x3, x4 = 0;
	char ingredientes[20][10];
	bool comparisonSomeIsEqual;
	int offset3, offset4 = 0;
	int terms_count;

	// Métodos para leer el archivo y determinar los valores necesarios
	while(fgets(line, 1024, fp)){
		char *token;
		char *rest =line;
		
		if(line_count == 0){
				// Leer la primera lineal del archivo
		
		
			while(token = strtok_r(rest, " ", &rest)){
				
				quantities[terms_count] = atoi(token);
				terms_count++;
			}
			for(int k=1, k<4, k++){
				if(k=1){
					x1= quantities[k]
				}

				if(k=2){
					x2=quantities[k]
				}

				if(k=3){
					x3=quantities[k]
				}
			}
			/*Incrementamos variable de control para la entrada de este procedimiento*/
			line_count++;

		/*Lectura de platos y sus ingredientes*/
		}else{
			/*Lectura de numero de ingredientes por plato*/
			token = strtok_r(rest, " ", &rest);
			num_ingredientes = atoi(token);
			numero_total_platos++;

			/*Lectura de cada ingrediente por plato*/
			for(int i = 0; i<num_ingredients_per_plate; i++){
				

				to  = strtok_r(rest, " ", &rest);
				comparisonSomeIsEqual = false;
				char *aux = (char*)malloc(sizeof(char*));
				remove_spaces(aux,token);
				for(int k = 0; k < total_ingredientes; k++){
					if(strcmp(ingredientes[k], aux){
						comparisonSomeIsEqual= true;
					}
				}
				if(comparisonSomeIsEqual == false){
					strcpy(ingredientes[numero_total_ingredientes], aux);
					numero_total_ingredientes++;
				}
			}
		}

	}
}
