cmake_minimum_required(VERSION 3.8)
project(cpp-stratego-happy-vampires)

set(CMAKE_CXX_STANDARD 11)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

set(SOURCE_FILES main.cpp Game.cpp Game.h Display.cpp Display.h Texture.cpp Texture.h Pieces/Piece.cpp Pieces/Piece.h Pieces/Thing.hpp Pieces/Bomb.hpp Pieces/Flag.hpp Pieces/Barrier.hpp Pieces/Soldier.cpp Pieces/Soldier.h Pieces/Spy.hpp Pieces/Miner.hpp Pieces/Scout.hpp Button.cpp Button.h)
add_executable(cpp-stratego-happy-vampires ${SOURCE_FILES})

target_link_libraries(cpp-stratego-happy-vampires ${SLD2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})