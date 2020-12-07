#include <stdio.h>
/*
  把输入一次一个字符地复制到输出
  EOF:
  linux系统下，在输入bai回车换行后的空行位置，按 ctrl+d (先按ctrl键，不放，再按d键）。
  windows系统下，在输入回车换行后的空行位置，按 ctrl+z，再回车确认。
*/
int main(int argc, char const *argv[])
{
    int c; 
    while ((c = getchar()) != EOF)
    {
        putchar(c);
        c = getchar();
    }
    // printf("EOF=%d",EOF);//EOF =-1
    
    return 0;
}
