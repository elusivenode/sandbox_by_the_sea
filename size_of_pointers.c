#include <stdio.h>

int main(void) {
  int *int_ptr;
  char *char_ptr;
  double *double_ptr;

  printf("Size of int pointer: %zu bytes\n", sizeof(int_ptr));
  printf("Size of char pointer: %zu bytes\n", sizeof(char_ptr));
  printf("Size of double pointer: %zu bytes\n", sizeof(double_ptr));

  return 0;
}
