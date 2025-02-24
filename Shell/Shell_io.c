#include <stdarg.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "Shell_io.h"


static void _Echo(char c) 
{
    if ('\n' == c) 
    {
        ioShell()->putchar('\r');
        ioShell()->putchar('\n');
    } 
    else if ('\b' == c) 
    {
        ioShell()->putchar('\b');
        ioShell()->putchar(' ');
        ioShell()->putchar('\b');
    } 
    else 
    {
        ioShell()->putchar(c);
    }
}

void _Printf(const char *format, ...)
{
    char buffer[128]; // Adjust size as needed
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    
    for (const char *c = buffer; *c != '\0'; ++c) 
    {
        _Echo(*c);
    }
    
}

static Shell_io_ts mShellObject = 
{
    .getchar = getchar,
    .putchar = putchar,
    .printf = _Printf
};



/*============================================================================*/
/*== Implementation of Public Functions ======================================*/
/*============================================================================*/

/*----------------------------------------------------------------------------*/
Shell_io_ts* ioShell(void)
{
    return &mShellObject;
}