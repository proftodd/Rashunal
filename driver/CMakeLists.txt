include_directories("/usr/local/include")
link_directories("/usr/local/lib")

add_executable(main src/main.c)
target_include_directories(main PUBLIC include)
target_link_libraries(main rashunal)
target_compile_options(main PRIVATE -Werror)
