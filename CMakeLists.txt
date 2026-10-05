cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Sortirovka)

add_library(ip_out_lib ip_out.cpp ip_out.h)

add_executable(Sortirovka main.cpp)

target_link_libraries(Sortirovka PRIVATE ip_out_lib)

# Включаем поддержку тестирования и добавляем подпапку с тестами
enable_testing()
add_subdirectory(tests)
