add_library(cutils SHARED
#        "config_utils.cpp"
#        "fs_config.cpp"
#        "canned_fs_config.cpp"
        "hashmap.cpp"
        "iosched_policy.cpp"
#        "load_file.cpp"
#        "native_handle.cpp"
#        "open_memstream.c"
#        "record_stream.cpp"
        "sched_policy.cpp"
#        "sockets.cpp"
        "strdup16to8.cpp"
        "strdup8to16.cpp"
        "strlcpy.c"
        "threads.cpp"
    "android_get_control_file.cpp"
#    "fs.cpp"
#    "multiuser.cpp"
#    "socket_inaddr_any_server_unix.cpp"
#    "socket_local_client_unix.cpp"
#    "socket_local_server_unix.cpp"
#    "socket_network_client_unix.cpp"
#    "sockets_unix.cpp"
    "str_parms.cpp"
#                "ashmem-host.cpp"
#                "trace-host.cpp"
#                "android_reboot.cpp"
#                "ashmem-dev.cpp"
                "klog.cpp"
#                "partition_utils.cpp"
#                "properties.cpp"
#                "qtaguid.cpp"
#                "trace-dev.cpp"
                "uevent.cpp"

    "../log.c"
)
target_compile_options(cutils PRIVATE -fno-threadsafe-statics)
target_link_libraries(cutils pthread)
set_target_properties(cutils PROPERTIES LINKER_LANGUAGE C)

add_subdirectory(tests)
