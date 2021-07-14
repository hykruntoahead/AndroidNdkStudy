#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int inputNumber;

    cout << "Enter an integer: ";

    cin >> inputNumber;

    cout << "Enter your name: ";

    string inputName;

    cin >> inputName;

    cout << inputName << " entered " << inputNumber << endl;

    return 0;
}
