find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)
add_executable(mixer_example main.cpp)
target_link_libraries(mixer_example sdl2xx SDL2::SDL2 SDL2::SDL2_mixer)

file(COPY wilhelm_scream.ogg DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
