## 参照书籍＜21天学通C++＞


### Chapter1:绪论

#### 1.1 C++简史

使用 C++编写的**应用程序、操作系统、Web 服务、数据库和企业软件**多如牛毛，因此无论您从事
什么工作，使用计算机来做什么，都可能正在使用 C++编写的软件。除软件工程师外，C++还常被物
理学家和数学家用来从事研究工作。

#### 1.2 编写 C++应用程序

##### 生成可执行文件的步骤

1．使用文本编辑器编写 C++代码。
2．使用 C++编译器对代码进行编译，将代码转换为包含在目标文件中的机器语言版本。
3．使用链接器链接编译器的输出，生成一个可执行文件

在编译过程中，C++代码（通常包含在.cpp 文本文件中）被转换为处理器能够执行的字节码。编
译器每次转换一个代码文件，生成一个扩展名为.o 或.obj 的目标文件，并忽略这个 cpp 文件可能对其他
文件中代码的依赖。解析这些依存关系的工作由链接程序负责，如果链接成功，则创建一个可执行文
件，供程序员执行和分发。整个过程也被称为构建可执行文件。

##### 编写第一个 C++应用程序
　
helloworld.cpp(/chapter_1/1.2_helloworld.cpp)

##### 生成并执行第一个 C++应用程序

调用 g++编译器和链接程序：
   g++ -o hello 1.2_helloworld.cpp
该命令行让 g++编译 C++文件 1.2_helloworld.cpp，并创建一个名为 hello 的可执行文件。


### Chapter2 C++ 程序的组成部分

#### 2.1 Hello World 程序的组成部分

```
 // Preprocessor directive that includes header iostream 
 #include <iostream> 

 // Start of your program: function block main() 
 int main() 
 { 
 /* Write to the screen */ 
  std::cout << "Hello World" << std::endl; 
 
// Return a value to the OS 
 return 0; 
 } 
```

##### 预处理器编译指令#include

预处理器是一个在编译前运行的工具。

#include <filename>让预处理器获取指定文件（这里是 iostream）的内容，并将它们放在在编译指令所处的位置。iostream 是一个标准头文件.

注意：尖括号（<>）通常用于包含标准头文件．＃include "fileA";双引号包含自己创建的头文件


##### 程序的主体　main()

声明main( )时，总是在它前面加上 int，这是一种标准化约定，表示 main( )函数的返回类型为整数。

代码段:
```
 std::cout << "Hello World" << std::endl; 
```
**cout（控制台输出，读作 see-out）**是将 Hello World 显示到控制台（即屏幕）的语句。cout 是在名
称空间 std 中定义的一个流（因此这里使用了 std::cout），这里使用**流插入运算符<<**将文本 Hello World
放到这个流中。**std::endl 用于换行**，将其插入流中相当于插入回车。每次需要将新实体插入流中时，都
使用了流插入运算符<<。


##### 返回值
程序员可使用 main( )的返回值向父应用程序传递成功或错误状态。
根据约定，程序员在程序运行成功时返回 0，并在出现错误时返回−1。然而，返回值为整数，程序员可利用整个整数范围，指出众多不同的成功或失败状态。

#### 2.2名称空间的概念

程序中使用的是 std::cout 而不是 cout，原因在于 **cout 位于标准（std）名称空间**中。

名称空间是给代码指定的名称，有助于降低命名冲突的风险。

> 使用 std（读作 standard）名称空间来调用获得 ISO 标准委员会批准的函数、流和工具。

使用 cout 和 std 名称空间中的其他功能时，在代码中添加 std 限定符很繁琐。为避免添加该限定符，可使用声明 **using namespace**

代码见：/chapter_2/2.2.cpp

更严谨写法：/chapter_2/2.3.cpp

#### 2.３ C++代码注释
两种风格：
- // 指出从这里开始到行尾都为注释 即单行注释
- /*和*/表示它们之间的文本为注释，多行注释

