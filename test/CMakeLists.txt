cmake_minimum_required(VERSION 3.1)

include_directories(
    "../estd"
    "./"
)

add_subdirectory("./combination_solver")
add_subdirectory("./random")
add_subdirectory("./stopwatch")
