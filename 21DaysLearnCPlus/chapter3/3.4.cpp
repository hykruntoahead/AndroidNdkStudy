 #include <iostream> 
 using namespace std; 

// 变量溢出
int main() 
{ 

unsigned short uShortValue = 65535; 
cout << "Incrementing unsigned short " << uShortValue << " gives: "; //0
cout << ++uShortValue << endl; 

short signedShort = 32767; 
cout << "Incrementing signed short " << signedShort << " gives: "; //-32768
cout << ++signedShort << endl; 

return 0; 
} 