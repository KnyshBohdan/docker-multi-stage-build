cmake_minimum_required(VERSION 3.7)
project(csv_mean)

find_package(Eigen3 REQUIRED)

add_executable(csv_mean main.cpp)
target_link_libraries(csv_mean Eigen3::Eigen)
