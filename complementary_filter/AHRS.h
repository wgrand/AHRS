#include <iostream>
#include <string>

#include "../model/Quaternion.h"
#include "../model/Vector.h"
#include "../model/Mat3x3.h"

#include "../model/RotationMatrix.h"

using namespace std;

class AHRS {
public:
   static const float gain;
   static const float gyro_bias;
   static Quaternion Update(Quaternion q_prior, Vector gyr, Vector acc, Vector mag, float dt, string frame);

private:
   static Quaternion AttitudePropagation(Quaternion q_prior, Vector omega, float dt);
   static Quaternion AM_Estimation(Vector acc, Vector mag, string frame);
};
