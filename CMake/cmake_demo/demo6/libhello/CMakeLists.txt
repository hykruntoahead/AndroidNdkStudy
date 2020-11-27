set(LIB_SRC hello.c)

# 为当前目录及以下目录中的源文件向编译器命令行中加入flags. 可以加任何flags,
# 但最初是加预处理定义. Flags 从 -D or /D 开始看起来像预处理定义的自动加入当前目录的 COMPILE_DEFINITIONS 属性中.
# 保留一些不复杂的定义，便于向后兼容. 参看 directory, target, and source 文件COMPILE_DEFINITIONS 属性文档
# 预处理定义加入特定范围和配准中.

add_definitions("-LIBHELLO_BUILD")
#动态库 .so
add_library(libhello SHARED ${LIB_SRC})
#库文件在 build/lib 目录
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set_target_properties(libhello PROPERTIES OUTPUT_NAME "hello")