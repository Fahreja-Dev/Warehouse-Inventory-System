# Set Version C++ and Name Project
cmake_minimum_required(VERSION 3.15)
project(AplikasiGudang VERSION 1.0.0 LANGUAGES CXX)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Auto-detect all source files
file(GLOB_RECURSE SOURCES 
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

# Auto-detect all header files
file(GLOB_RECURSE HEADERS 
    "${PROJECT_SOURCE_DIR}/include/*.hpp"
    "${PROJECT_SOURCE_DIR}/include/*.h"
)

# Auto-detect all libraries files
file(GLOB_RECURSE LIBRARIES
"${PROJECT_SOURCE_DIR}/lib/*.hpp"
"${PROJECT_SOURCE_DIR}/lib/*.h"
)

# Library FMT
include(FetchContent)
FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt
  GIT_TAG        12.1.0) # 12.1.0
FetchContent_MakeAvailable(fmt)

# Include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/lib
)

# add_executable -> Untuk membuat target program executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Target executable dari library resmi dari fmt
target_link_libraries(AplikasiGudang PRIVATE fmt::fmt)

# Output directory - exe di root, file build di directory build/
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}
)

# Output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
)