cmake_minimum_required(VERSION 3.1)

set(target parallel_test)

find_package(Threads REQUIRED)

add_executable(${target}
    ./main.cpp
)

target_link_libraries(${target}
    ${CMAKE_THREAD_LIBS_INIT}
)

add_test(
    NAME parallel
    COMMAND $<TARGET_FILE:${target}>
)
