include_directories(
    ${PROJECT_SOURCE_DIR}/uc
)

add_library(uc
    type.hpp
    parameters.cpp
    text_converter.cpp
)
