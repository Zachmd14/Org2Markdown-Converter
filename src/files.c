#include "../include/files.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 64

int openAndReadOrgFile(FILE *file, char *argv[]) {

  // copy command line argument to string variable 'filename'
  char filename[MAX_FILENAME_SIZE];
  strncpy(filename, argv[1], 63);
  filename[63] = '\0';

  printf("path to file is : %s\n", filename);

  // open filename in read only mode
  file = fopen(filename, "r");
  if (file == NULL) {
    printf("ERROR : File dont exist");
    return -1;
  }

  fclose(file);
  return 0;
}
