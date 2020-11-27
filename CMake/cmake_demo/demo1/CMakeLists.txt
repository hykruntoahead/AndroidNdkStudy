#  不是强制性的，但最好始终都加上。这一行会引入两个变量
#    HELLO_BINARY_DIR 和 HELLO_SOURCE_DIR
#  同时，cmake自动定义了两个等价的变量
#
#    PROJECT_BINARY_DIR 和 PROJECT_SOURCE_DIR
project(HELLO)
message(${PROJECT_SOURCE_DIR})

#set命令用来设置变量
set(SRC_LIST main.c)
#add_executable　告诉工程生成一个可执行文件
add_executable(hello ${SRC_LIST})

#add_library 则告诉生成一个库文件。
#
#    注意：CMakeList.txt 文件中，命令名字是不区分大小写的，而参数和变量是大小写相关的。