cmake_minimum_required(VERSION 3.19)

project(NSObjects)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "source/*.c")
file(GLOB_RECURSE HEADERS RELATIVE ${CMAKE_SOURCE_DIR} "include/*.h")

add_library(
    objc
    STATIC
    ${SOURCES}
)

set_target_properties(
    objc
    PROPERTIES
    PUBLIC_HEADER
    "${HEADERS}"
)

INSTALL(
    TARGETS objc
    LIBRARY DESTINATION /usr/local/lib
    PUBLIC_HEADER DESTINATION /usr/local/include/NSObjects
)
