add_library(Unity STATIC "${unity_SOURCE_DIR}/src/unity.c")
target_include_directories(Unity PUBLIC "${unity_SOURCE_DIR}/src")

add_executable(test_rashunal_app src/test_rashunal.c)
target_link_libraries(test_rashunal_app rashunal Unity)
add_test(test_rashunal_app_suite test_rashunal_app)

add_executable(test_rashunal_util_app src/test_util.c)
target_link_libraries(test_rashunal_util_app rashunal Unity)
add_test(test_rashunal_util_app_suite test_rashunal_util_app)
