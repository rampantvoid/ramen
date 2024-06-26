# tests/CMakeLists.txt

# You might want to use a testing framework like Google Test
# find_package(GTest REQUIRED)

# Add test executable
add_executable(ramen_tests
    test_server.cpp

    # Add other test files here
)

# Link against Ramen library and potentially GTest
target_link_libraries(ramen_tests PRIVATE ramen) # GTest::GTest GTest::Main)

# Add the test
add_test(NAME ramen_tests COMMAND ramen_tests)