#### 2.4 C++函数

函数让您能够将应用程序划分成多个功能单元，并按您选择的顺序调用。

／chapter_2/2.4.cpp: 声明、定义和调用函数

函数可以接受参数，可以递归，可以包含多条返回语句，可以重载。函数还可声明为内联的，在
这种情况下，编译器将展开函数调用。

#### 2.5 使用 std::cin 和 std::cout 执行基本输入输出操作

要将简单的文本数据写入到控制台，可使用 **std::cout（读作 standard see-out）**；要从控制台读取文本和数字，可使用 **std::cin（读作 standard see-in）**。

cin 的用法很简单:
```
  std::cin >> Variable; 
```

cin 后面依次为**提取运算符>>（从输入流中提取数据）**以及要将数据存储到其中的变量。

具体使用：/chapter_2/2.6.cpp


### Chapter3 使用变量和常量

变量让程序员能够将数据临时存储一段时间，而常量让程序员能够定义不允许修改的东西．

#### 3.1 什么是变量

##### 内存和寻址概述

可编程设备都包含微处理器和一定数量的临时存储空间，这种临时存储器被称为随机存取存储器（RAM）。

可以将 RAM 当作宿舍里成排存物柜的存储区域，每个存物柜都有编号，即地址。要访问特定的内存单元，如内存单元 578，需要使用指令要求处理器从这里获取值或将值写入到这里。

##### 声明变量以访问和使用内存

定义变量非常简单，其语法如下：

```
  VariableType VariableName; 
  //或
  VariableType VariableName = InitialValue; 
```
变量类型向编译器指出了变量可存储的数据的性质，编译器将为变量预留必要的空间。

代码示例见:/chapter_3/3.1.cpp

分析其中的一个变量声明：

int firstNumber = 0; 

这行代码声明了一个变量，其类型为 int（表示整型），名称为 firstNumber，并将该变量的初始值设置为零.

将变量 firstNumber 关联到内存单元的工作由编译器负责，它还负责为您完成相关的簿记工作。
这样，程序员就可使用对人类友好的名称，把将变量关联到地址以及创建 RAM 访问指令的工作留给编
译器去做。


#### 声明并初始化多个类型相同的变量

```
  int firstNumber = 0, secondNumber = 0, multiplicationResult = 0; 
```

#### 理解变量的作用域

常规变量（如前面定义的所有变量）的作用域很明确，只能在作用域内使用它们，如果您在作用
域外使用它们，编译器将无法识别，导致程序无法通过编译。在作用域外面，变量是未定义的实体，
编译器对其一无所知。

#### 全局变量

如果变量是在函数外部而不是内部声明的，则在函数 中都可使用它们。

#### 命名约定

对于变量名，采用骆驼拼写法，而对于诸如
函数名等其他元素，采用 Pascal 拼写法．


### 3.2 编译器支持的常见 C++变量类型

| 类型 | 值 |
| --- | --- |
| bool | true/false |
| char | 256 个字符值 |
| unsigned short int | 0～65535 | 
| short int | –32768～32767 | 
| unsigned long int | 0～4294967295 | 
| long int | –2147483648～2147483647 |
| int (16 位) | –32768～32767 |
| int (32 位) | –2147483648～2147483647 |
| unsigned int（16 位） | 0～65535 |
| unsigned int（32 位） | 0～4294967295 |
| float | 1.2e–38～3.4e38 |
| double | 2.2e–308～1.8e308 |


诸如 short、int、long、unsigned short、unsigned int、unsigned long 等数据类型的容量有限，如果
算术运算的结果超出了选定数据类型的上限，将导致溢出.

演示有符号整型变量和无符号整型变量溢出的负面影响:/chapter_3/3.4.cpp

