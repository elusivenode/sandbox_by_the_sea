#include <stdio.h>

#define PRINT_PTR(ptr, type)                                                   \
  printf("The memory address of " #ptr " is %p (type: " #type "*)\n",          \
         (void *)(ptr))

int main(void) {
  typedef struct {
    int num;
    int denom;
  } fraction;

  fraction f;

  printf("The size of the fraction struct is %lu bytes\n", sizeof(f));
  printf("The size of the num field is %lu bytes\n", sizeof(f.num));
  PRINT_PTR(&f, fraction);
  PRINT_PTR(&f.num, int);
  PRINT_PTR(&f.denom, int);

  f.num = 1;
  f.denom = 2;

  float result = (float)f.num / f.denom;
  printf("The result of %d/%d is %f\n", f.num, f.denom, result);

  // casts the address of f.denom to a pointer to a fraction struct
  // then changes the value of the num field in the struct
  // this has the effect of changing the value of f.denom
  ((fraction *)&(f.denom))->num = 3;
  result = (float)f.num / f.denom;
  printf("The result of %d/%d is %f\n", f.num, f.denom, result);
}
