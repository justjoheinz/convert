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
    fprintf(stderr, "--hex,  -h \t\t convert a hexadecimal value\n");
    fprintf(stderr, "--help     \t\t display this help\n");
}

/**
 * @brief checks if a argv is one of two options
 * 
 * @param option the argv under consideration
 * @param longOpt  e.g. --dec
 * @param shortOpt e.g. -d 
 * @return int 0 if match was found
 */
int
checkOption(const char *const option, const char *const longOpt,
            const char *const shortOpt)
{
    return !strcmp(option, longOpt) || !strcmp(option, shortOpt);
}
