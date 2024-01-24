project(Hello)

as_library()
with_test(Hello gtest_main)

#single_executable(src/Main.cpp)