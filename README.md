# AndroidNdkStudy

## Android NDK 开发：CMake 使用

### 1.CMake 是什么？
CMake 是一个开源的跨平台自动化构建系统。
#### 1.1 CMake 的特点
- 1）开放源代码，使用类 BSD 许可发布。
- 2）跨平台，并可生成 native 编译配置文件，在 Linux/Unix 平台，生成 makefile，在Mac 平台，可以生成 xcode，在 Windows 平台，可以生成 MSVC 的工程文件。
- 3）能够管理大型项目；
- 4）简化编译构建过程和编译过程。Cmake 的工具链非常简单：cmake+make。
- 5）高效率；
- 6）可扩展，可以为 cmake 编写特定功能的模块，扩充 cmake 功能。

#### 1.2 使用建议

    1）如果你没有实际的项目需求，那么看到这里就可以停下来了，因为 CMake 的学习过程就是实践过程，没有实践，读的再多几天后也会忘记；
    2）如果你的工程只有几个文件，直接编写 Makefile 是最好的选择；（那得学习 make 命令和熟悉 Makefile 的构建规则，这是另外一回事了）
    3）如果使用的是 C/C++/Java 之外的语言，请不要使用 CMake；
    4）如果你使用的语言有非常完备的构建体系，比如 java 的 ant，也不需要学习 cmake；
    5）如果项目已经采用了非常完备的工程管理工具，并且不存在维护问题，没有必要迁移到CMake

CMakeLists.txt 文件是**CMake 的构建定义文件**。如果工程存在多个目录，需要在每个要管理的目录都添加一个 CMakeLists.txt 文件。

### 2.CMake命令
CMake命令行格式有很多种，介绍常用一种:
```
cmake [<options>] (<path-to-source> | <path-to-existing-build>)
```
options 为可选项，为空时，构建的路径为当前路径。
options 的值，可以通过输入cmake --help 查看，比如：
-G <generator-name> 是指定构建系统的生成器，当前平台所支持的 generator-name 也可以通过cmake --help查看。（options 一般默认为空就好，这里不做过多介绍）

path-to-source和path-to-existing-build二选一，分别表示 CMakeLists.txt 所在的路径和一个已存在的构建工程的目录

cmake .表示构建当前目录下 CMakeLists.txt 的配置，并在当前目录下生成 Makefile 等文件；【属于内部构建】
cmake ..表示构建上一级目录下 CMakeLists.txt 的配置，并在当前目录下生成 Makefile 等文件；
cmake [参数] [指定进行编译的目录或存放Makefile文件的目录] [指定CMakeLists.txt文件所在的目录] 【属于外部构建】

**内部构建（in-source build）与外部构建（out-of-source build）**  

内部构建生成的临时文件可能比源代码还要多，非常影响工程的目录结构和可读性。   
**Make官方建议使用外部构建，外部构建可以达到将生成中间产物与源代码分离。**

### 3.Hello CMake

 注:Ubuntu平台下
 ```shell script
apt install cmake
...
cmake -version #检验是否安装　显示cmake版本号
```
创建CMake/t1　目录,编写main.c 和 CMakeLists.txt文件

```  
#include <stdio.h>
int main()
{
    printf(“Hello World from CMake!\n”);
    return 0;
}
```

```cmake
PROJECT(HELLO)
SET(SRC_LIST main.c)
MESSAGE(STATUS "This is BINARY dir " ${HELLO_BINARY_DIR})  #终端打印的信息
MESSAGE(STATUS "This is SOURCE dir "${HELLO_SOURCE_DIR})
ADD_EXECUTABLE(hello ${SRC_LIST})
```

这里如果直接输入cmake .开始构建，属于内部构建。建议采用外部构建的方法，先建一个 build 文件夹，
进入 build 文件夹在执行cmake ..。构建后出现很多 log 包含以下，说明构建成功，并且目录下会生成
CMakeFiles, CMakeCache.txt, cmake_install.cmake, Makefile 等文件
```
-- This is BINARY dir /Users/cfanr/AndroidStudioProjects/NDK/CMake/t1
-- This is SOURCE dir /Users/cfanr/AndroidStudioProjects/NDK/CMake/t1
-- Configuring done
-- Generating done
-- Build files have been written to: /Users/cfanr/AndroidStudioProjects/NDK/CMake/t1
```
然后执行make命令,会生成 main.c 对应的可执行文件hello，并会出现以下彩色的 log
```
[ 50%] Building C object CMakeFiles/hello.dir/main.c.o
[100%] Linking C executable hello
[100%] Built target hello
```
最后执行 ./hello 会打印输出：
``` 
Hello World from CMake!
```

### 4.CMake 的基本语法规则
- 使用星号 # 作为注释
- 变量使用 ${} 方式取值，但是在 IF 控制语句中是直接使用变量名
- 指令名(参数1 参数2 …)，其中参数之间使用空格或分号隔开
- 指令与大小写无关，但参数和变量是大小写相关的

### 5.CMake 常用指令

#### 5.1 project 指令
语法: project([CXX][C][Java])
这个指令是定义工程名称的，并且可以指定工程支持的语言（当然也可以忽略，默认情况表示支持所有语言），**不是强制定义的**。
例如：project(HELLO)  

定义完这个指令会隐式定义了两个变量：  
<projectname>_BINARY_DIR和<projectname>_SOURCE_DIR  
由上面的例子也可以看到，MESSAGE 指令有用到这两个变量；  
 
另外 CMake 系统还会预定义了 PROJECT_BINARY_DIR 和 PROJECT_SOURCE_DIR 变量，  
它们的值和上面两个的变量对应的值是一致的。不过为了统一起见，  
建议直接使用PROJECT_BINARY_DIR 和PROJECT_SOURCE_DIR，即使以后修改了工程名字，也不会影响两个变量的使用。

