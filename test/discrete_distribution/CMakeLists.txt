cmake_minimum_required(VERSION 3.1)

set(target discrete_distribution_test)

add_executable(${target}
    ./main.cpp
)

add_test(
    NAME discrete_distribution
    COMMAND $<TARGET_FILE:${target}>
)
