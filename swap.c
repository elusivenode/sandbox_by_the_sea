#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(void) {
  int a = 10;
  int b = 20;

  printf("Before swap: a = %d, b = %d\n", a, b);
  swap(&a, &b);
  printf("After swap: a = %d, b = %d\n", a, b);

  return 0;
}
