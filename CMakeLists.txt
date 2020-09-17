project(unique_words_counter LANGUAGES CXX)
cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

option(BUILD_TESTS "If set to true, unit tests will be build as part of make all." FALSE)
if (BUILD_TESTS)
    message("BUILD_TESTS=TRUE, unit tests will be built.")
    # Download and unpack googletest at configure time
    configure_file(CMakeLists.txt.in ${CMAKE_SOURCE_DIR}/gtest/googletest-download/CMakeLists.txt)
    execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
            RESULT_VARIABLE result
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/gtest/googletest-download )
    if(result)
        message(FATAL_ERROR "CMake step for googletest failed: ${result}")
    endif()
    execute_process(COMMAND ${CMAKE_COMMAND} --build .
            RESULT_VARIABLE result
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/gtest/googletest-download )
    if(result)
        message(FATAL_ERROR "Build step for googletest failed: ${result}")
    endif()

    # Add googletest directly to our build. This defines
    # the gtest and gtest_main targets.
    add_subdirectory(${CMAKE_SOURCE_DIR}/gtest/googletest-src
            ${CMAKE_SOURCE_DIR}/gtest/googletest-build
            EXCLUDE_FROM_ALL)
else ()
    message("BUILD_TESTS=FALSE, unit tests will NOT be built.")
endif ()

file(GLOB unique_words_counter_src
    "src/*.cpp"
)

add_executable(unique_words_counter
    ${unique_words_counter_src}
)

if(BUILD_TESTS)
    add_subdirectory(test/unit)
endif()

target_include_directories(unique_words_counter PUBLIC
    "include"
)
