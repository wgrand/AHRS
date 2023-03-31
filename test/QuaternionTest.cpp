#include "gtest/gtest.h"
#include "../model/Quaternion.h"
#include "../model/Mat3x3.h"

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

TEST(QuaternionTest, FromRotationMatrix1) {

    Mat3x3 m = {1, 0, 0,
                0, 0, -1,
                0, 1, 0};

    Quaternion q = Quaternion(m);

    EXPECT_NEAR(q.w, 0.70710677, 0.0001);
    EXPECT_NEAR(q.x, 0.70710677, 0.0001);
    EXPECT_NEAR(q.y, 0.0, 0.0001);
    EXPECT_NEAR(q.z, 0.0, 0.0001);

}

TEST(QuaternionTest, FromRotationMatrix2) {

    Mat3x3 m = {0, 0, 1,
                0, 1, 0,
                -1, 0, 0};

    Quaternion q = Quaternion(m);

    EXPECT_NEAR(q.w, 0.70710677, 0.0001);
    EXPECT_NEAR(q.x, 0.0, 0.0001);
    EXPECT_NEAR(q.y, 0.70710677, 0.0001);
    EXPECT_NEAR(q.z, 0.0, 0.0001);

}

TEST(QuaternionTest, FromRotationMatrix3) {

    Mat3x3 m = {1, 0, 0,
                0, 1, 0,
                0, 0, 1};

    Quaternion q = Quaternion(m);

    EXPECT_NEAR(q.w, 1.0, 0.0001);
    EXPECT_NEAR(q.x, 0.0, 0.0001);
    EXPECT_NEAR(q.y, 0.0, 0.0001);
    EXPECT_NEAR(q.z, 0.0, 0.0001);

}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
