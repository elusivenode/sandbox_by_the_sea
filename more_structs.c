#include <stdio.h>
#include <string.h>

struct car {
  char *name;
  float price;
  int speed;
};

void set_price(struct car *c, float new_price) {
  // c.price = new_price;  // ERROR!! dot operator is for structs, not pointers
  //(*c).price = new_price; // Works, but is ugly and non-idiomatic
  // This is the idiomatic way to access fields in a struct
  c->price = new_price;
}

int main(void) {

  struct car saturn;
  saturn.name = "Saturn SL/2";
  saturn.price = 15999.99;
  saturn.speed = 175;

  printf("Name:           %s\n", saturn.name);
  printf("Price (USD):    %f\n", saturn.price);
  printf("Top Speed (km): %d\n", saturn.speed);

  // Now with an initializer! Same field order as in the struct declaration:
  // this style has to happen in the definition of the struct, not later.
  struct car saturn2 = {"Saturn SL/2", 16000.99, 175};

  printf("Name:      %s\n", saturn2.name);
  printf("Price:     %f\n", saturn2.price);
  printf("Top Speed: %d km\n", saturn2.speed);

  // Now with an initializer! Different field order than in the struct
  // price is not initialized, so it will be 0.0
  struct car saturn3 = {.speed = 175, .name = "Saturn SL/2"};

  printf("Name:      %s\n", saturn3.name);
  printf("Price:     %f\n", saturn3.price);
  printf("Top Speed: %d km\n", saturn3.speed);

  // What about no name? --> remains uninitialized
  struct car saturn4 = {.speed = 175};

  printf("Name:      %s\n", saturn4.name);
  printf("Price:     %f\n", saturn4.price);
  printf("Top Speed: %d km\n", saturn4.speed);

  set_price(&saturn3, 16000.99);

  printf("Name:      %s\n", saturn3.name);
  printf("Price:     %f\n", saturn3.price);
  printf("Top Speed: %d km\n", saturn3.speed);
}
