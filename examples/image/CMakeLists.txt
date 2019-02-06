find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_executable(image_example main.cpp)
target_link_libraries(image_example sdl2xx SDL2::SDL2 SDL2::SDL2_image)
file(COPY blue_torus.png DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
