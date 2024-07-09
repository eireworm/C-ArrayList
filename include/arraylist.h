#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct {
  enum { EMPTY_TYPE, INT_TYPE, FLOAT_TYPE, DOUBLE_TYPE, CHAR_TYPE, STRING_TYPE } datatype;
  union {
    int i;
    float f;
    double d;
    char c;
    char *s;
  };
} ALValue;

typedef struct {
  int capacity;
  int length;
  ALValue *datastore;
} ArrayList;

ArrayList createArrayList(int size);

ALValue arraylist_get(ArrayList *arr, int idx);

ALValue arraylist_peek(ArrayList *arr);

void arraylist_push(ArrayList *arr, ALValue data);

ALValue arraylist_pop(ArrayList *arr);

ALValue arraylist_shift(ArrayList *arr);

void arraylist_unshift(ArrayList *arr, ALValue data);

void arraylist_insertAt(ArrayList *arr, int idx, ALValue data);

void arraylist_deleteAt(ArrayList *arr, int idx);

ArrayList arraylist_resize(ArrayList *arr);

#endif
