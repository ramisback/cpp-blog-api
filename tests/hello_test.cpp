#include "../src/hello.h"
#include <gtest/gtest.h>
#include <iostream>

TEST(MainHello, HelloWorldOutput) {
    ASSERT_EQ("Hello World !", hello("Hello World !"));
}
