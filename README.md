# embed-final
Final project of Coursera's Introduction to Embedded Systems Software and Development Environments
### Features
This project implements
* basic statistics on given input data
    * mean()
    * median()
    * sort()
    * find_maximum()
    * find_minimum()

* memory functions
    * memmove()
    * memcpy()
    * memset()
    * memzero()
    * reverse()
    * reserve_words()
    * free()

* Data conversion
    * itoa() - integer to string
    * atoi() - string to integer

Refer to respective header file for documentation about the function.

### Build
Build system utilize make. Source and header files are in ./src and ./include respectively. Makefile for the project is in project root directory. 
This build supports compiling for two architectures - x86 and ARM.
The sources to be included in the build must be added in sources.mk file.
This file is included in Makefile using include directive.
Refer to the Makefile for the available targets.
Targets are built in the project root directory.

To build with verbose option, pass VERBOSE=YES.
```bash
make build PLATFORM=HOST VERBOSE=YES
```
