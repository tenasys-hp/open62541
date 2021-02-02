SET(SOURCE_GROUP ${SOURCE_GROUP}\\INtime)

ua_add_architecture("INtime")

list (FIND UA_AMALGAMATION_ARCHITECTURES "INtime" _index)
if (${_index} GREATER -1 OR "${UA_ARCHITECTURE}" STREQUAL "INtime")

    ua_include_directories($ENV{INTIME}rt/include/network7/)
    ua_include_directories($ENV{INTIME}rt/include/cpp)
    ua_include_directories($ENV{INTIME}rt/include/)

    ua_architecture_append_to_library($ENV{INTIME}rt/lib/rtppd.lib) # For C++ support
    ua_architecture_append_to_library($ENV{INTIME}rt/lib/cpplib.lib)
    ua_architecture_append_to_library($ENV{INTIME}rt/lib/rt.lib)
    ua_architecture_append_to_library($ENV{INTIME}rt/lib/pcibus.lib)
    ua_architecture_append_to_library($ENV{INTIME}rt/lib/netlib.lib)
    ua_architecture_append_to_library($ENV{INTIME}rt/lib/clib.lib)
    ua_architecture_append_to_library($ENV{INTIME}rt/lib/vshelper.lib)
    ua_architecture_append_to_library($ENV{INTIME}rt/lib/iwin32.lib) # Win32 API support

    if("${UA_ARCHITECTURE}" STREQUAL "INtime")
        ua_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
    endif()

    ua_add_architecture_file(${CMAKE_CURRENT_SOURCE_DIR}/ua_clock.c)
    ua_add_architecture_file(${CMAKE_CURRENT_SOURCE_DIR}/ua_architecture_functions.c)

endif()
