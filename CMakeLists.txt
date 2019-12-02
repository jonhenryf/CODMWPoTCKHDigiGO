cmake_minimum_required(VERSION 3.15)

project(CODMWPoTCKHDigiGO)

set(CMAKE_CXX_STANDARD 14)

add_executable(cheese main.cpp Character.cpp Character.h menu.cpp menu.h inventory.cpp inventory.h thanos.cpp thanos.h game_data.cpp game_data.h items.h enemy_actions.cpp enemy_actions.h attacks.cpp attacks.h attack_adapter.h)