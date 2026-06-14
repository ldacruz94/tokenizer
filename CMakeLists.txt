cmake_minimum_required(VERSION 3.16)
project(tokenizer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tokenizer src/main.cpp src/tokenizer.cpp)
target_include_directories(tokenizer PRIVATE include)
