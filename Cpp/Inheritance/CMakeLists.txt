project("Game")

#include_directories(${CMAKE_CURRENT_SOURCE_DIR})

single_executable(game/game.cpp game/character.cpp game/abilities.cpp game/weapons.cpp)

single_executable(casts/const_cast.cpp)
single_executable(casts/dynamic_cast.cpp)
single_executable(casts/reinterpret_cast.cpp)
single_executable(casts/static_cast.cpp)

single_executable(inheritance.cpp)
single_executable(lambda.cpp)

