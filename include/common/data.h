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



#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>
#include <stddef.h>


/****************************************************************************/
/*                Implemented data conversion functions                     */
/****************************************************************************/
/**
 * @brief Sets a value of a data array
 *
 * Handles the conversion of input integer to equivalent string representation
 * for the specified radix. Signedness of decimal number only is handled.
 *
 * @param data Input number to be converted
 * @param ptr Buffer to store the converted string
 * @param base Radix of the input number
 *
 * @return Length of converted string
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);


/**
 * @brief Converts the input integer string to integer
 *
 * Handles the integer string of given digits to integer type conversion with
 * radix of input number ranging from 2 to 16. Checks if individual number is
 * within the range of given radix is done.
 *
 * @param ptr Buffer to the input integer string
 * @param digits No. of digits in input number
 * @param base Radix of the input number
 *
 * @return Converted integer
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);


#endif /* __DATA_H__ */
