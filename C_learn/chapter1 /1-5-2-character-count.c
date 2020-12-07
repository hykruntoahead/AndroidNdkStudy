#include <stdio.h>
/*
字符计数
*/
int main(int argc, char const *argv[]){
    long nc;
    nc =0;
    while(getchar() != EOF){
        ++nc;;
        printf("%ld\n",nc);
    }
    return 0;
}
