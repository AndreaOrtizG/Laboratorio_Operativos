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

void imprimir_arreglo(int arreglo[], int tam){
	
	for(int k=0; k<tam; k++){
		printf(" %d ", arreglo[k]);
	}
	printf("\n");
}


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

	if(argc < 2){   // Verifica que el archivo se ingrese como parámetro
		printf("You must specify a filepath\n");
		return EXIT_FAILURE;
	}

	FILE* fp = fopen(argv[1], "r");

	
	if(!fp){
		printf("Error while opening the file %s\n", argv[1]);  //Verifica si hubo un error en la lectura del archivo
	}

	char line[1024];
	int line_count = 0;
	int numero_total_platos = 0;
	int total_ingredientes = 0;
	int quantities[4];
	int num_ingredientes = 0;
	int x2, x3, x4 = 0;
	char ingredientes[20][10];
	bool comparisonSomeIsEqual;
	int offset3, offset4 = 0;
	int terms_count;

	// Métodos para leer el archivo y determinar los valores necesarios, Como numero de ingredientes total o por plato
	while(fgets(line, 1024, fp)){
		char *token;
		char *rest =line;
		
		if(line_count == 0){
				// Leer la primera linea del archivo
		
		
			while(token = strtok_r(rest, " ", &rest)){
				
				quantities[terms_count] = atoi(token);
				terms_count++;
			}
			for(int k=1; k<4; k++){
				if(k=1){
					x2= quantities[k];
				}

				if(k=2){
					x3=quantities[k];
				}

				if(k=3){
					x4=quantities[k];
				}
			}
			
			line_count++;  // Se aumenta la variable de control  para el procedimiento

		// Métodos para la lectura del plato o ingredientes
		}else{
			//Número de ingredientes por plato
			token = strtok_r(rest, " ", &rest);
			num_ingredientes = atoi(token);
			numero_total_platos++;

			
			for(int i = 0; i<num_ingredientes; i++){

				token  = strtok_r(rest, " ", &rest);
				comparisonSomeIsEqual = false;
				char *aux = (char*)malloc(sizeof(char*));
				remove_spaces(aux,token);
				for(int k = 0; k < total_ingredientes; k++){
					if(strcmp(ingredientes[k], aux)){
						comparisonSomeIsEqual= true;
					}
				} // Ingredientes por Plato

				if(comparisonSomeIsEqual == false){
					strcpy(ingredientes[total_ingredientes], aux);
					total_ingredientes++;
				}
			}
		}

	}
	fclose(fp);


	printf("pedidos de 2 platos: %d \n", x2);
	printf("pedidos de 3 platos: %d \n", x3);
	printf("pedidos de 4 platos: %d \n", x4);
	
	printf("total de platos: %d \n", numero_total_platos);
	printf("total de ingredientes: %d \n", total_ingredientes);

	
			int p[numero_total_platos][total_ingredientes];
			for(int k = 0; k < numero_total_platos; k++){
				for(int l=0; l < total_ingredientes; l++){
					p[k][l] = 0;                       // Se llena la matriz P con ceros para no tener inconvenientes más adelante 
				}
			}
			

			//Se llena el vector AP para luego ser utilizado
			int ap[numero_total_platos];
			for(int i=0; i < numero_total_platos; i++){
				ap[i] = i;
				printf(" %d ", ap[i]);
			}

			// Se imprime la matriz P para verificar que quedo correctamente llena

			for(int i=0; i< numero_total_platos; i++){
				for(int j=0; j<total_ingredientes; j++){
					printf(" %d ", p[i][j]);
				}  
				printf("\n");
			}
			
			printf("\n");
			permutacion(ap, 0, numero_total_platos); // Permutación para todos los platos 

// Sumatoria para los pedidos de 2, 3 y 4 platos. 
		int sumatoria_pedidos(int numero_total_platos, int ap[numero_total_platos], int total_ingredientes, int p[numero_total_platos][total_ingredientes], int x2, int x3){
			int sumatoria = 0;
			int offset3, offset4 = 0;
			offset3 = 2*x2;
			offset4 = 2*x2 + 3*x3;

		
			for(int i=0; i < p2 ; i++){
				for(int j=0; j < total_ingredientes; j++){
					if( p[ap[2*i]][j] || p[ap[(2*i)+1]][j] ){
						sumatoria++;
					}
				}
			}

			for(int i=0; i<p3; i++){
				for(int j=0; j < total_ingredientes; j++){
					if( p[ap[(op3+(3*i))]][j] || p[ap[(op3+(3*i)+1)]][j] || p[ap[(op3+(3*i)+2)]][j]){
						sumatoria++;
					}
				}
			}

			
			for(int i=0; i < p4; i++){
				for(int j = 0; j < total_ingredientes; j++){
					if(p[ap[(op4+(4*i))]][j] || p[ap[(op4+(4*i)+1)]][j] || p[ap[(op4+(4*i)+2)]][j] || p[ap[(op4+(4*i)+3)]][j]){
						sumatoria++;
					}
				}
			}

			return sumatoria;
		}

}
