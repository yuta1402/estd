cmake_minimum_required(VERSION 3.1)

set(target stopwatch_test)

add_executable(${target}
    ./main.cpp
)

add_test(
    NAME stopwatch
    COMMAND $<TARGET_FILE:${target}>
)
