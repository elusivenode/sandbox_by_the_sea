#include <stdio.h>

int main(void) {
  FILE *fp; // Variable to represent open file

  fp = fopen("hello.txt", "r"); // Open file for reading

  int c = fgetc(fp);       // Read a single character
  printf("char: %c\n", c); // Print char to stdout
  printf("int backing char: %d\n", c);

  // note that fp has remembered its position in the file
  while ((c = fgetc(fp)) != EOF)
    printf("%c", c);

  fclose(fp);

  FILE *fp2;
  char s[1024]; // Big enough for any line this program will encounter
  int linecount = 0;

  fp2 = fopen("quote.txt", "r");

  // note fgets here instead of fgetc
  while (fgets(s, sizeof s, fp2) != NULL)
    printf("%d: %s", ++linecount, s);

  fclose(fp2);
}
