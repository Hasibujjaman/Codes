cmake_minimum_required(VERSION 3.10)

project(exgest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_VERBOSE_MAKEFILE ON)
find_package(GTest REQUIRED)

set(SOURCE_FILES
    sample_test.cpp
    test.cpp
    triangle.cpp
    lab_final.cpp
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


# foreach(SRC ${SOURCE_FILES})
#     get_filename_component(TARGET_NAME ${SRC} NAME_WE)
#     add_executable(${TARGET_NAME} ${SRC})
#     target_link_libraries(${TARGET_NAME} GTest::GTest GTest::Main pthread)
# endforeach()
foreach(SRC ${SOURCE_FILES})
    get_filename_component(TARGET_NAME ${SRC} NAME_WE)
    add_executable(${TARGET_NAME} ${SRC})
    target_link_libraries(${TARGET_NAME} GTest::GTest GTest::Main pthread)

    # Set the output directory for each target
    set_target_properties(${TARGET_NAME} PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../
    )
endforeach()

# Print macOS version
execute_process(
    COMMAND sw_vers -productVersion
    OUTPUT_VARIABLE OSX_VERSION
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
message(STATUS "macOS Version: ${OSX_VERSION}")