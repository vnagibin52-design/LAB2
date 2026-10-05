cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Sortirovka)

add_executable(Sortirovka main.cpp)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/ip_filter.tsv 
    ${CMAKE_CURRENT_BINARY_DIR}/Release/ip_filter.tsv 
    COPYONLY
)

