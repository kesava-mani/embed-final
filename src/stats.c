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
 * @date August 2020.
 *
 */

#include "stats.h"


/* Size of the Data Set */
#define SIZE (40)


en_status_t print_statistics(unsigned char* input, unsigned char size) {
  float result;
  unsigned char result_char;

  /* check for null */
  if (input == NULL) {
    return ERR_NULL;
  }

  result = find_mean(input, size);
  PRINTF("The mean is %f\n", result);

  result = find_median(input, size);
  PRINTF("The median is %f\n", result);

  result_char = find_maximum(input, size);
  PRINTF("The maximum is %d\n", result_char);

  result_char = find_minimum(input, size);
  PRINTF("The minimum is %d\n", result_char);

  if (result != OK || result_char != OK) {
    return ERR_LOGIC;
  }

  return OK;
}


en_status_t print_array(unsigned char* input, unsigned char size) {
#if(VERBOSE == TRUE)
  /* check for null */
  if (input == NULL) {
    return ERR_NULL;
  }

  /* print logic */
  for (unsigned char i = 0; i < size; ++i) {
    PRINTF("%d\t", input[i]);
  }
  PRINTF("\n\n");
#endif // VERBOSE

  return OK;

}



float find_median(unsigned char* input, unsigned char size) {
  /* sort the input array */
  sort_array(input, size);

  /* check if even */
  if (size % 2 == 0) {
    return (input[size / 2] + input[(size - 1) / 2]) / 2.0F;
  }

  /* when odd median is middle data */
  return input[size / 2];
}


float find_mean(unsigned char* input, unsigned char size) {
  float avg = 0.0F;

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
