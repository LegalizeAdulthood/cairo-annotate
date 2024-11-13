include(GoogleTest)

find_package(GTest CONFIG REQUIRED)

add_executable(test-annotater test.cpp)
set_target_properties(test-annotater PROPERTIES FOLDER "Tests")
target_link_libraries(test-annotater annotater GTest::gmock_main)

gtest_discover_tests(test-annotater)
