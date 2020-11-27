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
