#include "../include/arraylist.h"
#include <stdio.h>

int main() {
  ArrayList al = createArrayList(1);

  ALValue v1 = {INT_TYPE, {11}};
  ALValue v2 = {INT_TYPE, {22}};
  ALValue v3 = {INT_TYPE, {33}};
  ALValue v4 = {INT_TYPE, {44}};
  ALValue v5 = {INT_TYPE, {55}};

  arraylist_push(&al, v1);
  arraylist_push(&al, v2);
  arraylist_push(&al, v3);

  printf("ArrayList\n");
  printf("Capcity: %i\n", al.capacity);
  printf("Length: %i\n\n", al.length);

  arraylist_unshift(&al, v4);
  arraylist_unshift(&al, v5);

  printf("ArrayList\n");
  printf("Capcity: %i\n", al.capacity);
  printf("Length: %i\n\n", al.length);

  printf("0: %i\n", arraylist_get(&al, 0).i);
  printf("1: %i\n", arraylist_get(&al, 1).i);
  printf("2: %i\n", arraylist_get(&al, 2).i);
  printf("3: %i\n", arraylist_get(&al, 3).i);
  printf("4: %i\n", arraylist_get(&al, 4).i);
  printf("5: %i\n", arraylist_get(&al, 5).i);
  printf("\n");

  arraylist_deleteAt(&al, 3);

  printf("0: %i\n", arraylist_get(&al, 0).i);
  printf("1: %i\n", arraylist_get(&al, 1).i);
  printf("2: %i\n", arraylist_get(&al, 2).i);
  printf("3: %i\n", arraylist_get(&al, 3).i);
  printf("4: %i\n", arraylist_get(&al, 4).i);
  printf("5: %i\n", arraylist_get(&al, 5).i);

  printf("ArrayList\n");
  printf("Capcity: %i\n", al.capacity);
  printf("Length: %i\n\n", al.length);

  return 0;
}
