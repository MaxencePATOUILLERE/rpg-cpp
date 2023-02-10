cmake_minimum_required(VERSION 3.24)
project(RPG_POO)

set(CMAKE_CXX_STANDARD 17)

add_executable(RPG_POO main.cpp Character.cpp Character.h Inventory.cpp Inventory.h Item.cpp Item.h Weapon.cpp Weapon.h Armor.cpp Armor.h Talisman.cpp Talisman.h)
