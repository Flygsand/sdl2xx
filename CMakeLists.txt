cmake_minimum_required(VERSION 3.1)
project(sdl2xx VERSION 0.1.0 LANGUAGES CXX)

option(SDL2XX_BUILD_EXAMPLES "Build examples")

set(header_files
	${CMAKE_CURRENT_SOURCE_DIR}/include/sdl2xx.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/sdl2xx/image.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/sdl2xx/mixer.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/sdl2xx/net.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/sdl2xx/ttf.hpp)

add_library(sdl2xx INTERFACE)
target_sources(sdl2xx INTERFACE $<BUILD_INTERFACE:${header_files}>)
target_compile_features(sdl2xx INTERFACE cxx_std_14)
target_include_directories(sdl2xx INTERFACE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/include>)

if(SDL2XX_BUILD_EXAMPLES)
	list(INSERT CMAKE_MODULE_PATH 0 ${PROJECT_SOURCE_DIR}/cmake/modules)
	add_subdirectory(examples)
endif()
