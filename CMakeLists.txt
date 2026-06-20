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

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/releases/download/v1.15.2/googletest-1.15.2.tar.gz
  DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tokenizer_tests tests/tokenizer_test.cpp src/tokenizer.cpp)
target_include_directories(tokenizer_tests PRIVATE include)
target_link_libraries(tokenizer_tests PRIVATE nlohmann_json::nlohmann_json GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tokenizer_tests)
