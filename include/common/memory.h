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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls.
 *
 * @author Kesava Mani
 * @date August 2020
 *
 */

#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * @brief Sets a value of a data array
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero.
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/****************************************************************************/
/*                        Implemented Memory functions                      */
/****************************************************************************/
/**
 * @brief Moves elements from source to destination array
 *
 * Given a pointer to a byte array, this will move a number of elements
 * from a provided data array to the destination. The length is determined
 * by the provided size parameter. Overlapping of source data set is handled.
 *
 * @param ptr Pointer to the source data array
 * @param dst Pointer to the destination data array
 * @param length Number of elements to be copied
 *
 * @return Pointer to the moved array
 */
uint8_t* my_memmove(uint8_t * src, uint8_t * dst, size_t length);


/**
 * @brief Copies elements from source to destination array
 *
 * Given a pointer to a byte array, this will copy a number of elements
 * from a provided data array to the destination array. The length is
 * determined by the provided length parameter.
 *
 * @param ptr Pointer to the source data array
 * @param dst Pointer to the destination data array
 * @param length Number of elements to be copied
 *
 * @return Pointer to the copied array
 */
uint8_t* my_memcopy(uint8_t * src, uint8_t * dst, size_t length);


/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a byte array, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param src Pointer to data array
 * @param length Number of elements to set to value
 * @param value Value to write in the specified memory
 *
 * @return pointer to value set array
 */
uint8_t* my_memset(uint8_t * src, size_t length, uint8_t value);


/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a byte array, this will clear a number
 * of elements given the size provided. Clear means to set to zero.
 *
 * @param src Pointer to data array
 * @param length Number of elements to set to zero
 *
 * @return pointer to the zeroed array
 */
uint8_t* my_memzero(uint8_t * src, size_t length);


/**
 * @brief Reverses the elements of input array
 *
 * Given a byte pointer to input data of respective length, this reverse their
 * element's order using pointer arithmetic.
 *
 * @param src Pointer to data array
 * @param length Number of elements to be reversed
 *
 * @return pointer to the reversed array
 */
uint8_t* my_reverse(uint8_t * src, size_t length);


/**
 * @brief Dynamic allocation for input length.
 *
 * Given a length of data to be allocated, this function reserve them using
 * malloc(). Note that if memory reservation fails, NULL is returned. User
 * must check of this condition in their application.
 *
 * @param length Number of bytes to set to allocated
 *
 * @return word pointer to allocated memory
 */
int32_t* reserve_words(size_t length);


/**
 * @brief Clears memory allocated using reserve_words()
 *
 * Given a pointer to allocated memory, this will free the total memory
 * allocated.
 *
 * @param src Pointer to the allocated memory
 *
 * @return void.
 */
void free_words(uint32_t * src);


#endif /* __MEMORY_H__ */
