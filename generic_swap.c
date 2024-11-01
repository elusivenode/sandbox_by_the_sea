#include <stdio.h>
#include <string.h>

void swap(void *vp1, void *vp2, size_t size) {
  char buffer[size];
  memcpy(buffer, vp1, size);
  memcpy(vp1, vp2, size);
  memcpy(vp2, buffer, size);
}

int main(void) {
  int a = 10;
  int b = 20;
  puts("Int");
  printf("Before swap: a = %d, b = %d\n", a, b);
  swap(&a, &b, sizeof(int));
  printf("After swap: a = %d, b = %d\n", a, b);

  long c = 10;
  long d = 20;
  puts("Long");
  printf("Before swap: c = %ld, d = %ld\n", c, d);
  swap(&c, &d, sizeof(long));
  printf("After swap: c = %ld, d = %ld\n", c, d);

  float e = 10.5;
  float f = 20.6;
  puts("Float");
  printf("Before swap: e = %.1f, f = %.1f\n", e, f);
  swap(&e, &f, sizeof(float));
  printf("After swap: e = %.1f, f = %.1f\n", e, f);

  double g = 4925.1515;
  double h = 1583259.35233;
  puts("Double");
  printf("Before swap: g = %.5f, h = %.5f\n", g, h);
  swap(&g, &h, sizeof(double));
  printf("After swap: g = %.5f, h = %.5f\n", g, h);
}
