//
// Created by hyk on 20-12-7.
// 数组使用
//

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c,i,nwhite,nother;
    int ndight[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; i++){
        ndight[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <='9'){
            ++ndight[c - '0'];
        }else if (c == ' ' || c == '\n' || c == '\t'){
            ++nwhite;
        }else{
            ++nother;
        } 
    }

    printf("digits=");
    for ( i = 0; i < 10; i++){
        printf(" %d",ndight[i]);
    }
    printf(",white space = %d,other = %d \n",nwhite,nother);      

    return 0;
}
