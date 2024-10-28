#include <stdio.h>
#include <string.h>

int main(void) {
  /*
   * char *s = "Hello, world!"; This is a pointer to a string literal.
   * Immutable. Crash if you try to modify. chat t[] = "Hello, world!"; This is
   * an array of characters.  Mutable.  Can be modified. When you include a
   * string in double quotes in your code, the NUL character is automatically,
   * implicitly included. char *s = "Hello!";  // Actually "Hello!\0" behind the
   * scenes
   */
  char s[] = "Hello, world!";

  for (int i = 0; i < 14; i++)
    printf("The char is %c. The memory address is %p\n", s[i], (void *)&s[i]);

  char a[] = "Hello, world!";
  char *t;

  printf("Printing a before t = a %s\n", a); // "zello, world!"
  // This makes a copy of the pointer, not a copy of the string!
  t = a;

  // We modify t
  t[0] = 'z';

  // But printing s shows the modification!
  // Because t and s point to the same string!

  printf("Printing a after t = a %s\n", a); // "zello, world!"

  // This is a better way to copy a string ... strcpy
  char b[] = "Hello, world!";
  char c[100]; // Each char is one byte, so plenty of room

  // This makes a copy of the string!
  strcpy(c, b);

  // We modify t
  c[0] = 'z';

  // And s remains unaffected because it's a different string
  printf("Initial string %s\n", b); // "Hello, world!"

  // But t has been changed
  printf("The copy %s\n", c); // "zello, world!"
}
