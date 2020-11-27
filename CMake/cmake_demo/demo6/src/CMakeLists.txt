include_directories(${HELLO_SOURCE_DIR}/libhello)
message(STATUS "root dir is" ${HELLO_SOURCE_DIR})
set(APP_SRC main.c)
#让可执行文件放在build/bin目录
set(EXECUTABLE_OUTPUT_PATH ${HELLO_BINARY_DIR}/bin)
add_executable(hello ${APP_SRC})
target_link_libraries(hello libhello)