include_directories(
    "${EXTERNAL_GOOGLETEST_DIR}/googletest/include"
    "${EXTERNAL_GOOGLETEST_DIR}/googlemock/include"
)

add_executable(libcutils_test
#                "AshmemTest.cpp"
#                "MemsetTest.cpp"
#                "PropertiesTest.cpp"
                "sched_policy_test.cpp"
#                "trace-dev_test.cpp"
                "test_str_parms.cpp"
#                "android_get_control_socket_test.cpp"
#                "android_get_control_file_test.cpp"
#                "multiuser_test.cpp"
#                "fs_config.cpp"
                "test_str_parms.cpp"
)
target_link_libraries(libcutils_test cutils gtest gtest_main)
