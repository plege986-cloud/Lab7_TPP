
cmake_minimum_required(VERSION 3.10)

# Статическая библиотека
add_library(IntegrationLib STATIC
    IntegrationTask.cpp
)

target_include_directories(IntegrationLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(IntegrationLib PUBLIC cxx_std_20)

# Основная программа
add_executable(Lab7_TPP
    Lab7_TPP.cpp
)

target_link_libraries(Lab7_TPP PRIVATE
    IntegrationLib
)

# Автоматические тесты Google Test
enable_testing()

find_package(GTest CONFIG REQUIRED)

add_executable(IntegrationTests
    tests/IntegrationTests.cpp
)

target_link_libraries(IntegrationTests PRIVATE
    IntegrationLib
    GTest::gtest_main
)

include(GoogleTest)

gtest_add_tests(
    TARGET IntegrationTests
    TEST_LIST IntegrationTests_TESTS
)

# Демонстрация антипаттерна
add_executable(AntipatternDemo
    antipattern/main.cpp
)

target_compile_features(AntipatternDemo PRIVATE cxx_std_20)
