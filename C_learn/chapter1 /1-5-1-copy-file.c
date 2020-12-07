#include <stdio.h>
/*
把输入一次一个字符地复制到输出
*/
int main(int argc, char const *argv[])
{
    int c;
    c = getchar();
    while (c != EOF)
    {
        putchar(c);
        c = getchar();
    }
    
    return 0;
}
