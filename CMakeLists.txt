cmake_minimum_required(VERSION 3.5)

project(2020-2-12 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(2020-2-12 main.cpp
    header.h)

include(GNUInstallDirs)
install(TARGETS 2020-2-12
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
