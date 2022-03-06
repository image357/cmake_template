//
// Created by koepke on 1/5/22.
//

#include "GlobalTest.h"

#include <cmake_template/sub1/ClassA.h>
#include <cmake_template/sub2/ClassB.h>
#include <sub1/internal.h>
#include <sub2/internal.h>

void GlobalTest::SetUp()
{
    Test::SetUp();
}

void GlobalTest::TearDown()
{
    Test::TearDown();
}

TEST(GlobalTest, testA)
{
    sub1::ClassA a;
    SUCCEED();
}

TEST(GlobalTest, testB)
{
    sub2::ClassB b;
    SUCCEED();
}

TEST(GlobalTest, unequal)
{
    ASSERT_NE(::sub1::message, ::sub2::message);
}
