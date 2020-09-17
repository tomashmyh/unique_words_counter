enable_testing()

file(GLOB unit_tests_src
        "*.cpp"
        "*.h")

file(GLOB unique_words_counter_src
        "../../src/*.cpp")

list(REMOVE_ITEM unique_words_counter_src ${CMAKE_CURRENT_SOURCE_DIR}/../../src/main.cpp)

add_executable(unique_words_counter_tests ${unit_tests_src} ${unique_words_counter_src})

target_link_libraries(unique_words_counter_tests LINK_PUBLIC gtest_main)

target_include_directories(unique_words_counter_tests PUBLIC
    "../../include"
)

add_custom_target(
        run_unit_tests
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/unique_words_counter_tests.touch unique_words_counter_tests)

add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/unique_words_counter_tests.touch
        COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/unique_words_counter_tests)
