#pragma once
#include "AHRS.h"

using namespace std;

AHRS::AHRS() {
   this->gain = 0.995;
   this->gyro_bias = 0.02;
}

AHRS::AHRS(float gain, float gyro_bias) {
   this->gain = gain;
   this->gyro_bias = gyro_bias;
}

Quaternion AHRS::AttitudePrediction(Quaternion q_prior, Vector omega, float dt) {

   // 1. Attitude prediction
   Quaternion q_omega = Quaternion(1.0f, -0.5f*dt*omega.x, -0.5f*dt*omega.y, -0.5f*dt*omega.z);
   Quaternion q = q_omega*q_prior;
   q.Normalize();
      
   return q;

}

Quaternion AHRS::Update(Quaternion q_prior, Vector acc, Vector gyr, Vector mag, float dt, string frame) {

   // 1. Attitude prediction
   Quaternion q = AttitudePrediction(q_prior, gyr, dt);

   // 2. Attitude measurement
   Quaternion q_am = AM_Estimation(acc, mag, frame);

   // 3. Attitude estimation
   Quaternion q_est;
   Quaternion sum_q =  q + q_am;
   if (sum_q.Length() < sqrt(2)) {
      q_est = q*gain - q_am*(1 - gain); // If the components oppose each other, then they may add up to less than sqrt(2)
   } else { 
      q_est = q*gain + q_am*(1 - gain);
   }

   q.Normalize();

   return q_est;

}

Quaternion AHRS::AM_Estimation(Vector acc, Vector mag, string frame) {

   // 1. Rotation matrix
   Mat3x3 R = RotationMatrix(acc, mag, frame);

   // 2. Quaternion
   Quaternion q = Quaternion(R);

   return q;

}

