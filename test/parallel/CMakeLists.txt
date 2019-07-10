cmake_minimum_required(VERSION 3.1)

set(target parallel_test)

add_executable(${target}
    ./main.cpp
)

add_test(
    NAME parallel
    COMMAND $<TARGET_FILE:${target}>
)
