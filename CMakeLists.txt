cmake_minimum_required(VERSION 3.16)
project(cppudl VERSION 0.1.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(CTest)
enable_testing()

add_executable(cppudl main.cpp)
set_target_properties(cppudl PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

target_compile_features(cppudl PUBLIC cxx_std_20)
target_compile_options(cppudl PUBLIC
    # -fsanitize=address,undefined
    -fno-builtin
    -Wall
    -Wextra
    -Wpedantic
    -Wshadow
    -Wshadow
    -Werror
    -pedantic-errors
)
add_custom_command(
        TARGET ${PROJECT_NAME}  POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_BINARY_DIR}/compile_commands.json
                ${CMAKE_SOURCE_DIR}/compile_commands.json)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
