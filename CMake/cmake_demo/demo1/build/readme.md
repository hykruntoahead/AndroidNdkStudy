在改目录下执行
cmake .. -G"NMake Makefiles"
nmake

或者

cmake .. -G"MinGW Makefiles"
make

即可生成可执行程序 hello(.exe)
Ubuntu上会报错,并提示:

```cmake
CMake Error: Could not create named generator MinGW Makefiles

Generators
  Unix Makefiles               = Generates standard UNIX makefiles.
  Ninja                        = Generates build.ninja files.
  Watcom WMake                 = Generates Watcom WMake makefiles.
  CodeBlocks - Ninja           = Generates CodeBlocks project files.
  CodeBlocks - Unix Makefiles  = Generates CodeBlocks project files.
  CodeLite - Ninja             = Generates CodeLite project files.
  CodeLite - Unix Makefiles    = Generates CodeLite project files.
  Eclipse CDT4 - Ninja         = Generates Eclipse CDT 4.0 project files.
  Eclipse CDT4 - Unix Makefiles= Generates Eclipse CDT 4.0 project files.
  KDevelop3                    = Generates KDevelop 3 project files.
  KDevelop3 - Unix Makefiles   = Generates KDevelop 3 project files.
  Kate - Ninja                 = Generates Kate project files.
  Kate - Unix Makefiles        = Generates Kate project files.
  Sublime Text 2 - Ninja       = Generates Sublime Text 2 project files.
  Sublime Text 2 - Unix Makefiles
                               = Generates Sublime Text 2 project files.

```

#### cmake命令
cmake 命令后跟一个路径(..)，用来指出 CMakeList.txt 所在的位置。

由于系统中可能有多套构建环境，我们可以通过-G来制定生成哪种工程文件，通过 cmake -h 可得到详细信息。

要显示执行构建过程中详细的信息(比如为了得到更详细的出错信息)，可以在CMakeList.txt内加入：

    SET( CMAKE_VERBOSE_MAKEFILE on )

或者执行make时

    $ make VERBOSE=1

或者

    $ export VERBOSE=1
    $ make
