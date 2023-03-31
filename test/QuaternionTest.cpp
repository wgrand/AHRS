#include "gtest/gtest.h"
#include "../model/Quaternion.h"

TEST(QuaternionTest, Multiply) {
    Quaternion q1(1, 2, 3, 4);
    Quaternion q2(5, 6, 7, 8);

    Quaternion result = q1 * q2;

    EXPECT_FLOAT_EQ(result.Length(), q1.Length() * q2.Length());
}

TEST(QuaternionTest, Conjugate) {
    Quaternion q(1, 2, 3, 4);

    Quaternion conjugate = q.Conjugate();

    EXPECT_FLOAT_EQ(q.Length(), conjugate.Length());
    EXPECT_FLOAT_EQ(conjugate.x, -q.x);
    EXPECT_FLOAT_EQ(conjugate.y, -q.y);
    EXPECT_FLOAT_EQ(conjugate.z, -q.z);
}

TEST(QuaternionTest, Normalize) {
    Quaternion q(1, 2, 3, 4);

    q.Normalize();

    EXPECT_FLOAT_EQ(q.Length(), 1.0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
