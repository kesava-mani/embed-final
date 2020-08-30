/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Kesava Mani
 * @date August 2020
 *
 */

#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

/*****************************************************************************/
/*                  function implementation start                            */
/*****************************************************************************/
uint8_t* my_memmove(uint8_t * src, uint8_t * dst, size_t length){
  uint32_t i = 0;
  uint8_t *temp;

  /* allocate memory for temporary storage */
  temp = (uint8_t*) malloc(length * sizeof(uint8_t));

  /* move source data to temporary storage */
  for (i = 0; i < length; i++) {
    *(temp + i) = *(src + i);
  }

  /* move data from temporary to destination */
  for (i = 0; i < length; i++) {
    *(dst + i) = *(temp + i);
  }


  /* frees the allocated temp memory */
  free_words((uint32_t*)temp);

  return dst;
}


uint8_t* my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
  uint32_t i=0;

  /* byte copy from source to destination */
  for (i = 0; i < length; i++) {
    *(dst++) = *(src++);
  }

  return dst;
}


uint8_t* my_memset(uint8_t * src, size_t length, uint8_t value){
  uint32_t i=0;

  /* sets the input value to given buffer */
  for (i = 0; i < length; i++) {
    *(src + i) = value;
  }

  return src;
}


uint8_t* my_memzero(uint8_t * src, size_t length){
  /* sets value 0 to input buffer */
  src = my_memset(src, length, 0);

  return src;
}


uint8_t* my_reverse(uint8_t * src, size_t length){
  uint32_t i=0, j = 0;
  uint8_t temp;

  /* iterate until middle of string */
  for (i = 0, j = (length - 1); i < (length / 2); i++, j--) {
    /* swap extremes */
    temp = *(src + i);
    *(src + i) = *(src + j);
    *(src + j) = temp;
  }

  return src;
}


int32_t* reserve_words(size_t length){
  /* return pointer to allocated memory chunk */
  return (int32_t*) malloc(length * sizeof(int32_t));
}


void free_words(uint32_t * src){
  /* frees the allocated memory */
  free(src);
}
