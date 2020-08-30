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
 * @file stats.h
 * @brief Computes statistics on the given data.
 *
 * The statistics include mean, median, maximum and minimum of the given data.
 * The function and variable declaration for this are done in this file.
 *
 * @author Kesava Mani U
 * @date August 2020.
 *
 */


#ifndef __STATS_H__
#define __STATS_H__

#include "platform.h"
#include <stddef.h>
/**
 * @brief Prints the statistics of input data.
 *
 * Computes all statistics including mean, median, maximum and minimum
 * calculations.
 *
 * @param input - The data to be printed.
 * @param size - The size of the data to be printed.
 *
 * @return One of the values of en_status_t.
 */
en_status_t print_statistics(unsigned char* input, unsigned char size);


/**
 * @brief Prints the input array.
 *
 * This function prints the input data to standard output. Needs stdio.h to be
 * included.
 *
 * @param input - The data to be printed.
 * @param size - The size of the data to be printed.
 *
 * @return One of the values of en_status_t.
 */
en_status_t print_array(unsigned char* input, unsigned char size);


/**
 * @brief Calculates the median
 *
 * Performs median calculation of input array data. Data is sorted inside the
 * function.
 *
 * @param *input - The data to be calculated
 * @param size - The size of the data.
 *
 * @return Calculated median in float type
 */
float find_median(unsigned char* input, unsigned char size);


/**
 * @brief Calculates the mean.
 *
 * This function calculates average on input data like how normal person
 * would do.
 *
 * @param *input - The data to be calculated
 * @param size - The size of the data.
 *
 * @return Mean value in float type.
 */
float find_mean(unsigned char* input, unsigned char size);


/**
 * @brief Calculates maximum of the input.
 *
 * The input is sorted implicit and maximum value is returned.
 *
 * @param *input - The data to be calculated
 * @param size - The size of the data.
 *
 * @return Maximum value.
 */
unsigned char find_maximum(unsigned char* input, unsigned char size);


/**
 * @brief Calculates minimum of the input.
 *
 * The input is sorted implicit and minimum value is returned.
 *
 * @param *input - The data to be calculated
 * @param size - The size of the data.
 *
 * @return Minumum value.
 */
unsigned char find_minimum(unsigned char* input, unsigned char size);


/**
 * @brief Sorts the input array.
 *
 * This function sorts the input array using bubble sort algorithm.
 * Optimizations done include checking array if it is already sorted and
 * inner loop iteration reduction.
 *
 * @param *input - The data to be calculated
 * @param size - The size of the data.
 *
 * @return One of the values of en_status_t.
 */
en_status_t sort_array(unsigned char* input, unsigned char size);


/**
 * @brief Performs swapping
 *
 * This function does the swapping of two numbers. Pointers to the data must
 *  be passed as input.
 *
 * @param *a - Fist data
 * @param *b - Second data
 *
 * @return One of the values of en_status_t.
 */
en_status_t swap(unsigned char* a, unsigned char* b);






#endif /* __STATS_H__ */
