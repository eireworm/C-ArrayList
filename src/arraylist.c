#include "../include/arraylist.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

ArrayList createArrayList(int size) {
  ALValue *data = malloc(sizeof(ALValue) * size);
  if (data == NULL) {
    printf("failed to allocate memory for new arraylist\n");
    exit(1);
  } else {
    for (int i = 0; i < size; i++) {
      ALValue newval;
      newval.datatype = EMPTY_TYPE;
      data[i] = newval;
    }
  }

  ArrayList arr;
  arr.capacity = size;
  arr.length = 0;
  arr.datastore = data;

  return arr;
}

void arraylist_push(ArrayList *arr, ALValue data) {
  if (arr->length >= arr->capacity) {
    *arr = arraylist_resize(arr);
  }
  arr->datastore[arr->length] = data;
  arr->length++;
}

ALValue arraylist_peek(ArrayList *arr) {
  return arr->datastore[arr->length - 1];
}

ArrayList arraylist_resize(ArrayList *arr) {
  int new_capacity =
      arr->capacity <= 10 ? arr->capacity * 2 : arr->capacity * 1.5;
  ArrayList newarr = createArrayList(new_capacity);
  for (int i = 0; i < arr->length; i++) {
    newarr.datastore[i] = arr->datastore[i];
    newarr.length++;
  }

  return newarr;
}

ALValue arraylist_get(ArrayList *arr, int idx) { return arr->datastore[idx]; }

ALValue arraylist_pop(ArrayList *arr) {
  if (arr->length == 0) {
    ALValue empt;
    empt.datatype = EMPTY_TYPE;
    return empt;
  }

  arr->length--;

  return arr->datastore[arr->length];
}

ALValue arraylist_shift(ArrayList *arr) {
  if (arr->length <= 0) {
    ALValue empt;
    empt.datatype = EMPTY_TYPE;
    return empt;
  }

  ALValue ret = arr->datastore[0];

  for (int i = 0; i < arr->length; i++) {
    arr->datastore[i] = arr->datastore[i + 1];
  }

  arr->length--;

  return ret;
}

void arraylist_unshift(ArrayList *arr, ALValue data) {
  if (arr->length == 0) {
    arraylist_push(arr, data);
    return;
  }

  if (arr->length >= arr->capacity) {
    *arr = arraylist_resize(arr);
  }

  for(int i = arr->length; i > 0; i--) {
    arr->datastore[i] = arr->datastore[i-1];
  }

  arr->datastore[0] = data;

  arr->length++;
}

void arraylist_insertAt(ArrayList *arr, int idx, ALValue data) {
  if (idx == 0) {
    arraylist_unshift(arr, data);
    return;
  }

  if (arr->length == 0) {
    return;
  }

  if (arr->length >= arr->capacity) {
    *arr = arraylist_resize(arr);
  }

  for(int i = arr->length; i > idx; i--) {
    arr->datastore[i] = arr->datastore[i-1];
  }

  arr->datastore[idx] = data;

  arr->length++;
}

void arraylist_deleteAt(ArrayList *arr, int idx) {
  if (idx == 0) {
    arraylist_shift(arr);
    return;
  }

  if (arr->length == 0) {
    return;
  }

  for (int i = idx; i < arr->length; i++) {
    arr->datastore[i] = arr->datastore[i + 1];
  }

  arr->length--;
}
