cmake_minimum_required(VERSION 3.1)

set(target ndvector_test)

add_executable(${target}
    ./main.cpp
)

add_test(
    NAME ndvector
    COMMAND $<TARGET_FILE:${target}>
)
