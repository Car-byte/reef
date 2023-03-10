cmake_minimum_required(VERSION 3.24)
project(simple)

set(CMAKE_CXX_STANDARD 20)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})

add_executable(simple src/main.cpp src/frontend/lexer/token.cpp src/frontend/lexer/lexer.cpp)

llvm_map_components_to_libnames(llvm_libs support core irreader passes)

target_link_libraries(simple ${llvm_libs})
