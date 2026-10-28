include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/releases/download/v1.15.2/googletest-1.15.2.tar.gz
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(unit_test unit_test.cpp)

target_link_libraries(unit_test PRIVATE GTest::gtest_main isRightTuple_lib)

include(GoogleTest)
gtest_discover_tests(unit_test)