cmake_minimum_required(VERSION 3.5)

project(unicodeConverter)
add_executable(${PROJECT_NAME} "main.cpp")

set(CMAKE_CXX_FLAGS "-std=c++11 -D_GLIBCXX_DEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-g3")

include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/uc
)

target_link_libraries(${PROJECT_NAME}
    uc
)

enable_testing()

add_subdirectory(uc)
add_subdirectory(test)
