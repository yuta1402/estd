cmake_minimum_required(VERSION 3.1)

set(target default_random_engine_test)

add_executable(${target}
    ./main.cpp
)

add_test(
    NAME default_random_engine
    COMMAND $<TARGET_FILE:${target}>
)
