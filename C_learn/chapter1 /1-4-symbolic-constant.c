#include <stdio.h>

/*
  符号常量 :
  #define 命名 替换文本

  注意:define语句尾部没有;
*/
#define LOWER 0     /* low limit of table*/
#define UPPER 300   /* upper limit*/
#define STEP 20 /*step size*/

int main(int argc, char const *argv[])
{
    int fahr ;

    for (fahr = LOWER; fahr <= UPPER;fahr = fahr + STEP){
        printf("%3d %6.1f\n",fahr,(5.0/9.0)*(fahr-32));
    }
    
    return 0;
}


