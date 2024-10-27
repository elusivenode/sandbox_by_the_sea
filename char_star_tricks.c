#include <stdio.h>

int main() {
  // double x = 3.1416;
  // char x = 'A';
  short x = 256;

  int ct = 260;
  for (int i = 0; i < ct; i++) {
    x = 256 + i;

    char ch = *(char *)&x;
    // printf("Size of x: %ld\n", sizeof(x));
    // printf("Size of ch: %ld\n", sizeof(ch));
    printf("x in decimal: %d\n", x);
    printf("x in hexadecimal: %x\n", x);
    if (ch == 0x0b) {
      printf("ch as a character: \\x0b (vertical tab)\n");
    } else if (ch == 0x1b) {
      printf("ch as a character: \\x1b (escape)\n");
    } else {
      printf("ch as a character: %c\n", ch);
    }
    printf("ch as an int: %d\n\n", ch);
  }

  short s = 45;
  double d = *(double *)&s;
  printf("double d: %f\n", d);
}
