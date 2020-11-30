#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#include "cmdline.h"

struct option   convert_options[] = {
    {"help", no_argument, 0, 'h'},
    {"dec", required_argument, 0, 'd'},
    {"bin", required_argument, 0, 'b'},
    {"hex", required_argument, 0, 'x'},
    {0, 0, 0, 0}
};

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
main(int argc, char **argv)
{

    char           *stop = NULL;
    unsigned long   value = 0;
    char            buffer[128];

    int             index,
                    c;
    while (1) {
        c = getopt_long(argc, argv, "hd:b:x:", convert_options, &index);

        if (c == -1)
            break;

        switch (c) {
        case 'h':
            help();
            return EXIT_SUCCESS;
        case 'd':
            value = strtoul(optarg, &stop, 10);
            break;
        case 'b':
            value = strtoul(optarg, &stop, 2);
            break;
        case 'x':
            value = strtoul(optarg, &stop, 16);
            break;
        }

        if (stop && strcmp(stop, "")) {
            printf("Invalid value option = %s\n", stop);
            return EXIT_FAILURE;
        }

        size_t          bits =
            convert_to_bin(buffer, sizeof(buffer), value);

        printf("Binary: %lu'b%s\n", bits, buffer);
        printf("Hex   : 0x%lX\n", value);
        printf("Dec   : %lu\n\n", value);
    }

    return EXIT_SUCCESS;
}
