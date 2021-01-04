cmake_minimum_required(VERSION 3.16)
project(MI6SIMShell4Windows C)

set(CMAKE_C_STANDARD 11)

add_executable(MI6SIMShell4Windows
        src/main/c/main.c
        src/main/c/controller/SimShell.h
        src/main/c/controller/SimShell.c
        )