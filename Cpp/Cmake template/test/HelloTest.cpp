#include <gtest/gtest.h>

#include "Hello.hpp"

using namespace hello;

/*  TEST - макрос, который задаёт имя группы тестов и имя теста
    TEST(TestSuiteName, TestName) {
      ... test body ...
    }
*/

TEST(Hello, add) {
    int a = 10;
    int b = 20;
    EXPECT_EQ(a + b, add(a, b));
}

// Тест с перехватом cin и cout
TEST(Hello, print_name) {
    std::istringstream input_stream("World");
    std::streambuf *original_in_buf = std::cin.rdbuf();
    std::cin.rdbuf(input_stream.rdbuf());      // Redirect cin

    std::stringstream output_stream;
    std::streambuf *original_out_buf = std::cout.rdbuf();
    std::cout.rdbuf(output_stream.rdbuf());    // Redirect cout to our output_stream

    print_hello();

    std::cout.rdbuf(original_out_buf);              // Redirect cout to its old self
    std::cin.rdbuf(original_in_buf);    // Redirect cin back to its old self

    EXPECT_EQ(output_stream.str(), "Hello, World\n");
}

