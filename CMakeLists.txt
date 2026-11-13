cmake_minimum_required(VERSION 4.2.3)
project(gary LANGUAGES CXX)

set(CMAKE_COLOR_DIAGNOSTICS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_INCLUDE_CURRENT_DIR)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

# Source
file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADERS "${CMAKE_SOURCE_DIR}/include/*.h")
include_directories("${PROJECT_SOURCE_DIR}/include")

add_library(Gary STATIC ${SRC})

set(GARYC_MAIN "${CMAKE_SOURCE_DIR}/tools/garyc.cpp")
add_executable(garyc ${GARYC_MAIN})
target_link_libraries(garyc Gary)

# # Test
file(GLOB_RECURSE TEST_SRC "${CMAKE_SOURCE_DIR}/tests/test_*.cpp")
add_executable(garyc-tests ${TEST_SRC})
target_link_libraries(garyc-tests Gary)
add_custom_target(
  test
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/tests/resources
          ${CMAKE_BINARY_DIR}/resources
  COMMAND "${CMAKE_BINARY_DIR}/garyc-tests"
  DEPENDS garyc-tests)

# Format
add_custom_target(format clang-format -i ${SRC} ${HEADERS} ${TEST_SRC})
