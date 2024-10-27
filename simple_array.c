#include <stdio.h>

int main(void) {
  int array[10];
  printf("The size of the array is %lu\n", sizeof(array));
  printf("The memory address of f is %p\n", (void *)&array);

  for (int i = 0; i < 10; i++) {
    printf("The memory address of array[%d] is %p\n", i, (void *)&array[i]);
  }

  // this is out of bounds
  printf("The memory address of array[%d] is %p\n", 10, (void *)&array[10]);
  // even access slot before
  printf("The memory address of array[%d] is %p\n", -1, (void *)&array[-1]);

  for (int i = 0; i < 10; i++) {
    array[i] = i;
  }

  printf("*array is %d\n", *array);
  printf("*(array + 9) is %d\n", *(array + 9));

  int arr[5];
  arr[3] = 1;
  printf("arr[3] is %d\n", arr[3]);
  ((short *)arr)[7] = 1;
  printf("arr[3] is %d\n", arr[3]);
}
