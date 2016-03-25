#include <stdio.h>
int main(int argc, char **argv)
{
    char *name;
    name = argv[0];
    while(*name)
    {
        putchar(tolower(*name++));
    }
}
