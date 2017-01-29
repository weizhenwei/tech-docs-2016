/*
 *  test extern "C"
 *  2017.05.09
 *  weizhenwei
 */

#include <stdio.h>
#include "extern_c.h"

void print_hello()
{
    fprintf(stdout, "Hello, world!\n");
    fflush(stdout);
}

