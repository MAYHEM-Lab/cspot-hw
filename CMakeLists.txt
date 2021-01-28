cmake_minimum_required(VERSION 3.13)
project(cspot-hw)

find_package(woof REQUIRED)

add_handler(hw hw.c)

add_executable(hw-client hw-client.c)
target_link_libraries(hw-client woof)
