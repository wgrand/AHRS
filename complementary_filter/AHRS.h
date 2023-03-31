#include <iostream>
#include <string>

#include "../model/Quaternion.h"
#include "../model/Vector.h"
#include "../model/Mat3x3.h"
#include "../model/RotationMatrix.h"

using namespace std;

class AHRS {
private:
   Quaternion AttitudePropagation(Quaternion q_prior, Vector omega, float dt);
   Quaternion AM_Estimation(Vector acc, Vector mag, string frame);

public:
   float gain;
   float gyro_bias;
   AHRS() { }
   Quaternion Update(Quaternion q_prior, Vector acc, Vector gyr, Vector mag, float dt, string frame) { };
};
