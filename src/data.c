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
 * @file data.c
 * @brief Abstraction of data conversion between integer and ASCII.
 *
 * This implementation file provides an abstraction of conversion between
 * integer and ASCII and vice versa via function calls.
 *
 * @author Kesava Mani
 * @date August 2020
 *
 */
#include "data.h"

/***********************************************************
 Function Definitions
***********************************************************/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
  uint8_t i = 0, temp = 0, j = 0;
  uint8_t neg_chk = 0;
  uint8_t length = 0;
  /* check inputs */
  if (ptr == NULL || base < 2 || base > 16) {
    return -1;
  }

  /* check if data is 0, then NULL terminate and exit */
  if (data == 0) {
    *(ptr + ++i) = '\0';
    return 1;
  }

  /* check if data is negative */
  if (data < 0 && base == 10) {
    data = -data;
    neg_chk = 1;
  }

  /* slice digits from one's place */
  while (data != 0) {
    *(ptr + i) = data % base;
    data = data / base;
    i = i + 1;
  }
  /* append - sign */
  if(neg_chk) {
    *(ptr + i++) = '-';
  }

  /* store string length */
  length = i;

  /* reverse the string */
  for (i = 0, j = (length - 1); i < (length / 2); i++, j--) {
    temp = *(ptr + i);
    *(ptr + i) = *(ptr + j);
    *(ptr + j) = temp;
  }

  return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
  uint8_t i = 0;
  uint8_t num = 0;
  uint8_t neg_chk = 0;
  int32_t result = 0;

  /* check inputs */
  if (ptr == NULL || digits <= 0 || base < 2 || base > 16) {
    return -1;
  }
  /* check if input data is negative */
  if (*(ptr+i) == '-') {
    i = 1;
    neg_chk = 1;
  }

  /* iterate until digits */
  while (i < digits) {
    /* convert string to integer */
    //num = *(ptr + i) - '0';

    num = *(ptr + i);

    if (num > (base - 1)) {
      /* check if number is out of base's range */
      return -1;
    }

    /* accumulate the result */
    result = num + (result * base);
    i++;
  }

  /* multiply by -1 for negative number */
  if (neg_chk) {
    result *= -1;
  }

  return result;
}
