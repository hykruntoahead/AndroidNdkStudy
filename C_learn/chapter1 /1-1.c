#include <stdio.h>

int main(int argc, char const *argv[])
{
    //style1 printf
    printf("hello, world\n");
    //style2 printf
    printf("hello,");
    printf("world");
    printf("\n");

    //practice - "warning: unknown escape sequence: '\c'"
    // printf("hello \c");
    return 0;
}
