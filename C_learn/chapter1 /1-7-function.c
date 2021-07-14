#include <stdio.h>

//函数声明
int power(int m,int n);

int main(int argc, char const *argv[])
{
    int i;

    for(i = 0;i<10;++i)
        printf("%d %d %d\n",i,power(2,i),power(-3,i));
    return 0;
}

//函数定义
//传值调用-被调用函数不能直接修改主调函数中变量的值,而只能修改其私有的临时副本的值
int power(int base,int n){
    int i,p;

    p =1;
    for (i = 1; i <= n; ++i){
        p =p *base;
    }
    return p;
}
