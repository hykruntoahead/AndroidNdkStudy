//读入一组文本行,并把最长的文本行打印出来.


#include <stdio.h>

#define MAX_LINE 1000

int getLine(void);
void copy(void);

int main(int argc, char const *argv[])
{
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = getLine()) > 0)
    {
        if (len > max){
            max = len;
            copy();
        }
    }
     
    printf("%d\n",max);
    
    if (max > 0){
        printf("%s",longest);
    }

    return 0;
}

int getLine(void){
    int c,i;
    extern char line[];
    for (i = 0; i < MAX_LINE-1 && (c = getchar())!= EOF && c!='\n' && c!=' '; ++i){
        line[i] = c;
    }
    if (c == '\n'){
        line[i] = c;
        ++i;
    }
    //'\0'为字符串结束标识
    line[i] = '\0';
    return i;
}

void copy(void){
    int i;
    
    extern char line[],longest[];

    i = 0;
    while ((longest[i] = line[i])!= '\0'){
        ++i;
    }
    
}