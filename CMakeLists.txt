cmake_minimum_required(VERSION 3.12)

project(IEP)
add_subdirectory(p1)
add_subdirectory(p2)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
find_package(square REQUIRED)

set(SQUARE_DIR "p1/src/square")

include_directories(${SQUARE_DIR})

target_include_directories(p1 PUBLIC p1)

target_link_directories(p1 PRIVATE p1)