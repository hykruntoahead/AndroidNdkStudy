#include <stdio.h>
/*
打印华氏温度与摄氏温度对照表
*/
int main(int argc, char const *argv[])
{
    float fahr,celsius;
    float lower,upper,step;

    lower = 0; //温度表下限
    upper = 300; //温度表上限
    step = 20;

    fahr = lower;
    while (fahr <= upper){
        celsius = 5.0/9.0 * (fahr-32.0); 
        printf("%3.0f\t%6.0f\n",fahr,celsius);
        fahr = fahr + step;
    }

    return 0;
}
