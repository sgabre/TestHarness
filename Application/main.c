#include <stdio.h>
#include <Module.h>

int main(int argc, char *argv[])
{
    printf("Average of 4, 5, and 6: %d\n", Module_Function(4, 5, 6));

    return 0;
}
