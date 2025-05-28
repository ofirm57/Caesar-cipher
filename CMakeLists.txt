#cmake_minimum_required(VERSION 3.10)
#project(ex1 C)
#
#set(CMAKE_C_STANDARD 99)
#
#add_executable(ex1 main.c cipher.c tests.c)
#


cmake_minimum_required(VERSION 3.23)
project(ex1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ex1
        cipher.c
        cipher.h
        main.c
        tests.c
        tests.h
        )
