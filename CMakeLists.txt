cmake_minimum_required(VERSION 3.28)

project(kmeans)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES
    src/kmeans.cpp
    src/kmeans_kdtree.cpp
    src/main.cpp
    src/timer.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
