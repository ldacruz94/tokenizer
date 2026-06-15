cmake_minimum_required(VERSION 3.16)
project(tokenizer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  nlohmann_json
  URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
  DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_MakeAvailable(nlohmann_json)

add_executable(tokenizer src/main.cpp src/tokenizer.cpp)
target_include_directories(tokenizer PRIVATE include)
target_link_libraries(tokenizer PRIVATE nlohmann_json::nlohmann_json)
