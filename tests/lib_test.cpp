/**
 * @file lib_test.cpp
 * @brief Unit tests for the functionality in lib.c.
 */

#include "lib.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "mock_template.hpp"
#include "lib_internal.h"

/*****************************************************************************
 * Module Under Test
 ****************************************************************************/

#define const
extern "C" {
#include "lib.c"
}
#undef const

/*****************************************************************************
 * Fixture Classes
 ****************************************************************************/

class lib_TestFixture : public ::testing::Test {
 protected:
  void SetUp() override { mock_obj = new MockObj(); }

  void TearDown() override { delete mock_obj; }
};

/*****************************************************************************
 * Test Cases
 ****************************************************************************/

using ::testing::AtLeast;

TEST_F(lib_TestFixture, test_case) {
    EXPECT_CALL(*mock_obj, bar()).Times(AtLeast(1));
    foo();
    std::cout << WORD << std::endl;
    ASSERT_TRUE(true);
}

/*****************************************************************************
 * Test Suites
 ****************************************************************************/

// Define additional test suites if needed

/*****************************************************************************
 * Helper Functions
 ****************************************************************************/

// Add helper functions used by the tests as needed
