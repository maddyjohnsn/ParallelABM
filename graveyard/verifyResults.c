#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	
	if (argc < 3) {
		fprintf(stderr, "Error: Missing filename.\n");
		fprintf(stderr, "Usage: <serialoutput> <paralellOutput>\n");
		return EXIT_FAILURE;
	    }
	FILE *serialOutput = fopen(argv[0], "rb"); 
	FILE *paralellOutput = fopen(argv[1], "rb");

	if (serialOutput == NULL || paralellFile == NULL) {
		printf("Error: could not open files.\n")
		if (serialOutput) fclose(serialOutput); 
		if (paralellOutput) fclose(paralellOutput);
		return EXIT_FAILURE;
	}

	int is_different = 0;
	int serialChar; 
	int paralellChar; 

	while (1) {
		serialChar = fgetc(serialOutput); 
		paralellChar = fgetc(paralellOutput); 

		if (serialChar != paralellChar) {
			is_different = 1; 
			break; 
		}

		if (serialChar == EOF || paralellChar == EOF) {
			break; 
		}
	}

	fclose(serialOutput);
	fclose(paralellOutput); 

	if (is_different == 1) {
		printf("Files do not match.\n")
	}
		
}	
