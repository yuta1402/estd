cmake_minimum_required(VERSION 3.1)

set(target random_test)

add_executable(${target}
    ./main.cpp
)

add_test(
    NAME random
    COMMAND $<TARGET_FILE:${target}>
)
