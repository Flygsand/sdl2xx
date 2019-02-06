find_package(SDL2 REQUIRED)
find_package(SDL2_net REQUIRED)
add_executable(net_example main.cpp)
target_link_libraries(net_example sdl2xx SDL2::SDL2 SDL2::SDL2_net)
