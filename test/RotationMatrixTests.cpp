#include <string>
#include <iostream>
#include <cmath>

#include "gtest/gtest.h"
#include "../RefFrame.h"
#include "../model/Vector.h"
#include "../model/Quaternion.h"
#include "../model/Mat3x3.h"
#include "../model/RotationMatrix.cpp" // TODO: Import the header file instead of the source file.

TEST(RotationMatrixTest, Identity) {

    // Test case 1: NED frame

    // Define an acceleration vector with gravity pointing down in the +z direction.
    Vector acc(0.0, 0.0, 1.0);

    // Define a magnetic field vector with the magnetic field pointing north in the +x direction.
    Vector mag(1.0, 0.0, 0.0);

    // Create a rotation matrix from the acceleration and magnetic field vectors.
    Mat3x3 result = RotationMatrix(acc, mag, RefFrame::NED);

    // Define the expected result.
    Mat3x3 expected_result = {1.0, 0.0, 0.0,
                              0.0, 1.0, 0.0,
                              0.0, 0.0, 1.0};

    EXPECT_NEAR(result[0][0], expected_result[0][0], 0.0001);
    EXPECT_NEAR(result[0][1], expected_result[0][1], 0.0001);
    EXPECT_NEAR(result[0][2], expected_result[0][2], 0.0001);
    EXPECT_NEAR(result[1][0], expected_result[1][0], 0.0001);
    EXPECT_NEAR(result[1][1], expected_result[1][1], 0.0001);
    EXPECT_NEAR(result[1][2], expected_result[1][2], 0.0001);
    EXPECT_NEAR(result[2][0], expected_result[2][0], 0.0001);
    EXPECT_NEAR(result[2][1], expected_result[2][1], 0.0001);
    EXPECT_NEAR(result[2][2], expected_result[2][2], 0.0001);
    


    // Test case 2: ENU frame
    // Create a rotation matrix from the acceleration and magnetic field vectors.
    Mat3x3 result2 = RotationMatrix(acc, mag, RefFrame::ENU);

    // Define the expected result.
    Mat3x3 expected_result2 = {0.0, 1.0, 0.0,
                               1.0, 0.0, 0.0,
                               0.0, 0.0, -1.0};

    EXPECT_NEAR(result2[0][0], expected_result2[0][0], 0.0001);
    EXPECT_NEAR(result2[0][1], expected_result2[0][1], 0.0001);
    EXPECT_NEAR(result2[0][2], expected_result2[0][2], 0.0001);
    EXPECT_NEAR(result2[1][0], expected_result2[1][0], 0.0001);
    EXPECT_NEAR(result2[1][1], expected_result2[1][1], 0.0001);
    EXPECT_NEAR(result2[1][2], expected_result2[1][2], 0.0001);
    EXPECT_NEAR(result2[2][0], expected_result2[2][0], 0.0001);
    EXPECT_NEAR(result2[2][1], expected_result2[2][1], 0.0001);
    EXPECT_NEAR(result2[2][2], expected_result2[2][2], 0.0001);

}



int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
