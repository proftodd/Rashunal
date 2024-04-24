add_library(rashunal SHARED src/rashunal.c src/rashunal_util.c)
target_include_directories(rashunal
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
target_link_libraries(rashunal m)
target_compile_options(rashunal PRIVATE -Werror)

add_subdirectory(test)

set(PUBLIC_HEADERS_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/include/rashunal_util.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/rashunal.h"
)

set_target_properties (
    rashunal
    PROPERTIES
    PUBLIC_HEADER "${PUBLIC_HEADERS_FILES}"
)

install(
    TARGETS rashunal
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
