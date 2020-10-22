add_library(
	square
	src/square/square.hpp
	src/square/square.cpp
)

target_include_directories(square PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)