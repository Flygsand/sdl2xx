find_package(SDL2 REQUIRED)
add_executable(renderer_example main.cpp)
target_link_libraries(renderer_example sdl2xx SDL2::SDL2)
