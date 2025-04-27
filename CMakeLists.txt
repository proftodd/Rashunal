cmake_minimum_required(VERSION 3.15...4.0 FATAL_ERROR)
project(rashunal
    DESCRIPTION "A rational number library in C"
    LANGUAGES C
    VERSION 0.0.1
)

enable_testing()

add_subdirectory(rashunal)
add_subdirectory(driver)
