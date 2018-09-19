#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

/***********************************************************
*Main method for the reverse a file program.
*@param int argc: number of args
*@param char* argv[]: list of args
*@return int
***********************************************************/
int main(int argc, char* argv[]){

	if(argc != 3){
		printf("Invalid arguments!\n");
		printf("Input should be ./reverse inputFile outputFile\n");
		return -1;
	}

	//Input file
	char * input;

	//Output file
	char * output;

	//This will hold the contents of the file
	char * word;

	//This will hold the reversed contents
	char * reverse;

	//Test int
	int test;

	//Assigning filenames
	input = argv[1];
	output = argv[2];

	//Finds size of file
	struct stat st;
	stat(input, &st);
        int size = st.st_size;
 
	printf("Size of file = %d\n", size);

	//Read the input file
	test = read_file(input, &word);

	//Check to see if file was read successfully
	if(test != 0){
		fprintf(stderr, "Error reading file \n");
		return -1;
	}
	//Allocates memory
        word = (char*)malloc(size * sizeof(char));
        reverse = (char*)malloc(size * sizeof(char));

	//Reverse the contents of the file
	for(int i = 0; i<size; ++i){
		//Iterate through the word array backwards
		reverse[i] = word[size-i-1];
	}
	
	//Write the new contents to a file
	write_file(output, reverse, size);

	//Free the memory
	free(word);
	free(reverse);

	puts("File successfully reversed!");

	return 0;
}
