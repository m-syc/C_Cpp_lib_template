cmake_minimum_required(VERSION 3.22)
cmake_policy(SET CMP0048 NEW)
set(LIB_NAME
    template
)
project(
    C_Cpp_lib_template
    VERSION 0.1.0.0
    DESCRIPTION "What does it do?"
    LANGUAGES CXX C
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

set(SOURCES src/lib.h src/lib_internal.h src/lib.c)

enable_testing()

set(LIB_MOCKS
    mock_template
)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
include_directories(${GTEST_INCLUDE_DIRS})

add_library(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC src/)

find_library(ext_cfg ${PROJECT_NAME}_cfg)
if(ext_cfg)
    target_link_libraries(${PROJECT_NAME} PRIVATE ext_cfg)
endif()

add_executable(lib_ut tests/lib_test.cpp)
add_subdirectory(tests/cfg_ut)
foreach(MOCK ${LIB_MOCKS})
    add_subdirectory("tests/mock/${MOCK}")
    target_link_libraries(lib_ut PUBLIC ${MOCK})
endforeach(MOCK)

target_link_libraries(lib_ut PRIVATE ${LIB_NAME}_cfg-ut PUBLIC ${GTEST_LIBRARIES} gtest_main gmock_main)
target_include_directories(lib_ut PRIVATE tests/ src/)
target_compile_definitions(lib_ut PUBLIC UNIT_TESTS)

add_test(
    NAME lib_ut
    COMMAND lib_ut
)
