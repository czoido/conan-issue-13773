cmake_minimum_required(VERSION 3.25)
project(TestMailPrj)

set(CMAKE_CXX_STANDARD 20)

find_package(Poco REQUIRED)

add_executable(TestMailPrj main.cpp)
target_link_libraries(${PROJECT_NAME} Poco::Poco)
