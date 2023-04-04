#include "gtest/gtest.h"
#include "../model/Quaternion.h"
#include "../model/Mat3x3.h"

TEST(QuaternionTest, Multiply) {
    Quaternion q1(1, 2, 3, 4);
    Quaternion q2(5, 6, 7, 8);

    Quaternion result = q1*q2;

    EXPECT_FLOAT_EQ(result.Length(), q1.Length()*q2.Length());

    EXPECT_FLOAT_EQ(result.w, -60);
    EXPECT_FLOAT_EQ(result.x, 20);
    EXPECT_FLOAT_EQ(result.y, 14);
    EXPECT_FLOAT_EQ(result.z, 32);

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

TEST(QuaternionTest, FromRotationMatrix) {

    // Test case 1
    Mat3x3 m = {1, 0, 0,
                0, 0, -1,
                0, 1, 0};

    Quaternion q = Quaternion(m);

    EXPECT_NEAR(q.w, 0.70710677, 0.0001);
    EXPECT_NEAR(q.x, 0.70710677, 0.0001);
    EXPECT_NEAR(q.y, 0.0, 0.0001);
    EXPECT_NEAR(q.z, 0.0, 0.0001);

    // Test case 2
    Mat3x3 m2 = {0, 0, 1,
                 0, 1, 0,
                -1, 0, 0};

    Quaternion q2 = Quaternion(m2);

    EXPECT_NEAR(q2.w, 0.70710677, 0.0001);
    EXPECT_NEAR(q2.x, 0.0, 0.0001);
    EXPECT_NEAR(q2.y, 0.70710677, 0.0001);
    EXPECT_NEAR(q2.z, 0.0, 0.0001);

    // Test case 3
    Mat3x3 m3 = {1, 0, 0,
                 0, 1, 0,
                 0, 0, 1};

    Quaternion q3 = Quaternion(m3);

    EXPECT_NEAR(q3.w, 1.0, 0.0001);
    EXPECT_NEAR(q3.x, 0.0, 0.0001);
    EXPECT_NEAR(q3.y, 0.0, 0.0001);
    EXPECT_NEAR(q3.z, 0.0, 0.0001);

}

TEST(QuaternionTest, Multiplication) {

  // Test case 1: Identity quaternion
  Quaternion q1(1, 0, 0, 0);
  Quaternion q2(2, 3, 4, 5);
  Quaternion q_result = q1*q2;
  EXPECT_TRUE(q_result == q2);

  // Test case 2: Non-identity quaternions
  Quaternion q3(2, 1, 0, -1);
  Quaternion q4(3, -2, 1, 4);
  Quaternion q_expected(12, -2, 4, 4);
  Quaternion q_actual = q3*q4;
  EXPECT_TRUE(q_actual == q_expected);

}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
