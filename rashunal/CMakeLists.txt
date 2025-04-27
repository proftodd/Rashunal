include(GNUInstallDirs)
option(RASHUNAL_BUILD_TESTS "Build Rashunal's unit tests" ON)

add_library(rashunal SHARED src/rashunal.c src/rashunal_util.c)
target_include_directories(rashunal
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
target_link_libraries(rashunal m)
target_compile_options(rashunal PRIVATE -Wall -Werror)

if (RASHUNAL_BUILD_TESTS)
    include(FetchContent)

    FetchContent_Declare(
        Unity
        GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
        GIT_TAG master
    )
    FetchContent_MakeAvailable(Unity)
    FetchContent_GetProperties(Unity)

    add_subdirectory(test)
endif()

set_target_properties (
    rashunal
    PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

install(
    TARGETS rashunal
    EXPORT rashunalTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT rashunalTargets
  FILE rashunalTargets.cmake
  NAMESPACE rashunal::
  DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/rashunal"
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/rashunalConfig.cmake
    DESTINATION lib/cmake/rashunal
)

include (CMakePackageConfigHelpers)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/rashunalConfig.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/rashunal"
)
