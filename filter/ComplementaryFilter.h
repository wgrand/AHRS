#include <iostream>
#include <string>

#include "../RefFrame.h"
#include "../model/Quaternion.h"
#include "../model/Vector.h"
#include "../model/Mat3x3.h"
#include "../model/RotationMatrix.h"

class ComplementaryFilter {
private:
   float gain;
   float gyro_bias;
   Quaternion AttitudePrediction(Quaternion q_prior, Vector omega, float dt);
   Quaternion AttitudeMeasurement(Vector acc, Vector mag, RefFrame frame);

public:
   ComplementaryFilter();
   ComplementaryFilter(float gain, float gyro_bias);
   Quaternion Update(Quaternion q_prior, Vector acc, Vector gyr, Vector mag, float dt, RefFrame frame);
};
