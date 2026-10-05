include(FetchContent)

# 1. Скачиваем Google Test напрямую с GitHub
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/releases/download/v1.15.2/googletest-1.15.2.tar.gz
)

# Для ускорения сборки отключаем установку gtest в систему
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 2. Создаем исполняемый файл для тестов
add_executable(unit_test unit_test.cpp)

# 3. Линкуем код наших тестов с Google Test и нашей библиотекой math_lib
target_link_libraries(unit_test PRIVATE GTest::gtest_main ip_out_lib)

# 4. Регистрируем исполняемый файл в системе CTest (чтобы работала команда ctest)
include(GoogleTest)
gtest_discover_tests(unit_test)