#### 5.2 set 指令
语法:set(VAR [VALUE])
这个指令是用来显式地定义变量，多个变量用空格或分号隔开
例如：
```cmake
set(SRC_LIST main.c test.c)

```

注意，当需要用到定义的 SRC_LIST 变量时，需要用${var}的形式来引用，如：${SRC_LIST}
不过，在 IF 控制语句中可以直接使用变量名。

#### 5.3 message 指令
语法：message([SEND_ERROR | STATUS | FATAL_ERROR] “message to display” … )
这个指令用于向终端输出用户定义的信息，包含了三种类型：
SEND_ERROR，产生错误，生成过程被跳过；
STATUS，输出前缀为—-的信息；（由上面例子也可以看到会在终端输出相关信息）
FATAL_ERROR，立即终止所有 CMake 过程；

#### 5.4 add_executable　指令
语法：add_executable(executable_file_name [source])
将一组源文件 source 生成一个可执行文件。 source 可以是多个源文件，也可以是对应定义的变量
如：add_executable(hello main.c)

#### 5.5 cmake_minimun_required(VERSION 3.4.1)
用来指定 CMake 最低版本为3.4.1，如果没指定，执行 cmake 命令时可能会出错

#### 5.6 add_subdirectory 指令
语法：add_subdirectory(source_dir [binary_dir] [EXCLUDE_FROM_ALL])
这个指令用于向当前工程添加存放源文件的子目录，并可以指定中间二进制和目标二进制存放的位置。
EXCLUDE_FROM_ALL参数含义是将这个目录从编译过程中排除。

另外，也可以通过 SET 指令重新定义 EXECUTABLE_OUTPUT_PATH 和 LIBRARY_OUTPUT_PATH 变量来指定最终的目标二进制的位置(指最终生成的 hello 或者最终的共享库，不包含编译生成的中间文件)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

#### 5.7 add_library 指令
语法：add_library(libname [SHARED | STATIC | MODULE] [EXCLUDE_FROM_ALL] [source])
将一组源文件 source 编译出一个库文件，并保存为 libname.so (lib 前缀是生成文件时 CMake自动添加上去的)。其中有三种库文件类型，
**不写的话，默认为 STATIC**: 
- SHARED: 表示动态库，可以在(Java)代码中使用 System.loadLibrary(name) 动态调用；
- STATIC: 表示静态库，集成到代码中会在编译时调用
- MODULE: 只有在使用 dyId 的系统有效，如果不支持 dyId，则被当作 SHARED 对待
- EXCLUDE_FROM_ALL: 表示这个库不被默认构建，除非其他组件依赖或手工构建

```
#将compress.c 编译成 libcompress.so 的共享库
add_library(compress SHARED compress.c)
```
add_library 命令也可以用来导入第三方的库:
add_library(libname [SHARED | STATIC | MODULE | UNKNOWN] IMPORTED)

如，导入 libjpeg.so
``` 
add_library(libjpeg SHARED IMPORTED)
```
导入库后，当**需要使用 target_link_libraries 链接库时，可以直接使用该库**

#### 5.8 find_library　指令
语法：find_library( name1 path1 path2 …)
VAR 变量表示找到的库全路径，包含库文件名 。例如：
``` 
find_library(libX  X11 /usr/lib)
find_library(log-lib log)  #路径为空，应该是查找系统环境变量路径
```

#### 5.9 set_target_properties 指令
语法: set_target_properties(target1 target2 … PROPERTIES prop1 value1 prop2 value2 …)
这条指令可以用来设置输出的名称（设置构建同名的动态库和静态库，或者指定要导入的库文件的路径），对于动态库，
还可以用来指定动态库版本和 API 版本。
如，set_target_properties(hello_static PROPERTIES OUTPUT_NAME “hello”)
设置同名的 hello 动态库和静态库：
``` 
set_target_properties(hello PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(hello_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
```
指定要导入的库文件的路径
```cmake
add_library(jpeg SHARED IMPORTED)
#注意要先 add_library，再 set_target_properties
set_target_properties(jpeg PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/libs/${ANDROID_ABI}/libjpeg.so)
```

设置动态库 hello 版本和 API 版本：
```cmake
set_target_properties(hello PROPERTIES VERSION 1.2 SOVERSION 1)
```
和它对应的指令：
get_target_property(VAR target property)
如上面的例子，获取输出的库的名字
```cmake
get_target_property(OUTPUT_VALUE hello_static OUTPUT_NAME)
message(STATUS "this is the hello_static OUTPUT_NAME:"${OUTPUT_VALUE})
```

#### 6.10 include_directories 指令
语法：include_directories([AFTER | BEFORE] [SYSTEM] dir1 dir2…)
这个指令可以用来向工程添加多个特定的头文件搜索路径，路径之间用空格分割，如果路径中包含了空格，可以使用双引号将它括起来，
默认的行为是追加到当前的头文件搜索路径的后面。

#### 6.11 target_link_libraries 指令
语法：target_link_libraries(target library library2…)
这个指令可以用来为 target 添加需要的链接的共享库，同样也可以用于为自己编写的共享库添加共享库链接。
如:
```cmake
#指定 compress 工程需要用到 libjpeg 库和 log 库
target_link_libraries(compress libjpeg ${log-lib})
```
同样，link_directories(directory1 directory2 …) 可以添加非标准的共享库搜索路径。

还有其他 file、list、install 、find_ 指令和控制指令等就不介绍了，详细可以查看手册。