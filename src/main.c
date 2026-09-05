#include "../include/files.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // argc -> number of arguments (no arg -> "1", one arg -> 2, etc...)
  // argv -> array of arguments

  if (argc == 2) {
    // if one argument is passed
    FILE *file = NULL;
    readOrgFile(file, argv);

  } else if (argc > 2) {
    // if more than one argument is passed
    printf("Too many arguments supplied.\n");
  } else {
    // if no argument is passed
    printf("You need to specify a file name.\n");
  }

  return 0;
}
