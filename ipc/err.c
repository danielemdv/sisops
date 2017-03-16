#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

extern char *pname;

void err_sys(char *fmt, ...)
{
        va_list args;

        va_start(args, fmt);
        if (pname != NULL)
                fprintf(stderr, "%s: ", pname);
        vfprintf(stderr, fmt, args);
        va_end(args);

        exit(1);
}
