//读入一组文本行,并把最长的文本行打印出来.


#include <stdio.h>

#define MAX_LINE 1000

int getLine(char line[],int maxLine);
void copy(char to[],char from[]);

int main(int argc, char const *argv[])
{
    int len;
    int max;

    char line[MAX_LINE];
    char longest[MAX_LINE];

    max = 0;
    while ((len = getLine(line,MAX_LINE)) > 0)
    {
        if (len > max){
            max = len;
            copy(longest,line);
        }
    }
     
    printf("%d\n",max);

    if (max > 0){
        printf("%s",longest);
    }

    return 0;
}

int getLine(char s[],int lim){
    int c,i;

    for (i = 0; i < lim-1 && (c = getchar())!= EOF && c!='\n'; ++i){
        s[i] = c;
    }
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    //'\0'为字符串结束标识
    s[i] = '\0';
    return i;
}

void copy(char to[],char from[]){
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0'){
        ++i;
    }
    
}