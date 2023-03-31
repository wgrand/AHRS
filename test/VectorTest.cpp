#include "gtest/gtest.h"
#include "../model/Vector.h"
#include "../model/Quaternion.h"
#include "../model/Mat3x3.h"

TEST(VectorTest, DotProduct) {
    Vector v1(1, 2, 3);
    Vector v2(5, 6, 7);

    float expected_result = 38.0;
    float result = v1*v2;

    EXPECT_FLOAT_EQ(result, expected_result);
}

TEST(VectorTest, Normalize) {
    Vector v(1, 2, 3);

    v.Normalize();

    EXPECT_FLOAT_EQ(v.Length(), 1.0);
}

TEST(VectorTest, CrossProduct) {
    Vector v1(1, 2, 3);
    Vector v2(5, 6, 7);

    Vector result = v1^v2;

    Vector expected_result(-4, 8, -4);

    EXPECT_TRUE(result == expected_result);

}

TEST(VectorTest, Multiplication) {

    // Define a quaternion
    Quaternion q(0.707, 0.0, 0.0, 0.707); // represents a 90 degree rotation about the z-axis

    // Define a vector
    Vector v(1.0, 0.0, 0.0);

    // Multiply the vector by the quaternion
    Vector result = v*q;

    // Define the expected result
    Vector expected_result(0.0, 1.0, 0.0);

    // Check that the result matches the expected result
    EXPECT_NEAR(result.x, expected_result.x, 0.001);
    EXPECT_NEAR(result.y, expected_result.y, 0.001);
    EXPECT_NEAR(result.z, expected_result.z, 0.001);

}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
