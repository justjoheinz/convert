#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "cmdline.h"

#define BASE10 10

/**
 * @brief Convert a number into a string which represents the number in binary format.
 Leading zeros are ommited.
 * 
 * @param buffer 
 * @param buf_size 
 * @param number 
 * @return size_t 
 */
size_t
convert_to_bin(char *const buffer, size_t buf_size, unsigned long number)
{
    size_t          bits = (sizeof(unsigned long) * 8 - 1);
    unsigned long   mask = 1UL << bits;
    bool            msb = false;

    assert(buf_size > bits);
    strcpy(buffer, "");

    for (int i = bits; i >= 0; i--, mask = mask >> 1UL) {
        if (number & mask) {
            strncat(buffer, "1", 1);
            msb = true;
        } else if (msb == true) {
            strncat(buffer, "0", 1);
        }
    }
    return strlen(buffer);
}

int
main(int argc, const char *argv[])
{

    char           *stop = NULL;
    unsigned long   value = 0;
    char            buffer[128];

    if (argc == 1) {
        help();
        return EXIT_FAILURE;
    }
    if (argc == 2) {
        if (!strcmp(argv[1], "--help")) {
            help();
            return EXIT_SUCCESS;
        }
    }
    if (argc == 3) {
        int             i = 1;
        const char     *const option = argv[i];

        if (checkOption(option, "--dec", "-d")) {
            value = strtoul(argv[i + 1], &stop, BASE10);
        } else if (checkOption(option, "--hex", "-h")) {
            value = strtoul(argv[i + 1], &stop, 16);
        } else if (checkOption(option, "--bin", "-b")) {
            value = strtoul(argv[i + 1], &stop, 2);
        }
        if (stop && strcmp(stop, "")) {
            printf("Invalid value option = %s\n", stop);
            return EXIT_FAILURE;
        }
    }
    if (argc > 3) {
        fprintf(stderr, "Too many options.");
        return EXIT_FAILURE;
    }

    size_t          bits = convert_to_bin(buffer, sizeof(buffer), value);

    printf("Binary: %lu'b%s\n", bits, buffer);
    printf("Hex   : 0x%lX\n", value);
    printf("Dec   : %lu\n", value);

    return EXIT_SUCCESS;
}
