#ifndef FILE_UTILS
#define FILE_UTILS
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
/***********************************************************
*Reads a given file, finds the file size, and allocates
*memory for it.
*@param char* filename: A pointer to the name of the file
*@param char **buffer: A pointer to the memory address
*of the contents of our file.
*@return int: return 0 for success and -1 for errors
***********************************************************/
int read_file(char* filename, char **buffer);

/***********************************************************
*Writes to a given file.
*@param char* filename: A pointer to the name of the file
*@param char *buffer: A pointer to the memory address
*of the contents of our file.
*@param int size: the size of the file.
*@return int: return 0 for success and -1 for errors
***********************************************************/
int write_file(char* filename, char *buffer, int size);

#endif //FILE_UTILS

