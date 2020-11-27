project(HELLO)
set(LIB_SRC hello.c)
set(APP_SRC main.c)
# 告诉生成一个库文件
add_library(libhello ${LIB_SRC})
# 告诉工程生成一个可执行文件。
add_executable(hello ${APP_SRC})
# 添加共享库链接
target_link_libraries(hello libhello)
set_target_properties(libhello PROPERTIES OUTPUT_NAME "hello")
