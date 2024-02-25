add_library(rashunal src/rashunal.c src/rashunal_util.c)
target_include_directories(rashunal
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
target_link_libraries(rashunal m)
target_compile_options(rashunal PRIVATE -Werror)

add_subdirectory(test)
