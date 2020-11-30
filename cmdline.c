#include <stdio.h>
#include <string.h>

/**
 * @brief prints help instructions to stderr
 * 
 */
void
help(void)
{
    fprintf(stderr, "Convert <option> <value>\n\n");
    fprintf(stderr, "Options:\n");
    fprintf(stderr, "--dec,  -d \t\t convert a decimal value\n");
    fprintf(stderr, "--bin,  -b \t\t convert a binary value\n");
    fprintf(stderr, "--hex,  -x \t\t convert a hexadecimal value\n");
    fprintf(stderr, "--help, -h \t\t display this help\n");
}
