cmake_minimum_required(VERSION 3.1)

set(target combination_solver_test)

add_executable(${target}
    ./main.cpp
)

add_test(
    NAME combination_solver
    COMMAND $<TARGET_FILE:${target}>
)
