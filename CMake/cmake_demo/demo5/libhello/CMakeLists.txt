set(LIB_SRC hello.c)
add_library(libhello ${LIB_SRC})
#库文件在 build/lib 目录
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set_target_properties(libhello PROPERTIES OUTPUT_NAME "hello")