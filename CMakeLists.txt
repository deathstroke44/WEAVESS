cmake_minimum_required(VERSION 3.5)
# set cmake C and CXX compiler, only required for local Mac environment
#set(CMAKE_C_COMPILER "/usr/local/bin/gcc-7")
#set(CMAKE_CXX_COMPILER "/usr/local/bin/g++-7")
project(WEAVESS)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/include)

# Boost
find_package(Boost REQUIRED)
if (Boost_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${Boost_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Boost_CXX_FLAGS}")
    include_directories(${Boost_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Boost dynamic-bitset is required")
endif()

# OpenMP
find_package(OpenMP REQUIRED)
if (OPENMP_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
else()
    message(FATAL_ERROR "OpenMP is required")
endif()

#Python
#include_directories(F:/Python/include)
#link_libraries(F:/Python/libs/python38.lib)

#add_definitions (-std=c++11 -O3 -lboost -march=native -Wall -DINFO)

add_subdirectory(src)
add_subdirectory(test)
