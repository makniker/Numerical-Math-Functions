cmake_minimum_required(VERSION 3.0.0)
project(NumMath VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(NumMath 
    src/main.cpp
    src/LAGR.hpp
    src/LAGR.cpp
    src/Functor.hpp
    src/Functor.cpp
    src/Table.hpp
    src/Table.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
