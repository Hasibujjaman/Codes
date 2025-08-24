#include <iostream>
#include <gtest/gtest.h>

using namespace std;

bool isTriangle(int a, int b, int c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

class TriangleTest : public ::testing::Test {
};

TEST_F(TriangleTest, ValidTriangle) {
    EXPECT_TRUE(isTriangle(3, 4, 5));
    EXPECT_TRUE(isTriangle(5, 12, 13));
    EXPECT_TRUE(isTriangle(7, 10, 5));
}

TEST_F(TriangleTest, InvalidTriangle) {
    EXPECT_FALSE(isTriangle(1, 2, 3));
    EXPECT_FALSE(isTriangle(5, 1, 1));
    EXPECT_FALSE(isTriangle(0, 0, 0));
}

TEST_F(TriangleTest, NegativeSides) {
    EXPECT_FALSE(isTriangle(-1, 4, 5));
    EXPECT_FALSE(isTriangle(3, -4, 5));
    EXPECT_FALSE(isTriangle(3, 4, -5));
}

TEST_F(TriangleTest, ZeroSides) {
    EXPECT_FALSE(isTriangle(0, 4, 5));
    EXPECT_FALSE(isTriangle(3, 0, 5));
    EXPECT_FALSE(isTriangle(3, 4, 0));
}

TEST_F(TriangleTest, EquilateralTriangle) {
    EXPECT_TRUE(isTriangle(5, 5, 5));
    EXPECT_TRUE(isTriangle(10, 10, 10));
    EXPECT_TRUE(isTriangle(100, 100, 100));
}

TEST_F(TriangleTest, IsoscelesTriangle) {
    EXPECT_TRUE(isTriangle(5, 5, 6));
    EXPECT_TRUE(isTriangle(10, 10, 12));
    EXPECT_TRUE(isTriangle(100, 100, 120));
}

TEST_F(TriangleTest, ScaleneTriangle) {
    EXPECT_TRUE(isTriangle(3, 4, 5));
    EXPECT_TRUE(isTriangle(5, 12, 13));
    EXPECT_TRUE(isTriangle(7, 10, 5));
}


class TestEventListener : public ::testing::EmptyTestEventListener {
public:
    void OnTestEnd(const ::testing::TestInfo& test_info) override {
        if (test_info.result()->Passed()) {
            std::cout << "Test " << test_info.name() << " succeeded." << std::endl;
        }
    }
};

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::TestEventListeners& listeners = ::testing::UnitTest::GetInstance()->listeners();
    listeners.Append(new TestEventListener);
    return RUN_ALL_TESTS();
}