> C++14 新增了用单引号表示的组块分隔符（chunking separator）。使用这种分隔符可提高
> 代码的可读性，如下面的初始化语句所示：
> int moneyInBank = -70'000; // -70000 
> long populationChange = -85'000; // -85000 
> long long countryGDPChange = -70'000'000'000; // -70 billion 
> double pi = 3.141'592'653'59; // 3.14159265359 

### 3.3 使用 sizeof 确定变量的长度
   变量长度指的是程序员声明变量时，编译器将预留多少内存，用于存储赋给该变量的数据。变量
的长度随类型而异，C++提供了一个方便的运算符—sizeof，可用于确定变量的长度（单位为字节）
或类型。
    
**使用列表初始化避免缩窄转换错误**
   使用取值范围较大的变量来初始化取值范围较小的变量时，将面临出现缩窄转换错误的风险，因
为编译器必须将大得多的值存储到容量没那么大的变量中，下面是一个这样的示例：
int largeNum = 5000000; 
short smallNum = largeNum; // compiles OK, yet narrowing error 
   
   
### 3.4 使用 auto 自动推断类型
   
### 3.5 使用 typedef 替换变量类型

   ```
   typedef unsigned int STRICTLY_POSITIVE_INTEGER; 
   STRICTLY_POSITIVE_INTEGER numEggsInBasket = 4532; 
   ```

### 3.6 什么是常量
   在 C++中，常量可以是：
   - 字面常量；
   - 使用关键字 **const** 声明的常量；
   - 使用关键字 **constexpr** 声明的常量表达式（C++11 新增的）；
   - 使用关键字 **enum** 声明的枚举常量；
   - 使用**#define**定义的常量（已摒弃，不推荐）。
   
   
## 4.管理数组和字符串   
   - 数组是一系列元素；
   - 数组中所有元素的类型都相同；
   - 这组元素形成一个完整的集合。
在 C++中，数组让您能够按顺序将一系列相同类型的数据存储到内存中.
### 4.1 一维数组   
#### 4.1.1 为何需要数组
   
#### 4.1.2 声明和初始化静态数组
   
- int myNumbers [5] = {34, 56, -21, 5002, 365};
- int myNumbers [5] = {}; // initializes all integers to 0 
- int myNumbers [5] = {34, 56}; // initialize first two elements to 34 and 56 and the rest to 0 
- const int ARRAY_LENGTH = 5; 
  int myNumbers [ARRAYLENGTH] = {34, 56, -21, 5002, 365};
- int myNumbers [] = {2016, 2052, -525}; // array of 3 elements 
   
#### 4.1.3 数组中的数据是如何存储的
> 一般而言，编译器为数组预留的内存量如下所示（单位为字节）：
Bytes consumed by an array = sizeof(element-type) * Number of Elements
   
#### 4.1.4 访问存储在数组中的数据
    myNumbers [0] //0 - len-1
   
#### 4.1.5 修改存储在数组中的数据
   myNumbers [3] = 2016; 

### 4.2　多维数组 

#### 4.2.1 声明和初始化多维数组
   
   int solarPanels [2][3] = {{0, 1, 2}, {3, 4, 5}}; 

#### 4.2.2 访问多维数组中的元素
   
   可将多维数组视为由数组组成的数组。

```
   int threeRowsThreeColumns [3][3] = {{-501, 205, 2016}, {989, 101, 206}, {303, 456, 596}}; 
   //访问
   int num = threeRowsThreeColumns [0][1] 
```
   
### 4.3 动态数组
   。C++提供了 std::vector，这是一种方便而易于使用的动态数组.(代码示例:见4.4.cpp)
### 4.4 C 风格字符串
   
   char sayHello[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', 
'\0'}; 
   
### 4.5 C++字符串：使用 std::string
   
   无论是处理文本输入，还是执行拼接等字符串操作，使用 C++标准字符串都是更高效、更安全的
方式。不同于字符数组（C 风格字符串实现），std::string 是动态的，在需要存储更多数据时其容量将增
大。
   
