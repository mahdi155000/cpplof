cmake_minimum_required(VERSION 3.16)

# Project name and language
project(clof LANGUAGES CXX)

# -------------------------------
# C++ standard
# -------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -------------------------------
# Build type (default: Debug)
# -------------------------------
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# -------------------------------
# Compiler warnings
# -------------------------------
add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
    -pthread
)

# -------------------------------
# Include directories
# -------------------------------
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/plugins
)

# -------------------------------
# Find required libraries
# -------------------------------
find_package(PkgConfig REQUIRED)

pkg_check_modules(NCURSES REQUIRED ncursesw)
pkg_check_modules(SQLITE3 REQUIRED sqlite3)
pkg_check_modules(CURL REQUIRED libcurl)
pkg_check_modules(CJSON REQUIRED libcjson)

# -------------------------------
# Source files
# -------------------------------
file(GLOB_RECURSE PROJECT_SOURCES
    src/*.cpp
    plugins/*.cpp
)

# -------------------------------
# Executable
# -------------------------------
add_executable(clof
    ${PROJECT_SOURCES}
)

# -------------------------------
# Link libraries
# -------------------------------
target_link_libraries(clof
    ${NCURSES_LIBRARIES}
    ${SQLITE3_LIBRARIES}
    ${CURL_LIBRARIES}
    ${CJSON_LIBRARIES}
    pthread
)

# -------------------------------
# Include library headers
# -------------------------------
target_include_directories(clof PRIVATE
    ${NCURSES_INCLUDE_DIRS}
    ${SQLITE3_INCLUDE_DIRS}
    ${CURL_INCLUDE_DIRS}
    ${CJSON_INCLUDE_DIRS}
)
