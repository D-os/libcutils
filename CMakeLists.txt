add_library(cutils SHARED
#    "fs.cpp"
    "hashmap.cpp"
#    "multiuser.cpp"
#    "socket_inaddr_any_server_unix.cpp"
#    "socket_local_client_unix.cpp"
#    "socket_local_server_unix.cpp"
#    "socket_network_client_unix.cpp"
#    "sockets_unix.cpp"
    "str_parms.cpp"
#        "config_utils.cpp"
#        "canned_fs_config.cpp"
#        "iosched_policy.cpp"
#        "load_file.cpp"
#        "native_handle.cpp"
#        "record_stream.cpp"
#        "sockets.cpp"
#        "strdup16to8.cpp"
#        "strdup8to16.cpp"
        "strlcpy.c"
        "threads.cpp"
#                "ashmem-host.cpp"
#                "fs_config.cpp"
#                "trace-host.cpp"
                "android_get_control_file.cpp"
#                "android_reboot.cpp"
#                "ashmem-dev.cpp"
#                "fs_config.cpp"
                "klog.cpp"
#                "partition_utils.cpp"
#                "properties.cpp"
#                "qtaguid.cpp"
#                "trace-dev.cpp"
#                "uevent.cpp"

    "../log.c"
)
target_compile_options(cutils PRIVATE -fno-threadsafe-statics)
target_link_libraries(cutils pthread base)
set_target_properties(cutils PROPERTIES LINKER_LANGUAGE C)

include_directories(
    "${EXTERNAL_GOOGLETEST_DIR}/googletest/include"
    "${EXTERNAL_GOOGLETEST_DIR}/googlemock/include"
)

add_executable(libcutils_test
                "str_parms_test.cpp"
)
target_link_libraries(libcutils_test cutils gtest gtest_main)

gtest_discover_tests(libcutils_test)
