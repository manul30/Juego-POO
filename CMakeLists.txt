cmake_minimum_required(VERSION 3.15)

project(ClionSFML)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS system window graphics audio)

add_executable(ClionSFML main.cpp Personajes.cpp Personajes.h ventana.cpp ventana.h Arma.cpp Arma.h Tipos.h)

target_link_libraries(ClionSFML sfml-system sfml-window sfml-graphics sfml-audio)