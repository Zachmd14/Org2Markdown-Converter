#include "../include/files.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 64

int readOrgFile(FILE *file, char *argv[]) {

  // copy command line argument to string variable 'filename'
  char filename[MAX_FILENAME_SIZE];
  strncpy(filename, argv[1], 63);
  filename[63] = '\0';

  printf("path to file is : %s\n", filename);

  // open filename in read only mode
  file = fopen(filename, "r");
  if (file == NULL) {
    printf("ERROR : File dont exist");
    return 1;
  }

  // load first line of filename
  char buff[500];
  /* fgets(buff, sizeof(buff), file); */
  printf("%s content is :\n\n", filename);
  while (fgets(buff, sizeof(buff), file) != NULL) {
    printf("%s", buff);
  }

  printf("\n");

  // free memory
  fclose(file);
  return 0;
}

