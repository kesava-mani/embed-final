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
 * @file stats.c
 * @brief Computes statistics on the given data.
 *
 * The statistics include mean, median, maximum and minimum of the input data.
 *
 * @author Kesava Mani U
 * @date August 10, 2020.
 *
 */


#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)


int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  en_status_t error_sts;

  /* Statistics and Printing Functions Go Here */
  print_array(test, SIZE);
  error_sts = print_statistics(test,SIZE);

  if(error_sts != OK) {
    /* misc error code */
    return 1;
  }

  /* success exit code */
  return 0;
}

en_status_t print_statistics(unsigned char* input, unsigned char size) {
  float result;
  unsigned char result_char;

  /* check for null */
  if (input == NULL) {
    return ERR_NULL;
  }

  result = find_mean(input, size);
  printf("The mean is %f\n", result);

  result = find_median(input, size);
  printf("The median is %f\n", result);

  result_char = find_maximum(input, size);
  printf("The maximum is %d\n", result_char);

  result_char = find_minimum(input, size);
  printf("The minimum is %d\n", result_char);

  return OK;
}


en_status_t print_array(unsigned char* input, unsigned char size) {
  /* check for null */
  if (input == NULL) {
    return ERR_NULL;
  }

  /* print logic */
  for (unsigned char i = 0; i < size; ++i) {
    printf("The array at index %d is %d\n", i, input[i]);
  }

  return OK;
}


float find_median(unsigned char* input, unsigned char size) {
  /* sort the input array */
  sort_array(input, size);

  /* check if even */
  if (size % 2 == 0) {
    return (input[size / 2] + input[(size - 1) / 2]) / 2.0;
  }

  /* when odd median is middle data */
  return input[size / 2];
}


float find_mean(unsigned char* input, unsigned char size) {
  float avg = 0.0;

  /* averaging logic */
  for (int i = 0; i < size; ++i) {
    avg += input[i];
  }

  /* return calculated average */
  return avg/size;
}


unsigned char find_maximum(unsigned char* input, unsigned char size) {
  /* sort the array first */
  sort_array(input, size);

  /* return the largest value. 0th index due to descending sort */
  return input[0];
}


unsigned char find_minimum(unsigned char* input, unsigned char size) {
  /* sort the array first */
  sort_array(input, size);

  /* return the largest value. (size-1)th index due to descending sort */
  return input[size - 1];
}


en_status_t sort_array(unsigned char* input, unsigned char size) {
  /* check for null */
  if (input == NULL) {
    return ERR_NULL;
  }

  /* variable declaration */
  int i, j, swap_chk;
  /* run up to end of the array */
  for (i = 0; i < size - 1; i++) {
    swap_chk = FALSE;
    /* compare with adjacent indices */
    for (j = 0; j < size - i - 1; j++) {
      /* check if descending */
      if(input[j] < input[j + 1]) {
        /* so swap */
        swap(&input[j], &input[j + 1]);
        swap_chk = TRUE;
      }
    }

    /* check for sorted array. */
    if (swap_chk == FALSE) {
      break;
    }
  }

  return OK;
}


en_status_t swap(unsigned char* a, unsigned char* b) {
  /* check for null */
  if (a == NULL || b == NULL) {
    return ERR_NULL;
  }

  /* check if both point to same variable */
  if (a == b) {
    return ERR_LOGIC;
  }

  *a = *a + * b;
  *b = *a - *b;
  *a = *a - *b;

  return OK;
}
