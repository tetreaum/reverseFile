#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "file_utils.h"

/***********************************************************
*Reads a given file, finds the file size, and allocates
*memory for it.
*@param char* filename: A pointer to the name of the file
*@param char **buffer: A pointer to the memory address
*of the contents of our file.
*@return int: return 0 for success and -1 for errors
***********************************************************/
int read_file(char* filename, char **buffer){
	//Finds file size
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;

	//Opens file for reading
	FILE *f;
	f = fopen(filename, "r");
	//Error checking
	if(f == NULL){
		fprintf(stderr, "Error opening file\n");
		return -1;
	}
	else{
		//Reads file
		fread(buffer, sizeof(char), size, f);
		fclose(f);
	}
	return 0;
}

/***********************************************************
*Writes to a given file.
*@param char* filename: A pointer to the name of the file
*@param char *buffer: A pointer to the memory address
*of the contents of our file.
*@param int size: the size of the file.
*@return int: return 0 for success and -1 for errors
***********************************************************/
int write_file(char* filename, char *buffer, int size){
	FILE *f;
	f = fopen(filename, "w");
	if(f == NULL){
		fprintf(stderr, "Error opening file\n");
		return -1;
	}
	else{
		fwrite(buffer, sizeof(char), size, f);
		fclose(f);
	}
	return 0;
}

