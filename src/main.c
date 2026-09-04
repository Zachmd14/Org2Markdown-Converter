#include "../include/files.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 64

int main(int argc, char *argv[]) {
  // argc → number of arguments (no arg -> "1", one arg -> 2, etc...)
  // argv → array of arguments

  // TODO: create function to test if filename is valid

  if (argc == 2) {

    char filename[MAX_FILENAME_SIZE];
    strncpy(filename, argv[1], 63);
    filename[63] = '\0';

    printf("filename is %s\n", filename);
    FILE *file = fopen(filename, "r");


    if (file == NULL) {
      printf("ERROR : File dont exist");
      return -1;
    }

    fclose(file);

  } else if (argc > 2) {
    printf("Too many arguments supplied.\n");
  } else {
    printf("You need to specify a file name.\n");
  }

}
