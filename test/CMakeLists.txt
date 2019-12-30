cmake_minimum_required(VERSION 3.1)

include_directories(
    "../estd"
    "./"
)

add_subdirectory("./combination_solver")
add_subdirectory("./default_random_engine")
add_subdirectory("./discrete_distribution")
add_subdirectory("./parallel")
add_subdirectory("./random")
add_subdirectory("./stopwatch")
