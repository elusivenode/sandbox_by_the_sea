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
  printf("\n");

  fclose(fp2);

  FILE *fp3;
  char name[1024]; // Big enough for any line this program will encounter
  float length;
  int mass;

  fp3 = fopen("whales.txt", "r");

  while (fscanf(fp3, "%s %f %d", name, &length, &mass) != EOF)
    printf("%s whale, %d tonnes, %.1f meters\n", name, mass, length);

  fclose(fp3);

  FILE *fp4;
  int x = 32;

  // `fp4 = fopen("output.txt", "w");
  // fp4 = stdout; // stdout is a FILE* that represents the console
  fp4 = stderr; // stderr is also just a FILE*

  fputc('B', fp4);
  fputc('\n', fp4); // newline
  fprintf(fp4, "x = %d\n", x);
  fputs("Hello, world!\n", fp4);

  fclose(fp4);

  FILE *fp5;
  unsigned char bytes[6] = {5, 37, 0, 88, 255, 12};

  fp5 = fopen("output.bin", "wb"); // wb mode for "write binary"!

  // In the call to fwrite, the arguments are:
  //
  // * Pointer to data to write
  // * Size of each "piece" of data
  // * Count of each "piece" of data
  // * FILE*

  fwrite(bytes, sizeof(char), 6, fp5);

  fclose(fp5);

  FILE *fp6;
  unsigned char c1;

  fp6 = fopen("output.bin", "rb"); // rb for "read binary"!

  while (fread(&c1, sizeof(char), 1, fp6) > 0)
    printf("decimal %d hex %x \n", c1, c1);

  fclose(fp6);

  FILE *fp7;
  fp7 = stdout;
  unsigned short v = 0x1234; // Two bytes, 0x12 and 0x34

  // prints as 4 because 0x34 is ASCII for '4'
  // 0x12 is not a printable character
  fwrite(&v, sizeof(v), 1, fp7);
}
