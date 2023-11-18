# CMakeFiles.txt for LibraryTemplate
#
# This CMake file is responsible for configuring and building the template
# library. It provides a template for creating CMakeLists.txt for your own
# libraries. Customize the variables and settings according to your project's
# requirements.
# Sample usage:
# 1. Copy directory "cfg_template" to folder "cfg" in root directory
# 2. Rename library
# 3. Append "LIB_CFG" section with library name

cmake_minimum_required (VERSION 3.8)
cmake_policy(SET CMP0048 NEW)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 11)

set(headers
    lib_cfg.h)

add_library(${LIB_NAME}_cfg-ut STATIC ${headers})
set_target_properties(${LIB_NAME}_cfg-ut PROPERTIES LINKER_LANGUAGE C)
target_include_directories(${LIB_NAME}_cfg-ut PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
