#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>

int main(){

	int input_width;
	int block_width;
	int i, j, k, l, temp;

	struct timeval start, end;

	printf("Enter width for square matrix: \n");
	scanf("%d", &input_width);

	printf("Enter width of block: \n");
	scanf("%d", &block_width);

	int mat[input_width][input_width];

	printf("Matrix: \n");

	for(i = 0; i < input_width; i++){
		for(j = 0; j < input_width; j++){
			//initialize input matrix using rand()
			mat[i][j] = rand() % 10000;
			//printf("Matrix: \n");
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}

	//gettimeofday() to record the start and end of the transposition 
	gettimeofday(&start, NULL);
	printf("%ld\n", start.tv_sec * 1000000 + start.tv_usec);

	printf("Transposed Matrix: \n");

/*
	for(i = 0; i < input_width; i++){
		for(j = i + 1; j < input_width; j++){
			temp = mat[i][j];
			mat[i][j] = mat[j][i];
			mat[j][i] = temp;
			//printf("Transposed Matrix: \n");
			
		}
		
	}
*/
	
	for(i = 0; i < input_width; i+= block_width){
		for(j = 0; j < input_width; j+= block_width){
			for(k = i; k < i + block_width; k++){
				for(l = j; l < j + block_width; l++){
					temp = mat[k][l*input_width];
					mat[k][l*input_width] = mat[l][k*input_width];
					mat[l][k*input_width] = temp;	
				}
			}
		}
	}

	

	for(i = 0; i < input_width; i+= block_width){
		for(j = 0; j < input_width; j+= block_width){
			for(k = i; k < i + block_width; k++){
				for(l = j; l < j + block_width; l++){

					printf("%d\t", mat[l][k]);
				}
			}
		}
		printf("\n");
	}

	gettimeofday(&end, NULL);
	printf("%ld\n", end.tv_sec * 1000000 + end.tv_usec);

	printf("%ld\n", ((end.tv_sec + end.tv_usec)
		  - (start.tv_sec + start.tv_usec)));


//transpose(width_matrix, width_block)

	return 0;
}

