//
// Created by koepke on 1/5/22.
//

#ifndef CMAKE_TEMPLATE_GLOBALTEST_H
#define CMAKE_TEMPLATE_GLOBALTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

class GlobalTest : public ::testing::Test {
protected:
    void SetUp() override;
    void TearDown() override;
};

#endif //CMAKE_TEMPLATE_GLOBALTEST_H
