#include<iostream>
#include<string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Enter a word NOT longer than 20 characters:" << endl;

    char userInput [21] = {'\0'};

    cin >> userInput;

    cout << "Length of your input was :" << strlen(userInput) << endl;

    /* code */
    return 0;
}
