cmake_minimum_required(VERSION 3.14)

project(wuiExample)
add_executable(${PROJECT_NAME} main.cpp)

find_package(wui REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE wui::wui)
